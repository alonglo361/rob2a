#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)

// Functions Prototypes
void Forward(int tickingGoal);
void Turn(float r, bool clockwise);

// Declare Global Variables
const float onedegreeturn = 3.2972441;  // One degree.

task main()
{
	SensorValue[leftEncoder] = 0;
	int distance_needed = 50; //How much distance we want to travel in cm's
	int drivecm = (distance_needed/33) * 360;

	wait1Msec(1000);
	Forward(drivecm);
	Turn(onedegreeturn, true);
	Forward(drivecm);
	Turn(onedegreeturn, false);
	Forward(drivecm);
	Turn(onedegreeturn, false);
	Forward(drivecm);
}


void Forward(int tickingGoal)
{
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	while(abs(SensorValue[leftEncoder]) < tickingGoal)
	{
		motor[rightMotor] = 63;
		motor[leftMotor]  = 63;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}


void Turn(float r, bool clockwise)
{
  SensorValue[rightEncoder] = 0;    /* Clear the encoders for    */
  SensorValue[leftEncoder]  = 0;    /* consistancy and accuracy. */

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  if(clockwise == true)
  {
	  while(SensorValue[rightEncoder] < (r * 90) && SensorValue[leftEncoder] > (-1 * r * 90))
	  {
	    motor[rightMotor] = 63;         // Run the right motor forward at half speed
	    motor[leftMotor]  = -63;        // Run the left motor backward at half speed
	  }
	}
	else if (clockwise == false)
	{
		while(SensorValue[rightEncoder] > (-1 * r * 90) && SensorValue[leftEncoder] < (r * 90))
	  {
	    motor[rightMotor] = -63;         // Run the right motor forward at half speed
	    motor[leftMotor]  = 63;        // Run the left motor backward at half speed
	  }
	}
  motor[rightMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[leftMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
