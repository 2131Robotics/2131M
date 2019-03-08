#ifndef CONT_CONFIG_HPP
#define CONT_CONFIG_HPP

#include"okapi/api.hpp"

extern okapi::Controller MController;

namespace Drive{
  extern okapi::ControllerButton HoldToggle;
  extern okapi::ControllerButton DriveToggle;
}

namespace Flipper{
  extern okapi::ControllerButton Up;
  extern okapi::ControllerButton Down;
}

namespace Catapult{
  extern okapi::ControllerButton Fire;
}

namespace Lift{
  extern okapi::ControllerButton Up;
  extern okapi::ControllerButton Down;
}

namespace Intake{
  extern okapi::ControllerButton In;
  extern okapi::ControllerButton Out;
}

#endif /* end of include guard: CONT_CONFIG_HPP */
