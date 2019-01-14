/*testing*/
    void test(){
        
        liftRotateTo(250);
        vex::task::sleep(500);

        setWristPower(100);
        liftRotateTo(0);

        vex::task::sleep(300);
        setWristPower(0);
        WristCalibrated=true;
        WristMotor.resetRotation();

        /*AtonSlide(5);
        wait(500);
        AtonSlide(-5);
        wait(500);*/
        
        /*AtonDriveRamp(10,100);  
        wait(500);
        AtonSlide(1800);
        wait(500);
        AtonDriveRamp(-10,100);  
        wait(500);
        AtonSlide(-1800);
        wait(500);

        AtonTurn(NineM);
        wait(500);
        AtonSlide(1800);
        wait(500);
        AtonTurn(-NineM);
        wait(500);
        AtonSlide(-1800);
        wait(500);*/
    }
/**/
/*blue*/
    //Normal
        void FrontBlue(){
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-23,100);
            wait(1);

            AtonTurn(NineM+2);
            AtonDriveRamp(1,75);
            //AtonDriveRamp(-4,100);

            AutoCataFiring = true;
            wait(500);

            AtonDriveRamp(30,100);
            AtonTurn(9);
            AtonDriveRamp(-6,100);

            // autoRamFlip();
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

            //autoRamFlip();
            AtonDriveRamp(3,100);

            SlideRecon(500, 40, 1);
            RamRodPos(250);
            AtonTurn(-FullM);

            //AtonDriveRamp(-1,100);
            TimeAutoDrive(1500,-20);
            AtonDriveRamp(-10,100);
            stopDriveHold();
        }
    //Parking
        void ParkFrontBlue(){
        }

        void ParkBackBlue(){
        }
    //Sniper
        void SniperFrontBlue(){
        }

        void SniperBackBlue(){
        }
    //Other
        void OtherFrontBlue(){
        }

        void OtherBackBlue(){
        }
/**/
/*red*/
    //Normal
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

            // autoRamFlip();
            AtonDriveRamp(6,100);
        }

        void BackRed(){
            AtonDriveRamp(35,100);
            wait(250);

            AtonTurn(-NineM-.5);
            //AtonDriveRamp(-4,100);

            //AutoCataFiring = true;
            //wait(500);

            AtonDriveRamp(-3,100);

            // autoRamFlip();
            AtonDriveRamp(3,100);

            SlideRecon(600, 40, -1);
            RamRodPos(250);
            AtonTurn(FullM+.75);

            //AtonDriveRamp(-1,100);
            TimeAutoDrive(1500,-20);
            AtonDriveRamp(-10,100);
            stopDriveHold();
        }
    //Parking
        void ParkingFrontRed(){
        }

        void ParkingBackRed(){
        }
    //Sniper
        void SniperFrontRed(){
        }

        void SniperBackRed(){
        }
    //Other
        void OtherFrontRed(){
        }

        void OtherBackRed(){
        }

/**/
/*skills*/
    void Skills(){

        AtonDriveRamp(35,100);
        wait(250);
        AtonDriveRamp(-27.5,100);
        wait(250);
        AtonTurn(-NineM+1);

        //SlideRecon(800, 80, -1);
        //SlideRecon(500, 80, 1);

        AtonDriveRamp(38,100);
        wait(250); 

        SlideRecon(800, 40, -1);
        wait(500);
        SlideRecon(500, 40, 1);
        
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
        AtonDriveRamp(38,100);
        RamRodPos(250);
        AtonTurn(-NineM-2);

        //AtonDriveRamp(33,100);
        wait(500);
        AutoCataFiring = true;
        wait(500);

        AtonDriveRamp(20,100);
        wait(100);  
        AtonTurn(-3);
        AtonDriveRamp(18,100);
        TimeAutoDrive(800,30);
        RamRodPos(30);
        AutoCataFiring = true;

        AtonDriveRamp(-15,100);
        AtonTurn(NineM+.5);
        //wait(200);
        AtonDriveRamp(-3,100);

        // autoRamFlip();

        AtonDriveRamp(3,50);
        AtonTurn(-NineM+1);
        RamRodPos(250);

        AtonDriveRamp(-22,100);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(-15,100);
        stopDriveHold();
        AtonTurn(-NineM+1.5);
        TimeAutoDrive(1000,-12);
        AtonDriveRamp(-11,100);
        stopDriveHold();
    }
/**/
/*Other*/
    //User Functions
    void PlaceCap(){
        vex::task AtonDrive(Drive_Ramping);
        while(Controller1.Axis3.value()==0 || Controller1.Axis2.value()==0){
            liftRotateFor(-200,100);
            AtonDriveRamp(-5,75);
            wait(500);
            DriveRampingEnabled = false;
        }
    }
/**/