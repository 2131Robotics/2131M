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
	bool WristTaskEnabled;
	bool WristMotorConBtnPressed;
	bool WristMotorInverted = false;
	bool WristCalibrated=false;
	bool wristRan=true;
	//bool WristMotorConBtnTwoPressed;
	//bool WristMotorInvertedTwo = true;

/*Catapult vars*/
	bool AutoCatapultEnabled;

/*Intake vars*/
	bool AutoIntakeEnabled = false;
	bool AutoIntakeTaskEnabled = false;
	bool AutoIntakeOff = false;
	bool AutoFlip=false;
	// bool AutoMan=false;

	bool IntakeEnabledBtnPressed;
	bool IntakeEnabledInverted = true;
	bool UserAutoIntakeMode = false;

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
	//bool easyFlipDir = false;
	bool LiftEEnabledBtnPressed;

/*Lock vars*/
	bool jawButtonWait;
	int jawMode = 1;
	int jawUserCpower = 100;

	bool JawMotorConBtnPressed;
	bool JawMotorInverted = false;


/*Aton vars*/
	double Nine = 9;
	double NineM = /*15*/17.5;
	int FullM = NineM*2;

	// int UP = 90;
	// int DOWN = 30;

/*VEX Brake vars
	pros::Motor::set_brake_mode DriveBrakeType=pros::E_MOTOR_BRAKE_HOLD;
	vex::brakeType LiftBrakeType=vex::brakeType::brake;
	vex::brakeType CatapultBrakeType=vex::brakeType::coast;
	vex::brakeType IntakeBrakeType=vex::brakeType::coast;
	vex::brakeType LockBrakeType=vex::brakeType::coast;
	vex::brakeType WristBrakeType=vex::brakeType::brake;*/
