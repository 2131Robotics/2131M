#include "main.h"

#include "N_Custom/declars/Ramping.hpp"
#include "N_Custom/declars/Aton/Drive.hpp"
#include "N_Custom/declars/Aton/Catapult.hpp"
#include "N_Custom/declars/Aton/Intake.hpp"
#include "N_Custom/declars/Aton/Lift.hpp"

#include "N_Custom/declars/Aton/Routines.hpp"
#include "N_Custom/declars/Aton/AtonSelector.hpp"

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  pros::Task DriveRampingTask (Drive::Drive_Ramping,(void*)"PROS",
    TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");
  pros::Task AutoCatapultTask (Catapult::catapultTaskChargeFire,(void*)"PROS",
    TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "AutoCatapultTask");
  pros::Task AutoIntakeTask (Intake::Auto_Intaking,(void*)"PROS",
    TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");

  PotSelectors();
}
