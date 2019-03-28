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
  // Drive::ShortSlide(200);
  // pros::delay(400);
  // Drive::ShortSlide(200);
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
  // pros::delay(400);
  // Drive::ShortSlide(50);
  // pros::delay(400);
  // Drive::ShortSlide(-50);
  // pros::delay(5000);

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
void BackRed(){
  //-------Stack the Cap------------//
  Intake::AutoIntakeOff=true;
  Drive::AtonDriveRamp(890);
  Intake::AutoIntakeOff=false;
  Drive::AtonTurn(-Nine+30);
  Lift::setLiftVel(-5);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(500,-20);
  Lift::RotateTo(120,100,true);
  Drive::AtonDriveRamp(75);
  Drive::AtonTurn(-Nine+50);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(550);
  Drive::TimeAutoDrive(600,80);
  Flipper::RotateTo(0);
  pros::delay(700);
  Lift::RotateTo(775);
  Drive::TimeAutoDrive(700,80);
  // pros::delay(800);
  Drive::AtonDriveRamp(-45);
  Lift::RotateTo(0,200,true);
  Drive::AtonSlide(200);
  Drive::TimeAutoDrive(700,100);
  pros::delay(200);
  //-------First Row of Flags-------//
  Drive::AtonDriveRamp(-45);
  Drive::AtonTurn(Nine-100);

  //tne  add the park!!!!!!!!!!!
}
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
void Skills(){
  Flipper::RotateTo(-230);
  Intake::AutoIntakeOff=true;
  Drive::AtonDriveRamp(890);
  Flipper::RotateTo(0);
  Intake::AutoIntakeOff=false;
  pros::delay(200);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(Nine/2);
  Flipper::RotateTo(-320);
  pros::delay(200);
  Drive::AtonDriveRamp(200);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(-(Nine/2)-150);
  Drive::AtonDriveRamp(-300);
  Drive::TimeAutoDrive(700,-80);
  // Drive::AtonTurn(2000);
  // // pros::delay(200);
  // Flipper::RotateTo(-320);
  // Drive::AtonDriveRamp(250);
  // Flipper::RotateTo(0);
  // pros::delay(300);
  // // Drive::AtonDriveRamp(-100);
  // Flipper::RotateTo(-320);
  // pros::delay(400);
  // Drive::AtonTurn(Nine+1000);
  // // pros::delay(200);
  // // Drive::AtonDriveRamp(80);
  // Flipper::RotateTo(0);
  // // Drive::AtonDriveRamp(-80);
  // Drive::AtonTurn(Nine);
  // Drive::AtonDriveRamp(250);
  // Drive::AtonTurn(-2000);
  // Drive::AtonDriveRamp(400);
  // Drive::TimeAutoDrive(700,-100);
  //-------First Row of Flags-------//
  Drive::AtonDriveRamp(35);
  pros::delay(150);
  Drive::AtonTurn(-Nine+300);
  Drive::AtonDriveRamp(720);
  Catapult::Shoot=true;
  pros::delay(600);
  // Drive::ShortSlide(-10);
  Drive::AtonDriveRamp(550);
  Drive::SlideRecon(500, 80, -1);
  Drive::AtonDriveRamp(100);
  Drive::TimeAutoDrive(450,80);
  Drive::SlideRecon(600, 80, 1);
  Drive::TimeAutoDrive(500,80);
  //-------Seconed Row of Flags-------//
  Drive::AtonDriveRamp(-950);
  pros::delay(200);
  Drive::AtonSlide(200);
  pros::delay(400);
  Flipper::RotateTo(-320);
  Drive::AtonDriveRamp(250);
  Flipper::RotateTo(0);
  pros::delay(300);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(Nine-200);
  // Drive::AtonDriveRamp(-500);
  // Drive::TimeAutoDrive(700,-80);
  // pros::delay(300);
  Intake::AutoIntakeOff=true;
  Drive::AtonDriveRamp(250);
  Intake::AutoIntakeOff=false;
  pros::delay(150);
  Drive::AtonDriveRamp(-80);
  Drive::AtonTurn(-Nine);
  // Drive::AtonDriveRamp(-60);
  Drive::TimeAutoDrive(500,-80);
  pros::delay(150);
  // Drive::AtonDriveRamp(35);
  Drive::AtonTurn(1200);
  Catapult::Shoot=true;
  pros::delay(400);
  // Drive::SlideRecon(250, 80, -1);
  Drive::AtonDriveRamp(400);
  Drive::AtonTurn(-1200);
  // Drive::SlideRecon(500, 80, -1);
  Drive::AtonDriveRamp(150);
  Drive::TimeAutoDrive(450,80);
  Drive::SlideRecon(600, 80, 1);
  Drive::TimeAutoDrive(700,80);
  //-------Third Row of Flags-------//
  Drive::AtonDriveRamp(-280);
  Drive::AtonTurn(Nine-50);
  Flipper::RotateTo(-320);
  Drive::AtonDriveRamp(750);
  Flipper::RotateTo(0);
  // Drive::AtonSlide(570);
  // Drive::AtonTurn(Nine*2);
  Drive::AtonTurn(-Nine);
  Drive::AtonDriveRamp(-220);
  Drive::AtonTurn(-Nine-100);

  Flipper::RotateTo(-240);
  Intake::AutoIntakeOff=true;
  Drive::AtonDriveRamp(300);
  Flipper::RotateTo(0);
  Intake::AutoIntakeOff=false;
  // Drive::AtonDriveRamp(-100);
  // Drive::SlideRecon(800, 80, -1);
  // Drive::AtonDriveRamp(-180);
  pros::delay(400);
  Drive::AtonTurn((Nine*2)-3500);
  Drive::AtonDriveRamp(35);
  Catapult::Shoot=true;
  pros::delay(500);
  Drive::AtonDriveRamp(700);
  Drive::AtonTurn(-2000);
  Drive::AtonDriveRamp(150);
  Drive::TimeAutoDrive(450,80);
  Drive::SlideRecon(700, 80, 1);
  Drive::TimeAutoDrive(700,80);
  // Drive::AtonDriveRamp(40);
  //
  // Catapult::Shoot=true;
  // pros::delay(400);
  // Drive::SlideRecon(250, 80, -1);
  // Drive::AtonDriveRamp(600);
  // Drive::TimeAutoDrive(350,80);
  // Drive::SlideRecon(300, 80, 1);
  // Drive::TimeAutoDrive(500,80);
  //----------Parking----------//
  Drive::AtonDriveRamp(-950);
  pros::delay(300);
  Lift::RotateTo(120);
  Drive::AtonSlide(-200);
  Drive::TimeAutoDrive(700,-20);
  Drive::AtonDriveRamp(-350);
  Drive::MechDriveLockA();
  Drive::AtonTurn(Nine);
  Drive::TimeAutoDrive(1000,-20);
  Drive::AtonDriveRamp(-350);
  Drive::MechDriveLockA();
  Intake::AutoIntakeOff=true;
  Lift::RotateTo(0);
}
