//---------------------Auto Intake-----------------------//
bool AutoIntakeEnabled = false;
int	BottomLightValue;
int TopLightValue;
int MiddleLightValue;
int BottomBallInMax = 70;
int MiddleBallInMax = 70;
int TopBallInMax = 65;

bool BallInBottom;
bool BallInTop;

void Auto_Intake() {
	BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
	TopLightValue = BallSenseTop.value(vex::percentUnits::pct);
	MiddleLightValue = BallSenseMid.value(vex::percentUnits::pct);

	if (BottomLightValue < BottomBallInMax || MiddleLightValue < MiddleBallInMax) BallInBottom = true;
	else BallInBottom = false;
	if (TopLightValue < TopBallInMax) BallInTop = true;
	else BallInTop = false;

	if (Controller1.ButtonL1.pressing()) {
		setIndexPower(-100);
	}
	else {
		if (BallInBottom && BallInTop) {
			setIntakePower(0);
			setIndexPower(0);
			IntakeMotor.stop(vex::brakeType::brake);
		}
		if (BallInBottom && !BallInTop) {
			setIntakePower(100);
			setIndexPower(-50);
		}
		if (BallInTop && !BallInBottom) {
			setIntakePower(100);
			setIndexPower(0);
		}
		if (!BallInBottom && !BallInTop) {
			setIntakePower(100);
			setIndexPower(-50);
		}
	}
}