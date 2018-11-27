void AtonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
	//calculate distince using inch
    double WheelCir=4*3.14159265;
    double Direction=sgn(Distance);
    double Rev= std::abs(Distance)/WheelCir;
     int LPowerSend=0;
     int RPowerSend=0;
	//clear enc
    LeftMotor.resetRotation();
    RightMotor.resetRotation();
	//is it there yet?
    while(std::abs(RightMotor.rotation(vex::rotationUnits::rev))<std::abs(Rev)){
        double LMotorEncValue=LeftMotor.rotation(vex::rotationUnits::deg);
        double RMotorEncValue=RightMotor.rotation(vex::rotationUnits::deg);
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
        SetDRpower(LPowerSend,RPowerSend);
        vex::task::sleep(1);
    }
    SetDRpower(0,0);
    while(RightMotor.isSpinning() || LeftMotor.isSpinning()){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
}

void TimeAutoDrive(int time, int power){
    LeftMotor.resetRotation();
    RightMotor.resetRotation();

    RightMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    LeftMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    vex::task::sleep(time);
    RightMotor.stop(vex::brakeType::coast);
    LeftMotor.stop(vex::brakeType::coast);
}

void AtonTurn(double deg,int LPowerSend=50,int RPowerSend=50,int EndWait=250){ //-left,+right
    int Dir=sgn(deg);
    deg=abs(deg)/12.56;
    LPowerSend=LPowerSend*Dir;
    RPowerSend=RPowerSend*Dir;
    GyroCalibration();
    while(abs(Gyro.value(vex::rotationUnits::deg))<deg){
        DI(LPowerSend,-RPowerSend);
        vex::task::sleep(1);
    }
    DI(0,0);
    RightMotor.stop(vex::brakeType::brake);
    LeftMotor.stop(vex::brakeType::brake);
    while(RightMotor.isSpinning() || LeftMotor.isSpinning()){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
    DI(0,0);
}

void IntakeAtonSet(bool ON, bool direction){
    if(ON){
        if(direction) setIntakePower(100);
        if(!direction) setIntakePower(-100);
    }
    if(!ON){IntakeMotor.stop();}
}