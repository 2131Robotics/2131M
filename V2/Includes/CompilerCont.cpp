/*---------------------------------------------------------------------------*/
/*                              Pre Aton Control Task                        */
/*---------------------------------------------------------------------------*/
void PreAutonFun() {
    Brain.Screen.render(true,false);
    vex::task SmartPot(WhatAton);

        //wait for vex to not be a dumb
    while(MainAtonSelect.value(vex::percentUnits::pct)==0 && SecAtonSelect.value(vex::percentUnits::pct)==0){}
    LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    
    LiftMotor.setStopping(vex::brakeType::brake);
    
    CatapultMotor.setStopping(vex::brakeType::coast);
    
    LiftMotor.resetRotation();
    LockMotor.resetRotation();
    CatapultMotor.resetRotation();
    LeftFMotor.resetRotation();
    LeftBMotor.resetRotation();
    RightFMotor.resetRotation();
    RightBMotor.resetRotation();
}

/*---------------------------------------------------------------------------*/
/*                              Aton Control Task                            */
/*---------------------------------------------------------------------------*/

void AtonFun() {
    vex::task AutoCat(AutoCatapult);
    
    AutoIntakeEnabled = false;
    vex::task AtonDrive(Drive_Ramping);

    LiftMotor.resetRotation();
    LockMotor.resetRotation();

    // LockRotateTo(-60);
    
    PotSelectors();
    //setDriveBrakeCoast();

}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void UserContFun() {

    vex::task AutoCat(AutoCatapult);

    AutoIntakeEnabled = false;
    DriveRampingEnabled=false;
    MechDriveRampingEnabled=false;

    //vex::task Debug(ControllerScreen);

    while (true) {
        DriveCont_LockContM();
        AutoIntakeCont();
        //intakeControll();
        liftManualCont();
        LockJawCont();
        //catapultControll();

        vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
    }
}
