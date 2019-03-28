#include "main.h"

#include "N_Custom/declars/Systems/Drive.hpp"
#include "N_Custom/declars/Systems/Catapult.hpp"
#include "N_Custom/declars/Systems/Intake.hpp"
#include "N_Custom/declars/Systems/Lift.hpp"
#include "N_Custom/declars/Systems/Flipper.hpp"

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
	MechDriveRampingEnabled=false;
	AutoIntakeTaskEnabled=false;
	AutoCatapultEnabled=false;
	while (true) {
		Drive::IsDriveFippedControll();

		Drive::DriveCont_LockContM();
		Catapult::catapultChargeFire();
		Intake::intakeControll();
		Lift::liftManualCont();
		Flipper::FlipManualCont();

		pros::delay(20);
	}
}
