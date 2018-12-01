void testA(){
/*    bool tog=false;
    bool tog1=true;
    while(1){
        if(Brain.Screen.pressing()&&!tog1){
            tog1=true;
            Turn(30*(tog ? 1 : -1));
            tog=!tog;
        }
        else if(!Brain.Screen.pressing()&&tog1) tog1=false;
    }*/
}

void testB(){
    AutoIntakeEnabled = true;
    FlyChargeUpWait();
    AtonTurn(-Nine);
    toggleFlipper();
    vex::task::sleep(1000);
    toggleFlipper();
    AtonTurn(Nine);
    //Turn(90);
    //toggleFlipper();
    //AtonTurn(Full);
    //Turn(-90);
   // toggleFlipper();
}

void RightBlue(){
    AtonDriveRamp(10);
}