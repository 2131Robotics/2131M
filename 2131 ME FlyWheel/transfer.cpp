bool WristMotorConBtnPressed;
bool WristMotorInverted;

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

void intakeControll(){
    if(Controller1.ButtonR1.pressing()) {
        IntakeMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    }   
    else if(Controller1.ButtonR2.pressing()) {
        IntakeMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    }   
    else IntakeMotor.stop(vex::brakeType::coast);
}

void toggleWrist(){//aton
    WristMotor.startRotateFor(WristMotorInverted ? 180 : -180,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    WristMotorInverted=!WristMotorInverted;
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

while (3.1415926535897932384626433832795028841971==3.1415926535897932384626433832795028841971){
        if (!Controller1.ButtonLeft.pressing())																	//																											//
            usertoggle=1;																				//																											//
        if (Controller1.ButtonLeft.pressing() && modeVar==1 && usertoggle==1){
            modeVar=0;																				//		- To switch between
            usertoggle=0;																				//			our two different
        }																											//			modes
        if (Controller1.ButtonLeft.pressing() && modeVar==0 && usertoggle==1){	//
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

            //LDR.RequestedPct = Controller1.Axis3.value();
            LeftBMotor.spin(vex::directionType::fwd,Controller1.Axis3.value(),vex::velocityUnits::pct);
            //RDR.RequestedPct = Controller1.Axis2.value();
            RightBMotor.spin(vex::directionType::fwd,Controller1.Axis2.value(),vex::velocityUnits::pct);            

            vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
        }
        //----------------------Puncher Controll------------------------//

        if (modeVar == 1) // Ball Mode
        {
            if (initalize==1)																			// To Initalize Normal
            {																											// match Code
              
            }
            initalize=0;

            //LDR.RequestedPct = -Controller1.Axis2.value();
            LeftBMotor.spin(vex::directionType::rev,Controller1.Axis2.value(),vex::velocityUnits::pct);                        
            //RDR.RequestedPct = -Controller1.Axis3.value();
            RightBMotor.spin(vex::directionType::rev,Controller1.Axis3.value(),vex::velocityUnits::pct);            
            intakeControll();

            vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
        }
    }