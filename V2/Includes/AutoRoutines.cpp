/*testing*/
    void test(){
        AtonDriveRamp(50,75);
        wait(200);
        AtonTurn(15); 
        wait(200);
        AtonDriveRamp(50,75);
        wait(200);
        AtonTurn(15); 
        wait(200);
        AtonDriveRamp(50,75);
        wait(200);
        AtonTurn(15); 
        wait(200);
        AtonDriveRamp(50,75);
        wait(200);
        AtonTurn(15); 
    }
/**/
/*blue*/
    //Normal
        void FrontBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(400);
            AtonDriveRamp(-900,100);
            TimeAutoDrive(350,-50);
            wait(50);   
            AtonDriveRamp(65,75);  
            AtonTurn(NineM-2);

            AutoCataFiring = true;
            wait(450);

            AtonDriveRamp(400,100);
            wait(250);
            SlideRecon(200, 50, 1);
            wait(300);
            AtonDriveRamp(300,100);
            TimeAutoDrive(350,40);
            SlideRecon(300, 60, -1);
            // TimeAutoDrive(800,30);
            AtonDriveRamp(-350,100);
            AtonTurn(-NineM-1.5);

            AutoIntakeOff = true;
            AutoFlip = true;

            AtonDriveRamp(450,100);
            AutoFlip = false;
            AutoIntakeOff = false;

            AtonTurn(NineM-5);
            AtonDriveRamp(-25,75);
            AutoCataFiring = true;
        }

        void BackBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(NineM+3);
            AtonDriveRamp(-230,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();

            AtonDriveRamp(100,75);
            liftRotateTo(350);
            wait(100);
            AtonTurn(NineM+7);
            AtonDriveRamp(-100,75);

            TimeAutoDrive(550,-15);
            AtonDriveRamp(-350,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Parking
        void ParkFrontBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(500);
            AtonDriveRamp(-15,75);
            AtonTurn(-NineM+8);
            
            AtonDriveRamp(-250,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();
            AtonDriveRamp(25,75);

            AtonTurn(NineM+2);
            AutoFlip = false;
            AutoIntakeOff = false;

            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(180,70);
            AtonTurn(NineM-13);
            liftRotateTo(280);
            AtonDriveRamp(-670,100);

            TimeAutoDrive(1300,-8);
            AtonDriveRamp(-300,100);
            MechDriveLock();
            AutoIntakeOff = true;
            liftRotateTo(0);
        }

        void ParkBackBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1050,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(NineM+3);
            AtonDriveRamp(-150,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();

            AtonDriveRamp(60,75);
            liftRotateTo(350);
            wait(100);
            AtonTurn(-NineM+8);
            AtonDriveRamp(15,75);
            wait(500);//
            AutoCataFiring = true;
            wait(500);
            AtonTurn(-NineM-8);
            wait(200);

            // AtonSlide(-75,75);
            AtonDriveRamp(-100,100);
            TimeAutoDrive(550,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Sniper
        void SniperFrontBlue(){
        }

        void SniperBackBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(950,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(NineM+3);
            AtonDriveRamp(-250,100);
            wait(400);
            liftRotateTo(150);
            AtonDriveRamp(25,75);
            wait(500);

            AtonDriveRamp(100,100);
            AtonTurn(-2);
            // AtonDriveRamp(-100,100);
            // wait(200);
            // AtonDriveRamp(25,75);
            wait(100);
            WristMotorInverted=!WristMotorInverted;
            setWristPower(WristMotorInverted ? -100 : 100);
            vex::task::sleep(800);
            setWristPower(0);
            //wait(500);
            // AtonDriveRamp(150,100);
            liftRotateTo(1200);
            AtonSlide(130,75);
            wait(300);
            AtonDriveRamp(-150,75);
            TimeAutoDrive(300,-50);
            wait(500);
            //place
            DI(30,30);
            wait(200);
            setLiftPower(-40);
            wait(600);
            setLiftPower(0);
            wait(400);
            DI(0,0);
            
            AtonDriveRamp(80,100);
            liftRotateTo(200);
            AtonSlide(-300,75);
            AtonTurn(-FullM+2);
            AtonDriveRamp(-25,75);

            TimeAutoDrive(550,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Other
        void OtherFrontBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(500);
            AtonDriveRamp(-50,75);
            liftRotateTo(280);
            wait(9800);
            AutoIntakeOff = false;
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(NineM-7);
            AtonDriveRamp(75,75);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackBlue(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;
            AtonDriveRamp(1100,80);  
            wait(500);
            AutoIntakeEnabled = true;
            wait(200);
            AtonDriveRamp(-750,100);
            TimeAutoDrive(500,-50);
            wait(150);   
            AtonDriveRamp(20,75);  
            AtonTurn(NineM-2.5);
            // TimeAutoDrive(800,-50);
            // wait(200);
            AtonDriveRamp(1200,100);
            wait(250); 
            
            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(300,100);
            wait(100);  
            SlideRecon(250, 50, 1);
            wait(300);
            AtonDriveRamp(250,100);
            TimeAutoDrive(800,30);
            SlideRecon(500, 60, 1);
            TimeAutoDrive(500,30);
        }
/**/
/*red*/
    //Normal
        void FrontRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(400);
            AtonDriveRamp(-900,100);
            TimeAutoDrive(350,-50);
            wait(50);   
            AtonDriveRamp(22,75);  
            AtonTurn(-NineM+2);
            // AtonDriveRamp(8,75);  
            AutoCataFiring = true;
            wait(450);

            AtonDriveRamp(400,100);
            wait(250);
            SlideRecon(300, 50, -1);
            wait(300);
            AtonDriveRamp(300,100);
            TimeAutoDrive(350,40);
            SlideRecon(300, 60, 1);
            TimeAutoDrive(400,30);
            AtonDriveRamp(-350,100);
            AtonTurn(NineM+1.5);

            AutoIntakeOff = true;
            AutoFlip = true;

            AtonDriveRamp(450,100);
            AutoFlip = false;
            AutoIntakeOff = false;

            AtonTurn(-NineM+5);
            AutoCataFiring = true;
            AtonDriveRamp(-25,75);
            // AutoCataFiring = true;
        }

        void BackRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1050,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(-NineM-4);
            AtonDriveRamp(-200,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();

            AtonDriveRamp(100,75);
            liftRotateTo(350);
            wait(100);
            AtonTurn(-NineM-7);
            AtonDriveRamp(-100,75);

            TimeAutoDrive(550,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Parking
        void ParkingFrontRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(500);
            AtonDriveRamp(-15,75);
            AtonTurn(NineM-8);
            
            AtonDriveRamp(-250,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();
            AtonDriveRamp(18,75);

            AtonTurn(-NineM-3);
            AutoFlip = false;
            AutoIntakeOff = false;

            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(150,70);
            AtonTurn(-NineM+12);
            liftRotateTo(280);
            AtonDriveRamp(-650,100);

            TimeAutoDrive(1300,-8);
            AtonDriveRamp(-300,100);
            MechDriveLock();
            AutoIntakeOff = true;
            liftRotateTo(0);
        }

        void ParkingBackRed(){ // not done
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1050,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(-NineM-4);
            AtonDriveRamp(-180,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();

            AtonDriveRamp(65,75);
            liftRotateTo(350);
            wait(100);
            AtonTurn(NineM-6.5);
            AtonDriveRamp(15,75);
            wait(500);//
            AutoCataFiring = true;
            wait(500);
            AtonTurn(NineM+8);
            wait(200);

            AtonSlide(75,75);
            AtonDriveRamp(-100,100);
            TimeAutoDrive(550,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Sniper
        void SniperFrontRed(){
        }

        void SniperBackRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(950,80);  
            wait(500);
            AtonDriveRamp(-75,100);
           
            AtonTurn(-NineM-3);
            AtonDriveRamp(-250,100);
            wait(400);
            liftRotateTo(150);
            AtonDriveRamp(25,75);
            wait(500);

            AtonDriveRamp(100,100);
            AtonTurn(2);
            // AtonDriveRamp(-100,100);
            // wait(200);
            // AtonDriveRamp(25,75);
            wait(100);
            WristMotorInverted=!WristMotorInverted;
            setWristPower(WristMotorInverted ? -100 : 100);
            vex::task::sleep(800);
            setWristPower(0);
            //wait(500);
            // AtonDriveRamp(150,100);
            liftRotateTo(1200);
            AtonSlide(-130,75);
            wait(300);
            AtonDriveRamp(-150,75);
            TimeAutoDrive(300,-50);
            wait(500);
            //place
            DI(30,30);
            wait(200);
            setLiftPower(-40);
            wait(600);
            setLiftPower(0);
            wait(400);
            DI(0,0);
            
            AtonDriveRamp(80,100);
            liftRotateTo(200);
            AtonSlide(300,75);
            AtonTurn(FullM-2);
            AtonDriveRamp(-25,75);

            TimeAutoDrive(550,-15);
            AtonDriveRamp(-400,100);
            MechDriveLock();
            liftRotateTo(0);
        }
    //Other
        void OtherFrontRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1000,80);  
            wait(500);
            AtonDriveRamp(-60,75);
            liftRotateTo(280);
            wait(9500);
            AutoIntakeOff = false;
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(-NineM+7);
            AtonDriveRamp(75,75);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackRed(){
            vex::task WristCalibration(WristCal);
            AutoIntakeEnabled = true;

            AtonDriveRamp(1050,80);  
            wait(500);
            AtonDriveRamp(-75,100);
            
            AtonTurn(-NineM-4);
            AtonDriveRamp(-160,100);
            WristMotorInverted=!WristMotorInverted;
            FLIP();

            AtonDriveRamp(200,100);

            AtonTurn(NineM+4);

            AtonDriveRamp(-800,100);
                TimeAutoDrive(500,-50);
                wait(150);   
                AtonDriveRamp(15,75);  
                AtonTurn(-NineM+2);
                // TimeAutoDrive(800,-50);
                // wait(200);
            AtonDriveRamp(1100,100);
            wait(250); 
            
            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(300,100);
            wait(100);  
            SlideRecon(320, 50, -1);
            wait(300);
            AtonDriveRamp(250,100);
        }

/**/
/*skills*/
    void Skills(){
        vex::task WristCalibration(WristCal);
        AtonDriveRamp(900,100);
        wait(200);
        AutoIntakeEnabled = true;
        wait(200);

        AtonDriveRamp(-75,100);
        
        AtonTurn(-NineM-4);
        AtonDriveRamp(-160,100);
        WristMotorInverted=!WristMotorInverted;
        FLIP();

        AtonDriveRamp(200,100);

        AtonTurn(NineM+4);

        AtonDriveRamp(-800,100);
            TimeAutoDrive(500,-50);
            wait(150);   
            AtonDriveRamp(15,75);  
            AtonTurn(-NineM+2);
            // TimeAutoDrive(800,-50);
            // wait(200);
        AtonDriveRamp(940,100);
        wait(250);
        AtonTurn(.5); 
        
        AutoCataFiring = true;
        wait(600);
        AtonDriveRamp(300,100);
        wait(100);  
        SlideRecon(320, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(500,30);

        //-----------2rd Row of Flags--------------//
        AtonDriveRamp(-1100,100);
        AtonTurn(NineM-1);
        TimeAutoDrive(800,-50);
        wait(400);
        
        AutoIntakeOff = true;
        AtonDriveRamp(910,100);
        wait(200);
        AutoIntakeOff = false;
        wait(200);
        AtonDriveRamp(-50,100);
        AutoIntakeOff = false;
        AtonTurn(-NineM+4.5);
        wait(200);
        // AtonDriveRamp(15,75);

        AutoCataFiring = true;
        wait(400);
        AtonDriveRamp(420,100);
        wait(100);
        AtonTurn(-2);
        wait(300);
        // SlideRecon(400, 50, -1);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(750,30);
        wait(200);

        //-----------3rd Row of Flags--------------//
        AtonDriveRamp(-370,100);
        AtonTurn(-NineM+1);

        AutoIntakeOff = true;
        AutoFlip = true;

        AtonDriveRamp(500,100);
        AutoFlip = false;
        AutoIntakeOff = false;

        AtonDriveRamp(-1700,100);
        liftRotateTo(350);
        toggleWrist();
        wait(100);
        liftRotateTo(0);
        wait(100);

        AtonDriveRamp(70,100);
        AtonSlide(-300,75);
        wait(200);
        AutoIntakeOff = true;
        AtonDriveRamp(200,100);
        wait(300);
        AutoIntakeOff = false;
        SlideRecon(1000, 60, -1);
        wait(100);

        AtonDriveRamp(-260,100);
        // TimeAutoDrive(850,-50);
        // wait(300);
        // AtonDriveRamp(200,100);
        wait(200);
        AtonTurn(NineM-2);
        AtonDriveRamp(50,75);
        // liftRotateTo(350);
        AutoCataFiring = true;
        wait(400);
        AtonDriveRamp(300,100);
        wait(100);
        SlideRecon(450, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(800,30);

        //-----------Parking------------//
        // AtonDriveRamp(-200,75);
        // AutoCataFiring = true;
        // wait(500);
        AtonDriveRamp(-1000,100);
        liftRotateTo(350);
        wait(300);
        AtonSlide(-290,80);
        wait(250);

        TimeAutoDrive(1000,-8);
        wait(200);
        AtonDriveRamp(-440,100);
        MechDriveLock();
        AtonTurn(NineM-1);
        TimeAutoDrive(700,-15);
        AtonDriveRamp(-400,100);
        MechDriveLock();
        AutoIntakeOff = true;
    }
/**/
/*Other*/
    //User Functions
/**/