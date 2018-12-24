//------Manual Drive Mech Controll------------//
void ManualMechDriveCont(){
    LeftVirtJoy=Controller1.Axis3.value();
    RightVirtJoy=Controller1.Axis2.value();
    LeftHorJoy=Controller1.Axis4.value();
    RightHorJoy=Controller1.Axis1.value();

    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
    
    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
        DriveManualControlEnabled=true;
        DriveMechPowerSend(RightVirtJoy,LeftVirtJoy,RightHorJoy,LeftHorJoy);
    }
    else{
        setMechDrivePower(0,0);//Last loop before disableing; used to release drivemanualcontrol
    }        
}

void driveLock(){
    stopDriveHold();
}
void DriveCont_LockCont(){
    if(Controller1.ButtonB.pressing() && DriveLockConBtnPressed==false){
        DriveLockConBtnPressed=true;
        DriveLockInverted=!DriveLockInverted;
    }
    if(!Controller1.ButtonB.pressing() && DriveLockConBtnPressed==true){
        DriveLockConBtnPressed=false;
    }
    
    if(DriveLockInverted) driveLock();
    else if(!DriveLockInverted) {
        setDriveBrakeCoast();
        ManualMechDriveCont();
    }
}