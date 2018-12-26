//------Manual Drive Mech Controll------------//
void ManualMechDriveCont(){
    int LeftVirtJoy=Controller1.Axis3.value();
    int RightVirtJoy=Controller1.Axis2.value();
    int LeftHorJoy=Controller1.Axis4.value();
    int RightHorJoy=Controller1.Axis1.value();

    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
    
    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
        DriveMechPowerSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
    }
    else{
        setMechDrivePower(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
    }        
}

/*void driveLock(){
    stopDriveHold();
}*/
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

void intakeControll(){
    if(Controller1.ButtonR1.pressing()) {
        setIntakePower(100);
    }   
    else if(Controller1.ButtonR2.pressing()) {
        setIntakePower(-100);
    }   
    else IntakeMotor.stop(vex::brakeType::coast);
}

void catapultControll(){
    if(Controller1.ButtonL1.pressing()) {
        setCatapultPower(100);
    }  
    else CatapultMotor.stop(vex::brakeType::coast);
}