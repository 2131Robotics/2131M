
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
    while(true){
        while(AutoIntakeEnabled){
            Auto_Intake();
            vex::task::sleep(20);
        }
      vex::task::sleep(20);
    }
    return 1;
}
int ControllerScreen(){
    Brain.Screen.render(true,false);
    while(true){
        Brain.Screen.newLine();
       // Brain.Screen.print((Gyro.value(vex::rotationUnits::deg)));
        Brain.Screen.render();
        vex::task::sleep(20);
        
    }
}