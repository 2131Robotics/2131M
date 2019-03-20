#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"
#include "N_Custom/declars/Aton/Catapult.hpp"

namespace Catapult{
//-------------------Auto Catapult Task--------------------//
  bool Shoot=false;

  bool Charged=false;
  int ChargeSenseValue;
  int ChargeMaxValue = 2500;

  void catapultTaskChargeFire(void*CatapultTask){
    while(AutoCatapultEnabled){
      ChargeSenseValue = ChargeLightSensor.get_value();

      if(ChargeSenseValue < ChargeMaxValue) Charged = true;

      if(Shoot){
        setCatapultVel(100);
        //wait till gone
        pros::delay(900);
        Shoot = false;
        setCatapultVel(0);
        Charged = false;
      }
      else{
        if(!Charged) setCatapultVel(100);
        else setCatapultVel(0);
      }
      pros::delay(20);
    }
  }
}
