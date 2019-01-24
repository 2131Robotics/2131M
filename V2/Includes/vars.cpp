/*Math vars*/
	double abs(double Var) {
		if (Var < 0)  Var = Var * (-1);
		return Var;
	}
	double sgn(double Var) {
		if (Var > 0)   Var = 1;
		else        Var = -1;
		return Var;
	}
/*Drive vars*/
	bool DriveRampingEnabled;
	bool MechDriveRampingEnabled;

	bool DriveLockConBtnPressed;
	bool DriveLockInverted = false;

	bool DriveDirConBtnPressed;
	bool DriveDirInverted = false;

/*Flipper vars*/
	bool FlipperMotorConBtnPressed;
	bool FlipperMotorInverted = false;

/*Wrist vars*/
	bool WristMotorConBtnPressed;
	bool WristMotorInverted = false;
	bool WristCalibrated=false;

	bool WristMotorConBtnTwoPressed;
	bool WristMotorInvertedTwo = true;

/*Catapult vars*/
	bool AutoCatapultEnabled;

/*Intake vars*/
	bool AutoIntakeEnabled = false;

	bool IntakeEnabledBtnPressed;
	bool IntakeEnabledInverted = true;
	bool UserAutoIntakeMode = false;

/*Index vars*/
	bool AutoIndexFiring = false;

/*Puncher vars*/
	bool AutoPuncherFiring = false;

/*Ram Rod vars*/
	bool RamEnabledBtnPressed;
	bool RamEnabledInverted;
	bool RamManualEnabled = false;
	bool RamPosEnabled = true;

/*Lift vars*/
	bool liftButtonWait;
	int liftMode = 1;
	int PIDliftUserCpower = 100;
	bool liftDeployed = false;

/*Lock vars*/
	bool jawButtonWait;
	int jawMode = 1;
	int jawUserCpower = 100;

	bool JawMotorConBtnPressed;
	bool JawMotorInverted = false;


/*Aton vars*/
	double Nine = 9;
	double NineM = 17.5;
	int Full = 18;

	int UP = 90;
	int DOWN = 30;

/*VEX Brake vars*/
	vex::brakeType DriveBrakeType=vex::brakeType::coast;
	vex::brakeType LiftBrakeType=vex::brakeType::brake;
	vex::brakeType CatapultBrakeType=vex::brakeType::coast;
	vex::brakeType IntakeBrakeType=vex::brakeType::coast;
	vex::brakeType LockBrakeType=vex::brakeType::coast;