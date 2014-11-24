#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     driveRight,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     winch,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     driveLeft,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     arm,           tmotorTetrix, openLoop)

#include "JoystickDriver.c"

void tankdrive() {
		motor[driveLeft] = (joystick.joy1_y1 / 1.28);
		motor[driveRight] = (joystick.joy1_y2 / 1.28);
}

void winchcontrol() {
	motor[winch] = (joystick.joy2_y2 / 1.28);
	//put autolift code here
}

void armcontrol() {
	if(joystick.joy2_TopHat == 2) {
		motor[arm] = 100;
	}
	else if(joystick.joy2_TopHat == 6) {
		motor[arm] = -100;
	}
	else {
		motor[arm] = 0;
	}
	//put autodump code here later
}

task main()
{
	while(true) {
		getJoystickSettings(joystick);
		tankdrive();
		winchcontrol();
		armcontrol();
	}

}
