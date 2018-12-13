#pragma config(Sensor, in2,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, ultrasonic,     sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#pragma DebuggerWindows("debugStream")
#include "../headerfiles/constants.h"

/*----------------------------------------------------------------------------------------------------*\
|*                                         - Verkefni 4 -                                             *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            								Description:																						*|
|*								This project drives the robot forward until it senses a wall, which      						*|
|*									it will then proceed to turn until it is no longer facing a wall. 								*|
|*                     			It also checks for button press and room lighting.                        *|
\*----------------------------------------------------------------------------------------------------*/


void Turn(float r)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders */
  SensorValue[leftEncoder]  = 0;

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)

		while(SensorValue[rightEncoder] > (-1 * r * 90) && SensorValue[leftEncoder] < (r * 90))
	  {
	    motor[rightMotor] = REVERSEHALFPOWER;         // Run the right motor forward at half speed
	    motor[leftMotor]  = HALFPOWER;        				// Run the left motor backward at half speed
	  }

  motor[rightMotor] = 0;  // Stop both motors
  motor[leftMotor]  = 0;
}

void Forward()
{
		motor[rightMotor] = POWER; //Drive forward
		motor[leftMotor]  = POWER;
}

void Backward() //Drive backward
{
	motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
  wait1Msec(500);
  motor[rightMotor] = REVERSEPOWER;
  motor[leftMotor]  = REVERSEPOWER;
  wait1Msec(700);
  motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
  wait1Msec(500);
}

task main()
{
	clearDebugStream();
	while(vexRT[Btn8U] == 0)
	{
		while(SensorValue(lightSensor) < 200)
		{
			if (SensorValue[ultrasonic] > 30)
			{
				Forward();
			}
			else if (SensorValue[ultrasonic] < 30)
			{
				Backward();
				Turn(ONEDEGREETURN);
				while(SensorValue[ultrasonic] < 55)
				{
					Turn(ONEDEGREETURN);
				}
			}
			else
			{
				writeDebugStreamLine("Ekkert herna");
			}
		}
		motor[rightMotor] = 0;
		motor[leftMotor]  = 0;
	}

}
