void setLeftDrivePower(int pct){
    if(pct==0)   LeftDriveStop();
    else{
        FLDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        BLDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setRightDrivePower(int pct){
    if(pct==0)  RightDriveStop();
    else{
        FRDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        BRDriveMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setDrivePower(int left, int right){
    setLeftDrivePower(left);
    setRightDrivePower(right);
}
Ramping LDR(1,3);
Ramping RDR(1,3);
int Drive_Ramping(){
    DriveRampingEnabled=true;
    while(DriveRampingEnabled){
        LDR.TaskRun();
        RDR.TaskRun();
        setDrivePower(LDR.Pct,RDR.Pct);
        vex::task::sleep(LDR.ChangeMsec);
    }
    return 1;
}
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

void TurnRamp(double Distance,int LPowerSend=50,int RPowerSend=50,int EndWait=TurnEndWait){//-left,+right
    int Distance=SGN(Distance);
    Distance=ABS(Distance)/12.56;
    LPowerSend=LPowerSend*Distance;
    RPowerSend=RPowerSend*Distance;
    FLDriveMotor.resetRotation();
    while(ABS(FLDriveMotor.rotation(vex::rotationUnits::rev))<Distance){
        DI(LPowerSend,-RPowerSend);
        vex::task::sleep(1);
    }
    DI(0,0);
    while(BLDriveMotor.isSpinning() || BRDriveMotor.isSpinning()){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
}
void AtonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
	//calculate distince using inch
    double WheelCir=4*3.14159265;
    double Direction=SGN(Distance);
    double Rev=ABS(Dis)/WheelCir;
    int LPowerSend=0;
    int RPowerSend=0;
	//clear enc
    FLDriveMotor.resetRotation();
    FRDriveMotor.resetRotation();
	//is it there yet?
    while(ABS(FLDriveMotor.rotation(vex::rotationUnits::rev))<ABS(Rev)){
        double LMotorEncValue=FLDriveMotor.rotation(vex::rotationUnits::deg);
        double RMotorEncValue=FRDriveMotor.rotation(vex::rotationUnits::deg);
		//straiten
        if(ABS(LMotorEncValue)>ABS(RMotorEncValue)){
            LPowerSend=Pct-Correction;
            RPowerSend=Pct;
        }
        else if(ABS(LMotorEncValue)<ABS(RMotorEncValue)){
            LPowerSend=Pct;
            RPowerSend=Pct-Correction;
        }
        else if(ABS(LMotorEncValue)==ABS(RMotorEncValue)){
            LPowerSend=Pct;
            RPowerSend=Pct;
        }
		//correct direction
        LPowerSend=LPowerSend*Direction;
        RPowerSend=RPowerSend*Direction;
		//send to SetDRpower
        SetDRpower(LPowerSend,RPowerSend);
        vex::task::sleep(1);
    }
    SetDRpower(0,0);
    while(BLDriveMotor.isSpinning() || BRDriveMotor.isSpinning()){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
}