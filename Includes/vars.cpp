double abs(double Var) {
	if (Var < 0)  Var = Var * (-1);
	return Var;
}
double sgn(double Var) {
	if (Var > 0)   Var = 1;
	else        Var = -1;
	return Var;
}

int modeVar = 1;           //skills toggle variable
int usertoggle;          //usertoggle variable
int initalize = 0;         //initializing the toggle variable

bool DriveRampingEnabled;

bool FlipperMotorConBtnPressed;
bool FlipperMotorInverted = false;

bool DriveLockConBtnPressed;
bool DriveLockInverted = false;

bool DriveDirConBtnPressed;
bool DriveDirInverted = false;

bool WristMotorConBtnPressed;
bool WristMotorInverted = false;

bool WristMotorConBtnTwoPressed;
bool WristMotorInvertedTwo = true;

bool AutoCatapultEnabled;

bool AutoIntakeEnabled = false;
bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted = true;
bool UserAutoIntakeMode = false;
bool AutoIndexFiring = false;
bool AutoPuncherFiring = false;

bool RamEnabledBtnPressed;
bool RamEnabledInverted;
bool RamManualEnabled = false;
bool RamPosEnabled = true;

bool liftButtonWait;
int liftMode = 1;
int PIDliftUserCpower = 100;

bool jawButtonWait;
int jawMode = 1;
int jawUserCpower = 100;

bool JawMotorConBtnPressed;
bool JawMotorInverted = false;


//aton vars
double Nine = 9;
double NineM = 17.5;

int Full = 18;
double FullM = NineM*2;

int UP = 90;
int DOWN = 30;