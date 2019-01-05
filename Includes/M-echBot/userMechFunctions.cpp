//------Manual Drive Mech Controll------------//
void IsFippedControll(){
    if(Controller1.ButtonX.pressing() && DriveDirConBtnPressed==false){
        DriveDirConBtnPressed=true;
        DriveDirInverted=!DriveDirInverted;
    }
    if(!Controller1.ButtonX.pressing() && DriveDirConBtnPressed==true){
        DriveDirConBtnPressed=false;
    }
}
void ManualMechDriveCont(){
    IsFippedControll();
    int LeftVirtJoy=Controller1.Axis3.value();
    int RightVirtJoy=Controller1.Axis2.value();
    int LeftHorJoy=Controller1.Axis4.value();
    int RightHorJoy=Controller1.Axis1.value();

    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
    
    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
        if(!DriveDirInverted){
        DriveMechPowerSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
        }
        if(DriveDirInverted){
        DriveMechPowerSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
        }
    }
    else{
        setMechDrivePower(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
    }        
}

/*void driveLock(){-
    stopDriveHold();
}*/
void DriveCont_LockContM(){
    if(Controller1.ButtonB.pressing() && DriveLockConBtnPressed==false){
        DriveLockConBtnPressed=true;
        DriveLockInverted=!DriveLockInverted;
    }
    if(!Controller1.ButtonB.pressing() && DriveLockConBtnPressed==true){
        DriveLockConBtnPressed=false;
    }
    
    if(DriveLockInverted || Controller1.ButtonL1.pressing()) driveLock();
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

void RamRodContMan(){
    IsFippedControll();
    
    if(DriveDirInverted){

        IntakeMotor.stop(vex::brakeType::coast);

        if(Controller1.ButtonR1.pressing()) {
            setRamPower(100);
            RamManualEnabled = true;
            RamPosEnabled = false;
        }
        else if(Controller1.ButtonR2.pressing()) {
            setRamPower(-100);
            RamManualEnabled = true;
            RamPosEnabled = false;
        }
        else {
            setRamPower(0);
            RamManualEnabled = false;
        }

        if(Controller1.ButtonL2.pressing()){
            RamPosEnabled = true;
        }
    }
    if(!DriveDirInverted){
        
    }
}

void RamPosControll(){
        if(Controller1.ButtonL2.pressing() && RamEnabledBtnPressed==false){
        RamEnabledBtnPressed=true;
        RamEnabledInverted=!RamEnabledInverted;
        }
        if(!Controller1.ButtonL2.pressing() && RamEnabledBtnPressed==true){
        RamEnabledBtnPressed=false;
        }

        if(RamEnabledInverted){
            RamRodPos(250);
        }
        if(!RamEnabledInverted){
            RamRodPos(90);
        }
}

void smartRamRodCont(){
    RamRodContMan();
    if(RamPosEnabled){
        RamPosControll();
    }
}

void AutoIntakeCont(){
    if(Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==false){
        IntakeEnabledBtnPressed=true;
        IntakeEnabledInverted=!IntakeEnabledInverted;
    }
    if(!Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==true){
        IntakeEnabledBtnPressed=false;
    }
    if(IntakeEnabledInverted){ 
        AutoIntakeEnabled=false;
        intakeControll();
    }
    if(!IntakeEnabledInverted) {
        vex::task AutoIn(Auto_Intaking);
    }
}