#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorNormal, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#include "../headerfiles/constants.h"

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 3.1: Remote Control -                                 *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            								Description:																						*|
|*							This project uses a controller to control the robot going in all directions.			   	*|
|*              It also has claw and arm controls, and a button to stop the program.                  *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{

	while(vexRT[Btn8U] == 0) // While the button that turns of the program is NOT pressed.
	{
		motor[leftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		motor[rightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2

// Arm controls
		if(vexRT[Btn5U] == 1)       	//If button 6U is pressed, then raise the arm.
		{
			motor[armMotor] = POWER;
		}
		else if(vexRT[Btn6U] == 1)  	//Else if button 5U is pressed, then lower the arm.
		{
			motor[armMotor] = REVERSEPOWER;
		}
		else                      		//Otherwise if no button is pressed, stop the arm.
		{
			motor[armMotor] = 0;
		}

// Claw controls
		if(vexRT[Btn6D] == 1)       	//If button 5D is pressed, then close the claw.
		{
			motor[clawMotor] = POWER;
		}
		else if(vexRT[Btn5D] == 1)  	//Else if button 6D is pressed, then open the claw.
		{
			motor[clawMotor] = REVERSEPOWER;
		}
		else                      		//Otherwise if no button is pressed, then stop the claw.
		{
			motor[clawMotor] = 0;
		}
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
