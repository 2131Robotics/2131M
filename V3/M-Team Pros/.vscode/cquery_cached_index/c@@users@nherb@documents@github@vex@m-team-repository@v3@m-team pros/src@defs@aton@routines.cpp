#include "main.h"
#include "N_Custom/declars/Ramping.hpp"
#include "N_Custom/declars/Aton/Drive.hpp"
#include "N_Custom/declars/Aton/Catapult.hpp"
#include "N_Custom/declars/Aton/Intake.hpp"
#include "N_Custom/declars/Aton/Lift.hpp"
#include "N_Custom/declars/Aton/Flipper.hpp"

/*testing*/
void test(){
  // Drive::AtonDriveRamp(200);
  // Drive::AtonTurn(-18000);
  // Drive::AtonSlide(1000);
  // SlideRecon(int time, int power, int dir);
  // pros::delay(400);


  //
  // Catapult::Shoot=true;
  //
  // Intake::AutoIntakeOff=true;
  // Intake::IntakeFlip=true;
  //
  // Flipper::RotateTo(500);
  // Lift::RotateTo(500);
}

/*blue*/
//Normal
void FrontBlue(){
  Drive::AtonDriveRamp(850);
  pros::delay(300);
  Drive::AtonDriveRamp(-680);
  pros::delay(200);
  Drive::AtonTurn(Nine-200);
  Drive::AtonDriveRamp(60);

  Catapult::Shoot=true;
  pros::delay(400);
  Drive::AtonDriveRamp(250);
  Drive::SlideRecon(250,200,1);
  Drive::AtonDriveRamp(250);
  Drive::SlideRecon(230,150,-1);
  Drive::TimeAutoDrive(300,100);
  pros::delay(200);

  Drive::AtonDriveRamp(-800);
  Flipper::RotateTo(-200);
  Drive::AtonTurn((-Nine/2));
  Drive::AtonDriveRamp(120,150);
  Flipper::RotateTo(-350,200,true);
  Drive::TimeAutoDrive(175,-200);
  pros::delay(200);
  Drive::AtonDriveRamp(200);
  Catapult::Shoot=true;
  Flipper::RotateTo(0);
}

void BackBlue(){}
//Parking
void ParkFrontBlue(){}

void ParkBackBlue(){}
//Sniper
void SniperFrontBlue(){}

void SniperBackBlue(){}
//Other
void OtherFrontBlue(){}

void OtherBackBlue(){}

/*red*/
//Normal
void FrontRed(){
  Drive::AtonDriveRamp(850);
  pros::delay(300);
  Drive::AtonDriveRamp(-680);
  pros::delay(200);
  Drive::AtonTurn(-Nine+200);
  Drive::AtonDriveRamp(60);

  Catapult::Shoot=true;
  pros::delay(400);
  Drive::AtonDriveRamp(250);
  Drive::SlideRecon(250,200,-1);
  Drive::AtonDriveRamp(200);
  Drive::SlideRecon(230,150,1);
  Drive::TimeAutoDrive(300,100);
  pros::delay(200);

  Drive::AtonDriveRamp(-800);
  Flipper::RotateTo(-200);
  Drive::AtonTurn((Nine/2));
  Drive::AtonDriveRamp(80,150);
  Flipper::RotateTo(-350,200,true);
  Drive::TimeAutoDrive(175,-200);
  pros::delay(200);
  Drive::AtonDriveRamp(200);
  Catapult::Shoot=true;
  Flipper::RotateTo(0);
}
void BackRed(){}
//Parking
void ParkingFrontRed(){}

void ParkingBackRed(){}
//Sniper
void SniperFrontRed(){}

void SniperBackRed(){}
//Other
void OtherFrontRed(){}

void OtherBackRed(){}


/*skills*/
void Skills(){}
