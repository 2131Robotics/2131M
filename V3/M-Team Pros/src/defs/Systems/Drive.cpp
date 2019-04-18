#include "main.h"
//------Manual Drive Controll------------//
namespace Drive{
  void IsDriveFippedControll(){
    // if(DriveToggle.isPressed() && DriveDirConBtnPressed==false){
    //   DriveDirConBtnPressed=true;
    //   DriveDirInverted=!DriveDirInverted;
    // }
    // if(DriveToggle.isPressed() && DriveDirConBtnPressed==true){
    //   DriveDirConBtnPressed=false;
    // }

    if(DriveToggle.changed()){ // when the button changes
      if(DriveToggle.isPressed()){ //when it is pressed
        DriveDirInverted=!DriveDirInverted;
        Lift::setLiftVel(0);
        Flipper::setFlipVel(0);
      }
      else{

      }
    }
    else if(DriveToggle.isPressed()){ //if your holding the button do this
      Lift::setLiftVel(0);
      Flipper::setFlipVel(0);
    }
    else{ //default state

    }
  }
  void MechDriveLock(){
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    setMechDriveVel(0,0,0,0);
  }
  void MechDriveRelease(){
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }

  void ManualMechDriveCont(){
    int LeftVirtJoy=MController.getAnalog(okapi::ControllerAnalog::leftY)*200;
    int RightVirtJoy=MController.getAnalog(okapi::ControllerAnalog::rightY)*200;
    int LeftHorJoy=MController.getAnalog(okapi::ControllerAnalog::leftX)*200;
    int RightHorJoy=MController.getAnalog(okapi::ControllerAnalog::rightX)*200;

    // LeftVirtJoy=(LeftVirtJoy/127)*100;
    // RightVirtJoy=(RightVirtJoy/127)*100;
    // LeftHorJoy=(LeftHorJoy/127)*100;
    // RightHorJoy=(RightHorJoy/127)*100;

    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;

    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
        if(!DriveDirInverted){
          // vex::task AutoCat(AutoCatapult);
          DriveMechVelSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
        }
        if(DriveDirInverted){
          DriveMechVelSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
        }
    }
    else if(DriveDirInverted && Lift::Up.isPressed() &&
            Lift::LiftMotor.get_position() > 420){
      setDriveVel(50,50);
    }
    else{
      setMechDriveVel(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
    }
  }

  void DriveCont_LockContM(){
      //drive brake toggle
      // if(HoldToggle.isPressed() && DriveLockConBtnPressed==false){
      //   DriveLockConBtnPressed=true;
      //   DriveLockInverted=!DriveLockInverted;
      // }
      // if(HoldToggle.isPressed() && DriveLockConBtnPressed==true){
      //   DriveLockConBtnPressed=false;
      // }

      if(HoldToggle.changed()){ // when the button changes
        if(HoldToggle.isPressed()){ //when it is pressed
          DriveLockInverted=!DriveLockInverted;
        }
        else{

        }
      }
      else if(HoldToggle.isPressed()){ //if your holding the button do this

      }
      else{ //default state

      }

      if(DriveLockInverted){
        MechDriveLock();
        ManualMechDriveCont();
      }
      else if(!DriveLockInverted) {
        MechDriveRelease();
        ManualMechDriveCont();
      }
      // if(ControllerM.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){ //place cap
      //   if(DriveDirInverted){
      //     setDriveVel(30,30);
      //   }
      // }
  }
}
