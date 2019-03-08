#ifndef VARS_HPP
#define VARS_HPP

double abs(double Var);
double sgn(double Var);
/*Drive vars*/
extern bool DriveRampingEnabled;
extern bool MechDriveRampingEnabled;

extern bool DriveLockConBtnPressed;
extern bool DriveLockInverted;

extern bool DriveDirConBtnPressed;
extern bool DriveDirInverted;

/*Catapult vars*/
extern	bool AutoCatapultEnabled;

/*Intake vars*/
extern bool AutoIntakeEnabled;
extern bool AutoIntakeTaskEnabled;
extern bool AutoIntakeOff;
	// bool AutoMan=false;

extern bool IntakeEnabledBtnPressed;
extern bool IntakeEnabledInverted;
extern bool UserAutoIntakeMode;

/*Lift vars*/
extern	bool liftButtonWait;
extern	int liftMode;
extern	int PIDliftUserCpower;
extern	bool liftDeployed;
	//bool easyFlipDir = false;
extern	bool LiftEEnabledBtnPressed;

/*Aton vars*/
// double Nine;
// double NineM;
// int FullM = NineM;

// int UP;
// int DOWN;

#endif /* end of include guard: VARS_HPP */
