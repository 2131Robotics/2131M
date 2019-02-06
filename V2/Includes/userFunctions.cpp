//------Manual Drive Controll------------//
    void IsDriveFippedControll(){
        if(Controller1.ButtonX.pressing() && DriveDirConBtnPressed==false){
            DriveDirConBtnPressed=true;
            DriveDirInverted=!DriveDirInverted;
        }
        if(!Controller1.ButtonX.pressing() && DriveDirConBtnPressed==true){
            DriveDirConBtnPressed=false;
        }
    }
    void MechDriveLock(){
        DriveBrakeType = vex::brakeType::hold;
        setMechDrivePower(0,0,0,0);

    }
    void ManualMechDriveCont(){
        IsDriveFippedControll();
        int LeftVirtJoy=Controller1.Axis3.value();
        int RightVirtJoy=Controller1.Axis2.value();
        int LeftHorJoy=Controller1.Axis4.value();
        int RightHorJoy=Controller1.Axis1.value();

        if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
        if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
        if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
        if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
        
        if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
            if(!DriveDirInverted){
                // vex::task AutoCat(AutoCatapult);
                DriveMechPowerSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
            }
            if(DriveDirInverted){
                DriveMechPowerSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
            }
        }
        else{
            setMechDrivePower(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
        }        
    }
    void PlaceCap(){
        vex::task AtonDrive(Drive_Ramping);
            AtonDriveRamp(40,60);
            vex::task::sleep(100);
            liftRotateFor(-600,50);
            vex::task::sleep(300);
            DriveRampingEnabled = false;
    }
    void EasyFlip(){

    }

    void DriveCont_LockContM(){
        IsDriveFippedControll();
        if(Controller1.ButtonB.pressing() && DriveLockConBtnPressed==false){
            DriveLockConBtnPressed=true;
            DriveLockInverted=!DriveLockInverted;
        }
        if(!Controller1.ButtonB.pressing() && DriveLockConBtnPressed==true){
            DriveLockConBtnPressed=false;
        }

        if(DriveLockInverted) MechDriveLock();
        else if(!DriveLockInverted) {
            DriveBrakeType = vex::brakeType::coast;
            ManualMechDriveCont();
        }
        if(Controller1.ButtonDown.pressing()){ //place cap
            if(DriveDirInverted){
            setDrivePower(30,30);
            }
        }
    }
/**/
//------Manual Intake Controll------------//
    void intakeControll(){
        if(!DriveDirInverted){
            if(Controller1.ButtonR1.pressing()) {
                setIntakePower(100);
            }   
            else if(Controller1.ButtonR2.pressing()) {
                setIntakePower(-100);
            }   
            else IntakeMotor.stop(vex::brakeType::coast);
        }
        else{}
    }

    void AutoIntakeCont(){
        if(Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==false){
            IntakeEnabledBtnPressed=true;
            IntakeEnabledInverted=!IntakeEnabledInverted;
        }
        if(!Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==true){
            IntakeEnabledBtnPressed=false;
        }

        if(IntakeEnabledInverted){ 
            AutoIntakeTaskEnabled=false;
            intakeControll();
        }
        if(!IntakeEnabledInverted) {
            vex::task AutoIn(Auto_Intaking);
            //AutoIntakeEnabled=false;

        }
    }
/**/
//------Manual Catapult Controll------------//
    void catapultControll(){
        if(!DriveDirInverted){
            if(Controller1.ButtonL1.pressing()) {
                setCatapultPower(100);
            }  
            else CatapultMotor.stop(CatapultBrakeType);
        }
    }
/**/
//------Manual Lift Controll------------//
    void liftManualCont(){
        IsDriveFippedControll();

            /*if(Controller1.ButtonL2.pressing() && LiftEEnabledBtnPressed==false){
                LiftEEnabledBtnPressed=true;
                if(!DriveDirInverted) liftRotateTo(easyFlipDir ? 0 : 350);
                easyFlipDir=!easyFlipDir;
            }
            if(!Controller1.ButtonL2.pressing() && LiftEEnabledBtnPressed==true){
                LiftEEnabledBtnPressed=false;
            }

        if(!DriveDirInverted){
            if(easyFlipDir==false) liftRotateTo(easyFlipDir ? 0 : 350);
            if(easyFlipDir==true) liftRotateTo(350);
            
        }*/
        if(DriveDirInverted){
            //IntakeMotor.stop(IntakeBrakeType);

            if(Controller1.ButtonL1.pressing()) setLiftPower(100);
            else if(Controller1.ButtonL2.pressing()) setLiftPower(-100);
            //easyFlipDir = false;
            else if(Controller1.ButtonDown.pressing()){
                setLiftPower(-40);
            }
            else setLiftPower(0);
        }
        else{}
    }
/**/
//------Lock Controll------------//
    void LockJawCont(){
        IsDriveFippedControll();
        // double LockPos = LockMotor.rotation(vex::rotationUnits::deg);
    if(DriveDirInverted){

            if(Controller1.ButtonR1.pressing()) setLockPower(100);
            else if(Controller1.ButtonR2.pressing()) setLockPower(-100);
            else setLockPower(0);

            // if(LockPos <= 0) setLockPower(0);
            // if(LockPos >=387) setLockPower(0);

        }
        if(!DriveDirInverted){
            
        }
    }
/**/
//------Wrist Controll------------//
    void wirstControll(){ //wrist void task
            int CCW = -300;
            int CW = 10;
            int spinFor = 800;
        if(WristCalibrated){
            IsDriveFippedControll();
            if(DriveDirInverted){
                if(Controller1.ButtonR1.pressing() && WristMotorConBtnPressed==false){
                    WristMotorConBtnPressed=true;
                    WristMotorInverted=!WristMotorInverted;
                    wristRan=false;
                }
                if(!Controller1.ButtonR1.pressing() && WristMotorConBtnPressed==true){
                    WristMotorConBtnPressed=false;
                }

                if(!wristRan){
                    setWristPower(WristMotorInverted ? -100 : 100);
                    vex::task::sleep(spinFor);
                    setWristPower(0);

                    wristRan=true;
                }
            }
            if(!DriveDirInverted){
                if(Controller1.ButtonL2.pressing() && WristMotorConBtnPressed==false){
                    WristMotorConBtnPressed=true;
                    WristMotorInverted=!WristMotorInverted;
                    wristRan=false;
                }
                if(!Controller1.ButtonL2.pressing() && WristMotorConBtnPressed==true){
                    WristMotorConBtnPressed=false;
                }

                if(!wristRan){ //easy flip
                    setLiftPower(100);
                    wait(450);
                    setWristPower(WristMotorInverted ? -100 : 100);
                    setLiftPower(-100);
                    vex::task::sleep(spinFor);
                    setLiftPower(0);
                    setWristPower(0);
                    wristRan=true;
                }
            }
        }
    }
    int WristTask(){
        WristTaskEnabled = true;
        while(WristTaskEnabled){
            wirstControll();
            vex::task::sleep(20);
        }
        return 1;
    }
/**/