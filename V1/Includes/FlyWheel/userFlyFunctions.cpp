void setDriveBrakeCoast(){
    LeftFMotor.setStopping(vex::brakeType::coast);
    RightFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
}
void setDriveBrakeBrake(){
    LeftFMotor.setStopping(vex::brakeType::brake);
    RightFMotor.setStopping(vex::brakeType::brake);
    LeftBMotor.setStopping(vex::brakeType::brake);
    RightBMotor.setStopping(vex::brakeType::brake);
}
void setDriveBrakeHold(){
    LeftFMotor.setStopping(vex::brakeType::hold);
    RightFMotor.setStopping(vex::brakeType::hold);
    LeftBMotor.setStopping(vex::brakeType::hold);
    RightBMotor.setStopping(vex::brakeType::hold);
}
void stopDriveCoast(){
    LeftBMotor.stop(vex::brakeType::coast);
    RightBMotor.stop(vex::brakeType::coast);
    LeftFMotor.stop(vex::brakeType::coast);
    RightFMotor.stop(vex::brakeType::coast);
}
void stopDriveBrake(){
    LeftBMotor.stop(vex::brakeType::brake);
    RightBMotor.stop(vex::brakeType::brake);
    LeftFMotor.stop(vex::brakeType::brake);
    RightFMotor.stop(vex::brakeType::brake);
}
void stopDriveHold(){
    LeftBMotor.stop(vex::brakeType::hold);
    RightBMotor.stop(vex::brakeType::hold);
    LeftFMotor.stop(vex::brakeType::hold);
    RightFMotor.stop(vex::brakeType::hold);
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
void indexControll(){
    if(Controller1.ButtonL1.pressing()) {
        setIndexPower(-100);
    }   
    else if(Controller1.ButtonL2.pressing()) {
        setIndexPower(100);
    }   
    else IndexMotor.stop(vex::brakeType::coast);
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