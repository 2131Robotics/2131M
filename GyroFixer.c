#pragma config(Sensor, in4,    Gyro,           sensorGyro)
//#pragma config(Sensor, in8,    GyroTwo,        sensorGyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void pre_auton()
{
	SensorValue[Gyro] = 0;					///

	SensorBias[Gyro] = 1862;
	wait1Msec(250);
	SensorScale[Gyro] = 134;
	wait1Msec(250);
/*
	SensorType[Gyro] = sensorNone;
	wait1Msec(1000);										//
	SensorType[Gyro] = sensorGyro;      // To correct Gyro Drift
	wait1Msec(1000);										//
	SensorType[Gyro] = sensorNone;
	*/

	/*for(int i = 0; i<2000; i++)
	{
		cumBias += (float)(SensorValue[Gyro]);
		wait1Msec(1);
	}
	debug = cumBias / 2000;
*/

}
task main()
{

	pre_auton();
while(true){}
}
