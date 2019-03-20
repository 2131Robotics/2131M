#ifndef VARS_HPP
#define VARS_HPP

// double abs(double Var);
double sgn(double Var);
/*Drive vars*/
extern bool MechDriveRampingEnabled;

extern bool DriveLockConBtnPressed;
extern bool DriveLockInverted;

extern bool DriveDirConBtnPressed;
extern bool DriveDirInverted;

/*Catapult vars*/
extern bool AutoCatapultEnabled;

/*Intake vars*/
extern bool AutoIntakeEnabled;
extern bool AutoIntakeTaskEnabled;

extern bool IntakeEnabledBtnPressed;
extern bool IntakeEnabledInverted;
extern bool UserAutoIntakeMode;

/*Lift vars*/
extern	bool liftButtonWait;
extern	int liftMode;
extern	int PIDliftUserCpower;
extern	bool liftDeployed;
extern	bool LiftEEnabledBtnPressed;

/*Aton vars*/
extern double Nine;
extern double Full;

extern double LiftDown;
extern double LiftUp;

#endif /* end of include guard: VARS_HPP */
