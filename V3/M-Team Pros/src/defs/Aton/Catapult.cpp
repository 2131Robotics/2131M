#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"
#include "N_Custom/declars/Aton/Catapult.hpp"

/**
 * Catapult Controll funtions for the Autonomous portoin of the match.
 * Runs inside a seperate task.
 * - Checks the light senseor equiped and lets it know if the catapult
 *   is charged or not.
 * - If I tell it to shoot it will run the catapult at full power for 
 *   900 milliseconeds and tell the catapult motor to recharge.
**/

namespace Catapult{
//-------------------Auto Catapult Task--------------------//
  bool Shoot=false;

  bool Charged=false;
  int ChargeSenseValue;
  int ChargeMaxValue = 2500; //Value that determines if the catapult is charged

  void catapultTaskChargeFire(void*CatapultTask){ //creates the catapult task
    while(AutoCatapultEnabled){ //booleon to easily disable the task if needed.
        //Checks the value of the ChargeLightSensor and stores it inside the ChargeSenseValue integer
      ChargeSenseValue = ChargeLightSensor.get_value();
        //Determines if its charged or not
      if(ChargeSenseValue < ChargeMaxValue) Charged = true;
        //Simple path to Allow it to fire.
      if(Shoot){
        setCatapultVel(100);
        //wait till gone
        pros::delay(900);
        Shoot = false;
        setCatapultVel(0);
        Charged = false;
      }
        //Tell the catapult to charge if its not charged
      else{
        if(!Charged) setCatapultVel(100);
        else setCatapultVel(0);
      }
      pros::delay(20); //end wait to avoid cpu hog
    }
  }
}
