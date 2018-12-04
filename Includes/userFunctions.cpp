void ManualDriveCont(bool Flipped){
    if(Flipped){
        setDrivePower(Controller1.Axis3.value(), Controller1.Axis2.value());
    }
    if(!Flipped){
        setDrivePower(-Controller1.Axis2.value(), -Controller1.Axis3.value());
    }
}
void driveLock(){
    stopDriveHold();
}
void DriveCont_LockCont(){
    if(Controller1.ButtonB.pressing() && DriveLockConBtnPressed==false){
        DriveLockConBtnPressed=true;
        DriveLockInverted=!DriveLockInverted;
    }
    if(!Controller1.ButtonB.pressing() && DriveLockConBtnPressed==true){
        DriveLockConBtnPressed=false;
    }
    
    if(DriveLockInverted) driveLock();
    else if(!DriveLockInverted && modeVar == 0) {
        setDriveBrakeCoast();
        ManualDriveCont(true);
    }
    else if(!DriveLockInverted && modeVar == 1) {
        setDriveBrakeCoast();
        ManualDriveCont(false);
    }
}

/*void intakeControll(){
    if(Controller1.ButtonR1.pressing()) {
        setIntakePower(100);
    }   
    else if(Controller1.ButtonR2.pressing()) {
        setIntakePower(-100);
    }   
    else IntakeMotor.stop(vex::brakeType::coast);
}*/

void toggleUserModesUpdate(){
    if (!Controller1.ButtonX.pressing())																	//																											//
            usertoggle=1;																				//																											//
        if (Controller1.ButtonX.pressing() && modeVar==1 && usertoggle==1){
            modeVar=0;																				//		- To switch between
            usertoggle=0;																				//			our two different
        }																											//			modes
        if (Controller1.ButtonX.pressing() && modeVar==0 && usertoggle==1){	//
            modeVar=1;																				//
            usertoggle=0;																				//
        }
}