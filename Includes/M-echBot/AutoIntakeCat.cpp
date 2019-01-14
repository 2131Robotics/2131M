//---------------------Auto Catapult-----------------------//
bool Charged=false;
int ChargeSenseValue;
int ChargeMaxValue = 5;
bool AutoCataFiring=true;

void catapultChargeFire(){
    ChargeSenseValue = ChargeLightSensor.value(vex::percentUnits::pct);

    if (ChargeSenseValue < ChargeMaxValue) Charged = true;

    if (Controller1.ButtonL1.pressing() && !DriveDirInverted) {

		Charged = false;
		setCatapultPower(100);
	}
	if(AutoCataFiring){
		setCatapultPower(100);
		
		//wait till gone
		vex::task::sleep(700);
		AutoCataFiring = false;
		setCatapultPower(0);
		Charged = false;
	}

	else {
		if(!Charged){
			AutoIntakeEnabled = false;
        	setCatapultPower(100); 
		}
        if(Charged){
			AutoIntakeEnabled = true;
        	setCatapultPower(0);
		}
	}

}

//---------------------Auto Intake-----------------------//
int	BottomLightValue;
int TopLightValue;
int BottomBallInMax = 40;
int TopBallInMax = 40;

bool BallInBottom;
bool BallInTop;

void Auto_Intake() { //with catapult
	BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
	TopLightValue = BallSenseTop.value(vex::percentUnits::pct);

	ChargeSenseValue = ChargeLightSensor.value(vex::percentUnits::pct);
	
	if (BottomLightValue < BottomBallInMax) BallInBottom = true;
	else BallInBottom = false;

	if (TopLightValue < TopBallInMax) BallInTop = true;
	else BallInTop = false;

	if (BallInBottom && BallInTop) {
		setIntakePower(0);
	}
	if (BallInBottom && !BallInTop) {
		setIntakePower(100);
	}
	if (BallInTop && !BallInBottom) {
		setIntakePower(100);
	}
	if (!BallInBottom && !BallInTop) {
		setIntakePower(100);
	}
}