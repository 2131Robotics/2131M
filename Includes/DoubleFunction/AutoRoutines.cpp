void FirstTest(){
    AutoIntakeEnabled = false;
    AtonDriveRamp(1,100);
    toggleWrist();
    PunchAton(true);
    wait(5000);
}

void BlueFront(){
    
    AutoIntakeEnabled = false;
    AtonDriveRamp(-25,100);
    wait(500);
    AtonDriveRamp(18,100);
    
    AtonTurn(Nine);
    AutoPuncherFiring = true;
    wait(500);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-6,100);
    //Brain.Screen.print("end");
    AutoPuncherFiring = true;
    wait(500);
    AtonTurn(2);
    AtonDriveRamp(-6,100);

    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonTurn(2);
    AtonDriveRamp(6,100);
    toggleWrist();
    AtonDriveRamp(-3,100);
}

void BlueBack(){
    AutoPuncherFiring = true;
    wait(500);
    AutoPuncherFiring = true;

    AtonTurn(-6);
    AtonDriveRamp(-27,100);

    wait(250);
    AtonDriveRamp(7,100);
    
    AtonTurn(13);
    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonDriveRamp(8,100);
    toggleWrist();

    AtonDriveRamp(-3,60);
    AtonTurn((-Nine/2));
    AtonDriveRamp(-28,100);
    stopDriveBrake();
}

void RedFront(){
    
    AutoIntakeEnabled = false;
    AtonDriveRamp(-28,100);
    wait(500);
    AtonDriveRamp(25,100);
    
    AtonTurn(-Nine-.35);
    AutoPuncherFiring = true;
    wait(500);
    AtonTurn(-.5);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-6,100);
    //Brain.Screen.print("end");

    AutoPuncherFiring = true;
    wait(500);
    //AtonTurn(-2);
    AtonDriveRamp(-6,100);

    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonTurn(-6);
    AtonDriveRamp(6,100);
    toggleWrist();
    AtonDriveRamp(-3,100);
}

void RedBack(){
    AutoPuncherFiring = true;
    wait(500);
    AutoPuncherFiring = true;

    AtonTurn(6);
    AtonDriveRamp(-27,100);

    wait(250);
    AtonDriveRamp(7,100);
    
    AtonTurn(-13);
    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonDriveRamp(8,100);
    toggleWrist();

    AtonDriveRamp(-3,60);
    AtonTurn((Nine/2));
    AtonDriveRamp(-28,100);
    stopDriveBrake();
}