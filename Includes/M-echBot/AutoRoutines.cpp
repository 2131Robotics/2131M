void test(){
    AtonTurn(NineM);
    wait(500);
    AtonTurn(-NineM);
    wait(500);
}

void FrontBlue(){
    AtonDriveRamp(30,100);  
    wait(250);
    AtonDriveRamp(-22,100);
    wait(1);

    AtonTurn(NineM-3);
    //AtonDriveRamp(-4,100);

    AutoCataFiring = true;
    wait(500);

    AtonDriveRamp(30,100);
    AtonTurn(11);
    AtonDriveRamp(-6,100);

    autoRamFlip();
    AtonDriveRamp(6,100);
}

void BackBlue(){
    AtonDriveRamp(35,100);
    wait(250);

    AtonTurn(NineM);
    //AtonDriveRamp(-4,100);

    //AutoCataFiring = true;
    //wait(500);

    AtonDriveRamp(-3,100);

    autoRamFlip();
    AtonDriveRamp(3,100);

    SlideRecon(800, 40, 1);
    RamRodPos(250);
    AtonTurn(-FullM);

    //AtonDriveRamp(-1,100);
    TimeAutoDrive(1500,-20);
    AtonDriveRamp(-10,100);
    stopDriveHold();
}

void FrontRed(){
    AtonDriveRamp(30,100);  
    wait(250);
    AtonDriveRamp(-22,100);
    wait(1);

    AtonTurn(-NineM+3);
    //AtonDriveRamp(-4,100);

    AutoCataFiring = true;
    wait(500);

    AtonDriveRamp(30,100);
    AtonTurn(-11);
    AtonDriveRamp(-6,100);

    autoRamFlip();
    AtonDriveRamp(6,100);
}

void BackRed(){
    AtonDriveRamp(35,100);
    wait(250);

    AtonTurn(-NineM);
    //AtonDriveRamp(-4,100);

    //AutoCataFiring = true;
    //wait(500);

    AtonDriveRamp(-3,100);

    autoRamFlip();
    AtonDriveRamp(3,100);

    SlideRecon(800, 40, -1);
    RamRodPos(250);
    AtonTurn(FullM);

    //AtonDriveRamp(-1,100);
    TimeAutoDrive(1500,-20);
    AtonDriveRamp(-10,100);
    stopDriveHold();
}

void Skills(){

    AtonDriveRamp(35,100);
    wait(250);
    AtonDriveRamp(-29,100);
    wait(250);
    AtonTurn(-NineM+1.5);

    //SlideRecon(800, 80, -1);
    //SlideRecon(500, 80, 1);

    AtonDriveRamp(32,100);
    wait(250);  
    AutoCataFiring = true;
    wait(600);
    AtonDriveRamp(20,100);
    wait(100);  
    AtonTurn(-3);
    AtonDriveRamp(18,100);
    TimeAutoDrive(800,30);

    AtonDriveRamp(-34,100);
    //AtonDriveRamp(-4,100);
    wait(700);

    /*if(!BallInTop){ //park if unsecsessfull grabbing a ball
        AtonDriveRamp(-10,100);
        AtonTurn(NineM+2);
        AtonDriveRamp(2,100);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(8,100);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(6,100);
        stopDriveHold();
        wait(60000);
    }*/

    AtonTurn(NineM-1.5);
    AtonDriveRamp(36,100);
    RamRodPos(250);
    AtonTurn(-NineM-1);

    //AtonDriveRamp(33,100);
    wait(500);
    AutoCataFiring = true;
    wait(500);
    RamRodPos(50);
    AtonDriveRamp(30,100);
    TimeAutoDrive(1000,30);

    AtonDriveRamp(-13,100);
    AtonTurn(NineM+0);
    //wait(200);
    AtonDriveRamp(-6,100);

    autoRamFlip();

    AtonDriveRamp(3,50);
    AtonTurn(-NineM+1);
    RamRodPos(250);

    AtonDriveRamp(-22,100);
    TimeAutoDrive(1000,-12);
    AtonDriveRamp(-10,100);
    stopDriveHold();
    AtonTurn(-NineM+1.5);
    TimeAutoDrive(1000,-12);
    AtonDriveRamp(-15,100);
    stopDriveHold();
}