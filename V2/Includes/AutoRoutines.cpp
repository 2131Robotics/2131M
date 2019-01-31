/*testing*/
    void test(){
        toggleWrist();
        wait(500);
        toggleWrist();
        // TimeAutoDrive(10000,-1);
        // AutoIntakeEnabled = false;
        // wait(500);
        // AutoIntakeEnabled = true;
        // wait(10000);
    }
/**/
/*blue*/
    //Normal
        void FrontBlue(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(300);
            // AutoMan=true;

            AtonDriveRamp(800,100); 
            // AutoMan=true;
            wait(450);
            // AutoMan=false;
            // AutoIntakeOff = false;
            AtonDriveRamp(-800,100);
            wait(1);
            TimeAutoDrive(350,-50);
            wait(50);
            AtonDriveRamp(60,75);  
            AtonTurn(NineM-3);
            // AtonDriveRamp(25,75);  
            // SlideRecon(1000, 60, -1);
            // wait(500);
            // AtonSlide(4);

            AutoCataFiring = true;
            wait(450);

            AtonDriveRamp(400,100);
            wait(250);
            SlideRecon(300, -50, -1);
            wait(300);
            AtonDriveRamp(300,100);
            TimeAutoDrive(450,40);
            SlideRecon(200, -60, 1);
            wait(200);
            AtonDriveRamp(-300,100);
            AtonTurn(-NineM+1.5);

            AutoIntakeOff = true;
            AutoFlip = true;

            AtonDriveRamp(450,100);
            AutoFlip = false;
            AutoIntakeOff = false;

            AtonTurn(NineM-3);
            AutoCataFiring = true;
        }

        void BackBlue(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(350);
            AtonDriveRamp(1000,65);  
            wait(500);
            AtonDriveRamp(-50,100);
            AtonSlide(-350);

            AutoIntakeOff = true;
            AutoFlip = true;
            wait(200);

            AtonDriveRamp(210,100);
            wait(500);
            // AtonDriveRamp(-80,100);
            AutoIntakeOff = false;
            AutoFlip = false;
            SlideRecon(800, -40, 1);
            wait(500);
            AtonSlide(100);
            AtonTurn(-NineM+2);
            liftRotateTo(350);

            AtonDriveRamp(-300,75);
            wait(800);
            TimeAutoDrive(800,-15);
            AtonDriveRamp(-450,100);
            MechDriveLock();
        }
    //Parking
        void ParkFrontBlue(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(500);

            AtonDriveRamp(900,75); 
            wait(450);
            AtonDriveRamp(50,50);
            AtonDriveRamp(-70,75);
            AtonTurn(NineM+3);
            // AtonSlide(-4);

            AutoIntakeOff = true;
            AutoFlip = true;
            
            AtonDriveRamp(300,100);

            AtonDriveRamp(-25,75);

            AtonTurn(-NineM+6);
            AutoFlip = false;
            AutoIntakeOff = false;

            AutoCataFiring = true;
            wait(600);
            liftRotateTo(350);
            AtonDriveRamp(280,70);
            AtonTurn(4);
            // AtonSlide(2);
            AtonDriveRamp(-650,100);

            TimeAutoDrive(1300,-15);
            AtonDriveRamp(-300,100);
            MechDriveLock();
            AutoIntakeOff = true;
            liftRotateTo(450);
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
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(500);

            AtonDriveRamp(900,75); 
            AtonDriveRamp(50,50);
            AtonDriveRamp(-70,75);

            MechDriveLock();
            AutoIntakeOff = true;
            wait(9000);
            AutoIntakeOff = false;
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(NineM-7);
            AtonDriveRamp(75,75);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackBlue(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(350);
            AtonDriveRamp(1000,65);  
            AtonDriveRamp(-20,100);
            wait(500);
            AtonDriveRamp(-700,100);
            AtonTurn(NineM+1);
            AtonDriveRamp(1100,100);
            wait(250); 
            SlideRecon(1000, -60, -1);
            wait(500);
            AtonSlide(-80,75);
            
            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(300,100);
            wait(100);  
            SlideRecon(300, -50, -1);
            wait(300);
            AtonDriveRamp(250,100);
            TimeAutoDrive(800,30);
            SlideRecon(500, 60, 1);
            TimeAutoDrive(800,30);
        }
/**/
/*red*/
    //Normal
        void FrontRed(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;//allready
            wait(300);
            // AutoMan=true;

            AtonDriveRamp(800,100); 
            // AutoMan=true;
            wait(450);
            // AutoMan=false;
            // AutoIntakeOff = false;
            AtonDriveRamp(-800,100);
            wait(1);
            TimeAutoDrive(350,-50);
            wait(50);
            AtonDriveRamp(70,75);  
            AtonTurn(-NineM);
            // AtonDriveRamp(25,75);  
            // SlideRecon(1000, 60, -1);
            // wait(500);
            // AtonSlide(4);

            AutoCataFiring = true;
            wait(450);

            AtonDriveRamp(400,100);
            wait(250);
            SlideRecon(300, 50, -1);
            wait(300);
            AtonDriveRamp(300,100);
            TimeAutoDrive(450,40);
            SlideRecon(300, 60, 1);
            // TimeAutoDrive(800,30);
            AtonDriveRamp(-300,100);
            AtonTurn(NineM+1.5);

            AutoIntakeOff = true;
            AutoFlip = true;

            AtonDriveRamp(450,100);
            AutoFlip = false;
            AutoIntakeOff = false;

            AtonTurn(-NineM+4);
            AutoCataFiring = true;
        }

        void BackRed(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(350);
            AtonDriveRamp(1000,65);  
            wait(500);
            AtonDriveRamp(-50,100);
            AtonSlide(210);

            AutoIntakeOff = true;
            AutoFlip = true;
            wait(200);

            AtonDriveRamp(210,100);
            wait(500);
            AtonDriveRamp(-130,100);
            AutoIntakeOff = false;
            AutoFlip = false;
            SlideRecon(700, 40, 1);
            wait(500);
            AtonSlide(-100);
            AtonTurn(NineM);
            liftRotateTo(350);

            AtonDriveRamp(-300,75);
            wait(800);
            TimeAutoDrive(400,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
        }
    //Parking
        void ParkingFrontRed(){
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(500);

            AtonDriveRamp(750,75); 
            wait(450);
            AtonDriveRamp(80,50);
            wait(300);
            AtonDriveRamp(-50,75);
            AtonTurn(-NineM-3);
            // AtonSlide(-4);

            AutoIntakeOff = true;
            AutoFlip = true;
            
            AtonDriveRamp(260,100);

            AtonDriveRamp(-25,75);

            AtonTurn(NineM-6);
            AutoFlip = false;
            AutoIntakeOff = false;

            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(320,70);
            AtonTurn(-NineM+8.5);
            liftRotateTo(280);
            // AtonSlide(2);
            AtonDriveRamp(-650,100);

            TimeAutoDrive(1300,-8);
            AtonDriveRamp(-300,100);
            MechDriveLock();
            AutoIntakeOff = true;
            liftRotateTo(0);
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
            AutoIntakeEnabled = true;
            AutoIntakeOff = false;
            wait(500);

            AtonDriveRamp(900,75); 
            AtonDriveRamp(50,50);
            AtonDriveRamp(-70,75);

            MechDriveLock();
            AutoIntakeOff = true;
            wait(9000);
            AutoIntakeOff = false;
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(-NineM+7);
            AtonDriveRamp(75,75);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackRed(){
            AutoIntakeEnabled = true;
            AtonDriveRamp(1000,100);
            wait(200);
            AtonDriveRamp(-900,100);
            AtonTurn(-NineM+5);
            AtonDriveRamp(1100,100);
            wait(250); 
            SlideRecon(1000, 60, -1);
            wait(500);
            AtonSlide(130,75);
            
            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(300,100);
            wait(100);  
            SlideRecon(300, 50, -1);
            wait(300);
            AtonDriveRamp(250,100);
            TimeAutoDrive(800,30);
            SlideRecon(500, 60, 1);
            TimeAutoDrive(800,30);
        }

/**/
/*skills*/
    void Skills(){
        vex::task WristCalibration(WristCal);
        AtonDriveRamp(1000,100);
        wait(200);
        AutoIntakeEnabled = true;
        wait(200);
        AtonDriveRamp(-900,100);
        AtonTurn(-NineM+5);
        AtonDriveRamp(1000,100);
        wait(250); 
        SlideRecon(1100, 60, -1);
        wait(500);
        AtonSlide(100,75);
        
        AutoCataFiring = true;
        wait(600);
        AtonDriveRamp(300,100);
        wait(100);  
        SlideRecon(300, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(800,30);

        //-----------2rd Row of Flags--------------//
        AtonDriveRamp(-1020,100);
        AtonTurn(NineM-1);
        TimeAutoDrive(800,-50);
        wait(400);
        
        AutoIntakeOff = true;
        AtonDriveRamp(910,100);
        wait(200);
        AutoIntakeOff = false;
        wait(200);
        AtonDriveRamp(-40,100);
        AutoIntakeOff = false;
        AtonTurn(-NineM+5);
        wait(200);
        AtonDriveRamp(30,75);

        AutoCataFiring = true;
        wait(400);
        AtonDriveRamp(410,100);
        wait(100);
        AtonTurn(-5);
        wait(300);
        // SlideRecon(400, 50, -1);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(1000,30);
        wait(200);

        //-----------3rd Row of Flags--------------//
        AtonDriveRamp(-400,100);
        AtonTurn(-NineM+5);
        AtonDriveRamp(-1000,100);
        liftRotateTo(350);
        toggleWrist();
        wait(300);

        AtonSlide(-360,75);
        liftRotateTo(0);
        wait(200);
        AutoIntakeOff = true;
        AtonDriveRamp(360,100);
        wait(300);
        AutoIntakeOff = false;
        SlideRecon(1000, 60, -1);
        wait(100);

        AtonDriveRamp(-300,100);
        AtonTurn(NineM);
        AtonDriveRamp(50,75);
        liftRotateTo(350);
        AutoCataFiring = true;
        wait(400);
        AtonDriveRamp(300,100);
        wait(100);  
        SlideRecon(300, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(800,30);

        //-----------Parking------------//
        AtonDriveRamp(-65,75);
        AutoCataFiring = true;
        wait(500);
        AtonDriveRamp(-780,100);
        wait(300);
        AtonSlide(-310,75);
        wait(250);

        TimeAutoDrive(500,-8);
        wait(200);
        AtonDriveRamp(-420,100);
        MechDriveLock();
        AtonTurn(NineM+1);
        TimeAutoDrive(700,-15);
        AtonDriveRamp(-400,100);
        MechDriveLock();
        AutoIntakeOff = true;
    }
/**/
/*Other*/
    //User Functions
/**/