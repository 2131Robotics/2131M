#include "main.h"
#include "N_Custom/declars/Ramping.hpp"

Ramping::Ramping(int CP,int CM,int MaxP,int MinDP,int MinUP){
        //ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

void Ramping::TaskRun(){
  if(RequestedPct>Pct){ //ramp up
      Pct=Pct+ChangePct;
  }
  else if(RequestedPct<Pct){ //ramp down
      Pct=Pct-ChangePct;
  }
  //limit Pct
  if(Pct>MaxPct)	Pct=MaxPct;
  if(Pct<-MaxPct)	Pct=-MaxPct;
  if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
  if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
}

namespace Drive{
  void SetDRMvel(int LFpower,int LBpower,int RFpower,int RBpower){ //DMR
    LFDR.RequestedPct = LFpower;
    RFDR.RequestedPct = RFpower;
    LBDR.RequestedPct = LBpower;
    RBDR.RequestedPct = RBpower;
  }
  void DI(int Lpower,int Rpower){
    LFDR.RequestedPct=Lpower;
    RFDR.RequestedPct=Rpower;
    LBDR.RequestedPct=Lpower;
    RBDR.RequestedPct=Rpower;
    LFDR.Pct=Lpower;
    RFDR.Pct=Rpower;
    LBDR.Pct=Lpower;
    RBDR.Pct=Rpower;
    Drive::setDriveVel(LBDR.Pct,RBDR.Pct);
  }
  void Drive_Ramping(void*DriveRampingTask){
    MechDriveRampingEnabled=true;
    while(MechDriveRampingEnabled){
        LFDR.TaskRun();
        RFDR.TaskRun();
        LBDR.TaskRun();
        RBDR.TaskRun();
        Drive::setMechDriveVel(LFDR.Pct,LBDR.Pct,RFDR.Pct,RBDR.Pct);
        pros::delay(LFDR.ChangeMsec);
    }
  }
}
