#include "robot-config.h"

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;
//vex::motor dt(LeftFMotor, RightFMotor, 4, 12.5, vex::distanceUnits::in);
//bool buttontoggle = false;
//bool togglewait = false;

bool WristMotorConBtnPressed;
bool WristMotorInverted;

bool liftButtonWait;
int liftMode = 1;
int liftUserCpower = 100;

int modeVar;           //skills toggle variable
int usertoggle;          //usertoggle variable
int initalize=0;         //initializing the toggle variable

class Ramping{
    public:
    int ChangePct=1;      //the amout of Pct change per loop
    int ChangeMsec=1;     //the amount of time inbetween loops

    int RequestedPct=0;   //used to request Pct value change
    int Pct=0;            //Pct output
    int MinUpPct=0;         //Used as moveing up StillSpeed
    int MinDownPct=0;       //Used as moving down StillSpeed
    int MaxPct=100;         //the max pct value

    Ramping();

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
        //ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

    void TaskRun(){
        if(RequestedPct>Pct){
            Pct=Pct+ChangePct;
        }
        else if(RequestedPct<Pct){
            Pct=Pct-ChangePct;
        }
        //limit Pct
        if(Pct>MaxPct)	Pct=MaxPct;
        if(Pct<-MaxPct)	Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
    }
};

int ControllerScreen(){
    while(true){
        Controller1.Screen.print(RightBMotor.rotation(vex::rotationUnits::deg));
        vex::task::sleep(250);
    }
}

void LMotorPowers(int rpm){
    //LeftFMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
    LeftBMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
}

void RMotorPowers(int rpm){
    // RightFMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
    RightBMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
}

void DriveCont(int left, int right){
    LMotorPowers(left);
    RMotorPowers(right);
}

Ramping LDR(1,3);
Ramping RDR(1,3);

int DriveContRamp(){
    while(1){
        LDR.TaskRun();
        RDR.TaskRun();
        DriveCont(LDR.Pct, RDR.Pct);
        vex::task::sleep(RDR.ChangeMsec);
    }
}
void liftControll(){
    //Lift Control
    /*  if(Controller1.ButtonL1.pressing()) {
            LiftMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        }   
        else if(Controller1.ButtonL2.pressing()) {
            LiftMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        }   
        else LiftMotor.stop(vex::brakeType::hold);*/
    //----------------------Lift Controll------------------------//
    if(liftMode > 5)
        liftMode = 5;
    if(liftMode < 1)
        liftMode = 1;

    if(Controller1.ButtonL1.pressing() == false && Controller1.ButtonL2.pressing() == false)
        liftButtonWait=true;
    if(Controller1.ButtonL1.pressing() && liftButtonWait == true && liftMode <= 5){
        liftButtonWait=false;
        liftMode++;
    }

    if(Controller1.ButtonL2.pressing() && liftButtonWait == true && liftMode >= 1){
        liftButtonWait=false;
        liftMode--;
    }

    if(liftMode == 1)
        LiftMotor.rotateTo(0,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 2)
        LiftMotor.rotateTo(145,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 3)
        LiftMotor.rotateTo(400,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 4)
        LiftMotor.rotateTo(530,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 5)
        LiftMotor.rotateTo(680,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
}
void ballLiftCont(){
    //----------------------Lift Controll------------------------//
    if(liftMode > 2)
        liftMode = 2;
    if(liftMode < 1)
        liftMode = 1;

    if(Controller1.ButtonL1.pressing() == false && Controller1.ButtonL2.pressing() == false)
        liftButtonWait=true;
    if(Controller1.ButtonL1.pressing() && liftButtonWait == true && liftMode <= 5){
        liftButtonWait=false;
        liftMode++;
    }

    if(Controller1.ButtonL2.pressing() && liftButtonWait == true && liftMode >= 1){
        liftButtonWait=false;
        liftMode--;
    }

    if(liftMode == 1)
        LiftMotor.rotateTo(0,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 2)
        LiftMotor.rotateTo(180,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
}
void wirstControll(){
    if(Controller1.ButtonA.pressing() && WristMotorConBtnPressed==false){
        WristMotorConBtnPressed=true;
        WristMotor.startRotateFor(WristMotorInverted ? 180 : -180,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        WristMotorInverted=!WristMotorInverted;
    }
    if(!Controller1.ButtonA.pressing() && WristMotorConBtnPressed==true){
        WristMotorConBtnPressed=false;
    }
}

void puncherControll(){
    if(Controller1.ButtonUp.pressing()) {
        PuncherMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }  
    else PuncherMotor.stop(vex::brakeType::coast);
}
void intakeControll(){
    if(Controller1.ButtonR1.pressing()) {
        IntakeMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }   
    else if(Controller1.ButtonR2.pressing()) {
        IntakeMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }   
    else IntakeMotor.stop(vex::brakeType::coast);
}
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
    Brain.Screen.print("Setting Up...");
    //Controller1.Screen.print("Hi Trent! Initializing...");

    WristMotor.resetRotation();
    WristMotor.setStopping(vex::brakeType::brake);
    WristMotor.setTimeout(250,vex::timeUnits::msec);
    //LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    //RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    LiftMotor.setStopping(vex::brakeType::brake);
    PuncherMotor.setStopping(vex::brakeType::coast);
    IntakeMotor.setStopping(vex::brakeType::brake);

    LiftMotor.resetRotation();
}

void AutoDrive(int degg, int vel, bool wait){
    if(!wait){
        RightBMotor.startRotateFor(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
        LeftBMotor.startRotateFor(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
    }
    if(wait){
        RightBMotor.startRotateFor(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
        LeftBMotor.rotateFor(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
    }
}
void DriveSpeedSet(){
    //LeftFMotor.rotateTo
    //RightFMotor.rotateTo(90,vex::rotationUnits::deg,50,vex::velocityUnits::pct,false);
}

void DriveTurn(int degg, bool direction, bool wait){
    if(wait){
        LeftBMotor.startRotateFor(direction ? degg : -degg,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        RightBMotor.rotateFor(direction ? -degg : degg,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    }
    if(!wait){
        LeftBMotor.startRotateFor(direction ? degg : -degg,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        RightBMotor.startRotateFor(direction ? -degg : degg,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    }
}
void AutoLift(int degg, int vel, bool wait){
    if(wait){
        LiftMotor.rotateTo(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
    }
    if(!wait){
        LiftMotor.startRotateTo(degg,vex::rotationUnits::deg,vel,vex::velocityUnits::pct);
    }
}

void toggleWrist(){
    WristMotor.startRotateFor(WristMotorInverted ? 180 : -180,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    WristMotorInverted=!WristMotorInverted;
}

void IntakeAtonSet(bool ON, int direction){
    if(ON){
        if(direction == 1){IntakeMotor.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);}
        if(direction == 2){IntakeMotor.spin(vex::directionType::rev,100,vex::velocityUnits::pct);}
    }
    if(!ON){IntakeMotor.stop();}
}
void PunchAton(bool wait){
    if(wait)
        PuncherMotor.rotateFor(-1080,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    if(!wait)
        PuncherMotor.startRotateFor(-1080,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
}
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
void FirstTest(){
    IntakeAtonSet(true, 1);
    AutoDrive(-2000, 100, true);
    AutoDrive(1400,100,true);

    DriveTurn(440, true, true);
    IntakeAtonSet(false, 1);
    PunchAton(true);
    
    /*IntakeAtonSet(true, 1);
     PunchAton(true);
    //IntakeAtonSet(true, 2);
     //PunchAton(true);
    IntakeAtonSet(false, 1);*/
    //IntakeMotor.spin(vex::directionType::fwd,100,vex::velocityUnits::pct);
}
void autonomous( void ) {
    //LeftFMotor.setStopping(vex::brakeType::hold);
    LeftBMotor.setStopping(vex::brakeType::hold);
    //RightFMotor.setStopping(vex::brakeType::hold);
    RightBMotor.setStopping(vex::brakeType::hold);

    Brain.Screen.print("Auton Start");
    //Controller1.Screen.print("Hi Nate! Good luck...");
    /*
    //AutoDrive(1000, 100, true);
    //AutoLift(500, 50, false);
    IntakeAtonSet(true, 1);
    //PunchAton();

    IntakeAtonSet(false, 1);*/

    /*toggleWrist();
    PunchAton(true);
    toggleWrist();*/
    FirstTest();
    
     //LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    //RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
    Brain.Screen.print("Start Usercontroll");
    //Controller1.Screen.print("Hi Trent! You're driving now...");

    vex::task printDis(ControllerScreen);
    vex::task DriveContRampTask(DriveContRamp);

    while(1) 
    {
        if (!Controller1.ButtonLeft.pressing())																	//
        {																											//
            usertoggle=1;																				//
        }																											//
        if (Controller1.ButtonLeft.pressing() && modeVar==1 && usertoggle==1) //
        {																											//  USER CONTROL TOGGLE
            modeVar=0;																				//		- To switch between
            usertoggle=0;																				//			our two different
        }																											//			modes
        if (Controller1.ButtonLeft.pressing() && modeVar==0 && usertoggle==1)	//
        {																											//
            modeVar=1;																				//
            usertoggle=0;																				//
        }	
        
        
        //=========================Normal Caps Drive Control===========================//
        if (modeVar == 0)
        {
            if (initalize==0)																			// To Initalize Normal
            {																											// match Code

            }
            initalize=1;

            LDR.RequestedPct = Controller1.Axis3.value();
            RDR.RequestedPct = Controller1.Axis2.value();            
            liftControll();
            intakeControll();
            puncherControll();
            wirstControll();

            vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
        }
        //----------------------Puncher Controll------------------------//

        if (modeVar == 1) // Ball Mode
        {
            if (initalize==1)																			// To Initalize Normal
            {																											// match Code
                liftMode = 1;
            }
            initalize=0;

            LDR.RequestedPct = -Controller1.Axis2.value();
            RDR.RequestedPct = -Controller1.Axis3.value();
                intakeControll();
            ballLiftCont();
            puncherControll();
            wirstControll();

            vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
        }
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

    //Run the pre-autonomous function. 
    pre_auton();

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
        vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    

}