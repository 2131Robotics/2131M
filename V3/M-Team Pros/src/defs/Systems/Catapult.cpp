#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"

/**
 * Catapult Controll funtions for the User Controll portoin of the match.
 * Runs inside the user controll while loop
 * - Checks the light senseor equiped and lets it know if the catapult
 *   is charged or not.
 * - If I tell it to shoot it will run the catapult at full power for 
 *   900 milliseconeds and tell the catapult motor to recharge.
**/

namespace Catapult{
//---------------------User Catapult-----------------------//
  bool UserCharged=false;
  int UserChargeSenseValue;
  int UserChargeMaxValue = 2500; //Value that determines if the catapult is charged

  void catapultChargeFire(){
      //Checks the value of the ChargeLightSensor and stores it inside the ChargeSenseValue integer
    UserChargeSenseValue = ChargeLightSensor.get_value();
      //Determines if its charged or not
    if(UserChargeSenseValue < UserChargeMaxValue) UserCharged = true;
      //Allows driver to fire only in Ball mode
    if(Fire.isPressed() && !DriveDirInverted) {
        // Drive::MechDriveLock();
        UserCharged = false;
        setCatapultVel(100);
    }
      //If not charged, charge. vice verse
    else{
      if(!UserCharged) setCatapultVel(100);
      else setCatapultVel(0);
    }
  }
}
