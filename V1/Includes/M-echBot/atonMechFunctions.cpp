void AtonSlide(double Distance,int Pct=100,int EndWait=500,int Correction=2){
    DriveRampingEnabled=false; //stop other ramping task to avoid conflicting
    vex::task AtonMechDrive(Mech_Drive_Ramping);

    //calculate direction and set L & R PowerSend
    double Direction=sgn(Distance);

    int LPowerSend=0;
    int RPowerSend=0;
	//clear enc
    LeftBMotor.resetRotation();
    RightFMotor.resetRotation();
    LeftFMotor.resetRotation();
    RightBMotor.resetRotation();
	//is it there yet?
    while(std::abs(RightBMotor.rotation(vex::rotationUnits::rev))<std::abs(Distance)){
        double LMotorEncValue=LeftFMotor.rotation(vex::rotationUnits::deg);
        double RMotorEncValue=RightBMotor.rotation(vex::rotationUnits::deg);
		//straiten
        if(std::abs(LMotorEncValue)>std::abs(RMotorEncValue)){
            LPowerSend=Pct-Correction;
            RPowerSend=Pct;
        }
        else if(std::abs(LMotorEncValue)<std::abs(RMotorEncValue)){
            LPowerSend=Pct;
            RPowerSend=Pct-Correction;
        }
        else if(std::abs(LMotorEncValue)==std::abs(RMotorEncValue)){
            LPowerSend=Pct;
            RPowerSend=Pct;
        }
		//correct direction
        LPowerSend=LPowerSend*Direction;
        RPowerSend=RPowerSend*Direction;
		//send to SetDRpower
        SetDRMpower(LPowerSend,RPowerSend);

        vex::task::sleep(1);
    }

    SetDRMpower(0,0);
    vex::task::sleep(EndWait);
    
    MechDriveRampingEnabled = false;
    vex::task AtonDrive(Drive_Ramping);
}

/*void autoRamFlip(int time=800){
    RamRodPos(250);
    wait(time);
    RamRodPos(100);
}*/
void SlideRecon(int time, int power, int dir){
    DriveRampingEnabled=false;
    setMechLFPower(power*dir);
    setMechLBPower(-power*dir);
    setMechRFPower(-power*dir);
    setMechRBPower(power*dir);

    wait(time);

    setMechLFPower(0);
    setMechLBPower(0);
    setMechRFPower(0);
    setMechRBPower(0);

    vex::task AtonDrive(Drive_Ramping);
}

void toggleWrist(){
    int CCW = -385;
    int CW = -30;
    WristMotor.startRotateTo(WristMotorInverted ? CW : CCW,vex::rotationUnits::deg,100,vex::velocityUnits::pct);    WristMotorInverted=!WristMotorInverted;
    WristMotorInverted=!WristMotorInverted;

}