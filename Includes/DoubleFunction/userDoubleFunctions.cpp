void setDriveBrakeCoast(){
    LeftBMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    LeftFMotor.setStopping(vex::brakeType::coast);
    RightFMotor.setStopping(vex::brakeType::coast);
}
void setDriveBrakeBrake(){
    LeftBMotor.setStopping(vex::brakeType::brake);
    RightBMotor.setStopping(vex::brakeType::brake);
    LeftFMotor.setStopping(vex::brakeType::brake);
    RightFMotor.setStopping(vex::brakeType::brake);
}
void setDriveBrakeHold(){
    LeftBMotor.setStopping(vex::brakeType::hold);
    RightBMotor.setStopping(vex::brakeType::hold);
    LeftFMotor.setStopping(vex::brakeType::hold);
    RightFMotor.setStopping(vex::brakeType::hold);
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


//---------------------------------------------//

void liftControll(int pct=100){
    //Lift Control
    if(Controller1.ButtonL1.pressing()) {
        setLiftPower(pct);
    }   
    else if(Controller1.ButtonL2.pressing()) {
        setLiftPower(-pct);
    }   
    else{ 
        LiftMotorR.stop(vex::brakeType::hold);
    }
}
void liftContVPID(){
    //----------------------Lift Controll------------------------//
    if(liftMode > 5)
        liftMode = 5;
    if(liftMode < 1)
        liftMode = 1;

    if(Controller1.ButtonL1.pressing() == false && Controller1.ButtonL2.pressing() == false)
        liftButtonWait=true;
    if(Controller1.ButtonL1.pressing() && liftButtonWait == true && liftMode <= 5){
        liftButtonWait=false;
        liftMode++;
    }

    if(Controller1.ButtonL2.pressing() && liftButtonWait == true && liftMode >= 1){
        liftButtonWait=false;
        liftMode--;
    }

    if(liftMode == 1)
        liftRotoateTo(0);
    if(liftMode == 2)
        liftRotoateTo(145);
    if(liftMode == 3)
        liftRotoateTo(400);
    if(liftMode == 4)
        liftRotoateTo(530);
    if(liftMode == 5)
        liftRotoateTo(680);
}
void wirstControll(){
    if(Controller1.ButtonR2.pressing() && WristMotorConBtnPressed==false){
        WristMotorConBtnPressed=true;
        WristMotor.startRotateFor(WristMotorInverted ? 350 : -350,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        WristMotorInverted=!WristMotorInverted;
    }
    if(!Controller1.ButtonR2.pressing() && WristMotorConBtnPressed==true){
        WristMotorConBtnPressed=false;
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
        puncherControll();
    }
}

void jawControll(){
    if(Controller1.ButtonR1.pressing() && JawMotorConBtnPressed==false){
        JawMotorConBtnPressed=true;
        JawMotor.startRotateTo(JawMotorInverted ? 0 : 50,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        JawMotorInverted=!JawMotorInverted;
    }
    if(!Controller1.ButtonR1.pressing() && JawMotorConBtnPressed==true){
        JawMotorConBtnPressed=false;
    }
}

void jawBandCont(){
    if(Controller1.ButtonR1.pressing()){
        setJawPower(100);
    }
    else {
        setJawPower(0);
    }
}