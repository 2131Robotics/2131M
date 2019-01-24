//------------------Drive voids----------------------//
/*void LeftDriveStop(){
    LeftBMotor.stop();
    LeftFMotor.stop();
}
void RightDriveStop(){
    RightBMotor.stop();
    RightFMotor.stop();
}

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
}*/
void setMechLFPower(int pct){
    if(pct==0)   LeftFMotor.stop(DriveBrakeType);
    else{
        LeftFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setMechLBPower(int pct){
    if(pct==0)   LeftBMotor.stop(DriveBrakeType);
    else{
        LeftBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setMechRFPower(int pct){
    if(pct==0)   RightFMotor.stop(DriveBrakeType);
    else{
        RightFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setMechRBPower(int pct){
    if(pct==0)   RightBMotor.stop(DriveBrakeType);
    else{
        RightBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setMechDrivePower(int LF,int LB,int RF,int RB){
    setMechLFPower(LF);
    setMechLBPower(LB);
    setMechRFPower(RF);
    setMechRBPower(RB);
}

//---------Mech Drive Ramping Task--------//
int Mech_Drive_Ramping(){
    MechDriveRampingEnabled=true;
    while(MechDriveRampingEnabled){
        LFDR.TaskRun();
        RFDR.TaskRun();
        LBDR.TaskRun();
        RBDR.TaskRun();
        setMechDrivePower(LFDR.Pct,LBDR.Pct,RFDR.Pct,RBDR.Pct);
        vex::task::sleep(LFDR.ChangeMsec);
    }
    return 1;
}
//----------------------------------------//

void DriveMechPowerSend(int j1,int j2,int j3=0,int j4=0){//left,right,side1,side2
    int LF=j1;//left
    int RF=j2;//right
    int SD=(j3+j4)/2;//side

    setMechDrivePower(//left go apart && right go into when going right
        LF+SD,
        LF-SD,
        RF-SD,
        RF+SD);
}
void setDrivePower(int left, int right){
    setMechLFPower(left);
    setMechLBPower(left);
    setMechRFPower(right);
    setMechRBPower(right);
}
////////////////////////////////////////////
void setIntakePower(int power){
    IntakeMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
}
void setIntakeautofeedPower(int power){
    if(power==0)  IntakeMotor.stop(vex::brakeType::brake);
    else{
        IntakeMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}

void setCatapultPower(int power){
    if(power==0)  CatapultMotor.stop(vex::brakeType::coast);
    else{
        CatapultMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}

void setRamPower(int power){
    /*if(power==0)  RamMotor.stop(vex::brakeType::brake);
    else{
        RamMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }*/
}

void RamRodPos(int pos, int power=100){
    //RamMotor.startRotateTo(pos,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
}

void setLiftPower(int power){
    if(power==0)  LiftMotor.stop(vex::brakeType::brake);
    else{
        LiftMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
void liftRotateTo(int pos, int power=100){
    LiftMotor.startRotateTo(pos,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
    LiftMotor.setStopping(vex::brakeType::brake);
}
void liftRotateFor(int pos, int power=100){
    LiftMotor.startRotateFor(pos,vex::rotationUnits::deg,power,vex::velocityUnits::pct);
    LiftMotor.setStopping(vex::brakeType::brake);
}
void setWristPower(int power){
    if(power==0)  WristMotor.stop(vex::brakeType::brake);
    else{
        WristMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    }
}
//-----------------------------//
void DI(int Lpower,int Rpower){
    LDR.RequestedPct=Lpower;
    RDR.RequestedPct=Rpower;
    LDR.Pct=Lpower;
    RDR.Pct=Rpower;
    setDrivePower(LDR.Pct,RDR.Pct);
}