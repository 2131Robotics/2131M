//------------------Drive voids----------------------//
void LeftDriveStop(){
    LeftBMotor.stop();
}
void RightDriveStop(){
    RightBMotor.stop();
}
void setLeftDrivePower(int pct){
    if(pct==0)   LeftDriveStop();
    else{
        LeftBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setRightDrivePower(int pct){
    if(pct==0)  RightDriveStop();
    else{
        RightBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setDrivePower(int left, int right){
    setLeftDrivePower(left);
    setRightDrivePower(right);
}

//--------------------------------------------//
void setFlyPower(int rpm){
   FlyMotor.spin(vex::directionType::fwd,rpm,vex::velocityUnits::rpm);
}
void setIndexPower(int power){
    IndexMotor.spin(vex::directionType::rev, power, vex::velocityUnits::pct);
}
void setIntakePower(int power){
    IntakeMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
}
void setIntakeautofeedPower(int power){
    if(power==0)  IntakeMotor.stop(vex::brakeType::brake);
    else{
        IntakeMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}

//-----------------Dive Aton COntroll-----------------//
void SetDRpower(int Lpower,int Rpower){ //DR
    LDR.RequestedPct=Lpower;
    RDR.RequestedPct=Rpower;
}
void DI(int Lpower,int Rpower){
    LDR.RequestedPct=Lpower;
    RDR.RequestedPct=Rpower;
    LDR.Pct=Lpower;
    RDR.Pct=Rpower;
    setDrivePower(LDR.Pct,RDR.Pct);
}