#pragma config(Sensor, in5,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
#include "../headerfiles/constants.h"

/*----------------------------------------------------------------------------------------------------*\
|*                                   - Verkefni 5: Triple Sensor Line Tracking -                      *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                            								Description:																						*|
|*							This project uses the line sensors to follow and drive the robot on black lines.	   	*|
|*                               																																		  *|
\*----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);          // The program waits for 2000 milliseconds before continuing.

  bool wasLeft; 						// THIS BOOLEAN CHECKS IF THE LAST MOVE THE ROBOT MADE BEFORE LOSING TRACK OF THE LINE WAS LEFT OR NOT
  													// IT IS USED IN THE CODE TO FIND ITS WAY BACK TO THE LINE IF IT DRIVES OFF TRACK.

  int threshold = 2100;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  while(vexRT[Btn8U] == 0)
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+


    if(SensorValue(lineFollowerRIGHT) > threshold && SensorValue(lineFollowerCENTER) > threshold)
    {
    	motor[leftMotor]  = 80;
      motor[rightMotor] = 80;
      wasLeft = false;
    }

    if(SensorValue(lineFollowerLEFT) > threshold && SensorValue(lineFollowerCENTER) > threshold)
    {
    	motor[leftMotor]  = 80;
      motor[rightMotor] = 80;
      wasLeft = true;
    }

    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = 80;
      motor[rightMotor] = 30;
      wasLeft = false;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight. Middle doesnt need to declare wasLeft because they are going straight.
      motor[leftMotor]  = 80;
      motor[rightMotor] = 80;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 30;
      motor[rightMotor] = 80;
      wasLeft = true;
    }

    // Herna atti ad koma i veg fyrir ef skyldi thurfa ad beyja alveg, en thad thurfti ekki fyrir thetta verkefni.
    // thad virkar lika ekki alveg.
    /*
   if(SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold && SensorValue(lineFollowerLEFT) && threshold
     && wasLeft == true)
   {
     while(SensorValue(lineFollowerCENTER) < threshold && SensorValue(lineFollowerLEFT) < threshold)
     {
     motor[leftMotor]  = 0;
     motor[rightMotor] = 127;
   	 }
   }
   if(SensorValue(lineFollowerLEFT) < threshold && SensorValue(lineFollowerRIGHT) < threshold && SensorValue(lineFollowerLEFT) && threshold
     && wasLeft == false)
   {
     while(SensorValue(lineFollowerCENTER) < threshold && SensorValue(lineFollowerLEFT) < threshold)
     {
     motor[leftMotor]  = 127;
     motor[rightMotor] = 0;
   	 }
   }
   */
  }
}
