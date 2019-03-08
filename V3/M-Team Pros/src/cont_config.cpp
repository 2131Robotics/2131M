#include "N_Custom/cont_config.hpp"

//Devices
okapi::Controller MController(okapi::ControllerId::master);

namespace Drive{
  okapi::ControllerButton HoldToggle = MController[okapi::ControllerDigital::B];
  okapi::ControllerButton DriveToggle = MController[okapi::ControllerDigital::X];
}

namespace Flipper{
  okapi::ControllerButton Up = MController[okapi::ControllerDigital::L1];
  okapi::ControllerButton Down = MController[okapi::ControllerDigital::L2];
}

namespace Catapult{
  okapi::ControllerButton Fire = MController[okapi::ControllerDigital::R2];
}

namespace Lift{
  okapi::ControllerButton Up = MController[okapi::ControllerDigital::L1];
  okapi::ControllerButton Down = MController[okapi::ControllerDigital::L2];
}

namespace Intake{
  okapi::ControllerButton In = MController[okapi::ControllerDigital::R1];
  okapi::ControllerButton Out = MController[okapi::ControllerDigital::down];
}
