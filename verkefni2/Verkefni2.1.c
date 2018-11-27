#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Moving Forward -                                         *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            							This is project2                                          *|
|*                                                                                                    *|
\*-----------------------------------------------------------------------------------------------4246-*/
int power = -127;
int reversepower = 127;
int drive_time = 1150;

void drive_forward(int drive_time, int counter){
	motor[rightMotor] = power;
	motor[leftMotor]  = power;
	wait1Msec(drive_time*counter);
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;

}

void drive_backward(int drive_time, int counter){
	motor[rightMotor] = reversepower;
	motor[leftMotor]  = reversepower;
	wait1Msec(drive_time*counter);
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;

}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	wait1Msec(1000);

	for(int i = 1; i<5;i++){
		drive_forward(drive_time, i);
		wait1Msec(2000);
		drive_backward(drive_time, i);
		wait1Msec(2000);
	}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
