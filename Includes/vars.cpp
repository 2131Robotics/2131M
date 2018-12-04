double abs(double Var) {
	if (Var < 0)  Var = Var * (-1);
	return Var;
}
double sgn(double Var) {
	if (Var > 0)   Var = 1;
	else        Var = -1;
	return Var;
}

int modeVar;           //skills toggle variable
int usertoggle;          //usertoggle variable
int initalize = 0;         //initializing the toggle variable

bool DriveRampingEnabled;

bool FlipperMotorConBtnPressed;
bool FlipperMotorInverted = false;

bool DriveLockConBtnPressed;
bool DriveLockInverted = false;

bool WristMotorConBtnPressed;
bool WristMotorInverted = false;

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted = false;
bool UserAutoIntakeMode = false;
bool AutoIndexFiring = false;

bool liftButtonWait;
int liftMode = 1;
int PIDliftUserCpower = 100;

bool jawButtonWait;
int jawMode = 1;
int jawUserCpower = 100;

bool JawMotorConBtnPressed;
bool JawMotorInverted = false;


//aton vars
double Nine = 10;
int Full = 180;