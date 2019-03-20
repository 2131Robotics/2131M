#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
	okapi::Controller SController(okapi::ControllerId::master);
	okapi::Motor LeftFOneMotor(17,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftFTwoMotor(13,true,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFOneMotor(6,true,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFTwoMotor(8,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
	okapi::Motor LeftBOneMotor(14,true,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBTwootor(20,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightBOneMotor(15,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightBTwoMotor(11,true,okapi::AbstractMotor::gearset::green,
	    okapi::AbstractMotor::encoderUnits::degrees);
	while (true) {

		LeftFOneMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::leftY));
		LeftFTwoMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::leftY));
		RightFOneMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::rightY));
		RightFTwoMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::rightY));

		LeftBOneMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::leftY));
		LeftBTwootor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::leftY));
		RightBOneMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::rightY));
		RightBTwoMotor.moveVelocity(200*SController.getAnalog(okapi::ControllerAnalog::rightY));

		pros::delay(20);
	}
}
