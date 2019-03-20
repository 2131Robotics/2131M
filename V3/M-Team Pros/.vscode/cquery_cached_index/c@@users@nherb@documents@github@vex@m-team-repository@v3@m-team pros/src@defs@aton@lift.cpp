#include "main.h"
#include "N_Custom/declars/Aton/Lift.hpp"

namespace Lift{
  void RotateTo(double pos, int vel, bool wait){
    LiftMotor.moveAbsolute(pos,vel);
    if(wait) while(LiftMotor.isStopped()==0) pros::delay(5);
  }
}
