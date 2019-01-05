void AtonSlide(double Distance,int Pct=100,int EndWait=250,int Correction=2){
    //calculate distince using inch
    double WheelCir=4*3.14159265358979323846264338327950288419716939937510582097494459237816406286208998628034253421170679;
    double Direction=sgn(Distance);
    double Rev= std::abs(Distance)/WheelCir;
     int LPowerSend=0;
     int RPowerSend=0;
	//clear enc
    LeftBMotor.resetRotation();
    RightFMotor.resetRotation();
	//is it there yet?
    while(std::abs(RightBMotor.rotation(vex::rotationUnits::rev))<std::abs(Rev)){
        double LMotorEncValue=LeftFMotor.rotation(vex::rotationUnits::deg);
        double RMotorEncValue=RightFMotor.rotation(vex::rotationUnits::deg);
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
        setMechLFPower(LPowerSend);
        setMechLBPower(-LPowerSend);
        setMechRFPower(-RPowerSend);
        setMechRBPower(RPowerSend);

        vex::task::sleep(1);
    }

    setMechLFPower(0);
    setMechLBPower(0);
    setMechRFPower(0);
    setMechRBPower(0);
    vex::task::sleep(EndWait);
}

void autoRamFlip(int time=800){
    RamRodPos(250);
    wait(time);
    RamRodPos(100);
}
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