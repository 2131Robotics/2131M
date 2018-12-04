void FirstTest(){
    
}

void BlueFront(){
    
    //WristLock();
    AtonDriveRamp(-33,100);
    IntakeAtonSet(true, 1);
    AtonDriveRamp(-9,100);
    vex::task::sleep(500);
    IntakeAtonSet(false, 1);
    AtonDriveRamp(66,100);
    TimeAutoDrive(250,60);
    IntakeAtonSet(false, 1);
    
    AtonDriveRamp(-3,100);
    AtonTurn(14);
    AtonDriveRamp(-.6,100);
    PunchAton(true);

    AtonTurn(1);
    IntakeAtonSet(true, 1);
    AtonDriveRamp(-12,100);
    PunchAton(true);
    IntakeAtonSet(false, 1);
    AtonTurn(1.5);
    AtonDriveRamp(-18.5,100);
/*
    toggleWrist();
    //AutoLift(30,50,true);
    toggleJaw();
    AtonDriveRamp(10,100);
    AtonTurn(10);
    toggleWrist();
    AtonDriveRamp(2.5,100);
    toggleJaw();
    vex::task::sleep(500);
    toggleWrist();
    
    toggleJaw();
    vex::task::sleep(500);
    toggleJaw();*/
}

void BlueBack(){
    
    PunchAton(true);
    IntakeAtonSet(true, 1);
    AtonTurn(-7);
    toggleWrist();
    
    TimeAutoDrive(100,60);
    AtonDriveRamp(-33,100);
    AtonDriveRamp(-9,100);
    vex::task::sleep(250);
    IntakeAtonSet(true, 1);
    vex::task::sleep(250);
    IntakeAtonSet(false, 1);
    
    AtonTurn(10);
    setJawPower(100);
    AtonDriveRamp(17.5,100);
    setJawPower(0);
    
    AutoLift(250,50,true);
    vex::task::sleep(500);
    setJawPower(100);
    vex::task::sleep(500);
    setJawPower(0);
    AutoLift(0,50,true);
    
    AtonTurn(8);
    AtonDriveRamp(-10,100);
    AtonTurn(-8);
    AtonDriveRamp(-44,100);
    driveLock();
}

void RedFront(){
        
    //WristLock();
    AtonDriveRamp(-33,100);
    IntakeAtonSet(true, 1);
    AtonDriveRamp(-9,100);
    vex::task::sleep(500);
    IntakeAtonSet(false, 1);
    AtonDriveRamp(66,100);
    TimeAutoDrive(250,60);
    IntakeAtonSet(false, 1);
    
    AtonDriveRamp(-3,100);
    AtonTurn(-14);
    AtonDriveRamp(-.6,100);
    PunchAton(true);

    AtonTurn(-1);
    IntakeAtonSet(true, 1);
    AtonDriveRamp(-12,100);
    PunchAton(true);
    IntakeAtonSet(false, 1);
    AtonTurn(-1.5);
    AtonDriveRamp(-18.5,100);
/*
    toggleWrist();
    //AutoLift(30,50,true);
    toggleJaw();
    AtonDriveRamp(10,100);
    AtonTurn(-10);
    toggleWrist();
    AtonDriveRamp(2.5,100);
    toggleJaw();
    vex::task::sleep(500);
    toggleWrist();
    
    toggleJaw();
    vex::task::sleep(500);
    toggleJaw();*/
}

void RedBack(){
    PunchAton(true);
    IntakeAtonSet(true, 1);
    AtonTurn(7);
    toggleWrist();
    
    TimeAutoDrive(100,60);
    AtonDriveRamp(-33,100);
    AtonDriveRamp(-9,100);
    vex::task::sleep(250);
    IntakeAtonSet(true, 1);
    vex::task::sleep(250);
    IntakeAtonSet(false, 1);
    
    AtonTurn(-10);
    //setJawPower(100);
    AtonDriveRamp(17.5,100);
    //setJawPower(0);
    
    AutoLift(250,50,true);
    vex::task::sleep(500);
    //setJawPower(100);
    vex::task::sleep(500);
    //setJawPower(0);
    AutoLift(0,50,true);
    
    AtonTurn(-8);
    AtonDriveRamp(-10,100);
    AtonTurn(8);
    AtonDriveRamp(-44,100);
    driveLock();
}