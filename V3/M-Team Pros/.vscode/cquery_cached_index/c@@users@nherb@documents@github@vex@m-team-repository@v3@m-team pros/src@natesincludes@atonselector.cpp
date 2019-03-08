//-----------Brain Screen Aton Display------------//
    void AtonUpdator(){
        int MainSelectValue = MainAtonSelect.value(vex::percentUnits::pct);
        int secSelectValue = SecAtonSelect.value(vex::percentUnits::pct);
        Brain.Screen.clearScreen();

        if(MainSelectValue > 90) {//test
            Brain.Screen.clearLine(1,vex::color::purple);
            Brain.Screen.clearLine();

            Brain.Screen.print("Test");
        }
        else if(MainSelectValue > 60){//skills
            Brain.Screen.clearLine(1,vex::color::orange);
            Brain.Screen.clearLine();

            Brain.Screen.print("Skills");

        }
        else if(MainSelectValue > 45) {//back red
            Brain.Screen.clearLine(1,vex::color::red);
            Brain.Screen.clearLine();

            if(secSelectValue > 90) Brain.Screen.print("BackRed - Other");
            else if(secSelectValue > 50) Brain.Screen.print("BackRed - Sniper");
            else if(secSelectValue > 10) Brain.Screen.print("BackRed - Parking");
            else if(secSelectValue >= 0) Brain.Screen.print("BackRed - Normal");
        }
        else if(MainSelectValue > 25){//front red
            Brain.Screen.clearLine(1,vex::color::red);
            Brain.Screen.clearLine();

            if(secSelectValue > 90) Brain.Screen.print("FrontRed - Other");
            else if(secSelectValue > 50) Brain.Screen.print("FrontRed - Sniper");
            else if(secSelectValue > 10) Brain.Screen.print("FrontRed - Parking");
            else if(secSelectValue >= 0) Brain.Screen.print("FrontRed - Normal");
        }
        else if(MainSelectValue > 10){//back blue
            Brain.Screen.clearLine(1,vex::color::blue);
            Brain.Screen.clearLine();

            if(secSelectValue > 90) Brain.Screen.print("BackBlue - Other");
            else if(secSelectValue > 50) Brain.Screen.print("BackBlue - Sniper");
            else if(secSelectValue > 10) Brain.Screen.print("BackBlue - Parking");
            else if(secSelectValue >= 0) Brain.Screen.print("BackBlue - Normal");
        }
        else if(MainSelectValue >= 0){//front blue
            Brain.Screen.clearLine(1,vex::color::blue);
            Brain.Screen.clearLine();

            if(secSelectValue > 90) Brain.Screen.print("FrontBlue - Other");
            else if(secSelectValue > 50) Brain.Screen.print("FrontBlue - Sniper");
            else if(secSelectValue > 10) Brain.Screen.print("FrontBlue - Parking");
            else if(secSelectValue >= 0) Brain.Screen.print("FrontBlue - Normal");
        }
        
    }
    int WhatAton(){
        while(true){
            AtonUpdator();
            Brain.Screen.render();
            vex::task::sleep(20);
        }
        return 1;
    }
/**/
//-----------Pot Selector Values Function------------//
    void PotSelectors(){
        int MainSelectValue = MainAtonSelect.value(vex::percentUnits::pct);
        int secSelectValue = SecAtonSelect.value(vex::percentUnits::pct);
        if(MainSelectValue > 90) {
            test();
        }
        else if(MainSelectValue > 60){
            Skills();
        }
        else if(MainSelectValue > 45) {
            if(secSelectValue > 90) OtherBackRed();
            else if(secSelectValue > 50) SniperBackRed();
            else if(secSelectValue > 10) ParkingBackRed();
            else if(secSelectValue >= 0) BackRed();
        }
        else if(MainSelectValue > 25){
            if(secSelectValue > 90) OtherFrontRed();
            else if(secSelectValue > 50) SniperFrontRed();
            else if(secSelectValue > 10) ParkingFrontRed();
            else if(secSelectValue >= 0) FrontRed();
    
        }
        else if(MainSelectValue > 10){
            if(secSelectValue > 90) OtherBackBlue();
            else if(secSelectValue > 50) SniperBackBlue();
            else if(secSelectValue > 10) ParkBackBlue();
            else if(secSelectValue >= 0) BackBlue();
        }
        else if(MainSelectValue >= 0){
            if(secSelectValue > 90) OtherFrontBlue();
            else if(secSelectValue > 50) SniperFrontBlue();
            else if(secSelectValue > 10) ParkFrontBlue();
            else if(secSelectValue >= 0) FrontBlue();
        }
    }
 /**/