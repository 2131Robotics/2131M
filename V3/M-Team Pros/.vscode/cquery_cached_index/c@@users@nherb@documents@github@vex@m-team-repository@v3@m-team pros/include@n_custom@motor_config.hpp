#ifndef MOTOR_CONFIG_HPP
#define MOTOR_CONFIG_HPP

#include "api.h"

//Motors
extern pros::Controller ControllerM;
extern pros::Motor LeftFMotor;
extern pros::Motor LeftBMotor;
extern pros::Motor RightFMotor;
extern pros::Motor RightBMotor;

extern pros::Motor IntakeMotor;
extern pros::Motor CatapultMotor;

extern pros::Motor LiftMotor;
extern pros::Motor FlipMotor;

//Sensors
extern pros::ADIAnalogIn ChargeLightSensor;
extern pros::ADIAnalogIn BallSenseBottom;
extern pros::ADIAnalogIn BallSenseTop;

extern pros::ADIAnalogIn MainAtonSelect;
extern pros::ADIAnalogIn SecAtonSelect;

#endif /* end of include guard: MOTOR_CONFIG_HPP */
