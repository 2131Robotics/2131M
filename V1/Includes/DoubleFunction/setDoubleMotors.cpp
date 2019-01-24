/*---------------------------------------------*/

void setLiftPower(int pPower){
    LiftMotorR.spin(vex::directionType::fwd, pPower, vex::velocityUnits::pct);
}
void liftRotoateTo(int deg){
    LiftMotorR.rotateTo(deg,vex::rotationUnits::deg,PIDliftUserCpower,vex::velocityUnits::pct);
}

//------------------Drive voids----------------------//
void LeftDriveStop(){
    LeftBMotor.stop();
    LeftFMotor.stop();
}
void RightDriveStop(){
    RightBMotor.stop();
    RightFMotor.stop();
}
void setLeftDrivePower(int pct){
    if(pct==0)   LeftDriveStop();
    else{
        LeftBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        LeftFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setRightDrivePower(int pct){
    if(pct==0)  RightDriveStop();
    else{
        RightBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        RightFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setDrivePower(int left, int right){
    setLeftDrivePower(left);
    setRightDrivePower(right);
}

//----------------------------------------------//
void setJawPower(int power){
   JawMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
}
void setWristPower(int power){
   WristMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
}
void setPuncherPower(int power){
    PuncherMotor.spin(vex::directionType::rev, power, vex::velocityUnits::pct);
}
void setIntakePower(int power){
    IntakeMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
}