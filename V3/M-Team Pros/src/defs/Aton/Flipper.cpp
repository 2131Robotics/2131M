#include "main.h"
 #include "N_Custom/declars/Aton/Flipper.hpp"

 namespace Flipper { //In Flipper namespace
   void RotateTo(double pos, int vel, bool wait){ //Rotate to Spesicic position
     FlipMotor.moveAbsolute(pos,vel);
     if(wait) while(FlipMotor.getActualVelocity()>0) pros::delay(5); //Wait untill it gets there if prefered
   }
 } /* Flipper */
