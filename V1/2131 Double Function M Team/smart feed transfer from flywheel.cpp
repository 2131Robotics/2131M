vex::analog_in BallSenseTop = vex::analog_in(Brain.ThreeWirePort.A);
vex::analog_in BallSenseBottom = vex::analog_in(Brain.ThreeWirePort.B);
vex::analog_in BallSenseMid = vex::analog_in(Brain.ThreeWirePort.E);

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted = false;

//--------------------------------------------//
bool AutoIntakeEnabled = false;		
int	BottomLightValue;
int MiddleLightValue;
int TopLightValue;
int BottomBallInMax = 70;
int BallInMiddleMax = 70;
int TopBallInMax = 50;

bool BallInBottom;
bool BallInTop;

void Auto_Intake(){
	BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
	TopLightValue = BallSenseTop.value(vex::percentUnits::pct);
	MiddleLightValue = BallSenseMid.value(vex::percentUnits::pct);
	
	if(BottomLightValue < BottomBallInMax || BallInMiddleMax) BallInBottom = true;
        else BallInBottom = false;
	if(TopLightValue < TopBallInMax) BallInTop = true;
	    else BallInTop = false;
	
	if(Controller1.ButtonL1.pressing()) {
		setIndexPower(-100);
		}
	else/* if(!Controller1.ButtonL1.pressing())*/{
        if(BallInBottom && BallInTop){
			setIntakePower(0);
			IntakeMotor.stop(vex::brakeType::brake);
		}
		if(BallInBottom && !BallInTop){
			setIntakePower(100);
			setIndexPower(-50);
		}
		if(BallInTop && !BallInBottom){
			setIntakePower(100);
			setIndexPower(0);
		}
		if(!BallInBottom && !BallInTop){
			setIntakePower(100);
			setIndexPower(-50);
		}
	}
	
}

void AutoIntakeIndexCont(){
    if(Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==false){
        IntakeEnabledBtnPressed=true;
        IntakeEnabledInverted=!IntakeEnabledInverted;
    }
    if(!Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==true){
        IntakeEnabledBtnPressed=false;
    }
    if(IntakeEnabledInverted){ AutoIntakeEnabled = true;}
    if(!IntakeEnabledInverted) {
        AutoIntakeEnabled = false;
        intakeControll();
        indexControll();
        FlyWheelControll();

    }
}

int Auto_Intaking(){
    AutoIntakeEnabled = true;
    while(true){
        while(AutoIntakeEnabled){
            Auto_Intake();
            vex::task::sleep(20);
        }
      vex::task::sleep(20);
    }
    return 1;
}

vex::task AutoFeedSensing(Auto_Intaking);