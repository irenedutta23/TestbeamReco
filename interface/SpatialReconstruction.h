#ifndef SPATIALRECONSTRUCTION_H
#define SPATIALRECONSTRUCTION_H

#include "TestbeamReco/interface/Utility.h"

class SpatialReconstruction
{
private:
    std::shared_ptr<TProfile2D> y_timeDiff_ampFrac;
    std::vector<std::shared_ptr<TProfile2D>> v_timeDiff_coarse_vs_xy_channel;
    std::vector<std::shared_ptr<TProfile>> v_timeDiff_coarse_vs_x_channel;

    double getDX(const std::vector<double>& coeffs, const double x, const double shift = 0.0)
    {
        double dX = 0.0;
        int index = 0;
        for(const auto& coeff : coeffs)
        {
            dX += coeff*pow(x - shift,index);
            index++;
        }
        return (dX >= 0.0) ? dX : 0.0;
    }

    double getDXDerivative(const std::vector<double>& coeffs, const double x, const double shift = 0.0)
    {
        double dXD = 0.0;
        int index = 0;
        for(const auto& coeff : coeffs)
        {
            dXD += index*coeff*pow(x - shift,index-1);
            index++;
        }
        return dXD;
    }

    void spatialReconstruction([[maybe_unused]] NTupleReader& tr)
    {

	//******************************************************************
	//Position Reconstruction
	//******************************************************************
        const auto& enablePositionReconstruction = tr.getVar<bool>("enablePositionReconstruction");
        const auto& positionRecoPar = tr.getVar<std::vector<double>>("positionRecoPar");
        const auto& ampLGAD = tr.getVec<std::vector<double>>("ampLGAD");
        const auto& maxAmpIndex = tr.getVar<int>("maxAmpIndex");
        const auto& Amp2Index = tr.getVar<int>("Amp2Index");
        const auto& stripCenterXPositionLGAD = tr.getVec<std::vector<double>>("stripCenterXPositionLGAD");
        const auto& Amp1OverAmp1and2 = tr.getVar<double>("Amp1OverAmp1and2");
        //const auto& x = tr.getVar<double>("x");
        const auto& positionRecoMaxPoint = tr.getVar<double>("positionRecoMaxPoint");
        const auto& pitch = tr.getVar<double>("pitch");
        const auto& noiseAmpThreshold = tr.getVar<double>("noiseAmpThreshold");
        const auto& deltaT = tr.getVar<double>("deltaT");
        //std::vector<int> parity = {1,-1,1,-1,1,-1,1,-1};
        std::vector<int> parity = {-1,1,-1,1,-1,1,-1,1};
        const auto& parityLGAD = utility::remapToLGADgeometry(tr, parity, "parityLGAD");

        auto& goodNeighbour = tr.createDerivedVar<bool>("goodNeighbour");
        goodNeighbour = abs(maxAmpIndex - Amp2Index)==1 && ampLGAD[0][Amp2Index]>noiseAmpThreshold;
        auto& twoStripsReco = tr.createDerivedVar<bool>("twoStripsReco");
        twoStripsReco = goodNeighbour && (Amp1OverAmp1and2 < positionRecoMaxPoint);
        double y_reco=0.0, x_reco = 0.0, x1 = 0.0, y1 = 0.0, x2 = 0.0;
        double x_reco_basic = 0.0, y_reco_basic = 0.0;
        double dXdFrac = 0.0;
        if(enablePositionReconstruction)
        {	  
            assert(Amp1OverAmp1and2 >= 0); //make sure a1/(a1+a2) is a sensible number
            assert(Amp1OverAmp1and2 <= 1);
            x1 = stripCenterXPositionLGAD[0][maxAmpIndex];
            x2 = stripCenterXPositionLGAD[0][Amp2Index];

            //use the poly fit function
            auto dX = getDX(positionRecoPar, Amp1OverAmp1and2, 0.5);
            dX = (goodNeighbour && (Amp1OverAmp1and2 < positionRecoMaxPoint)) ? dX : 0.0;

            x_reco = (x2>x1) ? x1+dX : x1-dX;

            //Define basic x reco
            double xBasic = (1.0 - Amp1OverAmp1and2)*pitch;
            x_reco_basic = (x2>x1) ? x1 + xBasic : x1 - xBasic;

            //Define slope of poly fit function
            dXdFrac = getDXDerivative(positionRecoPar, Amp1OverAmp1and2, 0.5);

            //Define basic y reco
            double vX =  2.0;
            double vY = 50.0;
            double vR = vY/vX;
            double dXSign = (x2>x1) ? dX : -dX;
            double yBasic = vR*(pitch - 2*dXSign) + vY*deltaT;
            //double yBasic = vR*(pitch - 2*x_reco_basic) + vY*dT;
            //double yBasic = vR*pitch*(2*Amp1OverAmp1and2 - 1.0) + vY*dT;
            y_reco_basic = 0.5*parityLGAD[0][maxAmpIndex]*yBasic;

            //use lookup table for y reco
            if(y_timeDiff_ampFrac)
            {
                int ibin = y_timeDiff_ampFrac->FindBin(Amp1OverAmp1and2,deltaT);
                int xbin = utility::findBin(y_timeDiff_ampFrac, Amp1OverAmp1and2, "X");
                //int ibin = y_timeDiff_ampFrac->FindBin(x,deltaT);
                //int xbin = utility::findBin(y_timeDiff_ampFrac, x, "X");
                int ybin = utility::findBin(y_timeDiff_ampFrac, deltaT, "Y");
                y_reco = y_timeDiff_ampFrac->GetBinContent(ibin);

                if(y_reco == 0.0 && xbin > 0 && ybin > 0)
                {
                    y_reco = y_timeDiff_ampFrac->Interpolate(Amp1OverAmp1and2,deltaT);
                    //y_reco = y_timeDiff_ampFrac->Interpolate(x,deltaT);
                }

                y_reco *= parityLGAD[0][maxAmpIndex];
            }

        } //if enabled position reconstruction


        //Compute time resolution using reco positions
        const auto& y = tr.getVar<double>("y");
        const auto& x = tr.getVar<double>("x");
        const auto& corrTime = tr.getVec<double>("corrTime");
        auto& corrTimeLGADXTrackerY = tr.createDerivedVec<double>("corrTimeLGADXTrackY");
        auto& corrTimeLGADXY = tr.createDerivedVec<double>("corrTimeLGADXY");
        auto& corrTimeLGADXY0 = tr.createDerivedVec<double>("corrTimeLGADXY0");     
        auto& corrTimeLGADX = tr.createDerivedVec<double>("corrTimeLGADX");
        auto& corrTimeTrackerX = tr.createDerivedVec<double>("corrTimeTrackerX");   
          
        uint counter = 0;
        for(auto thisTime : corrTime)
        {
            double default_corr =  utility::getTrackerTimeCorr<TProfile2D>(x1, 0.0, thisTime, counter, v_timeDiff_coarse_vs_xy_channel); 
            double lgadX_trackerY_corr = default_corr;
            double lgadX_lgadY_corr =  default_corr;
            double lgadX_lgadY0_corr = default_corr;
            //Is this a good default?
            double lgadX_corr = default_corr;
         
            if (twoStripsReco)
            {
               lgadX_trackerY_corr = utility::getTrackerTimeCorr<TProfile2D>(x_reco, y, thisTime, counter, v_timeDiff_coarse_vs_xy_channel);
               lgadX_lgadY_corr = utility::getTrackerTimeCorr<TProfile2D>(x_reco, y_reco, thisTime, counter, v_timeDiff_coarse_vs_xy_channel);
               lgadX_lgadY0_corr = utility::getTrackerTimeCorr<TProfile2D>(x_reco, 0.0, thisTime, counter, v_timeDiff_coarse_vs_xy_channel);
               lgadX_corr = utility::getTrackerTimeCorr<TProfile>(x_reco, thisTime, counter, v_timeDiff_coarse_vs_x_channel);
            }
           
            auto TrackerX_corr = utility::getTrackerTimeCorr<TProfile>(x, thisTime, counter, v_timeDiff_coarse_vs_x_channel);
            
            corrTimeLGADXTrackerY.emplace_back(thisTime - lgadX_trackerY_corr);
            corrTimeLGADXY.emplace_back(thisTime - lgadX_lgadY_corr);
            corrTimeLGADXY0.emplace_back(thisTime - lgadX_lgadY0_corr);
            corrTimeLGADX.emplace_back(thisTime - lgadX_corr);
            corrTimeTrackerX.emplace_back(thisTime - TrackerX_corr);
            counter++;
        }

        utility::remapToLGADgeometry(tr, corrTimeLGADXTrackerY, "timeLGADXTrackerY");
        utility::remapToLGADgeometry(tr, corrTimeLGADXY,        "timeLGADXY");
        utility::remapToLGADgeometry(tr, corrTimeLGADXY0,       "timeLGADXY0");
        utility::remapToLGADgeometry(tr, corrTimeLGADX,         "timeLGADX");   
        utility::remapToLGADgeometry(tr, corrTimeTrackerX,      "timeTrackerX");

        // Position resolution for the pad sensors
        const auto& positionRecoParRight = tr.getVar<std::vector<double>>("positionRecoParRight");
        const auto& positionRecoParLeft = tr.getVar<std::vector<double>>("positionRecoParLeft");
        const auto& positionRecoParTop = tr.getVar<std::vector<double>>("positionRecoParTop");
        const auto& positionRecoParBot = tr.getVar<std::vector<double>>("positionRecoParBot");
        const auto& enablePositionReconstructionPad = tr.getVar<bool>("enablePositionReconstructionPad");
        const auto& sensorCenter = tr.getVar<double>("sensorCenter");
        const auto& sensorCenterY = tr.getVar<double>("sensorCenterY");
        const auto& amp1Indexes = tr.getVar<std::pair<int,int>>("amp1Indexes");
        const auto& AmpTopOverAmpTopandBotRight = tr.getVar<double>("AmpTopOverAmpTopandBotRight");
        const auto& AmpTopOverAmpTopandBotLeft = tr.getVar<double>("AmpTopOverAmpTopandBotLeft");
        const auto& AmpLeftOverAmpLeftandRightTop = tr.getVar<double>("AmpLeftOverAmpLeftandRightTop");
        const auto& AmpLeftOverAmpLeftandRightBot = tr.getVar<double>("AmpLeftOverAmpLeftandRightBot");
          	
        if(enablePositionReconstructionPad)
        {	  
            x1 = sensorCenter;
            
            //use the poly fit function
            auto dXTop = getDX(positionRecoParTop, AmpLeftOverAmpLeftandRightTop);
            auto dXBot = getDX(positionRecoParBot, AmpLeftOverAmpLeftandRightBot);
            auto dX = (amp1Indexes.first ==0) ? dXTop : dXBot;
            
            x_reco = x1 + dX;
           
            y1 = sensorCenterY;
            auto dYRight = getDX(positionRecoParRight, AmpTopOverAmpTopandBotRight);
            auto dYLeft = getDX(positionRecoParLeft, AmpTopOverAmpTopandBotLeft);
            auto dY = (amp1Indexes.second == 0) ? dYLeft : dYRight;
            
            y_reco = dY + y1;                                            
        } //if enabled position reconstruction

        tr.registerDerivedVar("x_reco", x_reco);
        tr.registerDerivedVar("x_reco_basic", x_reco_basic);
        tr.registerDerivedVar("dXdFrac", dXdFrac);
        tr.registerDerivedVar("y_reco", y_reco);
        tr.registerDerivedVar("y_reco_basic", y_reco_basic);
    }
public:
    SpatialReconstruction(const std::shared_ptr<TProfile2D>& histo, const std::vector<std::shared_ptr<TProfile2D>>& histVec,  const std::vector<std::shared_ptr<TProfile>>& histVec1D)
    : y_timeDiff_ampFrac(histo), v_timeDiff_coarse_vs_xy_channel(histVec), v_timeDiff_coarse_vs_x_channel(histVec1D)   
    {
        std::cout<<"Running Spatial Reconstruction Module"<<std::endl;
    }

    void operator()(NTupleReader& tr)
    {
        spatialReconstruction(tr);
    }
};

#endif
