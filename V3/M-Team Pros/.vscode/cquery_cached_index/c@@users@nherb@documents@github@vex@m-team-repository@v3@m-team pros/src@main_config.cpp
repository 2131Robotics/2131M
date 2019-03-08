#include "N_Custom\main_config.hpp"

namespace Drive{
  okapi::Motor LeftFMotor(12,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor LeftBMotor(13,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightFMotor(11,true,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor RightBMotor(14,true,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Flipper{
  okapi::Motor FlipMotor(5,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Catapult{
  okapi::Motor CatapultMotor(15,false,okapi::AbstractMotor::gearset::red,
    okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Lift{
  okapi::Motor LiftMotor(17,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Intake{
  okapi::Motor IntakeMotor(16,false,okapi::AbstractMotor::gearset::blue,
    okapi::AbstractMotor::encoderUnits::degrees);
}

//Sensors
pros::ADIAnalogIn ChargeLightSensor(3);
pros::ADIAnalogIn BallSenseBottom(5);
pros::ADIAnalogIn BallSenseTop(4);

pros::ADIAnalogIn MainAtonSelect(1);
pros::ADIAnalogIn SecAtonSelect(2);
