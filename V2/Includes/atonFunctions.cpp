//------Other Functions------------//
    void wait(int time){
        vex::task::sleep(time);
    }
    void toggleWrist(){
        int spinFor=800;
        setWristPower(WristMotorInverted ? 100 : -100);
        vex::task::sleep(spinFor);
        setWristPower(0);
        WristMotorInverted=!WristMotorInverted;
    }
    void FLIP(){
        setLiftPower(100);
        wait(450);
        setWristPower(WristMotorInverted ? -100 : 100);
        setLiftPower(-100);
        vex::task::sleep(800);
        setLiftPower(0);
        setWristPower(0);
        wristRan=true;
    }
/**/
//------Aton Drive Functions------------//
    void AtonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
        //update ramping speed
        LFDR.ChangeMsec = 6;
        RFDR.ChangeMsec = 6;
        LBDR.ChangeMsec = 6;
        RBDR.ChangeMsec = 6;

        double Direction=sgn(Distance);
        int LFPowerSend=0;
        int LBPowerSend=0;
        int RFPowerSend=0;
        int RBPowerSend=0;
        //clear enc
        LeftBMotor.resetRotation();
        RightBMotor.resetRotation();
        LeftFMotor.resetRotation();
        RightFMotor.resetRotation();
        //is it there yet?
        while(std::abs(RightBMotor.rotation(vex::rotationUnits::deg))<std::abs(Distance)){
            double LEncValue=LeftBMotor.rotation(vex::rotationUnits::deg);
            double REncValue=RightBMotor.rotation(vex::rotationUnits::deg);
            //straiten
            if(std::abs(LEncValue)>std::abs(REncValue)){
                LFPowerSend=Pct-Correction;
                LBPowerSend=Pct-Correction;
                RFPowerSend=Pct;
                RBPowerSend=Pct;
            }
            else if(std::abs(LEncValue)<std::abs(REncValue)){
                LFPowerSend=Pct;
                LBPowerSend=Pct;
                RFPowerSend=Pct-Correction;
                RBPowerSend=Pct-Correction;
            }
            else if(std::abs(LEncValue)==std::abs(REncValue)){
                LFPowerSend=Pct;
                LBPowerSend=Pct;
                RFPowerSend=Pct;
                RBPowerSend=Pct;
            }
            //correct direction
            LFPowerSend=LFPowerSend*Direction;
            LBPowerSend=LBPowerSend*Direction;
            RFPowerSend=RFPowerSend*Direction;
            RBPowerSend=RBPowerSend*Direction;
            //send to SetDRpower
            SetDRMpower(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
            vex::task::sleep(1);
        }
        SetDRMpower(0,0,0,0);
        vex::task::sleep(EndWait);
        DriveBrakeType = vex::brakeType::coast;

    }
    void AtonSlide(double Distance,int Pct=100,int EndWait=500,int Correction=2){
        //update ramping speed
        LFDR.ChangeMsec = 8;
        RFDR.ChangeMsec = 8;
        LBDR.ChangeMsec = 8;
        RBDR.ChangeMsec = 8;
        //calculate direction and set L & R PowerSend
        double Direction=sgn(Distance);
        int LFPowerSend=0;
        int LBPowerSend=0;
        int RFPowerSend=0;
        int RBPowerSend=0;
        //clear enc
        LeftBMotor.resetRotation();
        RightBMotor.resetRotation();
        LeftFMotor.resetRotation();
        RightFMotor.resetRotation();
        //is it there yet?
        while(std::abs(RightBMotor.rotation(vex::rotationUnits::deg))<std::abs(Distance)){
            double LEncValue=LeftBMotor.rotation(vex::rotationUnits::deg);
            double REncValue=RightBMotor.rotation(vex::rotationUnits::deg);
            //straiten
            if(std::abs(LEncValue)>std::abs(REncValue)){
                LFPowerSend=Pct-Correction;
                LBPowerSend=Pct-Correction;
                RFPowerSend=Pct;
                RBPowerSend=Pct;
            }
            else if(std::abs(LEncValue)<std::abs(REncValue)){
                LFPowerSend=Pct;
                LBPowerSend=Pct;
                RFPowerSend=Pct-Correction;
                RBPowerSend=Pct-Correction;
            }
            else if(std::abs(LEncValue)==std::abs(REncValue)){
                LFPowerSend=Pct;
                LBPowerSend=Pct;
                RFPowerSend=Pct;
                RBPowerSend=Pct;
            }
            //correct direction
            if(Direction == 1){
                LFPowerSend=LFPowerSend;
                LBPowerSend=LBPowerSend*(-1);
                RFPowerSend=RFPowerSend*(-1);
                RBPowerSend=RBPowerSend;
            }
            if(Direction == -1){
                LFPowerSend=LFPowerSend*(-1);
                LBPowerSend=LBPowerSend;
                RFPowerSend=RFPowerSend;
                RBPowerSend=RBPowerSend*(-1);
            }
            //send to SetDRpower
            SetDRMpower(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
            vex::task::sleep(1);
        }
        SetDRMpower(0,0,0,0);
        vex::task::sleep(EndWait);
    }

    void TimeAutoDrive(int time, int power){
        LeftBMotor.resetRotation();
        RightBMotor.resetRotation();
        LeftFMotor.resetRotation();
        RightFMotor.resetRotation();

        DI(power,power);
        DriveBrakeType = vex::brakeType::coast;
        vex::task::sleep(time);
        DI(0,0);
        while(LBDR.Pct!=0 || RBDR.Pct!=0){
            vex::task::sleep(1);
        }
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
    //V2
    /*void AtonTurn(double deg,int LPowerSend=50,int RPowerSend=50,int EndWait=500){ //-left,+right
        int Dir=sgn(deg);
        //calc dir
        LPowerSend=LPowerSend*Dir;
        RPowerSend=RPowerSend*Dir;
        //clear enc
        LeftBMotor.resetRotation();
        RightBMotor.resetRotation();
        LeftFMotor.resetRotation();
        RightFMotor.resetRotation();
        //is it there?
        while(abs(RightBMotor.rotation(vex::rotationUnits::rev))<abs(deg)){
            DI(LPowerSend,-RPowerSend);
            vex::task::sleep(1);
        }
        //it is!? stop
        DriveBrakeType = vex::brakeType::brake;
        DI(0,0);
        vex::task::sleep(EndWait);
        DriveBrakeType = vex::brakeType::coast;
    }*/
    //V1
    void AtonTurn(double deg,int LPowerSend=50,int RPowerSend=50,int EndWait=250/*500s*/){ //-left,+right
        int Dir=sgn(deg);
        deg=abs(deg)/12.56;
        LPowerSend=LPowerSend*Dir;
        RPowerSend=RPowerSend*Dir;

        LeftBMotor.resetRotation();
        RightBMotor.resetRotation();
        LeftFMotor.resetRotation();
        RightFMotor.resetRotation();

        double RFValue = abs(RightFMotor.rotation(vex::rotationUnits::rev));
        double RBValue = abs(RightBMotor.rotation(vex::rotationUnits::rev));
        double LFValue = abs(LeftFMotor.rotation(vex::rotationUnits::rev));
        double LBValue = abs(LeftBMotor.rotation(vex::rotationUnits::rev));
        double AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);

        while(/*(abs(RightBMotor.rotation(vex::rotationUnits::rev)))*/AbsTurnRotationsAvg <abs(deg)){
            DI(LPowerSend,-RPowerSend);

            RFValue = abs(RightFMotor.rotation(vex::rotationUnits::rev));
            RBValue = abs(RightBMotor.rotation(vex::rotationUnits::rev));
            LFValue = abs(LeftFMotor.rotation(vex::rotationUnits::rev));
            LBValue = abs(LeftBMotor.rotation(vex::rotationUnits::rev));
            AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);

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
/**/