/*testing*/
    void test(){
        setIntakePower(100);
        wait(5000);
        setIntakePower(0);
        wait(5000);
        vex::task AutoIn(Auto_Intaking);
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
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-24,100);
            wait(1);
            TimeAutoDrive(1000,-50);
            wait(500);
            AtonDriveRamp(3,50);  
            AtonTurn(NineM-2);
            AtonDriveRamp(1,40);  
            // SlideRecon(1000, 60, -1);
            // wait(500);
            // AtonSlide(4);

            AutoCataFiring = true;
            wait(700);

            AtonSlide(1);
            AtonDriveRamp(30,100);
            TimeAutoDrive(800,30);
            // AtonSlide(3);
            // TimeAutoDrive(800,30);
            AtonDriveRamp(-6,100);
            AtonTurn(-NineM+2);
            AutoIntakeEnabled = false;
            setIntakePower(-100);

            AtonDriveRamp(12,100);
            AtonTurn(NineM-8);
            AutoCataFiring = true;
            setIntakePower(0);
        }

        void BackBlue(){
            AutoIntakeEnabled = false;
            setIntakePower(100);
            AtonDriveRamp(29,100);  
            wait(250);
            // vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(-4,100);
            AtonSlide(-12);
            setIntakePower(0);
            wait(200);
            AutoIntakeEnabled = false;
            setIntakePower(-100);

            AtonDriveRamp(10,100);
            AtonDriveRamp(-1,100);

            SlideRecon(1000, 60, -1);
            wait(500);
            AtonSlide(4);
            AtonTurn(-NineM+1);
            liftRotateTo(450);

            AtonDriveRamp(-13,100);
            wait(800);
            // TimeAutoDrive(1500,-20);
            AtonDriveRamp(-15,100);
            MechDriveLock();
        }
    //Parking
        void ParkFrontBlue(){
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-2,100);
            AtonTurn(NineM);
            // AtonSlide(-4);

            AutoIntakeEnabled = false;
            setIntakePower(-100);
            
            AtonDriveRamp(15,100);

            AtonDriveRamp(-2,100);

            AtonTurn(-NineM+9);
            AutoCataFiring = true;
            wait(700);
            liftRotateTo(450);
            AtonDriveRamp(2,100);
            AtonTurn(NineM-10);
            // AtonSlide(2);
            AtonDriveRamp(-26,100);

            TimeAutoDrive(1300,-15);
            AtonDriveRamp(-12,100);
            MechDriveLock();
            AutoIntakeEnabled = false;
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
            vex::task AutoIn(Auto_Intaking);
            TimeAutoDrive(1,-15);
            AtonDriveRamp(30,100); 
            MechDriveLock();
            wait(10500);
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(NineM-4);
            AtonDriveRamp(3,100);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackBlue(){
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-24,100);
            AtonTurn(NineM);

            AtonDriveRamp(42,100);
            wait(250); 

            SlideRecon(1000, 60, 1);
            wait(500);
            AtonSlide(-3);
            
            AutoCataFiring = true;
            wait(600);
            AtonSlide(2);
            AtonDriveRamp(24,100);
            wait(100);  
            AtonSlide(2);
            TimeAutoDrive(500,30);
            AtonDriveRamp(-24,100);
        }
/**/
/*red*/
    //Normal
        void FrontRed(){
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-24,100);
            wait(1);
            TimeAutoDrive(1000,-50);
            wait(500);
            AtonDriveRamp(3,50);  
            AtonTurn(-NineM+2);
            AtonDriveRamp(1,40);  
            // SlideRecon(1000, 60, -1);
            // wait(500);
            // AtonSlide(4);

            AutoCataFiring = true;
            wait(700);

            AtonSlide(-1);
            AtonDriveRamp(30,100);
            TimeAutoDrive(800,30);
            // AtonSlide(3);
            // TimeAutoDrive(800,30);
            AtonDriveRamp(-6,100);
            AtonTurn(NineM+4);
            AutoIntakeEnabled = false;
            setIntakePower(-100);

            AtonDriveRamp(9,100);
            AtonTurn(-NineM+4);
            AutoCataFiring = true;
            setIntakePower(0);
        }

        void BackRed(){
            AutoIntakeEnabled = false;
            setIntakePower(100);
            AtonDriveRamp(29,100);  
            wait(250);
            // vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(-5,100);
            AtonSlide(12);
            setIntakePower(0);
            wait(200);
            AutoIntakeEnabled = false;
            setIntakePower(-100);

            AtonDriveRamp(6,100);
            wait(500);
            AtonDriveRamp(-3,100);
            setIntakePower(0);
            SlideRecon(1000, 60, 1);
            wait(500);
            AtonSlide(-4);
            AtonTurn(NineM);
            liftRotateTo(450);

            AtonDriveRamp(-13,100);
            wait(800);
            // TimeAutoDrive(1500,-20);
            AtonDriveRamp(-16,100);
            MechDriveLock();
        }
    //Parking
        void ParkingFrontRed(){
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-2,100);
            AtonTurn(-NineM+1);
            // AtonSlide(-4);

            AutoIntakeEnabled = false;
            setIntakePower(-100);
            
            AtonDriveRamp(15,100);

            AtonDriveRamp(-2,100);

            AtonTurn(NineM-8);
            AutoCataFiring = true;
            wait(700);
            liftRotateTo(450);
            AtonDriveRamp(4,100);
            AtonTurn(-NineM+7);
            // AtonSlide(2);
            AtonDriveRamp(-26,100);

            TimeAutoDrive(1300,-15);
            AtonDriveRamp(-13,100);
            MechDriveLock();
            AutoIntakeEnabled = false;
            liftRotateTo(450);
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
            vex::task AutoIn(Auto_Intaking);
            TimeAutoDrive(1,-15);
            AtonDriveRamp(30,100); 
            MechDriveLock();
            wait(10500);
            DriveBrakeType = vex::brakeType::coast;
            setMechDrivePower(0,0,0,0);
            AtonTurn(-NineM+5);
            AtonDriveRamp(3,100);
            AutoCataFiring = true;
            wait(600);
        }

        void OtherBackRed(){
            vex::task AutoIn(Auto_Intaking);
            AtonDriveRamp(30,100);  
            wait(250);
            AtonDriveRamp(-24,100);
            AtonTurn(-NineM+4);

            AtonDriveRamp(42,100);
            wait(250); 

            SlideRecon(1000, 60, -1);
            wait(500);
            AtonSlide(4);
            
            AutoCataFiring = true;
            wait(600);
            AtonDriveRamp(22,100);
            wait(100);  
            AtonSlide(-2);
            AtonDriveRamp(2,100);
            TimeAutoDrive(800,30);
            wait(600);
            AtonSlide(3);
            TimeAutoDrive(500,30);

            AtonDriveRamp(-38,100);
        }

/**/
/*skills*/
    void Skills(){
        setIntakePower(100);
        wait(200);
        setIntakePower(0);
        AtonDriveRamp(1000,100);
        wait(200);
        vex::task AutoIn(Auto_Intaking);
        wait(200);

        AtonDriveRamp(-900,100);
        //wait(250);        
        AtonTurn(-NineM+5);

        AtonDriveRamp(1100,100);
        wait(250); 

        SlideRecon(1000, 60, -1);
        wait(500);
        AtonSlide(120,75);
        
        AutoCataFiring = true;
        wait(600);

        AtonDriveRamp(300,100);
        wait(100);  
        // AtonSlide(-70,80);
        SlideRecon(300, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(800,30);

        // wait(600);
        // AtonDriveRamp(-80,75);
        // AtonSlide(65);
        // AtonDriveRamp(200,100);
        // TimeAutoDrive(800,30);

        //-----------2rd Row of Flags--------------//
        AtonDriveRamp(-950,100);

        AtonTurn(NineM-1);
        TimeAutoDrive(800,-50);
        wait(400);
        
        // AutoIntakeEnabled = false;
        // setIntakePower(0);
        AtonDriveRamp(1080,100);
        wait(400);
        // setIntakePower(100);
        AtonTurn(-NineM+2);
        wait(200);
        // TimeAutoDrive(1200,-75);
        // wait(200);
        AtonDriveRamp(20,75);

        AutoCataFiring = true;
        wait(400);
        // setIntakePower(100);
        // vex::task AutoIn(Auto_Intaking);
        AtonDriveRamp(500,100);
        SlideRecon(400, 50, -1);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);
        SlideRecon(500, 60, 1);
        TimeAutoDrive(800,30);

        //-----------3rd Row of Flags--------------//

        AtonDriveRamp(-430,100);
        AtonTurn(-NineM+5);
        AtonDriveRamp(-1000,100);
        liftRotateTo(350);
        wait(300);
        AtonSlide(-350,75);

        AutoIntakeEnabled = false;
        setIntakePower(0);
        AtonDriveRamp(300,100);
        wait(300);
        setIntakePower(100);
        SlideRecon(1000, 60, -1);
        wait(100);
        AtonDriveRamp(-200,100);

        AtonTurn(NineM+1);

        AtonDriveRamp(50,75);

        AutoCataFiring = true;
        wait(400);

        AtonDriveRamp(300,100);
        wait(100);  
        // AtonSlide(-70,80);
        SlideRecon(300, 50, -1);
        wait(300);
        AtonDriveRamp(250,100);
        TimeAutoDrive(800,30);

        AtonDriveRamp(-1000,100);
        wait(250);
        AtonSlide(150,75);
        wait(250);
        AtonDriveRamp(-350,100);
        AtonTurn(NineM);
        TimeAutoDrive(1000,-18);
        AtonDriveRamp(-1500,100);
        // MechDriveLock();
        // AtonTurn(NineM-3);
        // TimeAutoDrive(1000,-15);
        // AtonDriveRamp(-1200,100);
        MechDriveLock();
        AutoIntakeEnabled = false;

        // wait(200);
        // AtonSlide(-65);
        // wait(400);
        // TimeAutoDrive(1200,50);
        /*
        AtonDriveRamp(-1,100);
        AtonSlide(-4);
        liftRotateTo(450);
        TimeAutoDrive(1000,50);

        AtonDriveRamp(-48,100);
        TimeAutoDrive(1000,-15);
        AtonDriveRamp(-13,100);
        MechDriveLock();
        AtonTurn(-NineM+4);
        TimeAutoDrive(1000,-15);
        AtonDriveRamp(-16,100);
        MechDriveLock();
        AutoIntakeEnabled = false;*/
    }
/**/
/*Other*/
    //User Functions
/**/