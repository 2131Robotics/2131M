int Drive_Ramping(){
    DriveRampingEnabled=true;
    while(DriveRampingEnabled){
        LDR.TaskRun();
        RDR.TaskRun();
        setDrivePower(LDR.Pct,RDR.Pct);
        vex::task::sleep(LDR.ChangeMsec);
    }
    return 1;
}

int Auto_Intaking(){
    AutoIntakeEnabled = true;
    while(AutoIntakeEnabled){
        Auto_Intake();
        vex::task::sleep(20);
    }
    return 1;
}

int AutoCatapult(){
    AutoCatapultEnabled = true;
    while(AutoCatapultEnabled){
        catapultChargeFire();
        vex::task::sleep(20);
    }
    return 1;
}

int ControllerScreen(){
    Brain.Screen.render(true,false);
    while(true){
        //Brain.Screen.newLine();
        Brain.Screen.print(DriveDirInverted);
        Brain.Screen.render();
        //Controller1.Screen.print(Charged);
        vex::task::sleep(20);
    }
}

int WristCal(){
    while(!WristCalibrated){
        wristCal();
        WristMotor.resetRotation();
        vex::task::sleep(20);
    }
    WristMotor.resetRotation();
    return 1;
}