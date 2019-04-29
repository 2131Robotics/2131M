#include "main.h"
//------Manual Drive Controll------------//
namespace Drive{
  void IsDriveFippedControll(){ //Function to run and check if the drive direction has changed
    if(DriveToggle.changed()){ // when the button changes
      if(DriveToggle.isPressed()){ //when it is pressed
        DriveDirInverted=!DriveDirInverted; //togggles directon

        // Prevents left over command form contiuing after toggle
        Lift::setLiftVel(0);
        Flipper::setFlipVel(0);
      }
      else{}
    }
    else if(DriveToggle.isPressed()){ //if your holding the button do this
      // Prevents left over command form contiuing after toggle
      Lift::setLiftVel(0);
      Flipper::setFlipVel(0);
    }
    else{ /*DefaultState*/ }
  }
  void MechDriveLock(){ //Function to lock the drive and assists in defenseive plays
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    setMechDriveVel(0,0,0,0);
  }
  void MechDriveRelease(){ //Function to relase drive from hold
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }

  void ManualMechDriveCont(){ //Main code to controll drive train and motor chassie
      //Sets controller inputs to eaisily read variables
    int LeftVirtJoy=MController.getAnalog(okapi::ControllerAnalog::leftY)*200;
    int RightVirtJoy=MController.getAnalog(okapi::ControllerAnalog::rightY)*200;
    int LeftHorJoy=MController.getAnalog(okapi::ControllerAnalog::leftX)*200;
    int RightHorJoy=MController.getAnalog(okapi::ControllerAnalog::rightX)*200;
      //Create a deadzone for anolog sticks to work from to prevent unnessisary drift and accidental bump
    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
      //When no input signle is found
    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
        //Ball direction drive controll
      if(!DriveDirInverted){
        DriveMechVelSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
      }
        //Lift direction drive controll 
      if(DriveDirInverted){
        DriveMechVelSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
      }
    }
      //Feature that aids driver when stacking caps by backing into the wall to straiten while stacking
    else if(DriveDirInverted && Lift::Up.isPressed() && Lift::LiftMotor.get_position()>420){
      setDriveVel(50,50);
    }
      //Last loop before disableing; used to release drivemanualcontrol
    else setMechDriveVel(0,0,0,0);
  }

  void DriveCont_LockContM(){ //The code that will run in User Controll to override when set to drive lock state
    if(HoldToggle.changed()){ // when the button changes
      if(HoldToggle.isPressed()){ //when it is pressed
        DriveLockInverted=!DriveLockInverted;
      }
      else{}
    }
    else if(HoldToggle.isPressed()){/*if your holding the button do this*/}
    else{/*default state*/}
      //When the drive lock is enabled
    if(DriveLockInverted){
      MechDriveLock(); //Set the Braketype to hold
      ManualMechDriveCont(); // Allows for user controll if needed
    }
      //When the drive lock is disabled
    else if(!DriveLockInverted) {
      MechDriveRelease(); //Make sure braketype is in coast
      ManualMechDriveCont(); //Regualar Drive Controll
    }
  }
}
