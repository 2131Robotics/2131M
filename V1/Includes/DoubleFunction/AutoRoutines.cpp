void FirstTest(){
    TimeAutoDrive(1000,12);
    AtonDriveRamp(8,100);
    stopDriveHold();
    AtonTurn(-Nine-1);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(10,100);
    stopDriveHold();
    AutoIntakeEnabled = false;
    
}

void BlueFront(){
    
    AutoIntakeEnabled = false;
    AtonDriveRamp(-26,100);
    wait(500);
    AtonDriveRamp(22,100);
    
    AtonTurn(Nine+.5);
    AutoPuncherFiring = true;
    wait(500);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-6,100);
    //Brain.Screen.print("end");
    AutoPuncherFiring = true;
    wait(500);
    AtonTurn(1.5);
    AtonDriveRamp(-12,100);

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
    AtonDriveRamp(-26,100);
    stopDriveBrake();
}

void RedFront(){
    
    AutoIntakeEnabled = false;
    AtonDriveRamp(-28,100);
    wait(500);
    AtonDriveRamp(25,100);

    TimeAutoDrive(500,40);
    AtonDriveRamp(-2,15);

    AtonTurn(-Nine-.2);
    AutoPuncherFiring = true;
    wait(500);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-4,100);
    //Brain.Screen.print("end");

    AutoPuncherFiring = true;
    wait(800);
    //AtonTurn(-2);
    AtonDriveRamp(-14,100);
    //AtonDriveRamp(4,100);

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

    AtonDriveRamp(-2,40);
    AtonTurn(5.5);
    AtonDriveRamp(-30,100);
    stopDriveBrake();
}

void Skills(){
    AutoPuncherFiring = true;
    wait(500);
    AutoPuncherFiring = true;

    //AtonDriveRamp(1,15);
    AtonTurn(Nine+.5);
    AtonDriveRamp(-28,100);
    //AtonDriveRamp(3,20);

    wait(250);
    AtonTurn(-Nine-.25);
    AutoPuncherFiring = true;
    wait(500);

    AutoLift(250,50,true);
    toggleWrist();
    AutoLift(0,50,true);
    AtonDriveRamp(4,40);
    //AutoLift(250,50,true);
    toggleWrist();
    AtonDriveRamp(-4,40);
    AtonTurn(-Nine-.5);
    //AutoLift(0,50,true);
    //toggleWrist();

    AtonDriveRamp(-32,100);
    TimeAutoDrive(300,-40);

    AtonDriveRamp(1,30);
    AtonTurn(Nine+1);
    AtonDriveRamp(-80,100);
    AtonDriveRamp(1,100);
    AtonTurn(-1);
    //TimeAutoDrive(800,-40);

    AtonDriveRamp(34,100);
    AtonTurn(-Nine-2);

    /*AutoLift(250,50,true);
    AtonTurn(-15);
    toggleWrist();
    AutoLift(0,50,true);
    AtonDriveRamp(-8,100);
    AtonTurn(-Nine-1);

    AtonDriveRamp(-10,100);
    AtonTurn(-Nine-1);

    AutoPuncherFiring = true;
    wait(500);

    AtonDriveRamp(-12,100);*/

    
    /*TimeAutoDrive(1000,12);
    AtonDriveRamp(8,100);
    stopDriveHold();
    AtonTurn(-Nine-1);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(10,100);
    stopDriveHold();*/
    }

void SkillsTwo(){
    AutoIntakeEnabled = false;
    AtonDriveRamp(-35,100);
    //wait(500);
    AtonDriveRamp(31,100);

    TimeAutoDrive(500,40);
    AtonDriveRamp(-2,20);

    AtonTurn(-Nine-.25);
    AutoPuncherFiring = true;
    wait(500);

    //Brain.Screen.newLine();
    //Brain.Screen.print("start");
    AtonDriveRamp(-3,80);
    AtonTurn(-.25);
    //Brain.Screen.print("end");

    AutoPuncherFiring = true;
    wait(800);
    //AtonTurn(-2);
    AtonDriveRamp(-19,100);
    if(!BallInTop){
        AtonDriveRamp(55,100);
        AtonTurn(Nine+2);
        AtonDriveRamp(-2,100);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(-8,100);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(-6,100);
        stopDriveHold();
        wait(60000);
    }
    AtonTurn(-1);
    AtonDriveRamp(40,100);

    AtonTurn(Nine+.5);
    //TimeAutoDrive(800,50);
    AtonDriveRamp(-33,100);
    AtonTurn(-Nine);
    //TimeAutoDrive(800,40);

    AutoPuncherFiring = true;
    wait(500);
    AtonDriveRamp(-3,80);
    AutoPuncherFiring = true;
    wait(500);

    AtonDriveRamp(-10,100);
    TimeAutoDrive(1000,-30);

    AtonDriveRamp(18,100);
    AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonTurn(Nine+.5);
    wait(200);
    AtonDriveRamp(10,100);
    toggleWrist();
    AtonDriveRamp(-3,75);
    AtonTurn(-Nine-.5);
    AutoLift(200,50,true);

    AtonDriveRamp(22,100);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(8,100);
    stopDriveHold();
    AtonTurn(-Nine-1);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(10,100);
    stopDriveHold();
    AutoIntakeEnabled = false;

    /*AutoLift(250,50,true);
    AutoLift(0,50,true);
    AtonTurn(-4.5);
    AtonDriveRamp(6,100);
    AtonTurn(-3);
    AtonDriveRamp(6,100);
    toggleWrist();
    AtonDriveRamp(15,100);

    AtonTurn(4);

    AtonDriveRamp(25,100);

    /*
    AtonTurn(Nine+2);
    AtonDriveRamp(-6,100);
    wait(150);*/

    //
/*
    TimeAutoDrive(1000,12);
    AtonDriveRamp(8,100);
    stopDriveHold();
    AtonTurn(-Nine-1);
    TimeAutoDrive(1000,12);
    AtonDriveRamp(10,100);
    stopDriveHold();*/
}