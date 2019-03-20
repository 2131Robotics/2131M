#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"

namespace Catapult{
//---------------------User Catapult-----------------------//
  bool UserCharged=false;
  int UserChargeSenseValue;
  int UserChargeMaxValue = 2500;

  void catapultChargeFire(){
    UserChargeSenseValue = ChargeLightSensor.get_value();

    if(UserChargeSenseValue < UserChargeMaxValue) UserCharged = true;

    if(Fire.isPressed() && !DriveDirInverted) {
        Drive::MechDriveLock();
        UserCharged = false;
        setCatapultVel(100);
    }
    else{

      if(!UserCharged) setCatapultVel(100);
      else setCatapultVel(0);
    }
  }
}
