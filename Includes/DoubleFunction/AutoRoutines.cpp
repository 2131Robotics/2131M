void FirstTest(){
    AutoIntakeEnabled = false;
    TimeAutoDrive(1000,12);
    AtonDriveRamp(8,100);
    stopDriveHold();
    AtonTurn(-Nine-1);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(10,100);
    stopDriveHold();
    
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
    
    AtonTurn(14);
    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonDriveRamp(8,100);
    toggleWrist();

    AtonDriveRamp(-3,60);
    AtonTurn((-Nine/2));
    AtonDriveRamp(-30,100);
    stopDriveBrake();
}

void RedFront(){
    
    AutoIntakeEnabled = false;
    AtonDriveRamp(-28,100);
    wait(500);
    AtonDriveRamp(25,100);

    TimeAutoDrive(500,40);
    AtonDriveRamp(-2,15);

    AtonTurn(-Nine-.25);
    AutoPuncherFiring = true;
    wait(500);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-3,100);
    //Brain.Screen.print("end");

    AutoPuncherFiring = true;
    wait(800);
    //AtonTurn(-2);
    AtonDriveRamp(-6,100);

    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonTurn(-6);
    AtonDriveRamp(6,100);
    toggleWrist();
    wait(150);
    AtonDriveRamp(-3,100);
}

void RedBack(){
    AutoPuncherFiring = true;
    wait(500);
    AutoPuncherFiring = true;

    AtonTurn(6);
    AtonDriveRamp(-28,100);

    wait(250);
    AtonDriveRamp(7,100);
    
    AtonTurn(-13);
    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonDriveRamp(8,100);
    toggleWrist();

    AtonDriveRamp(-3,40);
    AtonTurn((Nine/2));
    AtonDriveRamp(-28,100);
    stopDriveBrake();
}

void Skills(){
    AutoPuncherFiring = true;
    wait(500);
    AutoPuncherFiring = true;

    //AtonDriveRamp(1,15);
    AtonTurn(Nine+.5);
    AtonDriveRamp(-26,100);
    AtonDriveRamp(-3,20);

    wait(250);
    AtonTurn(-Nine-.25);
    AutoPuncherFiring = true;
    wait(500);

    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonDriveRamp(3,30);
    AutoLift(250,50,true);
    toggleWrist();
    AtonTurn(-Nine+1);
    AutoLift(0,50,true);
    //toggleWrist();

    AtonDriveRamp(-32,100);
    //TimeAutoDrive(800,-40);

    //AtonDriveRamp(1,30);
    AtonTurn(Nine-1.25);
    AtonDriveRamp(-80,100);
    TimeAutoDrive(800,-40);

    AtonDriveRamp(1,50);
    AtonTurn(-4);
    AtonDriveRamp(15,100);
    AutoLift(250,50,true);
    AtonTurn(-15);
    toggleWrist();
    AutoLift(0,50,true);
    AtonDriveRamp(-8,100);
    AtonTurn(-Nine-1);

    AtonDriveRamp(-10,100);
    AtonTurn(-Nine-1);

    AutoPuncherFiring = true;
    wait(500);

    AtonDriveRamp(-12,100);
    }