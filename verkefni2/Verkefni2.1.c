#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#include "../headerfiles/constants.h"
/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            								Description:																						*|
|*							This project drives the robot forward and backwards using a time limit and a loop     *|
|*										to run it an X number of times (4 times for the assignment).										*|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/


void drive_forward(int drive_time, int counter){
	motor[rightMotor] = POWER;
	motor[leftMotor]  = POWER;
	wait1Msec(drive_time*counter);
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;

}

void drive_backward(int drive_time, int counter){
	motor[rightMotor] = REVERSEPOWER;
	motor[leftMotor]  = REVERSEPOWER;
	wait1Msec(drive_time*counter);
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(1000);

	for(int i = 1; i<5;i++){
		drive_forward(DRIVETIME, i);
		wait1Msec(2000);
		drive_backward(DRIVETIME, i);
		wait1Msec(2000);
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
