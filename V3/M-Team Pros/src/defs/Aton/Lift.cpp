#include "main.h"
#include "N_Custom/declars/Aton/Lift.hpp"

namespace Lift{ //inside lift namespace 
  void RotateTo(double pos, int vel, bool wait){ //function to rotate to spesific value
    LiftMotor.moveAbsolute(pos,vel);
    if(wait) while(LiftMotor.isStopped()==0) pros::delay(5);
  }
}
