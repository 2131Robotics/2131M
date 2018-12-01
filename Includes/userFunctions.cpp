void ManualDriveCont(bool Flipped){
    if(Flipped){
        setDrivePower(Controller1.Axis3.value(), Controller1.Axis2.value());
    }
    if(!Flipped){
        setDrivePower(-Controller1.Axis2.value(), -Controller1.Axis3.value());
    }
}
void driveLock(){
    LeftBMotor.stop(vex::brakeType::hold);
    RightBMotor.stop(vex::brakeType::hold);
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
    else if(!DriveLockInverted && modeVar == 0) {
        LeftBMotor.setStopping(vex::brakeType::coast);
        RightBMotor.setStopping(vex::brakeType::coast);
        ManualDriveCont(true);
    }
    else if(!DriveLockInverted && modeVar == 1) {
        LeftBMotor.setStopping(vex::brakeType::coast);
        RightBMotor.setStopping(vex::brakeType::coast);
        ManualDriveCont(false);
    }
}

void FlipperControll(){
    if(Controller1.ButtonR1.pressing() && FlipperMotorConBtnPressed==false){
        FlipperMotorConBtnPressed=true;
        FlipperMotor.startRotateFor(FlipperMotorInverted ? -350 : 350,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        FlipperMotorInverted=!FlipperMotorInverted;
    }
    if(!Controller1.ButtonR1.pressing() && FlipperMotorConBtnPressed==true){
        FlipperMotorConBtnPressed=false;
    }
}
void FliperStop(){
    FlipperMotor.stop();
}

void ManFliperControl(){
    if(Controller1.ButtonR2.pressing()) {
        FlipperMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }   
    else if(Controller1.ButtonR1.pressing()) {
        FlipperMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }   
    else FlipperMotor.stop(vex::brakeType::coast);
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

void indexControll(){
    if(Controller1.ButtonL1.pressing()) {
        setIndexPower(-100);
    }   
    else if(Controller1.ButtonL2.pressing()) {
        setIndexPower(100);
    }   
    else IndexMotor.stop(vex::brakeType::coast);
}

void FlyWheelControll(){
    if(Controller1.ButtonUp.pressing()) {
        setFlyPower(600);
    }   
    if(Controller1.ButtonLeft.pressing()) {
        setFlyPower(300);
    }
    if(Controller1.ButtonRight.pressing()) {
        setFlyPower(100);
    }
    if(Controller1.ButtonDown.pressing()) {
        FlyMotor.setStopping(vex::brakeType::coast);
        FlyMotor.stop();
    } 
}

void AutoIntakeIndexCont(){
    if(Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==false){
        IntakeEnabledBtnPressed=true;
        IntakeEnabledInverted=!IntakeEnabledInverted;
    }
    if(!Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==true){
        IntakeEnabledBtnPressed=false;
    }
    if(IntakeEnabledInverted){ AutoIntakeEnabled = true;}
    if(!IntakeEnabledInverted) {
        AutoIntakeEnabled = false;
        intakeControll();
        indexControll();
        FlyWheelControll();

    }
}

void toggleUserModesUpdate(){
    if (!Controller1.ButtonX.pressing())																	//																											//
            usertoggle=1;																				//																											//
        if (Controller1.ButtonX.pressing() && modeVar==1 && usertoggle==1){
            modeVar=0;																				//		- To switch between
            usertoggle=0;																				//			our two different
        }																											//			modes
        if (Controller1.ButtonX.pressing() && modeVar==0 && usertoggle==1){	//
            modeVar=1;																				//
            usertoggle=0;																				//
        }
}