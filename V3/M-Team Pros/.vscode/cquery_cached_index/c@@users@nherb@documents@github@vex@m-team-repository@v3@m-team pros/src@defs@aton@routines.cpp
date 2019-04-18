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
  Drive::AtonDriveRamp(830);
  pros::delay(300);
  Drive::AtonDriveRamp(-710);
  pros::delay(200);
  Drive::AtonTurn(Nine-200);
  Catapult::Shoot=true;
  pros::delay(400);
  Drive::AtonDriveRamp(300);
  Drive::SlideRecon(200,200,1);
  Drive::AtonDriveRamp(290);
  Drive::TimeAutoDrive(400,100);
  pros::delay(200);
  Drive::AtonDriveRamp(-70);
  Drive::AtonTurn(-Nine-2500);
  Flipper::RotateTo(-350,200,true);
  Drive::AtonDriveRamp(450);
  Flipper::RotateTo(0);
  Drive::AtonTurn(Nine-500);
  Catapult::Shoot=true;
  pros::delay(400);
}

void BackBlue(){
  Drive::AtonDriveRamp(890);
  Drive::AtonTurn(Nine-30);
  Lift::setLiftVel(-5);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(500,-20);
  Lift::RotateTo(120,100,true);
  Drive::AtonDriveRamp(65);
  Drive::AtonTurn(Nine-80);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(550);
  Drive::TimeAutoDrive(600,80);
  Flipper::RotateTo(0);
  pros::delay(200);
  Lift::RotateTo(775);
  Drive::TimeAutoDrive(700,80);
  pros::delay(200);

  Drive::AtonDriveRamp(-100);
  pros::delay(150);
  Lift::RotateTo(80,200,true);
  pros::delay(200);
  Drive::AtonSlide(-750);
  Drive::TimeAutoDrive(600,-30);
  Drive::AtonDriveRamp(-450);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
}
//Parking
void ParkFrontBlue(){
  Drive::AtonDriveRamp(800);
  Drive::AtonDriveRamp(-150);
  Catapult::Shoot=true;
  Flipper::RotateTo(-350);
  Drive::AtonTurn(Nine,125,125);
  Drive::AtonDriveRamp(300);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-280);
  Drive::AtonTurn(-Nine-4000);
  Flipper::RotateTo(-280);
  Drive::AtonDriveRamp(30);
  Drive::AtonDriveRamp(-60);
  Flipper::RotateTo(0);
  Lift::RotateTo(80,200,true);
  Drive::AtonTurn(Nine+3500);
  Drive::AtonSlide(-280);
  Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-500);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
  pros::delay(200);
  Drive::AtonTurn(-3000);
  Catapult::Shoot=true;
}

void ParkBackBlue(){
    //-------Stack the Cap------------//
  Drive::AtonDriveRamp(950);
  Drive::AtonTurn(Nine-30);
  Lift::setLiftVel(-5);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(250,-20);
  Lift::RotateTo(120,100,true);
  Drive::AtonDriveRamp(50);
  Drive::AtonTurn(-1700);
  Catapult::Shoot=true;
  pros::delay(600);
  Drive::AtonTurn(Nine+1800);
  Flipper::RotateTo(-250);

  Drive::AtonDriveRamp(550);
  Drive::TimeAutoDrive(600,80);
  Flipper::RotateTo(0);
  pros::delay(200);
  Lift::RotateTo(775);
  Drive::TimeAutoDrive(700,80);

  Drive::AtonDriveRamp(-600);
  Drive::AtonTurn(Nine+200);
  Lift::RotateTo(100,200,true);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(300,-20);
  Drive::AtonDriveRamp(-480);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
}
//Sniper
void SniperFrontBlue(){
  Drive::AtonDriveRamp(120);
  Drive::AtonTurn(-(Nine/2)+500);
  Drive::AtonDriveRamp(110);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(-100);
  Flipper::RotateTo(0);
  Drive::AtonTurn((Nine*2)-2600);
  Catapult::Shoot=true;
  pros::delay(550);

  Flipper::RotateTo(-320);
  Drive::AtonTurn(-2000);
  Drive::AtonDriveRamp(300);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(-Nine+1700);
  Drive::AtonDriveRamp(350);
  Drive::AtonTurn(3100);
  Catapult::Shoot=true;
  pros::delay(550);
  Drive::AtonTurn(-3100);
  Drive::AtonDriveRamp(-300);
}

void SniperBackBlue(){
  Drive::AtonDriveRamp(120);
  Drive::AtonTurn((Nine/2)-500);
  Drive::AtonDriveRamp(115);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(-60);
  Drive::AtonTurn(1600);
  Catapult::Shoot=true;
  Drive::AtonDriveRamp(20);
  pros::delay(100);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-90);
  Drive::AtonTurn(-(Nine/2)-1000);
  Drive::AtonDriveRamp(350,200);
  Drive::AtonDriveRamp(-280);
  Drive::AtonTurn(3150);
  Catapult::Shoot=true;
  pros::delay(400);
  Lift::RotateTo(80,200,true);
  Drive::AtonTurn(Nine+3000);
  Drive::AtonSlide(-500);
  Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-700);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);

}
//Other
void OtherFrontBlue(){}

void OtherBackBlue(){
  Drive::AtonDriveRamp(830);
  Drive::AtonDriveRamp(-180);
  Drive::AtonTurn(-Nine/2);
  Flipper::RotateTo(-320);
  pros::delay(200);
  Drive::AtonDriveRamp(200);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn((Nine/2)-100);
  Drive::AtonDriveRamp(-300);
  Drive::TimeAutoDrive(700,-80);
  //-------First Row of Flags-------//
  pros::delay(150);
  Drive::AtonTurn(Nine-200);
  // Drive::AtonDriveRamp(720);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::AtonDriveRamp(260);
  Drive::AtonTurn(Nine);
  Drive::TimeAutoDrive(400,100);
  Lift::RotateTo(80,200,true);
  // Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-1200);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);

}
/*red*/
//Normal
void FrontRed(){
  Drive::AtonDriveRamp(850);
  pros::delay(300);
  Drive::AtonDriveRamp(-680);
  pros::delay(200);
  Drive::AtonTurn(-Nine+150);
  Catapult::Shoot=true;
  pros::delay(400);
  Drive::AtonDriveRamp(300);
  Drive::SlideRecon(300,200,-1);
  Drive::AtonDriveRamp(200);
  Drive::TimeAutoDrive(300,100);
  pros::delay(200);
  Drive::AtonDriveRamp(-70);
  Drive::AtonTurn(Nine+3000);
  Flipper::RotateTo(-350,200,true);
  Drive::AtonDriveRamp(400);
  Flipper::RotateTo(0);
  Drive::AtonTurn(-Nine+100);
  Catapult::Shoot=true;
  pros::delay(400);
}

void BackRed(){
  //-------Stack the Cap------------//
  Drive::AtonDriveRamp(900);
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
  pros::delay(200);
  Lift::RotateTo(775);
  Drive::TimeAutoDrive(700,80);

  Drive::AtonDriveRamp(-200);
  pros::delay(200);
  Lift::RotateTo(80,200,true);
  pros::delay(200);
  Drive::AtonSlide(750);
  Drive::TimeAutoDrive(300,-20);
  Drive::AtonDriveRamp(-450);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
}
//Parking
void ParkingFrontRed(){
  Drive::AtonDriveRamp(800);
  Drive::AtonDriveRamp(-150);
  Catapult::Shoot=true;
  Flipper::RotateTo(-350);
  Drive::AtonTurn(-Nine,125,125);
  Drive::AtonDriveRamp(300);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-280);
  Drive::AtonTurn(Nine+4000);
  Flipper::RotateTo(-280);
  Drive::AtonDriveRamp(30);
  Drive::AtonDriveRamp(-60);
  Flipper::RotateTo(0);
  Lift::RotateTo(80,200,true);
  Drive::AtonTurn(-Nine-3500);
  Drive::AtonSlide(300);
  Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-500);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
  pros::delay(200);
  Drive::AtonTurn(2750);
  Catapult::Shoot=true;
}

void ParkingBackRed(){
  //-------Stack the Cap------------//
  Drive::AtonDriveRamp(950);
  Drive::AtonTurn(-Nine+30);
  Lift::setLiftVel(-5);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(250,-20);
  Lift::RotateTo(120,100,true);
  Drive::AtonDriveRamp(50);
  Drive::AtonTurn(1700);
  Catapult::Shoot=true;
  pros::delay(500);
  Drive::AtonTurn(-Nine-2000);
  Flipper::RotateTo(-250);

  Drive::AtonDriveRamp(550);
  Drive::TimeAutoDrive(600,80);
  Flipper::RotateTo(0);
  pros::delay(200);
  Lift::RotateTo(775);
  Drive::TimeAutoDrive(700,80);

  Drive::AtonDriveRamp(-600);
  Drive::AtonTurn(-Nine-200);
  Lift::RotateTo(100,200,true);
  Drive::AtonDriveRamp(-200);
  Drive::TimeAutoDrive(300,-20);
  Drive::AtonDriveRamp(-480);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);

}
//Sniper
void SniperFrontRed(){
  Drive::AtonDriveRamp(120);
  Drive::AtonTurn((Nine/2)-500);
  Drive::AtonDriveRamp(110);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(-100);
  Flipper::RotateTo(0);
  Drive::AtonTurn(-(Nine*2)+2600);
  Catapult::Shoot=true;
  pros::delay(550);

  Flipper::RotateTo(-320);
  Drive::AtonTurn(2000);
  Drive::AtonDriveRamp(300);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(Nine-1700);
  Drive::AtonDriveRamp(350);
  Drive::AtonTurn(-3100);
  Catapult::Shoot=true;
  pros::delay(550);
  Drive::AtonTurn(3100);
  Drive::AtonDriveRamp(-300);

}

void SniperBackRed(){
  Drive::AtonDriveRamp(120);
  Drive::AtonTurn(-(Nine/2)+500);
  Drive::AtonDriveRamp(130);
  Flipper::RotateTo(-250);
  Drive::AtonDriveRamp(-60);
  Drive::AtonTurn(-1300);
  Catapult::Shoot=true;
  Drive::AtonDriveRamp(40);
  pros::delay(100);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-90);
  Drive::AtonTurn((Nine/2)+1150);
  Drive::AtonDriveRamp(350,200);
  Drive::AtonDriveRamp(-280);
  Drive::AtonTurn(-3150);
  Catapult::Shoot=true;
  pros::delay(400);
  Lift::RotateTo(80,200,true);
  Drive::AtonTurn(-Nine-3000);
  Drive::AtonSlide(600);
  Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-500);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
}
//Other
void OtherFrontRed(){}

void OtherBackRed(){
  Drive::AtonDriveRamp(830);
  Drive::AtonDriveRamp(-180);
  Drive::AtonTurn(Nine/2);
  Flipper::RotateTo(-320);
  pros::delay(200);
  Drive::AtonDriveRamp(200);
  Flipper::RotateTo(0);
  Drive::AtonDriveRamp(-200);
  Drive::AtonTurn(-(Nine/2)-150);
  Drive::AtonDriveRamp(-300);
  Drive::TimeAutoDrive(700,-80);
  //-------First Row of Flags-------//
  pros::delay(150);
  Drive::AtonTurn(-Nine+200);
  // Drive::AtonDriveRamp(720);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::AtonDriveRamp(260);
  Drive::AtonTurn(-Nine);
  Drive::TimeAutoDrive(400,100);
  Lift::RotateTo(80,200,true);
  // Drive::TimeAutoDrive(250,-20);
  Drive::AtonDriveRamp(-1200);
  Drive::MechDriveLockA();
  Lift::RotateTo(0,200,true);
}

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
  //-------First Row of Flags-------//
  // Drive::AtonDriveRamp(35);
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
  Drive::AtonTurn(1150);
  Catapult::Shoot=true;
  pros::delay(400);
  // Drive::SlideRecon(250, 80, -1);
  Drive::AtonDriveRamp(450);
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
  Drive::AtonDriveRamp(-230);
  Drive::AtonTurn(-Nine-100);

  Flipper::RotateTo(-240);
  Intake::AutoIntakeOff=true;
  Drive::AtonDriveRamp(250);
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
  Drive::AtonDriveRamp(400);
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
  Drive::TimeAutoDrive(700,-10);
  Drive::AtonDriveRamp(-350);
  Drive::MechDriveLockA();
  Drive::AtonTurn(Nine-100);
  Drive::TimeAutoDrive(1000,-20);
  Drive::AtonDriveRamp(-350);
  Drive::MechDriveLockA();
  Intake::AutoIntakeOff=true;
  Lift::RotateTo(0);
}
