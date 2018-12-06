void puncherControll(){
    if(Controller1.ButtonL1.pressing()) {
        setPuncherPower(100);
    }  
    else PuncherMotor.stop(vex::brakeType::coast);
}
void PunchAton(bool wait){
    if(wait)
        PuncherMotor.rotateFor(-360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    if(!wait)
        PuncherMotor.startRotateFor(-360,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
}
//--------------------------------------------//
bool AutoIntakeEnabled = false;		
int	BottomLightValue;
int TopLightValue;
int BottomBallInMax = 70;
int TopBallInMax = 50;

bool BallInBottom;
bool BallInTop;

void Auto_Intake(){
	BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
	TopLightValue = BallSenseTop.value(vex::percentUnits::pct);
	
	if(BottomLightValue < BottomBallInMax) BallInBottom = true;
        else BallInBottom = false;
	if(TopLightValue < TopBallInMax) BallInTop = true;
	    else BallInTop = false;
    
    if(Controller1.ButtonL1.pressing() || AutoPuncherFiring){
         if (!AutoPuncherFiring) setPuncherPower(100);
         if (AutoPuncherFiring){
              PunchAton(true);
              AutoPuncherFiring = false;
         }
    }
    else{
        if(BallInBottom && BallInTop){
            setPuncherPower(0);
            setIntakePower(0);
            IntakeMotor.stop(vex::brakeType::brake);
        }
        else{
            setIntakePower(100);
            setPuncherPower(0);
        }
    }
}