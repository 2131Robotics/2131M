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
            // while(Controller1.Axis3.value()==0 || Controller1.Axis2.value()==0){
                liftRotateFor(-350,50);
                AtonDriveRamp(10,50);
                wait(500);
                DriveRampingEnabled = false;
            // }
        }

    void DriveCont_LockContM(){
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
        if(Controller1.ButtonDown.pressing()){
            PlaceCap();
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
            AutoIntakeEnabled=false;
            intakeControll();
        }
        if(!IntakeEnabledInverted) {
            vex::task AutoIn(Auto_Intaking);
        }
    }
/**/
//------Manual Catapult Controll------------//
    void catapultControll(){
        if(!DriveDirInverted){
            if(Controller1.ButtonL1.pressing()) {
                setCatapultPower(100);
            }  
            else CatapultMotor.stop(vex::brakeType::coast);
        }
    }
/**/
//------Manual Lift Controll------------//
    void liftManualCont(){
        IsDriveFippedControll();
    if(DriveDirInverted){

            IntakeMotor.stop(IntakeBrakeType);

            if(Controller1.ButtonL1.pressing()) setLiftPower(100);
            else if(Controller1.ButtonL2.pressing()) setLiftPower(-100);
            else setLiftPower(0);
        }
        if(!DriveDirInverted){
            //liftRotateTo(0);
        }
    }
/**/
//------Manual Lift Controll------------//
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