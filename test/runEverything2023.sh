
## BNL_50um_1cm_450um_W3051_2_2_170V
echo "Running over BNL_50um_1cm_450um_W3051_2_2_170V sensor"
cd ../test
./MyAnalysis -A InitialAnalyzer -D BNL_50um_1cm_450um_W3051_2_2_170V
cd ../macros
python FindDelayCorrections.py -D BNL_50um_1cm_450um_W3051_2_2_170V
python FindInputHistos4YReco.py -D BNL_50um_1cm_450um_W3051_2_2_170V -I
cd ../test
./MyAnalysis -A Analyze -D BNL_50um_1cm_450um_W3051_2_2_170V
cd ../macros

python DoPositionRecoFit.py         -D BNL_50um_1cm_450um_W3051_2_2_170V -A --xmax 0.79 --fitOrder 5
python PlotAmplitudeVsX.py          -D BNL_50um_1cm_450um_W3051_2_2_170V --xlength 2.5 --ylength 100.0
python PlotAmplitudeVsXY.py         -D BNL_50um_1cm_450um_W3051_2_2_170V --zmin 20.0 --zmax 100.0
python PlotTimeDiffVsX.py           -D BNL_50um_1cm_450um_W3051_2_2_170V --xlength 2.5 --ylength 150.0
python PlotTimeDiffVsXY.py          -D BNL_50um_1cm_450um_W3051_2_2_170V --zmin 25.0 --zmax 75.0
python PlotTimeDiffVsY.py           -D BNL_50um_1cm_450um_W3051_2_2_170V --xlength 6.0 --ylength 150.0
python PlotTimeMeanVsXY.py          -D BNL_50um_1cm_450um_W3051_2_2_170V --zmin -0.5 --zmax 0.5
python PlotSimpleXYMaps.py          -D BNL_50um_1cm_450um_W3051_2_2_170V
python PlotRecoDiffVsXY.py          -D BNL_50um_1cm_450um_W3051_2_2_170V --zmin 0.0 --zmax 100.0
python PlotRecoDiffVsX.py           -D BNL_50um_1cm_450um_W3051_2_2_170V --xlength 2.5 --ylength 150.0
python PlotEfficiency.py            -D BNL_50um_1cm_450um_W3051_2_2_170V -x 2.5
python plot1DRes.py                 -D BNL_50um_1cm_450um_W3051_2_2_170V
python PlotRecoDiffVsY.py           -D BNL_50um_1cm_450um_W3051_2_2_170V --xlength 5.6 --ylength 4.0
python PlotCutFlow.py               -D BNL_50um_1cm_450um_W3051_2_2_170V

# Paper plots
python Paper_1DRes.py               -D BNL_50um_1cm_450um_W3051_2_2_170V
python Paper_Efficiency.py          -D BNL_50um_1cm_450um_W3051_2_2_170V -x 2.5
python Paper_XRes.py                -D BNL_50um_1cm_450um_W3051_2_2_170V -x 2.5

python Paper_1DRes.py               -D BNL_50um_1cm_450um_W3051_2_2_170V -t
python Paper_Efficiency.py          -D BNL_50um_1cm_450um_W3051_2_2_170V -x 2.5 -t
python Paper_XRes.py                -D BNL_50um_1cm_450um_W3051_2_2_170V -x 2.5 -t

# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_450um_W3051_2_2_170V -x 1.2 -y 82
# python Paper_XRes.py                -D BNL_50um_1cm_450um_W3051_2_2_170V -x 1.2 --hot
# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_450um_W3051_2_2_170V -x 1.2 -y 82 --hot
# python Paper_Summary_XRes_Time.py   -D BNL_50um_1cm_450um_W3051_2_2_170V -x 1.2 -y 70 --hot



# ## BNL_50um_1cm_400um_W3051_1_4_160V
# echo "Running over BNL_50um_1cm_400um_W3051_1_4_160V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_50um_1cm_400um_W3051_1_4_160V
# cd ../macros
# python FindDelayCorrections.py -D BNL_50um_1cm_400um_W3051_1_4_160V
# python FindInputHistos4YReco.py -D BNL_50um_1cm_400um_W3051_1_4_160V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_50um_1cm_400um_W3051_1_4_160V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_50um_1cm_400um_W3051_1_4_160V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_50um_1cm_400um_W3051_1_4_160V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_50um_1cm_400um_W3051_1_4_160V --zmin 20.0 --zmax 100.0
# python PlotTimeDiffVsX.py           -D BNL_50um_1cm_400um_W3051_1_4_160V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_50um_1cm_400um_W3051_1_4_160V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_50um_1cm_400um_W3051_1_4_160V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_50um_1cm_400um_W3051_1_4_160V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_50um_1cm_400um_W3051_1_4_160V
# python PlotRecoDiffVsXY.py          -D BNL_50um_1cm_400um_W3051_1_4_160V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_50um_1cm_400um_W3051_1_4_160V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_50um_1cm_400um_W3051_1_4_160V -x 2.5
# python plot1DRes.py                 -D BNL_50um_1cm_400um_W3051_1_4_160V
# python PlotRecoDiffVsY.py           -D BNL_50um_1cm_400um_W3051_1_4_160V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_50um_1cm_400um_W3051_1_4_160V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_50um_1cm_400um_W3051_1_4_160V
# # python Paper_Efficiency.py          -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2
# # python Paper_XRes.py                -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_50um_1cm_400um_W3051_1_4_160V -x 1.2 -y 70 --hot



# ## BNL_50um_1cm_450um_W3052_2_4_185V
# echo "Running over BNL_50um_1cm_450um_W3052_2_4_185V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_50um_1cm_450um_W3052_2_4_185V
# cd ../macros
# python FindDelayCorrections.py -D BNL_50um_1cm_450um_W3052_2_4_185V
# python FindInputHistos4YReco.py -D BNL_50um_1cm_450um_W3052_2_4_185V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_50um_1cm_450um_W3052_2_4_185V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_50um_1cm_450um_W3052_2_4_185V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_50um_1cm_450um_W3052_2_4_185V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_50um_1cm_450um_W3052_2_4_185V --zmin 20.0 --zmax 100.0
# python PlotTimeDiffVsX.py           -D BNL_50um_1cm_450um_W3052_2_4_185V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_50um_1cm_450um_W3052_2_4_185V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_50um_1cm_450um_W3052_2_4_185V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_50um_1cm_450um_W3052_2_4_185V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_50um_1cm_450um_W3052_2_4_185V
# python PlotRecoDiffVsXY.py          -D BNL_50um_1cm_450um_W3052_2_4_185V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_50um_1cm_450um_W3052_2_4_185V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_50um_1cm_450um_W3052_2_4_185V -x 2.5
# python plot1DRes.py                 -D BNL_50um_1cm_450um_W3052_2_4_185V
# python PlotRecoDiffVsY.py           -D BNL_50um_1cm_450um_W3052_2_4_185V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_50um_1cm_450um_W3052_2_4_185V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_50um_1cm_450um_W3052_2_4_185V
# # python Paper_Efficiency.py          -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2
# # python Paper_XRes.py                -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_50um_1cm_450um_W3052_2_4_185V -x 1.2 -y 70 --hot



# ## BNL_20um_1cm_400um_W3074_1_4_95V
# echo "Running over BNL_20um_1cm_400um_W3074_1_4_95V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_20um_1cm_400um_W3074_1_4_95V
# cd ../macros
# python FindDelayCorrections.py -D BNL_20um_1cm_400um_W3074_1_4_95V
# python FindInputHistos4YReco.py -D BNL_20um_1cm_400um_W3074_1_4_95V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_20um_1cm_400um_W3074_1_4_95V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_20um_1cm_400um_W3074_1_4_95V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_20um_1cm_400um_W3074_1_4_95V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_20um_1cm_400um_W3074_1_4_95V --zmin 10.0 --zmax 50.0
# python PlotTimeDiffVsX.py           -D BNL_20um_1cm_400um_W3074_1_4_95V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_20um_1cm_400um_W3074_1_4_95V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_20um_1cm_400um_W3074_1_4_95V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_20um_1cm_400um_W3074_1_4_95V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_20um_1cm_400um_W3074_1_4_95V
# python PlotRecoDiffVsXY.py          -D BNL_20um_1cm_400um_W3074_1_4_95V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_20um_1cm_400um_W3074_1_4_95V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_20um_1cm_400um_W3074_1_4_95V -x 2.5
# python plot1DRes.py                 -D BNL_20um_1cm_400um_W3074_1_4_95V
# python PlotRecoDiffVsY.py           -D BNL_20um_1cm_400um_W3074_1_4_95V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_20um_1cm_400um_W3074_1_4_95V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_20um_1cm_400um_W3074_1_4_95V
# # python Paper_Efficiency.py          -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2
# # python Paper_XRes.py                -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_20um_1cm_400um_W3074_1_4_95V -x 1.2 -y 70 --hot



# ## BNL_20um_1cm_400um_W3075_1_2_80V
# echo "Running over BNL_20um_1cm_400um_W3075_1_2_80V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_20um_1cm_400um_W3075_1_2_80V
# cd ../macros
# python FindDelayCorrections.py -D BNL_20um_1cm_400um_W3075_1_2_80V
# python FindInputHistos4YReco.py -D BNL_20um_1cm_400um_W3075_1_2_80V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_20um_1cm_400um_W3075_1_2_80V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_20um_1cm_400um_W3075_1_2_80V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_20um_1cm_400um_W3075_1_2_80V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_20um_1cm_400um_W3075_1_2_80V --zmin 10.0 --zmax 50.0
# python PlotTimeDiffVsX.py           -D BNL_20um_1cm_400um_W3075_1_2_80V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_20um_1cm_400um_W3075_1_2_80V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_20um_1cm_400um_W3075_1_2_80V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_20um_1cm_400um_W3075_1_2_80V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_20um_1cm_400um_W3075_1_2_80V
# python PlotRecoDiffVsXY.py          -D BNL_20um_1cm_400um_W3075_1_2_80V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_20um_1cm_400um_W3075_1_2_80V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_20um_1cm_400um_W3075_1_2_80V -x 2.5
# python plot1DRes.py                 -D BNL_20um_1cm_400um_W3075_1_2_80V
# python PlotRecoDiffVsY.py           -D BNL_20um_1cm_400um_W3075_1_2_80V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_20um_1cm_400um_W3075_1_2_80V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_20um_1cm_400um_W3075_1_2_80V
# # python Paper_Efficiency.py          -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2
# # python Paper_XRes.py                -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_20um_1cm_400um_W3075_1_2_80V -x 1.2 -y 70 --hot



# ## BNL_20um_1cm_450um_W3074_2_1_95V
# echo "Running over BNL_20um_1cm_450um_W3074_2_1_95V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_20um_1cm_450um_W3074_2_1_95V
# cd ../macros
# python FindDelayCorrections.py -D BNL_20um_1cm_450um_W3074_2_1_95V
# python FindInputHistos4YReco.py -D BNL_20um_1cm_450um_W3074_2_1_95V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_20um_1cm_450um_W3074_2_1_95V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_20um_1cm_450um_W3074_2_1_95V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_20um_1cm_450um_W3074_2_1_95V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_20um_1cm_450um_W3074_2_1_95V --zmin 10.0 --zmax 50.0
# python PlotTimeDiffVsX.py           -D BNL_20um_1cm_450um_W3074_2_1_95V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_20um_1cm_450um_W3074_2_1_95V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_20um_1cm_450um_W3074_2_1_95V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_20um_1cm_450um_W3074_2_1_95V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_20um_1cm_450um_W3074_2_1_95V
# python PlotRecoDiffVsXY.py          -D BNL_20um_1cm_450um_W3074_2_1_95V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_20um_1cm_450um_W3074_2_1_95V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_20um_1cm_450um_W3074_2_1_95V -x 2.5
# python plot1DRes.py                 -D BNL_20um_1cm_450um_W3074_2_1_95V
# python PlotRecoDiffVsY.py           -D BNL_20um_1cm_450um_W3074_2_1_95V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_20um_1cm_450um_W3074_2_1_95V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_20um_1cm_450um_W3074_2_1_95V
# # python Paper_Efficiency.py          -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2
# # python Paper_XRes.py                -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_20um_1cm_450um_W3074_2_1_95V -x 1.2 -y 70 --hot



# ## BNL_20um_1cm_450um_W3075_2_4_80V
# echo "Running over BNL_20um_1cm_450um_W3075_2_4_80V sensor"
# cd ../test
# ./MyAnalysis -A InitialAnalyzer -D BNL_20um_1cm_450um_W3075_2_4_80V
# cd ../macros
# python FindDelayCorrections.py -D BNL_20um_1cm_450um_W3075_2_4_80V
# python FindInputHistos4YReco.py -D BNL_20um_1cm_450um_W3075_2_4_80V -I
# cd ../test
# ./MyAnalysis -A Analyze -D BNL_20um_1cm_450um_W3075_2_4_80V
# cd ../macros

# python DoPositionRecoFit.py         -D BNL_20um_1cm_450um_W3075_2_4_80V -A --xmax 0.79 --fitOrder 5
# python PlotAmplitudeVsX.py          -D BNL_20um_1cm_450um_W3075_2_4_80V --xlength 2.5 --ylength 100.0
# python PlotAmplitudeVsXY.py         -D BNL_20um_1cm_450um_W3075_2_4_80V --zmin 10.0 --zmax 50.0
# python PlotTimeDiffVsX.py           -D BNL_20um_1cm_450um_W3075_2_4_80V --xlength 2.5 --ylength 150.0
# python PlotTimeDiffVsXY.py          -D BNL_20um_1cm_450um_W3075_2_4_80V --zmin 25.0 --zmax 75.0
# python PlotTimeDiffVsY.py           -D BNL_20um_1cm_450um_W3075_2_4_80V --xlength 6.0 --ylength 150.0
# python PlotTimeMeanVsXY.py          -D BNL_20um_1cm_450um_W3075_2_4_80V --zmin -0.5 --zmax 0.5
# python PlotSimpleXYMaps.py          -D BNL_20um_1cm_450um_W3075_2_4_80V
# python PlotRecoDiffVsXY.py          -D BNL_20um_1cm_450um_W3075_2_4_80V --zmin 0.0 --zmax 100.0
# python PlotRecoDiffVsX.py           -D BNL_20um_1cm_450um_W3075_2_4_80V --xlength 2.5 --ylength 150.0
# python PlotEfficiency.py            -D BNL_20um_1cm_450um_W3075_2_4_80V -x 2.5
# python plot1DRes.py                 -D BNL_20um_1cm_450um_W3075_2_4_80V
# python PlotRecoDiffVsY.py           -D BNL_20um_1cm_450um_W3075_2_4_80V --xlength 5.6 --ylength 4.0
# python PlotCutFlow.py               -D BNL_20um_1cm_450um_W3075_2_4_80V

# # Paper plots
# # python Paper_1DRes.py               -D BNL_20um_1cm_450um_W3075_2_4_80V
# # python Paper_Efficiency.py          -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2
# # python Paper_XRes.py                -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2 -y 82
# # python Paper_XRes.py                -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2 --hot
# # python Paper_PlotTimeDiffVsX.py     -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2 -y 82 --hot
# # python Paper_Summary_XRes_Time.py   -D BNL_20um_1cm_450um_W3075_2_4_80V -x 1.2 -y 70 --hot



## BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
echo "Running over BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V sensor"
cd ../test
./MyAnalysis -A InitialAnalyzer -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
cd ../macros
python FindDelayCorrections.py -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
python FindInputHistos4YReco.py -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -I
cd ../test
./MyAnalysis -A Analyze -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
cd ../macros

python DoPositionRecoFit.py         -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -A --xmax 0.72 --fitOrder 5
python PlotAmplitudeVsX.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --xlength 2.7 --ylength 40.0
python PlotAmplitudeVsXY.py         -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --zmin 20.0 --zmax 40.0
python PlotTimeDiffVsX.py           -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --xlength 2.7 --ylength 150.0
python PlotTimeDiffVsXY.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --zmin 25.0 --zmax 75.0
python PlotTimeDiffVsY.py           -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --xlength 13.5 --ylength 150.0
python PlotTimeMeanVsXY.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --zmin -0.5 --zmax 0.5
python PlotSimpleXYMaps.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
python PlotRecoDiffVsXY.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --zmin 0.0 --zmax 100.0
python PlotRecoDiffVsX.py           -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --xlength 2.7 --ylength 150.0
python PlotEfficiency.py            -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 2.7
python plot1DRes.py                 -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
python PlotRecoDiffVsY.py           -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V --xlength 13.5 --ylength 4.0
python PlotCutFlow.py               -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V

# Paper plots
python Paper_1DRes.py               -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V
python Paper_Efficiency.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 2.7
python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 2.7

python Paper_1DRes.py               -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -t
python Paper_Efficiency.py          -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 2.7 -t
python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 2.7 -t

# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 1.2 -y 82
# python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 1.2 --hot
# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 1.2 -y 82 --hot
# python Paper_Summary_XRes_Time.py   -D BNL_50um_2p5cm_mixConfig1_W3051_1_4_170V -x 1.2 -y 70 --hot


## BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
echo "Running over BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V sensor"
cd ../test
./MyAnalysis -A InitialAnalyzer -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
cd ../macros
python FindDelayCorrections.py -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
python FindInputHistos4YReco.py -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -I
cd ../test
./MyAnalysis -A Analyze -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
cd ../macros

python DoPositionRecoFit.py         -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -A --xmax 0.72 --fitOrder 4
python PlotAmplitudeVsX.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --xlength 2.7 --ylength 40.0
python PlotAmplitudeVsXY.py         -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --zmin 20.0 --zmax 40.0
python PlotTimeDiffVsX.py           -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --xlength 2.7 --ylength 150.0
python PlotTimeDiffVsXY.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --zmin 25.0 --zmax 75.0
python PlotTimeDiffVsY.py           -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --xlength 13.5 --ylength 150.0
python PlotTimeMeanVsXY.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --zmin -0.5 --zmax 0.5
python PlotSimpleXYMaps.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
python PlotRecoDiffVsXY.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --zmin 0.0 --zmax 100.0
python PlotRecoDiffVsX.py           -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --xlength 2.7 --ylength 150.0
python PlotEfficiency.py            -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7
python plot1DRes.py                 -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
python PlotRecoDiffVsY.py           -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V --xlength 13.5 --ylength 4.0
python PlotCutFlow.py               -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V

# Paper plots
python Paper_1DRes.py               -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V
python Paper_Efficiency.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7
python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7

python Paper_1DRes.py               -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -t
python Paper_Efficiency.py          -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 -t
python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 -t

# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 -y 82
# python Paper_XRes.py                -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 --hot
# python Paper_PlotTimeDiffVsX.py     -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 -y 82 --hot
# python Paper_Summary_XRes_Time.py   -D BNL_50um_2p5cm_mixConfig2_W3051_1_4_170V -x 2.7 -y 70 --hot
