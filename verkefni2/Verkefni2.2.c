#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#include "../headerfiles/constants.h"

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            							Verkefni 2.2                                              *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/


void drive_forward(int drivecm, int counter){
	int tickingGoal = drivecm * counter;
	SensorValue[leftEncoder] = 0;
	wait1Msec(1000);

	while(abs(SensorValue[leftEncoder]) < tickingGoal)
	{
		motor[rightMotor] = POWER;
		motor[leftMotor]  = POWER;
		wait1Msec(1000);
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
	}
}

void drive_backward(int drivecm, int counter){
	int tickingGoal = drivecm * counter;
	SensorValue[leftEncoder] = 0;
	wait1Msec(1000);

	while(abs(SensorValue[leftEncoder]) < tickingGoal)
	{
		motor[rightMotor] = REVERSEPOWER;
		motor[leftMotor]  = REVERSEPOWER;
		wait1Msec(1000);
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
	}

}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	SensorValue[leftEncoder] = 0;
	int distance_needed = 50; //How much distance we want to travel in cm's
	int drivecm = (distance_needed/33) * 360; // An integer that determines a set distance of cm using ticks. In this case it's 50 cm


	wait1Msec(1000);

	for(int i = 1; i<5;i++){
		drive_forward(drivecm, i);
		wait1Msec(2000);
		drive_backward(drivecm, i);
		wait1Msec(2000);
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
