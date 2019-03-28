#include "main.h"
 #include "N_Custom/declars/Aton/Flipper.hpp"

 namespace Flipper {
   void RotateTo(double pos, int vel, bool wait){
     FlipMotor.moveAbsolute(pos,vel);
     if(wait) while(FlipMotor.getActualVelocity()>0) pros::delay(5);
   }
 } /* Flipper */
