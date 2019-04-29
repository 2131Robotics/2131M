#include "main.h"

namespace Lift{
  void liftManualCont(){
      //Updates lift brake height if above a spesific value
    if(LiftMotor.get_position() < 100)
         LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    else LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    if(DriveDirInverted){ // Run lift controll in lift mode
      if(Up.isPressed()) setLiftVel(200);
      else if(Down.isPressed()) setLiftVel(-200);
      else setLiftVel(0);
    }
    else{} // No controll in ball mode
  }
}
