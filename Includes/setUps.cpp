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