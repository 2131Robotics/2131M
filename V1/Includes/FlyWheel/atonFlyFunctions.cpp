void FlyChargeUpWait(){
    setFlyPower(600);
    while(FlyMotor.velocity(vex::velocityUnits::pct)<100){}
}

void toggleFlipper(){
    FlipperMotor.startRotateFor(FlipperMotorInverted ? -350 : 350,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
    FlipperMotorInverted=!FlipperMotorInverted;
}