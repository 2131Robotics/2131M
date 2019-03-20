#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  Drive::LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Catapult::CatapultMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Intake::IntakeMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Lift::LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

  Flipper::FlipMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

  Drive::LeftFMotor.tarePosition();
  Drive::LeftBMotor.tarePosition();
  Drive::RightFMotor.tarePosition();
  Drive::RightBMotor.tarePosition();

  Flipper::FlipMotor.tarePosition();
  Lift::LiftMotor.tarePosition();

  // pros::Task CatapultTask (usefull, (void) "PROS", TASK_PRIORITY_DEFAULT,
  // TASK_STACK_DEPTH_DEFAULT, "My Task");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  //future aton selector
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
