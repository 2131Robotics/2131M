#include "N_Custom\motor_config.hpp"

#include "api.h"
pros::Controller ControllerM (pros::E_CONTROLLER_MASTER);

pros::Motor LeftFMotor(12,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor LeftBMotor(13,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RightFMotor(11,pros::E_MOTOR_GEARSET_18,true,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor RightBMotor(14,pros::E_MOTOR_GEARSET_18,true,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor IntakeMotor(16,pros::E_MOTOR_GEARSET_06,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CatapultMotor(15,pros::E_MOTOR_GEARSET_36,false,pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor LiftMotor(17,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor FlipMotor(5,pros::E_MOTOR_GEARSET_18,false,pros::E_MOTOR_ENCODER_DEGREES);

//Sensors
pros::ADIAnalogIn ChargeLightSensor(3);
pros::ADIAnalogIn BallSenseBottom(5);
pros::ADIAnalogIn BallSenseTop(4);

pros::ADIAnalogIn MainAtonSelect(1);
pros::ADIAnalogIn SecAtonSelect(2);
