/*Drive Motor Power Sends*/
    void setMechLFPower(int pct){
        if(pct==0){
          LeftFMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
          LeftFMotor.move_velocity(100);
        }
        else{
            LeftFMotor.move_velocity(100);
        }
    }
    void setMechLBPower(int pct){
        if(pct==0)   LeftBMotor.stop(pros::E_MOTOR_BRAKE_COAST);
        else{
            LeftBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        }
    }
    void setMechRFPower(int pct){
        if(pct==0)   RightFMotor.stop(pros::E_MOTOR_BRAKE_COAST);
        else{
            RightFMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        }
    }
    void setMechRBPower(int pct){
        if(pct==0)   RightBMotor.stop(pros::E_MOTOR_BRAKE_COAST);
        else{
            RightBMotor.spin(vex::directionType::fwd,pct,vex::velocityUnits::pct);
        }
    }
    void setMechDrivePower(int LF,int LB,int RF,int RB){
        setMechLFPower(LF);
        setMechLBPower(LB);
        setMechRFPower(RF);
        setMechRBPower(RB);
    }
    void DriveMechPowerSend(int j1,int j2,int j3=0,int j4=0){//left,right,side1,side2
        int LF=j1;//left
        int RF=j2;//right
        int SD=(j3+j4)/2;//side

        setMechDrivePower(//left go apart && right go into when going right
            LF+SD,
            LF-SD,
            RF-SD,
            RF+SD);
    }
    void setDrivePower(int left, int right){
        setMechLFPower(left);
        setMechLBPower(left);
        setMechRFPower(right);
        setMechRBPower(right);
    }
/**/
