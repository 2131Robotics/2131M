#ifndef CONT_CONFIG_HPP
#define CONT_CONFIG_HPP

#include"okapi/api.hpp"

extern okapi::Controller MController;

namespace Drive{
  extern okapi::ControllerButton HoldToggle;
  extern okapi::ControllerButton DriveToggle;
}

namespace Catapult{
  extern okapi::ControllerButton Fire;
}

namespace Intake{
  extern okapi::ControllerButton In;
  extern okapi::ControllerButton Out;
}

namespace Lift{
  extern okapi::ControllerButton Up;
  extern okapi::ControllerButton Down;
}

namespace Flipper{
  extern okapi::ControllerButton Up;
  extern okapi::ControllerButton Down;
  extern okapi::ControllerButton CapPush;
}

#endif /* end of include guard: CONT_CONFIG_HPP */
