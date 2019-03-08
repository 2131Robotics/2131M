#include "N_Custom/main_config.hpp"
/*Drive Motor Vel Sends*/
namespace Drive{
  void setMechLFVel(int vel){
    vel*=2;
      if(vel==0) LeftFMotor.moveVelocity(0);
      else LeftFMotor.moveVelocity(vel);
  }
  void setMechLBVel(int vel){
    vel*=2;
      if(vel==0) LeftBMotor.moveVelocity(0);
      else LeftBMotor.moveVelocity(vel);
  }
  void setMechRFVel(int vel){
    vel*=2;
      if(vel==0) RightFMotor.moveVelocity(0);
      else RightFMotor.moveVelocity(vel);
  }
  void setMechRBVel(int vel){
    vel*=2;
      if(vel==0) RightBMotor.moveVelocity(0);
      else RightBMotor.moveVelocity(vel);
  }
  void setMechDriveVel(int LF,int LB,int RF,int RB){
      setMechLFVel(LF);
      setMechLBVel(LB);
      setMechRFVel(RF);
      setMechRBVel(RB);
  }
  void DriveMechVelSend(int j1,int j2,int j3=0,int j4=0){//left,right,side1,side2
      int LF=j1;//left
      int RF=j2;//right
      int SD=(j3+j4)/2;//side

      setMechDriveVel(//left go apart && right go into when going right
          LF+SD,
          LF-SD,
          RF-SD,
          RF+SD);
  }
  void setDriveVel(int left, int right){
      setMechLFVel(left);
      setMechLBVel(left);
      setMechRFVel(right);
      setMechRBVel(right);
  }
}

/*Intake Motor Vel Sends*/
namespace Intake{
  void setIntakeVel(int vel){
    vel*=6;
    if(vel==0) IntakeMotor.moveVelocity(0);
    else IntakeMotor.moveVelocity(vel);
}
}
/*Lock Motor Vel Sends*/
namespace Flipper{
  void setFlipVel(int vel){
    vel*=2;
    if(vel==0) FlipMotor.moveVelocity(0);
    else FlipMotor.moveVelocity(vel);
  }
}

/*Catapult Motor Vel Sends*/
namespace Catapult{
  void setCatapultVel(int vel){
    if(vel==0) CatapultMotor.moveVelocity(0);
    else CatapultMotor.moveVelocity(vel);
  }
}

/*Lift Motor Vel Sends*/
namespace Lift{
  void setLiftVel(int vel){
    vel*=2;
    if(vel==0) LiftMotor.moveVelocity(0);
    else LiftMotor.moveVelocity(vel);
  }
}
