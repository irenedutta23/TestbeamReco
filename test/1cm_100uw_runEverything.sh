#!/bin/bash
## EIC_W2_1cm_500up_100uw_220V

if [ $# == 0 ]
then
echo "Running over EIC_W2_1cm_500up_100uw_220V sensor"
cd ../test
./MyAnalysis -A InitialAnalyzer -D EIC_W2_1cm_500up_100uw_220V
cd ../macros
python FindDelayCorrections.py -D EIC_W2_1cm_500up_100uw_220V
python FindInputHistos4YReco.py -D EIC_W2_1cm_500up_100uw_220V -I
cd ../test
./MyAnalysis -A Analyze -D EIC_W2_1cm_500up_100uw_220V
echo "Analyzer finished"
fi

if [ $# == 0 ] || [ "$1" == "-q" ]
then
cd ../macros
#python DoPositionRecoFit.py -D EIC_W2_1cm_500up_100uw_220V -A --xmax 0.82 --fitOrder 4
#python PlotAmplitudeVsX.py  -D EIC_W2_1cm_500up_100uw_220V --xlength 2.5 --ylength 90.0
#python PlotAmplitudeVsXY.py -D EIC_W2_1cm_500up_100uw_220V --zmin 20.0 --zmax 90.0
python PlotTimeDiffVsX.py   -D EIC_W2_1cm_500up_100uw_220V --xlength 5.2 --ylength 4000.0
#python PlotTimeDiffVsXY.py  -D EIC_W2_1cm_500up_100uw_220V --zmin 25.0 --zmax 75.0
python PlotTimeDiffVsY.py   -D EIC_W2_1cm_500up_100uw_220V --xlength 5.2 --ylength 4000.0
#python PlotTimeMeanVsXY.py  -D EIC_W2_1cm_500up_100uw_220V --zmin -0.5 --zmax 0.5
#python PlotSimpleXYMaps.py  -D EIC_W2_1cm_500up_100uw_220V
#python PlotRecoDiffVsXY.py  -D EIC_W2_1cm_500up_100uw_220V --zmin 0.0 --zmax 100.0
python PlotRecoDiffVsX.py   -D EIC_W2_1cm_500up_100uw_220V --xlength 5.2 --ylength 4000.0
python PlotRecoDiffVsY.py   -D EIC_W2_1cm_500up_100uw_220V --xlength 5.2 --ylength 4000.0
#python PlotEfficiency.py    -D EIC_W2_1cm_500up_100uw_220V -x 2.5
#python plot1DRes.py         -D EIC_W2_1cm_500up_100uw_220V
#python PlotRecoDiffVsY.py   -D EIC_W2_1cm_500up_100uw_220V --xlength 10.0 --ylength 3500.0
fi

if [ $# == 0 ] || [ "$1" == "-q" ] || [ "$1" == "-d" ]
then
root -e "TFile *f = new TFile(\"../output/EIC_W2_1cm_500up_100uw_220V/EIC_W2_1cm_500up_100uw_220V_Analyze.root\",\"r\");\
TCanvas *c1 = new TCanvas(\"c1\",\"c1\",1400,500);\
c1->Divide(2);\
c1->cd(1);\
Yreco_vs_Ytrack->Draw(\"colz\");\
c1->cd(2);\
Yreco_vs_Ytrack->Draw();"
fi