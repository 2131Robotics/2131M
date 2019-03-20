#include "main.h"
#include "N_Custom/declars/Aton/Routines.hpp"

void PotSelectors(){
    int MainSelectValue = MainAtonSelect.get_value();
    int secSelectValue = SecAtonSelect.get_value();
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
