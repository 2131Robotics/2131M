#ifndef MAIN_CONFIG_HPP
#define MAIN_CONFIG_HPP

#include "okapi/api.hpp"
#include "N_Custom/declars/Ramping.hpp"

//Devices

//Motors
namespace Drive{
  extern okapi::Motor LeftFMotor;
  extern okapi::Motor LeftBMotor;
  extern okapi::Motor RightFMotor;
  extern okapi::Motor RightBMotor;

  extern Ramping LFDR;
  extern Ramping RFDR;
  extern Ramping LBDR;
  extern Ramping RBDR;

}

namespace Catapult{
  extern okapi::Motor CatapultMotor;

  extern pros::ADILineSensor ChargeLightSensor;
}

namespace Intake{
  extern okapi::Motor IntakeMotor;

  extern pros::ADILineSensor BallSenseTop;
  extern pros::ADILineSensor BallSenseBottom;
}

namespace Lift{
  extern okapi::Motor LiftMotor;
}

namespace Flipper{
  extern okapi::Motor FlipMotor;
}

//Sensors
extern pros::ADIAnalogIn MainAtonSelect;
extern pros::ADIAnalogIn SecAtonSelect;

#endif /* end of include guard: MAIN_CONFIG_HPP */
