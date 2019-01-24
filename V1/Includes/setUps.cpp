/*Gyro Cal*/
void GyroCalibration(bool Wait=true){
    Gyro.startCalibration();
    if(Wait){
        while(!Gyro.isCalibrating()){//wait for var to update
            vex::task::sleep(5);
        }
        while(Gyro.isCalibrating()){//wait for calibration
            vex::task::sleep(5);
        }
    }
}
/*Wrist Cal*/
void wristCal(int time=300){
    liftRotateTo(230);
    vex::task::sleep(500);

    setWristPower(100);
    vex::task::sleep(100);
    liftRotateTo(0);

    vex::task::sleep(time);
    setWristPower(0);
    WristCalibrated=true;
    WristMotor.resetRotation();
    liftDeployed = true;
}
