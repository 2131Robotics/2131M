#ifndef MAIN_CONFIG_HPP
#define MAIN_CONFIG_HPP

#include "okapi/api.hpp"

//Devices

//Motors
namespace Drive{
  extern okapi::Motor LeftFMotor;
  extern okapi::Motor LeftBMotor;
  extern okapi::Motor RightFMotor;
  extern okapi::Motor RightBMotor;
}

namespace Flipper{
  extern okapi::Motor FlipMotor;
}

namespace Catapult{
  extern okapi::Motor CatapultMotor;
}

namespace Lift{
  extern okapi::Motor LiftMotor;
}

namespace Intake{
  extern okapi::Motor IntakeMotor;
}

//Sensors
extern pros::ADIAnalogIn ChargeLightSensor;
extern pros::ADIAnalogIn BallSenseBottom;
extern pros::ADIAnalogIn BallSenseTop;

extern pros::ADIAnalogIn MainAtonSelect;
extern pros::ADIAnalogIn SecAtonSelect;

#endif /* end of include guard: MAIN_CONFIG_HPP */
