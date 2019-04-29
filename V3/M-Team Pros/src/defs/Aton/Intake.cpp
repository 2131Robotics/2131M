#include "main.h"
#include "N_Custom/declars/Aton/Intake.hpp"

/**
 * Spesific Funtion that runs the intake untill 2 balls are present in the feed
 * - Tests if ball in top 
 * - Tests if ball in bottom
**/

namespace Intake{ //In namespace intake
    //creates variables to store lightSensor values into
  int	BottomLightValue;
  int TopLightValue;
  int BottomBallInMax = 2500;
  int TopBallInMax = 2500;
    //Creates boolean stating if ball in top of bottom
  bool BallInBottom;
  bool BallInTop;
    //variables used in aton
  bool AutoIntakeOff = false;
  bool IntakeFlip=false;

  void Auto_Intaking(void*AutoIntaking){ //Creates void for AutoIntaking
    AutoIntakeTaskEnabled = true; //starts the task enabled
    while(AutoIntakeTaskEnabled){ 
        //Checks the value of the senseors
      BottomLightValue = BallSenseBottom.get_value();
      TopLightValue = BallSenseTop.get_value();
        //checks and compares default light value to the value of a ball inside
        //if less it sets the top or bottom boolean to true or false.
      if (BottomLightValue < BottomBallInMax) BallInBottom = true;
      else BallInBottom = false;

      if (TopLightValue < TopBallInMax) BallInTop = true;
      else BallInTop = false;
        //extra intake controll features during aton
      if(AutoIntakeOff){ //set this boolean to true to turn off the intake
          //sets intake vel to 0
        setIntakeVel(0);
          // If you want the intake to run in reverse toggle this boolean to true
        if(IntakeFlip) setIntakeVel(-600);
      }

      // if both balls are in top and bottom then it slowly outfeeds and if there are not two it runs the intake
      else if(BallInBottom && BallInTop) setIntakeVel(-10);
      else setIntakeVel(600);
    }
    setIntakeVel(0); //at the end of the task it turns the intake off
  }
}
