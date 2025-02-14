#ifndef Geometry_h
#define Geometry_h

#include "TestbeamReco/interface/NTupleReader.h"
#include "TestbeamReco/interface/Utility.h"

class DefaultGeometry
{
public:
    DefaultGeometry(const int v=0) : voltage(v){}
    virtual ~DefaultGeometry() = default;
    const int voltage;
    class VoltageDependence
    {
    public:
        double noiseAmpThreshold;
        double signalAmpThreshold;
    };

    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}};
    std::vector<std::vector<int>> geometry = {{0}};
    std::map<int, bool> acLGADChannelMap = {{0,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}};
    double stripWidth = 0.08;
    double pitch = 999;
    double sensorCenter = 0;
    double sensorCenterY = 0;
    std::vector<double> stripCenterXPosition = {{0,0.0}};
    std::vector<double> stripCenterYPosition = {{0,0.0}};
    int numLGADchannels = 0;
    int photekIndex = 7;
    int lowGoodStripIndex = 1;
    int highGoodStripIndex = 5;
    double alpha = 0.0;
    double beta  = 0.0;
    double gamma =  0.0;
    double z_dut = 0.0;
    double xBinSize = 0.05;
    double yBinSize = 0.05;
    double xBinSize_delay_corr = 0.05;
    double yBinSize_delay_corr = 0.2;
    double xmin =  -1;
    double xmax =  -1;
    double ymin =  -1;
    double ymax =  -1; 
    double positionRecoMaxPoint = 1.0;
    double photekSignalThreshold = 200.0; //in mV
    double photekSignalMax = 350.0; //in mV
    double noiseAmpThreshold = 15.0;      //in mV
    double signalAmpThreshold = 15.0;    //in mV       
    bool isPadSensor = false; 
    bool isHPKStrips = false;
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = false;
    bool uses2022Pix = false;
    bool isHorizontal = false;
    int minPixHits = 0;
    int minStripHits = 7;
    int CFD_threshold = 20;
    std::vector<std::string> CFD_list = {"5","10","15","20","25","30","35","40","50","60"};
    std::vector<double> positionRecoPar = {-1};
    std::vector<double> positionRecoParRight = {-1};
    std::vector<double> positionRecoParLeft = {-1};
    std::vector<double> positionRecoParTop = {-1};
    std::vector<double> positionRecoParBot = {-1}; 
    std::vector<std::vector<double>> sensorEdges = {{-999.9, -999.9}, {999.9, 999.9}};
    std::vector<std::vector<double>> sensorEdgesTight = {{-999.9, -999.9}, {999.9, 999.9}};
    std::vector<std::vector<double>> ySlices = {{-999.9, 999.9}, {-999.9, 999.9}};
    std::vector<std::vector<double>> xSlices = {{-999.9, 999.9}, {-999.9, 999.9}};
    std::vector<std::vector<double>> boxes_XY = {{-999.9, -999.9,-999.9, -999.9}};
    std::vector<utility::ROI> regionsOfIntrest = {{"default", -999.9,999.9, -999.9,999.9}};
};

class BNL2020Geometry : public DefaultGeometry
{
public:
    // BNL 2020 Mapping
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC strips, and scope channel 7 was the photek
    // -----------------
    // |000000000000000|
    // |0 1 2 3 4 5 6 0|             -----
    // |0 1 2 3 4 5 6 0|             |777|
    // |0 1 2 3 4 5 6 0|             |777|
    // |000000000000000|             -----
    // -----------------
    BNL2020Geometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1/1.043}, {2,1/1.000}, {3,1/1.078}, {4,1/1.084}, {5,1/1.067}, {6,1/1.017}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.5553183648148}, {2,10.6590122524753}, {3,10.6470996902006}, {4,10.6075997712141}, {5,10.6432860123283}, {6,10.6622858488865}, {7,0.0}};
    // std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.5553183648148+0.022066641}, {2,10.6590122524753+0.016205606}, {3,10.6470996902006+0.014540078}, {4,10.6075997712141+0.012709104}, {5,10.6432860123283+0.013754913}, {6,10.6622858488865+0.027125698}, {7,0.0}}; // Handmade for BNL2020 200V
    double stripWidth = 0.08;
    double pitch = 0.1;
    std::vector<double> stripCenterXPosition = {0.0, 0.635, 0.535, 0.435, 0.335, 0.235, 0.135, 0.0};
    int numLGADchannels = 6;
    // std::map<int,VoltageDependence> voltageDependenceMap = {{200,{2.0,8.0}}, {210,{3.5,20.0}}, {220,{10.0,30.0}}, {225,{15.0,45.0}}};
    std::map<int,VoltageDependence> voltageDependenceMap = {{200,{7.0,8.0}}, {210,{8,20.0}}, {220,{10.0,30.0}}, {225,{15.0,45.0}}};
    double alpha = 1.5;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -0.15;
    double xmax =  0.85;
    double ymin =  9.5;
    double ymax = 12.0; 
    double positionRecoMaxPoint = 0.75;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = voltageDependenceMap[voltage].noiseAmpThreshold;
    double signalAmpThreshold = voltageDependenceMap[voltage].signalAmpThreshold; 
    bool enablePositionReconstruction = true;   
    std::vector<double> positionRecoPar = {0.05, -0.104407, -1.24925, 10.5174, -27.1884};
    std::vector<std::vector<double>> sensorEdges = {{-0.06, 9.8}, { 0.8, 11.6}};
};

class BNL2021WideGeometry : public DefaultGeometry
{
public:
    // BNL 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC strips, and scope channel 7 was the photok
    // -----------------
    // |000000000000000|
    // |0 1 2 3 4 5 6 0|             -----
    // |0 1 2 3 4 5 6 0|             |777|
    // |0 1 2 3 4 5 6 0|             |777|
    // |000000000000000|             -----
    // -----------------
    BNL2021WideGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};   
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,0.0}, {2,0.0}, {3,1.0/0.91469191}, {4,1.0/1.0}, {5,1/1.000875317}, {6,0.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.6646501756637}, {2,10.67112230944859}, {3,10.65231275084190}, {4,10.5912852140283}, {5,10.6752360435417}, {6,10.6188857394863}, {7,0.0}};    
    double stripWidth = 0.08;
    double pitch = 0.20;
    std::vector<double> stripCenterXPosition = {0.0, -4.70, -4.85, -5.00, -5.20, -5.40, -5.60, 0.0};
    int numLGADchannels = 6;
    int lowGoodStripIndex = 3;
    int highGoodStripIndex = 3;
    double alpha = 1.3;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -6.2;
    double xmax = -4.4;
    double ymin =  9.0;
    double ymax =  12.5; 
    double positionRecoMaxPoint = 0.85;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 20.0;
    double signalAmpThreshold = 40.0;
    bool enablePositionReconstruction = true;
    std::vector<double> positionRecoPar = {0.1, -0.0906283, -2.09241, 10.5532, -17.5042};
    std::vector<std::vector<double>> sensorEdges = {{-5.8484, 9.30}, {-4.48058, 12.05}};
};

class BNL2021MediumGeometry : public DefaultGeometry
{
public:
    // BNL 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC strips, and scope channel 7 was the photok
    // -----------------
    // |000000000000000|
    // |0 1 2 3 4 5 6 0|             -----
    // |0 1 2 3 4 5 6 0|             |777|
    // |0 1 2 3 4 5 6 0|             |777|
    // |000000000000000|             -----
    // -----------------
    BNL2021MediumGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};   
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/0.888684191}, {2,1.0/1.054804164}, {3,1.0/1.034950947}, {4,1.0/1.0}, {5,1.0/0.991297836}, {6,1.0/0.990204448}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.6222952064563}, {2,10.6341462404406}, {3,10.61543585391420}, {4,10.58663873896650}, {5,10.67386990876170}, {6,10.63764448498840}, {7,0.0}};    
    double stripWidth = 0.08;
    double pitch = 0.15;
    std::vector<double> stripCenterXPosition = {0.0, -4.60, -4.75, -4.90, -5.05, -5.20, -5.35, 0.0};
    int numLGADchannels = 6;
    double alpha = 1.3;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xBinSize = 0.02;
    double yBinSize = 0.05;
    double xmin =  -5.7;
    double xmax =  -4.3;
    double ymin =   9.0;
    double ymax =  12.5;
    double positionRecoMaxPoint = 0.81;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 20.0;
    double signalAmpThreshold = 40.0;
    bool enablePositionReconstruction = true;
    std::vector<double> positionRecoPar = {0.075, -0.140285, -0.774667, 5.65837, -13.5359};
    std::vector<std::vector<double>> sensorEdges = {{-5.625, 9.272}, {-4.403, 12.067}};
};

class BNL2021NarrowGeometry : public DefaultGeometry
{
public:
    // BNL 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC strips, and scope channel 7 was the photok
    // -----------------
    // |000000000000000|
    // |0 1 2 3 4 5 6 0|             -----
    // |0 1 2 3 4 5 6 0|             |777|
    // |0 1 2 3 4 5 6 0|             |777|
    // |000000000000000|             -----
    // -----------------
    BNL2021NarrowGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};   
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,0.0}, {2,0.0}, {3,1.0}, {4,1.0/1.024783}, {5,1.0/1.066005523}, {6,1.0/1.139364787}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.4299204909350}, {2,10.5485097838644}, {3,10.5073049422881}, {4,10.5344490021019}, {5,10.5361014348539}, {6,10.6153329754486}, {7,0.0}};    
    double stripWidth = 0.08;
    double pitch = 0.10;
    std::vector<double> stripCenterXPosition = {0.0, -4.60, -4.70, -4.80, -4.90, -5.00, -5.10, 0.0};
    int numLGADchannels = 6;
    int lowGoodStripIndex = 3;
    int highGoodStripIndex = 4;
    double alpha = 1.3;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -5.4;
    double xmax = -4.3;
    double ymin =  9.0;
    double ymax =  12.5;
    double positionRecoMaxPoint = 0.73;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 20.0;
    double signalAmpThreshold = 40.0;
    bool enablePositionReconstruction = true;
    std::vector<double> positionRecoPar = {0.05, -0.0499398, -2.15926, 18.1142, -52.2208};
    std::vector<std::vector<double>> sensorEdges = {{-5.253, 9.278}, {-4.474, 12.079}};
};

class HPKPadC2Geometry : public DefaultGeometry
{
public:
    // HPK 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-4 was AC pads, 5-6 was the other sensor, and scope channel 7 was the photok
    // ----------
    // |0000000|             -----
    // |0 1 2 0|             |777|
    // |0 4 3 0|             |777|
    // |0000000|             -----
    // ----------
    HPKPadC2Geometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{2,1}}, {4,{2,0}}, {7,{3,0}}};    
    std::vector<std::vector<int>> geometry = {{0}, {1,2}, {4,3}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/0.935797725}, {2,1.0}, {3,1.0/0.979331568}, {4,1.0/1.021097111}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.4797103988649}, {2,10.5140246761814}, {3,10.4517123511449}, {4,10.4652081424981}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.45; 
    double pitch = 0.5;
    double sensorCenter =-5.773;
    double sensorCenterY = 10.391; 
    std::vector<double> stripCenterXPosition = {0.0, -6.023, -5.523, -5.523, -6.023,  0.0};
    std::vector<double> stripCenterYPosition = {0.0, 10.641, 10.641, 10.141, 10.141, 0.0};
    int numLGADchannels = 4;
    double alpha = -0.5;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -6.6;
    double xmax = -5.0;
    double ymin =  9.6;
    double ymax = 11.0; 
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 10.0;
    double signalAmpThreshold = 50.0; 
    bool isPadSensor = true;
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = true;
    std::vector<double> positionRecoParTop = {-0.494315,  1.28059, 1.92055, -9.89445, 11.8025, -4.01589};
    std::vector<double> positionRecoParBot = {-0.0849671, -3.72958, 25.6829, -63.7924, 70.3368, -28.3888};
    std::vector<double> positionRecoParRight = {-0.046495, -3.91451, 24.6937, -57.5006, 59.3214, -22.163};
    std::vector<double> positionRecoParLeft = {0.0339823, -5.42069, 33.1184, -78.8264, 84.4803, -33.3587};
    //std::vector<double> positionRecoParTop = {-0.137164, -0.126798, 1.18544,  -0.775188}; //100 microns around center
    //std::vector<double> positionRecoParBot = {-0.0409756, -0.748701, 2.46567, -1.61481}; // 100 microns around center
    //std::vector<std::vector<double>> sensorEdges = {{-5.87 , 9.94}, { -5.67, 10.84}}; //100 microns from center
    std::vector<std::vector<double>> sensorEdges = {{-6.023 , 10.141}, { -5.523, 10.641}}; //square interior of pads
    //std::vector<std::vector<double>> sensorEdges = {{-6.03 , 10.04}, { -5.53, 10.74}}; //current version for best x and y reco
    //std::vector<std::vector<double>> sensorEdges = {{-6.03 , 9.94}, { -5.53, 10.84}};  //older version for best x reco
    //std::vector<std::vector<double>> sensorEdges = {{-6.25 , 9.85}, { -5.10, 11.0}}; //original version whole sensor
    std::vector<std::vector<double>> ySlices = {{10.05, 10.35}, {10.55, 10.85}};
    std::vector<std::vector<double>> xSlices = {{-6.1, -5.8}, {-5.6, -5.3}};
    std::vector<std::vector<double>> boxes_XY ={{-6.1, -5.8,10.05, 10.35}}; 
};

class HPKPadB2Geometry : public DefaultGeometry
{
public:
    // HPK 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-4 was AC pads, 5-6 was the other sensor, and scope channel 7 was the photok
    // ----------
    // |0000000|             -----
    // |0 1 2 0|             |777|
    // |0 4 3 0|             |777|
    // |0000000|             -----
    // ----------
    HPKPadB2Geometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{2,1}}, {4,{2,0}}, {7,{3,0}}};    
    std::vector<std::vector<int>> geometry = {{0}, {1,2}, {4,3}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/0.983042521}, {2,1.0}, {3,1.0/1.02948944}, {4,1.0/1.028227936}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.61949518764660}, {2,10.64806524828680}, {3,10.593269954715}, {4,10.60141636634710}, {5,0.0}, {6,0.0}, {7,0.0}};
    double stripWidth = 0.45; 
    double pitch = 0.5;
    double sensorCenter =-5.437;
    double sensorCenterY = 10.132; 
    std::vector<double> stripCenterXPosition = {0.0, -5.687, -5.187, -5.187, -5.687, 0.0};
    std::vector<double> stripCenterYPosition = {0.0, 10.382, 10.382, 9.882, 9.882, 0.0}; //will fix this later but code for pad efficiency plots is not fully working
    int numLGADchannels = 4;
    double alpha = -1.65;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -6.1;
    double xmax =  -4.8;
    double ymin =  9.4;
    double ymax = 10.8;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 10.0;
    double signalAmpThreshold = 60.0;
    bool isPadSensor = true;
    bool enablePositionReconstruction = false;
    bool enablePositionReconstructionPad = true;
    std::vector<double> positionRecoParTop = {-1.73924, 8.02522, -13.6476, 9.01207};
    std::vector<double> positionRecoParBot = {-2.63515, 13.9472, -25.9853, 17.2325};
    std::vector<double> positionRecoParRight = {-1.59902, 7.41101, -12.5997, 8.27159};
    std::vector<double> positionRecoParLeft = {-0.440067, -0.0703567, 2.77482, -1.87093};
    std::vector<std::vector<double>> sensorEdges = {{-5.687 , 9.882}, { -5.187, 10.382}};
    std::vector<std::vector<double>> ySlices = {{9.85, 10.15}, {10.35, 10.65}};
    std::vector<std::vector<double>> xSlices = {{-5.55, -5.25}, {-5.05, -4.75}};
    std::vector<std::vector<double>> boxes_XY = { {-6.1, -5.8,10.05, 10.35}}; 
};

class HPKStripsC2WideMetalGeometry : public DefaultGeometry
{
public:
    // HPK Strips 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC pads, and scope channel 7 was the photok
    // ----------
    // |0000000000000|             -----
    // |0 1 1 1 1 1 0|             |777|
    // |0 2 2 2 2 2 0|             |777|
    // |0 3 3 3 3 3 0|             -----
    // |0 4 4 4 4 4 0|
    // |0 5 5 5 5 5 0|
    // |0 6 6 6 6 6 0|
    // |0000000000000|
    // ----------
    HPKStripsC2WideMetalGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};   
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/0.979851466}, {2,1.0/1.0}, {3,1.0/0.983149499}, {4,1.0/0.977206933}, {5,1.0/0.985974202}, {6,1.0/1.098791332}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.6798182741841}, {2,10.4423181134130}, {3,10.6384131291640}, {4,10.4103620415613}, {5,10.6007257972181}, {6,10.4517801214152}, {7,0.0}};
    double stripWidth = 0.045;
    double pitch = 0.080;
    std::vector<double> stripCenterXPosition = {0.0, 0.9429, 0.8712, 0.7889, 0.7076, 0.6297, 0.5486, 0.0};
    int numLGADchannels = 6;
    double alpha = -0.2;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin =   -1.0;
    double xmax =    2.5;
    double ymin =    0.0;
    double ymax =    4.2;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 4.0;
    double signalAmpThreshold = 30.0;
    bool isHPKStrips = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    std::vector<double> positionRecoPar = {0.8129, -3.599, 5.735, -3.166}; 
    // std::vector<std::vector<double>> sensorEdges = {{0.2329, 0.260}, {1.005, 4.106}};
    std::vector<std::vector<double>> sensorEdges = {{0.413, 1.000}, {1.005, 4.106}};
};

class HPKStripsC2NarrowMetalGeometry : public DefaultGeometry
{
public:
    // HPK Strips 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC pads, and scope channel 7 was the photok
    // ----------
    // |0000000000000|             -----
    // |0 6 6 6 6 6 0|             |777|
    // |0 5 5 5 5 5 0|             |777|
    // |0 4 4 4 4 4 0|             -----
    // |0 3 3 3 3 3 0|
    // |0 2 2 2 2 2 0|
    // |0 1 1 1 1 1 0|
    // |0000000000000|
    // ----------
    HPKStripsC2NarrowMetalGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,5}}, {2,{1,4}}, {3,{1,3}}, {4,{1,2}}, {5,{1,1}}, {6,{1,0}}, {7,{2,0}}};    
    std::vector<std::vector<int>> geometry = {{0}, {6,5,4,3,2,1}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/1.026449161}, {2,1.0/1.048446448}, {3,1.0/1.039418742}, {4,1.0/1.026293328}, {5,1.0/1.0}, {6,1.0/1.130503306}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.63158422778770}, {2,10.40489295380600}, {3,10.57580707002640}, {4,10.38063146228080}, {5,10.57271716853830}, {6,10.42845270625820}, {7,0.0}};
    double stripWidth = 0.030;
    double pitch = 0.080;
    std::vector<double> stripCenterXPosition = {0.0, 0.2792, 0.3495, 0.4361, 0.5153, 0.5974, 0.6899, 0.0}; 
    int numLGADchannels = 6;
    double alpha = -0.2;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin =  -1.2;
    double xmax =   2.5;
    double ymin =   0.0;
    double ymax =   4.3;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 4.0;
    double signalAmpThreshold = 27.0;
    bool isHPKStrips = true;
    bool isHorizontal = true;
    bool enablePositionReconstruction = true;
    std::vector<double> positionRecoPar = {0.8129, -3.599, 5.735, -3.166};
    // std::vector<std::vector<double>> sensorEdges = {{0.221252, 0.32692}, {0.832446, 4.03807}};
    std::vector<std::vector<double>> sensorEdges = {{0.221252, 1.000}, {0.832446, 4.03807}};

};

class RonStripsGeometry : public DefaultGeometry
{
public:
    // Ron Strips 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-6 was AC strips, and scope channel 7 was the photok
    // -----------------
    // |000000000000000|
    // |0 1 2 3 4 5 6 0|             -----
    // |0 1 2 3 4 5 6 0|             |777|
    // |0 1 2 3 4 5 6 0|             |777|
    // |000000000000000|             -----
    // -----------------
    RonStripsGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{1,0}}, {2,{1,1}}, {3,{1,2}}, {4,{1,3}}, {5,{1,4}}, {6,{1,5}}, {7,{2,0}}};
    std::vector<std::vector<int>> geometry = {{0}, {1,2,3,4,5,6}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,false}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0/0.981074198}, {2,1.0/1.0}, {3,1.0/1.033255985}, {4,1.0/0.978685834}, {5,1.0/1.031778822}, {6,1.0/1.04870677}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,10.510402741525}, {2,10.5446584367218}, {3,10.5986852805641}, {4,10.5781494107524}, {5,10.6004686623480}, {6,10.5716321601745}, {7,0.0}};
    double stripWidth = 0.05;
    double pitch = 0.2;
    std::vector<double> stripCenterXPosition = {0.0, -4.792, -4.992, -5.192, -5.392, -5.592, -5.792, 0.0};
    int numLGADchannels = 6;
    int lowGoodStripIndex = 1;
    double alpha = 0.2;
    double beta  = 0.0;
    double gamma = 0.0;
    double z_dut = 0.0;
    double xmin = -6.2;
    double xmax = -4.5;
    double ymin =  9.4;
    double ymax =  11.4;
    double positionRecoMaxPoint = 0.79;
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 8.0;
    double signalAmpThreshold = 10.0;
    bool enablePositionReconstruction = true;
    //std::vector<double> positionRecoPar = {1.03701, -3.31145, 3.7838, -1.58913};
    std::vector<double> positionRecoPar = {0.30593, -0.396956};
    std::vector<std::vector<double>> sensorEdges = {{-6.0, 9.621}, {-4.652, 11.267}};
};

class BNLPixelHexGeometry : public DefaultGeometry
{
public:
    // BNL Pixel 2021 Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0 was DC ring, scope channel 1-4 was AC pads, 5-6 was the other sensor, and scope channel 7 was the photok
    // ----------
    // |  1  2 |             -----
    // |0  6  3|             |777|
    // |  5  4 |             |777|
    // ----------            -----
    BNLPixelHexGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{1,{0,0}}, {2,{0,1}}, {0,{1,0}}, {6,{1,1}}, {3,{1,2}}, {5,{2,0}}, {4,{2,1}}, {7,{2,0}}};    
    std::vector<std::vector<int>> geometry = {{1,2}, {0,6,3}, {5,4}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {3,true}, {4,true}, {5,true}, {6,true}, {7,false}};     
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    std::vector<double> stripCenterXPosition = {0.0, 0, 0, 0, 0, 0, 0, 0.0};
    std::vector<double> stripCenterYPosition = {0.0, 0, 0, 0, 0, 0, 0, 0.0}; 
    int numLGADchannels = 6;
    double gamma = 0.0;
    double xmin = -5.0;
    double xmax =  5.0;
    double ymin = -5.0;
    double ymax =  5.0; 
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 10.0;
    double signalAmpThreshold = 30.0;
    bool enablePositionReconstruction = false;
    std::vector<double> positionRecoPar = {0.8129, -3.599, 5.735, -3.166};
    std::vector<std::vector<double>> sensorEdges = {{-999.9, -999.9}, {999.9, 999.9}};    
};

class HPK2DCLGADGeometry : public DefaultGeometry
{
public:
    // HPK2 DC LGAD Mapping set
    // Used lecroy scope channels 0-7
    // scope channel 0,1,2,4 went to sensor pads, channels 5,6 went to BNL 2020 strips, and scope channel 3,7 went to the photok
    // -------             -----
    // | 0 1 |             |777|
    // | 4 2 |             |777|
    // -------             -----
    HPK2DCLGADGeometry(const int v=0) : voltage(v){}
    const int voltage;
    std::map<int, std::vector<int>> indexToGeometryMap = {{0,{0,0}}, {1,{0,1}}, {4,{1,0}}, {2,{1,1}}, {7,{2,0}}};    
    std::vector<std::vector<int>> geometry = {{0,1}, {4,2}, {7}};
    std::map<int, bool> acLGADChannelMap = {{0,true}, {1,true}, {2,true}, {4,true}, {7,false}};
    std::map<int, double> amplitudeCorrectionFactor = {{0,1.0}, {1,1.0}, {2,1.0}, {3,1.0}, {4,1.0}, {5,1.0}, {6,1.0}, {7,1.0}};
    std::map<int, double> timeCalibrationCorrection = {{0,0.0}, {1,0.0}, {2,0.0}, {3,0.0}, {4,0.0}, {5,0.0}, {6,0.0}, {7,0.0}};
    std::vector<double> stripCenterXPosition = {-5.50, -6.00, -6.00, -5.50,  0.0};
    std::vector<double> stripCenterYPosition = {10.57, 10.57, 10.11, 10.11, 0.0};
    int numLGADchannels = 4;
    double gamma = 0.284886; 
    double xmin = -3.0;
    double xmax =  3.0;
    double ymin =  8.0;
    double ymax =  13.0; 
    double photekSignalThreshold = 50.0;
    double noiseAmpThreshold = 15.0;
    double signalAmpThreshold = 80.0;
    bool enablePositionReconstruction = false;
    std::vector<double> positionRecoPar = {0.8129, -3.599, 5.735, -3.166};
    std::vector<std::vector<double>> sensorEdges = {{-2.0 , 9.0}, { 2.0, 13.0}};
    std::vector<std::vector<double>> ySlices = {{10.05, 10.35}, {10.55, 10.85}};
    std::vector<std::vector<double>> xSlices = {{-6.1, -5.8}, {-5.6, -5.3}};
    std::vector<std::vector<double>> boxes_XY ={{-6.1, -5.8,10.05, 10.35}}; 
};

#endif
