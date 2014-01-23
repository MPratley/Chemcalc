echo Building main
g++ chemcalc.cpp -o chemcalc

echo Building GUI
g++ CCUI.cpp -o CCUI

echo Describing permissions
sudo chmod -x 777 chemcalc
sudo chmod -x 777 CCUI
