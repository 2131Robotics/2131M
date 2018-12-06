void AtonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
	//calculate distince using inch
    double WheelCir=4*3.14159265358979323846264338327950288419716939937510582097494459237816406286208998628034253421170679;
    double Direction=sgn(Distance);
    double Rev= std::abs(Distance)/WheelCir;
     int LPowerSend=0;
     int RPowerSend=0;
	//clear enc
    LeftBMotor.resetRotation();
    RightBMotor.resetRotation();
	//is it there yet?
    while(std::abs(RightBMotor.rotation(vex::rotationUnits::rev))<std::abs(Rev)){
        double LMotorEncValue=LeftBMotor.rotation(vex::rotationUnits::deg);
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
        SetDRpower(LPowerSend,RPowerSend);
        vex::task::sleep(1);
    }
    SetDRpower(0,0);
    while(LDR.Pct!=0 || RDR.Pct!=0){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
}

void TimeAutoDrive(int time, int power){
    LeftBMotor.resetRotation();
    RightBMotor.resetRotation();

    RightBMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    LeftBMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
    vex::task::sleep(time);
    RightBMotor.stop(vex::brakeType::coast);
    LeftBMotor.stop(vex::brakeType::coast);
}
//my old double function turning
/*void TurnRamp(double deg,int LPowerSend=50,int RPowerSend=50,int EndWait=250){ //-left,+right
    int Dir=sgn(deg);
    deg=abs(deg)/12.56;
    LPowerSend=LPowerSend*Dir;
    RPowerSend=RPowerSend*Dir;
    RightBMotor.resetRotation();
    while(abs(RightBMotor.rotation(vex::rotationUnits::rev))<deg){
        DI(LPowerSend,-RPowerSend);
        vex::task::sleep(1);
    }
    DI(0,0);
    while(RightBMotor.isSpinning() || LeftBMotor.isSpinning()){
        vex::task::sleep(1);
    }
    vex::task::sleep(EndWait);
}*/
/*void Turn(double Deg,bool Rel=true,int EndWait=250,int LPct=25,int RPct=25){//-left,+right
//    GyroCalibration(true);
    if(Rel) Deg+=Gyro.value(vex::rotationUnits::deg);
    if(std::abs(Deg)>360){
        while(std::abs(Deg)>360){
            Deg-=SGN(Deg)*360;//take care of the jump between -360,0,360
        }
        Dir=SGN(Deg);
        LPct=LPct*Dir;
        RPct=RPct*Dir;
        while(std::abs(Gyro.value(vex::rotationUnits::deg))<360){
            DI(LPct,-RPct);
            EndTimeSlice(1);
        }
    }
    
    int Dir=sgn(Deg);
    LPct=std::abs(LPct)*Dir;
    RPct=std::abs(RPct)*Dir;
    while(std::abs(Gyro.value(vex::rotationUnits::deg))<std::abs(Deg)){
        DI(LPct,-RPct);
        vex::task::sleep(1);
    }
    DI(0,0);
    //Controller1.Screen.clearLine();
    //Controller1.Screen.print("Turned");
    vex::task::sleep(EndWait);

}*/
void AtonGryoTurn(double deg, bool Relitive=true, int correction=10,int LPowerSend=25,int RPowerSend=25,int EndWait=250){ //-left,+right
    //make it a relitive turn, or turn this more...
    if(Relitive) (deg)+=(Gyro.value(vex::rotationUnits::deg));

    int Dir=sgn(deg);
    LPowerSend=std::abs(LPowerSend)*Dir;
    RPowerSend=std::abs(RPowerSend)*Dir;
    while(std::abs(Gyro.value(vex::rotationUnits::deg))<std::abs(deg)){
            DI(-LPowerSend,RPowerSend);
            vex::task::sleep(1);
    }
    while(std::abs(Gyro.value(vex::rotationUnits::deg))>std::abs(deg)){
            DI(LPowerSend,-RPowerSend);
            vex::task::sleep(1);
    }
    /*if(Dir == 1){
        while(abs(Gyro.value(vex::rotationUnits::deg))<deg){
            DI(LPowerSend,-RPowerSend);
            vex::task::sleep(1);
        }
    }
    if(Dir == -1){
        while(abs(Gyro.value(vex::rotationUnits::deg))<deg){
            DI(-LPowerSend,RPowerSend);
            vex::task::sleep(1);
        }
    }*/
    DI(0,0);
    RightBMotor.stop(vex::brakeType::brake);
    LeftBMotor.stop(vex::brakeType::brake);
    /*while(RightBMotor.isSpinning() || LeftBMotor.isSpinning()){
        vex::task::sleep(1);
    }*/
    vex::task::sleep(EndWait);
    DI(0,0);
    RightBMotor.stop(vex::brakeType::coast);
    LeftBMotor.stop(vex::brakeType::coast);
}
void AtonTurn(double deg,int LPowerSend=25,int RPowerSend=25,int EndWait=500){ //-left,+right
    int Dir=sgn(deg);
    deg=abs(deg)/12.56;
    LPowerSend=LPowerSend*Dir;
    RPowerSend=RPowerSend*Dir;
    RightBMotor.resetRotation();
    LeftBMotor.resetRotation();
    while(abs(RightBMotor.rotation(vex::rotationUnits::rev))<abs(deg)){
        DI(LPowerSend,-RPowerSend);
        vex::task::sleep(1);
    }
    DI(0,0);
    RightBMotor.stop(vex::brakeType::brake);
    LeftBMotor.stop(vex::brakeType::brake);
    vex::task::sleep(EndWait);
    //DI(0,0);
    RightBMotor.stop(vex::brakeType::coast);
    LeftBMotor.stop(vex::brakeType::coast);
}
void IntakeAtonSet(bool ON, bool direction){
    if(ON){
        if(direction) setIntakePower(100);
        if(!direction) setIntakePower(-100);
    }
    if(!ON){IntakeMotor.stop();}
}
void wait(int time){
    vex::task::sleep(time);
}