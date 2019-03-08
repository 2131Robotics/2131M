#ifndef VARS_HPP
#define VARS_HPP

double abs(double Var);
double sgn(double Var);

extern bool DriveRampingEnabled;
extern bool MechDriveRampingEnabled;

extern bool DriveLockConBtnPressed;
extern bool DriveLockInverted;

extern bool DriveDirConBtnPressed;
extern bool DriveDirInverted;

/*Flipper vars*/
extern bool FlipperMotorConBtnPressed;
extern bool FlipperMotorInverted;

/*Catapult vars*/
	bool AutoCatapultEnabled;

/*Intake vars*/
	bool AutoIntakeEnabled = false;
	bool AutoIntakeTaskEnabled = false;
	bool AutoIntakeOff = false;
	// bool AutoMan=false;

	bool IntakeEnabledBtnPressed;
	bool IntakeEnabledInverted = true;
	bool UserAutoIntakeMode = false;

/*Lift vars*/
	bool liftButtonWait;
	int liftMode = 1;
	int PIDliftUserCpower = 100;
	bool liftDeployed = false;
	//bool easyFlipDir = false;
	bool LiftEEnabledBtnPressed;

/*Aton vars*/
double Nine = 9;
double NineM = /*15*/17.5;
int FullM = NineM*2;

int UP = 90;
int DOWN = 30;

#endif /* end of include guard: VARS_HPP */
