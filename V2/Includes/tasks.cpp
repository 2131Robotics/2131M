/*Background Functions*/
    //---------------------Auto Catapult-----------------------//
        bool Charged=false;
        int ChargeSenseValue;
        int ChargeMaxValue = 30;
        bool AutoCataFiring=true;

        void catapultChargeFire(){
            ChargeSenseValue = ChargeLightSensor.value(vex::percentUnits::pct);

            if (ChargeSenseValue < ChargeMaxValue) Charged = true;

            if (Controller1.ButtonL1.pressing() && !DriveDirInverted) {

                DriveBrakeType = vex::brakeType::hold;
                setMechDrivePower(0,0,0,0);
                Charged = false;
                setCatapultPower(100);
            }
            if(AutoCataFiring){
                setCatapultPower(100);
                
                //wait till gone
                vex::task::sleep(900);
                AutoCataFiring = false;
                setCatapultPower(0);
                Charged = false;
            }

            else {
                DriveBrakeType = vex::brakeType::coast;

                if(!Charged){
                    // AutoIntakeEnabled = false;
                    setCatapultPower(100); 
                }
                if(Charged){
                    // AutoIntakeEnabled = true;
                    setCatapultPower(0);
                }
            }

        }

    //---------------------Auto Intake-----------------------//
        int	BottomLightValue;
        int TopLightValue;
        int BottomBallInMax = 40;
        int TopBallInMax = 40;

        bool BallInBottom;
        bool BallInTop;

        void Auto_Intake() { //with catapult
            BottomLightValue = BallSenseBottom.value(vex::percentUnits::pct);
            TopLightValue = BallSenseTop.value(vex::percentUnits::pct);

            ChargeSenseValue = ChargeLightSensor.value(vex::percentUnits::pct);
            
            if (BottomLightValue < BottomBallInMax) BallInBottom = true;
            else BallInBottom = false;

            if (TopLightValue < TopBallInMax) BallInTop = true;
            else BallInTop = false;

            if(AutoIntakeOff){
                setIntakePower(-5);
                if(AutoFlip) setIntakePower(-100);
                //if(AutoMan) setIntakePower(100);
            }
            /*else if(!Charged){
                setIntakePower(100);
            }
            else if(Charged){*/
                else if(BallInBottom && BallInTop) setIntakePower(0);
                else setIntakePower(100);
            // }
        }
    //---------------------Wrist-----------------------//
        void wristCall(){
            int liftUp = 400;
            int wristCalTIme = 500;
            setLiftPower(100);
            vex::task::sleep(liftUp);
            setLiftPower(0);

            setWristPower(100);
            vex::task::sleep(wristCalTIme);
            setWristPower(0);

            setLiftPower(-100);
            vex::task::sleep(liftUp);
            setLiftPower(0);
            WristCalibrated = true;
        }
        /*void WristControll{
            while()
        }*/
/**/
/*Background Tasks*/
    int Drive_Ramping(){
        DriveRampingEnabled=true;
        while(DriveRampingEnabled){
            LFDR.TaskRun();
            RFDR.TaskRun();
            LBDR.TaskRun();
            RBDR.TaskRun();
            setMechDrivePower(LFDR.Pct,LBDR.Pct,RFDR.Pct,RBDR.Pct);
            vex::task::sleep(LFDR.ChangeMsec);
        }
        return 1;
    }
    int Auto_Intaking(){
        AutoIntakeTaskEnabled = true;
        // AutoIntakeEnabled = true;
        while(AutoIntakeTaskEnabled){
            if(AutoIntakeEnabled){Auto_Intake();}
            else if(!AutoIntakeEnabled){/*intakeControll();*/}
            vex::task::sleep(20);
        }
        setIntakePower(0);
        return 1;
    }
    int AutoCatapult(){
        AutoCatapultEnabled = true;
        while(AutoCatapultEnabled){
            catapultChargeFire();
            vex::task::sleep(20);
        }
        return 1;
    }
    int BrainScreenDebug(){
        Brain.Screen.render(true,false);
        while(true){
            //Brain.Screen.newLine();
            Brain.Screen.print(AutoIntakeEnabled);
            Brain.Screen.render();
            //Controller1.Screen.print(Charged);
            vex::task::sleep(20);
        }
    }
    int WristCal(){
        while(!WristCalibrated){
            wristCall();
            WristMotor.resetRotation();
            vex::task::sleep(20);
        }
        WristMotor.resetRotation();
        return 1;
    }
/**/