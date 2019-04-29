#include "main.h"
#include "N_Custom/declars/Ramping.hpp"
#include "N_Custom/declars/Systems/Drive.hpp"
//---------------Auto Drive Controll----------------//
namespace Drive{
  void MechDriveLockA(){ // Aton Controll to lock the drive
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
      //turn motors off to activate brake
    setMechDriveVel(0,0,0,0);
  }

//------------Aton Drive Ramping---------------------//
    //Drive distance function
  void AtonDriveRamp(double Distance,int Pct,int EndWait,int Correction){
    //update ramping speed
    LFDR.ChangeMsec = 4;
    RFDR.ChangeMsec = 4;
    LBDR.ChangeMsec = 4;
    RBDR.ChangeMsec = 4;

    double Direction=sgn(Distance);
    int LFPowerSend=0;
    int LBPowerSend=0;
    int RFPowerSend=0;
    int RBPowerSend=0;
    //clear enc on motors
    LeftFMotor.tarePosition();
    LeftBMotor.tarePosition();
    RightBMotor.tarePosition();
    RightFMotor.tarePosition();
    //is it there yet? test for when the motors get to its position
    while(std::abs(RightBMotor.getPosition())<std::abs(Distance)){
      double LEncValue=LeftFMotor.getPosition();
      double REncValue=RightFMotor.getPosition();
      //straiten - compares the left side of the drive to the right
      if(std::abs(LEncValue)>std::abs(REncValue)){
        LFPowerSend=Pct-Correction;
        LBPowerSend=Pct-Correction;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      else if(std::abs(LEncValue)<std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct-Correction;
        RBPowerSend=Pct-Correction;
      }
      else if(std::abs(LEncValue)==std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      //correct direction
      LFPowerSend=LFPowerSend*Direction;
      LBPowerSend=LBPowerSend*Direction;
      RFPowerSend=RFPowerSend*Direction;
      RBPowerSend=RBPowerSend*Direction;
      //send to SetDRpower
      SetDRMvel(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
      pros::delay(LFDR.ChangeMsec);
    }
    SetDRMvel(0,0,0,0);
    pros::delay(EndWait);
      //realease drive
    LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
      //end delay to increase accuacy
    pros::delay(EndWait);
  }

  void TimeAutoDrive(int time, int power){ // Functoin to dead recon for a spific time at spesific power
      //clear motor enc
    LeftBMotor.tarePosition();
    RightBMotor.tarePosition();
    LeftFMotor.tarePosition();
    RightFMotor.tarePosition();
      //Set Power
    DI(power,power);
    pros::delay(time); //wait for specified time
    DI(0,0);
    while(LBDR.Pct!=0 || RBDR.Pct!=0){ //wait till motors are done moving
      pros::delay(1);
    }
  }
    //Function to use the ability to strafe side to side
  void AtonSlide(double Distance,int Pct,int EndWait,int Correction){
    //update ramping speed
    LFDR.ChangeMsec = 3;
    RFDR.ChangeMsec = 3;
    LBDR.ChangeMsec = 3;
    RBDR.ChangeMsec = 3;
    
    //calculate direction and set L & R PowerSend
    double Direction=sgn(Distance);
    int LFPowerSend=0;
    int LBPowerSend=0;
    int RFPowerSend=0;
    int RBPowerSend=0;
    //clear enc
    LeftFMotor.tarePosition();
    LeftBMotor.tarePosition();
    RightBMotor.tarePosition();
    RightFMotor.tarePosition();
    //is it there yet?
    while(std::abs(RightBMotor.getPosition())<std::abs(Distance)){
      double LEncValue=RightFMotor.getPosition();
      double REncValue=RightBMotor.getPosition();
      //straiten
      if(std::abs(LEncValue)>std::abs(REncValue)){
        LFPowerSend=Pct-Correction;
        LBPowerSend=Pct-Correction;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      else if(std::abs(LEncValue)<std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct-Correction;
        RBPowerSend=Pct-Correction;
      }
      else if(std::abs(LEncValue)==std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      //correct direction for strafing
      if(Direction == 1){
        LFPowerSend=LFPowerSend;
        LBPowerSend=LBPowerSend*(-1);
        RFPowerSend=RFPowerSend*(-1);
        RBPowerSend=RBPowerSend;
      }
      if(Direction == -1){
        LFPowerSend=LFPowerSend*(-1);
        LBPowerSend=LBPowerSend;
        RFPowerSend=RFPowerSend;
        RBPowerSend=RBPowerSend*(-1);
      }
      //send to SetDRpower
      SetDRMvel(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
      pros::delay(LBDR.ChangeMsec);
    }
      //Its there so stop motors
    SetDRMvel(0,0,0,0);
    //wait till they are stoped
    while(LBDR.Pct!=0 || RBDR.Pct!=0){
      pros::delay(1);
    }
      //accuracy wait
    pros::delay(EndWait);
  }
  //Function to strafe short distances
  void ShortSlide(double Distance,int Pct,int EndWait,int Correction){
    //Short stafe requires default motor speeds without ramping
    MechDriveRampingEnabled=false;
    //calculate direction and set L & R PowerSend
    double Direction=sgn(Distance);
    int LFPowerSend=0;
    int LBPowerSend=0;
    int RFPowerSend=0;
    int RBPowerSend=0;
    //clear enc
    LeftFMotor.tarePosition();
    LeftBMotor.tarePosition();
    RightBMotor.tarePosition();
    RightFMotor.tarePosition();
    //is it there yet?
    while(std::abs(RightBMotor.getPosition())<std::abs(Distance)){
      double LEncValue=LeftFMotor.getPosition();
      double REncValue=RightBMotor.getPosition();
      //straiten
      if(std::abs(LEncValue)>std::abs(REncValue)){
        LFPowerSend=Pct-Correction;
        LBPowerSend=Pct-Correction;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      else if(std::abs(LEncValue)<std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct-Correction;
        RBPowerSend=Pct-Correction;
      }
      else if(std::abs(LEncValue)==std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      //correct direction
      if(Direction == 1){
        LFPowerSend=LFPowerSend;
        LBPowerSend=LBPowerSend*(-1);
        RFPowerSend=RFPowerSend*(-1);
        RBPowerSend=RBPowerSend;
      }
      if(Direction == -1){
        LFPowerSend=LFPowerSend*(-1);
        LBPowerSend=LBPowerSend;
        RFPowerSend=RFPowerSend;
        RBPowerSend=RBPowerSend*(-1);
      }
      //send to SetDRpower
      setMechDriveVel(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
      pros::delay(10);
    }
      //stop motors
    SetDRMvel(0,0,0,0);
    pros::delay(EndWait);
      //re-enable ramping task
    pros::Task DriveRampingTask (Drive::Drive_Ramping,(void*)"PROS",
      TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");
  }
  //Function to dead recon side to side
  void SlideRecon(int time, int power, int dir){
        //Disable Ramping
      MechDriveRampingEnabled=false;
        //Set motors at specified vel
      setMechLFVel(power*dir);
      setMechLBVel(-power*dir);
      setMechRFVel(-power*dir);
      setMechRBVel(power*dir);
        //Delay for specific time
      pros::delay(time);
        //Stop motors
      setMechLFVel(0);
      setMechLBVel(0);
      setMechRFVel(0);
      setMechRBVel(0);
        //Re-enable ramping
      pros::Task DriveRampingTask (Drive::Drive_Ramping,(void*)"PROS",
        TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");
  }
    //Function to rurn my robot specified in degrees
  void AtonTurn(double deg,int LPowerSend,int RPowerSend,int EndWait){
    //right 90 turn 6000
    //right 180 turn 12000
    //right 270 turn 18000
    //left 90 turn -6000
    //left 180 turn -12000
    //left 270 turn -18000
    //-left,+right

      //obtain direction turn
    int Dir=sgn(deg);
      //convert value to degrees
    deg=abs(deg)/12.56;
      //correct Dir
    LPowerSend=LPowerSend*Dir;
    RPowerSend=RPowerSend*Dir;
      //clear motor enc
    LeftBMotor.tarePosition();
    RightBMotor.tarePosition();
    LeftFMotor.tarePosition();
    RightFMotor.tarePosition();
      //calculate the average abs position of all 4 motors 
    double RFValue = std::abs(RightFMotor.getPosition());
    double RBValue = std::abs(RightBMotor.getPosition());
    double LFValue = std::abs(LeftFMotor.getPosition());
    double LBValue = std::abs(LeftBMotor.getPosition());
      //stores it into and upadates variable
    double AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);
      //Wait untill turn is complete
    while(AbsTurnRotationsAvg < std::abs(deg)){ // tests if its there yet
        //sends power to the motors
      DI(LPowerSend,-RPowerSend);
        //recalculates new abs position of all 4 motors
      RFValue = std::abs(RightFMotor.getPosition());
      RBValue = std::abs(RightBMotor.getPosition());
      LFValue = std::abs(LeftFMotor.getPosition());
      LBValue = std::abs(LeftBMotor.getPosition());
        //stores it into and upadates variable
      AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);
        //Dont hog CPU
      pros::delay(1);
    }
      //Once there stop motors
    DI(0,0);
      //Sudden stop for accuracy 
    MechDriveLock();
      //Delay for accuracy
    pros::delay(EndWait);
      //Set motors to coast
    MechDriveRelease();
  }
}