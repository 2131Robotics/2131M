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
bool DriveLockInverted;

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted = false;
bool UserAutoIntakeMode = false;
bool AutoIndexFiring = false;

//aton vars
double Nine = 10;
int Full = 180;