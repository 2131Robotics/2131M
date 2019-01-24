vex::brain Brain;
vex::controller Controller1 = vex::controller();
//vex::vision Vision = vex::vision(vex::PORT1,60,sigObj1,sigObj2,sigObj3,sigObj4,sigObj5,sigObj6,sigObj7);

vex::motor LeftBMotor = vex::motor(vex::PORT1,vex::gearSetting::ratio18_1);
vex::motor RightBMotor = vex::motor(vex::PORT6,vex::gearSetting::ratio18_1,true);

vex::motor LiftMotor = vex::motor(vex::PORT9,vex::gearSetting::ratio18_1,true);
vex::motor WristMotor = vex::motor(vex::PORT10,vex::gearSetting::ratio18_1);
vex::motor IntakeMotor = vex::motor(vex::PORT20,vex::gearSetting::ratio18_1);
vex::motor PuncherMotor = vex::motor(vex::PORT7,vex::gearSetting::ratio18_1,true);
vex::motor JawMotor = vex::motor(vex::PORT5,vex::gearSetting::ratio18_1,true);