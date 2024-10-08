#include<iostream>
#include "lib.h"
#include "macro.h"
#include "powerMgr.h"
#include "antennaMgr.h"
#include "wifiMgr.h"
#include "systemPowerInterface.h"
using namespace std;
int main()
{
    #ifdef KIENMACRO
    changeWifiSource();
    cout<<KIENMACRO<<endl;
    #endif
    changePowerSource();
    cout<<"SYSTEM_POWER_MODE_MAIN "<<SYSTEM_POWER_MODE_MAIN<<endl;
    changeAntennaSource();
    #ifdef ECALL_ENABLE
    cout<<"hello world. good morning"<<COUNT<<endl;
    #else
    show();
    cout<<"ECALL_STATUS "<<ECALL_STATUS<<"  ECALL_RUNNING_VARIANT "<<ECALL_RUNNING_VARIANT<<endl;
    #endif
    return 0;
}