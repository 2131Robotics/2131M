//------------------------------------------------------//
void AutoLift(int degg, int pct, bool wait){
    if(wait){
        LiftMotorR.rotateTo(degg,vex::rotationUnits::deg,pct,vex::velocityUnits::pct);
    }
    if(!wait){
        LiftMotorR.startRotateTo(degg,vex::rotationUnits::deg,pct,vex::velocityUnits::pct);
    }
}

void toggleWrist(){
    WristMotor.startRotateFor(WristMotorInverted ? 350 : -350,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    WristMotorInverted=!WristMotorInverted;
}
void WristLock(){
    setWristPower(-50);
    WristMotor.startRotateTo(0,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
}
/*void IntakeAtonSet(bool ON, bool direction){
    if(ON){
        if(direction) setIntakePower(100);
        if(!direction) setIntakePower(-100);
    }
    if(!ON){IntakeMotor.stop();}
}*/
void toggleJaw(){
    JawMotor.startRotateFor(JawMotorInverted ? 0 : 50,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    JawMotorInverted=!JawMotorInverted;
}