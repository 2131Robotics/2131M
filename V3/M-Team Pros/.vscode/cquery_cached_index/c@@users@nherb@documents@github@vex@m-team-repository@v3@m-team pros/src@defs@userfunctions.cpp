#include "main.h"

//------Manual Drive Controll------------//
namespace Drive{
  void IsDriveFippedControll(){
      if(DriveToggle.isPressed() && DriveDirConBtnPressed==false){
        DriveDirConBtnPressed=true;
        DriveDirInverted=!DriveDirInverted;
      }
      if(DriveToggle.isPressed() && DriveDirConBtnPressed==true){
        DriveDirConBtnPressed=false;
      }
  }
  void MechDriveLock(){
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    setMechDrivePower(0,0,0,0);

  }
  void ManualMechDriveCont(){
      IsDriveFippedControll();
      int LeftVirtJoy=MController.getAnalog(okapi::ControllerAnalog::leftY);
      int RightVirtJoy=MController.getAnalog(okapi::ControllerAnalog::rightX);
      int LeftHorJoy=MController.getAnalog(okapi::ControllerAnalog::leftX);
      int RightHorJoy=MController.getAnalog(okapi::ControllerAnalog::rightX);

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

  void DriveCont_LockContM(){
      IsDriveFippedControll();
      //drive brake toggle
      if(HoldToggle.isPressed() && DriveLockConBtnPressed==false){
        DriveLockConBtnPressed=true;
        DriveLockInverted=!DriveLockInverted;
      }
      if(HoldToggle.isPressed() && DriveLockConBtnPressed==true){
        DriveLockConBtnPressed=false;
      }

      if(DriveLockInverted) MechDriveLock();
      else if(!DriveLockInverted) {
        LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        ManualMechDriveCont();
      }
      // if(ControllerM.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){ //place cap
      //   if(DriveDirInverted){
      //     setDrivePower(30,30);
      //   }
      // }
  }
}
