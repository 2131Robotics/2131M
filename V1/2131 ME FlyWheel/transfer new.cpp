void ManualDriveCont(bool Flipped){
    if(Flipped){
        setDrivePower(Controller1.Axis3.value(), Controller1.Axis2.value());
    }
    if(!Flipped){
        setDrivePower(-Controller1.Axis2.value(), -Controller1.Axis3.value());
    }
}
void driveLock(){
    LeftBMotor.stop(vex::brakeType::hold);
    LeftFMotor.stop(vex::brakeType::hold);
    RightBMotor.stop(vex::brakeType::hold);
    RightFMotor.stop(vex::brakeType::hold);
}
void DriveCont_LockCont(){
    if(Controller1.ButtonY.pressing() && DriveLockConBtnPressed==false){
        DriveLockConBtnPressed=true;
        DriveLockInverted=!DriveLockInverted;
    }
    if(!Controller1.ButtonY.pressing() && DriveLockConBtnPressed==true){
        DriveLockConBtnPressed=false;
    }
    
    if(DriveLockInverted) driveLock();
    else if(!DriveLockInverted && modeVar == 0) {
        LeftBMotor.setStopping(vex::brakeType::coast);
        RightBMotor.setStopping(vex::brakeType::coast);
        LeftFMotor.setStopping(vex::brakeType::coast);
        RightFMotor.setStopping(vex::brakeType::coast);
        ManualDriveCont(true);
    }
    else if(!DriveLockInverted && modeVar == 1) {
        LeftBMotor.setStopping(vex::brakeType::coast);
        RightBMotor.setStopping(vex::brakeType::coast);
        LeftFMotor.setStopping(vex::brakeType::coast);
        RightFMotor.setStopping(vex::brakeType::coast);
        ManualDriveCont(false);
    }
}

void wirstControll(){ //but to flippper
    if(Controller1.ButtonR2.pressing() && WristMotorConBtnPressed==false){
        WristMotorConBtnPressed=true;
        WristMotor.startRotateFor(WristMotorInverted ? 170 : -170,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        WristMotorInverted=!WristMotorInverted;
    }
    if(!Controller1.ButtonR2.pressing() && WristMotorConBtnPressed==true){
        WristMotorConBtnPressed=false;
    }
}

void intakeControll(){
    if(Controller1.ButtonR1.pressing()) {
        setIntakePower(100);
    }   
    else if(Controller1.ButtonR2.pressing()) {
        setIntakePower(-100);
    }   
    else IntakeMotor.stop(vex::brakeType::coast);
}


int ControllerScreen(){
    Brain.Screen.render(true,false);
    while(true){
        Brain.Screen.newLine();
        //Controller1.Screen.print(RightBMotor.rotation(vex::rotationUnits::deg));
        Brain.Screen.print(LDR.RequestedPct);
        Brain.Screen.print(", ");
        Brain.Screen.print(LDR.Pct);
        Brain.Screen.print(", ");
        Brain.Screen.print(RDR.RequestedPct);
        Brain.Screen.print(", ");
        Brain.Screen.print(RDR.Pct);
    Brain.Screen.render();
        vex::task::sleep(20);
        
    }
}


//atonssssss
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

void AtonDriveRamp(double Distance,int Pct=100,int EndWait=250,int Correction=2){
	//calculate distince using inch
    double WheelCir=4*3.14159265;
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
    while(RightBMotor.isSpinning() || LeftBMotor.isSpinning()){
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
void TurnRamp(double deg,int LPowerSend=50,int RPowerSend=50,int EndWait=250){ //-left,+right
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
}
void toggleWrist(){
    WristMotor.startRotateFor(WristMotorInverted ? 170 : -170,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    WristMotorInverted=!WristMotorInverted;
}
void WristLock(){
    setWristPower(-50);
    WristMotor.startRotateTo(0,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
}
void IntakeAtonSet(bool ON, bool direction){
    if(ON){
        if(direction) setIntakePower(100);
        if(!direction) setIntakePower(-100);
    }
    if(!ON){IntakeMotor.stop();}
}
void PunchAton(bool wait){
    if(wait)
        PuncherMotor.rotateFor(-360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    if(!wait)
        PuncherMotor.startRotateFor(-360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
}

void autonomous( void ) {
    int SelectValue = AtonSelect.value(vex::percentUnits::pct);
    //vex::task printDis(ControllerScreen);
        DriveRampingEnabled = false;
    vex::task AtonDrive(Drive_Ramping);
    
    WristMotor.stop(vex::brakeType::hold);
    //
    if(SelectValue > 90) {
        
    }
    if(SelectValue > 45) {
        RedBack();
    }
    if(SelectValue > 25){
        RedFront();
    }
    if(SelectValue > 10){
        BlueBack();
    }
    if(SelectValue == 0){
        BlueFront();
    }

    if(SelectValue > 90){
        FirstTest();
    }

    LeftBMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
}
//-toggle modes
if (!Controller1.ButtonLeft.pressing())
            usertoggle=1;
        if (Controller1.ButtonLeft.pressing() && modeVar==1 && usertoggle==1){
            modeVar=0;
            usertoggle=0;
        }
        if (Controller1.ButtonLeft.pressing() && modeVar==0 && usertoggle==1){
            modeVar=1;
            usertoggle=0;
        }
        
        DriveCont_LockCont();
		
bool AutoIntakeEnabled;		
int	BottomLightValue;
int TopLightValue;
int BottomBallInMax = 60;
int TopBallInMax = 60;

bool BallInBottom;
bool BallInTop;

//void ()


void Auto_Intake(){
	BottomLightValue = BallSenseBottom.value(vex::analogUnits::range8bit);
	TopLightValue = BallSenseTop.value(vex::analogUnits::range8bit);
	
	if(BottomLightValue < BottomBallInMax) BallInBottom = true;
	if(TopLightValue < TopBallInMax) BallInTop = true;
	
	else {
		BallInBottom = false;
		BallInTop = false;
	}
	
	if(Controller1.ButtonL1.pressing()) {
		setIndexPower(-100);
		}
	else if(!Controller1.ButtonL1.pressing()){
		if(!BallInBottom && !BallInTop){
			setIntakePower(100);
			setIndexPower(100);
		}
		if(BallInBottom && !BallInTop){
			setIntakePower(100);
			setIndexPower(100);
		}
		if(BallInTop && !BallInBottom){
			setIntakePower(100);
			setIndexPower(0);
		}
		if(BallInBottom && BallInTop){
			setIntakePower(100);
			setIndexPower(100);
		}
	}
	
}
