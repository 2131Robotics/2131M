//Includes files needed to run Autonomous routines
#include "main.h"
#include "N_Custom/declars/Aton/Routines.hpp"

/**
 * This portion of the code looks at both my potentiometers
 * and decides which aton routine to run depending on the
 * value of my levers on my robot.
 * Uses two potentiometers.
 *  - First one determines which section of the feild im at...
 *  - Seconed one to tell this function which program to run.
**/

void PotSelectors(){
    //Set the value of the potentiometers to a integer.
    int MainSelectValue = MainAtonSelect.get_value();
    int secSelectValue = SecAtonSelect.get_value();
    //test the values to determine routine
    if(MainSelectValue > 3500) {
        test();
    }
    else if(MainSelectValue > 2000){
        Skills();
    }
    else if(MainSelectValue > 1350) {
        if(secSelectValue > 3600) OtherBackRed();
        else if(secSelectValue > 1900) SniperBackRed();
        else if(secSelectValue > 450) ParkingBackRed();
        else if(secSelectValue >= 0) BackRed();
    }
    else if(MainSelectValue > 775){
        if(secSelectValue > 3600) OtherFrontRed();
        else if(secSelectValue > 1900) SniperFrontRed();
        else if(secSelectValue > 450) ParkingFrontRed();
        else if(secSelectValue >= 0) FrontRed();

    }
    else if(MainSelectValue > 225){
        if(secSelectValue > 3600) OtherBackBlue();
        else if(secSelectValue > 1900) SniperBackBlue();
        else if(secSelectValue > 450) ParkBackBlue();
        else if(secSelectValue >= 0) BackBlue();
    }
    else if(MainSelectValue >= 0){
        if(secSelectValue > 3600) OtherFrontBlue();
        else if(secSelectValue > 1900) SniperFrontBlue();
        else if(secSelectValue > 450) ParkFrontBlue();
        else if(secSelectValue >= 0) FrontBlue();
    }
}
