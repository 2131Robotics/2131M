#include "main.h"

namespace Lift{
  void liftManualCont(){
    // Flipper::setFlipVel(0);
    if(LiftMotor.get_position() < 100)
         LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    else LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    if(DriveDirInverted){
      if(Up.isPressed()) setLiftVel(200);
      else if(Down.isPressed()) setLiftVel(-200);
      else setLiftVel(0);
    }
    else{}
  }
}
