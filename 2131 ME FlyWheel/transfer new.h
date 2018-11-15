bool WristMotorConBtnPressed;
bool WristMotorInverted = false;


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


//------------------Drive voids----------------------//
void LeftDriveStop(){
    LeftBMotor.stop();
    LeftFMotor.stop();
}
void RightDriveStop(){
    RightBMotor.stop();
    RightFMotor.stop();
}
void setLeftDrivePower(int pct){
    if(pct==0)   LeftDriveStop();
    else{
        LeftBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        LeftFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setRightDrivePower(int pct){
    if(pct==0)  RightDriveStop();
    else{
        RightBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        RightFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
    }
}
void setDrivePower(int left, int right){
    setLeftDrivePower(left);
    setRightDrivePower(right);
}

//--------------------------------------------//
void setWristPower(int power){
   WristMotor.spin(vex::directionType::fwd,power,vex::velocityUnits::pct);
}
void setPuncherPower(int power){
    PuncherMotor.spin(vex::directionType::rev, power, vex::velocityUnits::pct);
}
void setIntakePower(int power){
    IntakeMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
}