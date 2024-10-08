#include<iostream>
#include"systemPowerInterface.h"
using namespace std;
void changePowerSource(){
    #ifdef POWER_FLAG
    cout<<"powerMgr changed power source from main to bub successfully "<<SYSTEM_POWER_MODE_MAIN<<endl;
    #else
    cout<<"powerMgr changed power source from bub to main successfully "<<SYSTEM_POWER_MODE_MAIN<<endl;
    #endif
}