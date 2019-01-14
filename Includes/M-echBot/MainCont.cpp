void PreAutonFun() {
    Brain.Screen.render(true,false);
    vex::task SmartPot(WhatAton);
    
    while(MainAtonSelect.value(vex::percentUnits::pct)==0 && SecAtonSelect.value(vex::percentUnits::pct)==0){}//wait for vex to get be a not dumb
    LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    
    CatapultMotor.setStopping(vex::brakeType::coast);
    
    LiftMotor.resetRotation();
    WristMotor.resetRotation();
    CatapultMotor.resetRotation();
    LeftFMotor.resetRotation();
    LeftBMotor.resetRotation();
    RightFMotor.resetRotation();
    RightBMotor.resetRotation();
}
void AtonFun() {
    //vex::task AutoCat(AutoCatapult);

    vex::task AutoIn(Auto_Intaking);
    vex::task AtonDrive(Drive_Ramping);
    //vex::task AtonMechDrive(Mech_Drive_Ramping);
    
    PotSelectors();
    //setDriveBrakeCoast();

}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void UserContFun() {

    //vex::task AutoCat(AutoCatapult);
    //vex::task AutoIn(Auto_Intaking);

    AutoIntakeEnabled = false;
    DriveRampingEnabled=false;
    MechDriveRampingEnabled=false;

    //vex::task Debug(ControllerScreen);
    vex::task UCleanUp(UserCleanUp);

    while (true) {
        DriveCont_LockContM();
        AutoIntakeCont();
        //intakeControll();
        liftManualCont();
        wirstControll();
        //smartRamRodCont();
        catapultControll();

        vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
    }
}
