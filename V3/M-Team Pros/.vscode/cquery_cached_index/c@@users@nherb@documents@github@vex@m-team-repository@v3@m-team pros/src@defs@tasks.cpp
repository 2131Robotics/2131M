#include "main.h"

//---------------------Auto Catapult-----------------------//
    /*bool Charged=false;
    int ChargeSenseValue;
    int ChargeMaxValue = 30;
    bool AutoCataFiring=true;

    void catapultChargeFire(void*t){
        ChargeSenseValue = ChargeLightSensor.get_value();

        if (ChargeSenseValue < ChargeMaxValue) Charged = true;

        if (ControllerM.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1 && !DriveDirInverted) {

          LeftFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
          LeftBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
          RightFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
          RightBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

          setMechDrivePower(0,0,0,0);
          Charged = false;
          setCatapultPower(100);
        }
        if(AutoCataFiring){
            setCatapultPower(100);

            //wait till gone
            pros::delay(900);
            AutoCataFiring = false;
            setCatapultPower(0);
            Charged = false;
        }

        else {
          LeftFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
          LeftBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
          RightFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
          RightBMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

            if(!Charged){
                // AutoIntakeEnabled = false;
                setCatapultPower(100);
            }
            if(Charged){
                // AutoIntakeEnabled = true;
                setCatapultPower(0);
            }
        }

    }

    pros::Task CatapultTask (catapultChargeFire, (void*)"PROS", TASK_PRIORITY_DEFAULT,
                    TASK_STACK_DEPTH_DEFAULT, "My Catapult Task");
*/
