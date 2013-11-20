#pragma config(Sensor, S4,     sonarSensor,         sensorSONAR)
#pragma config(Sensor, S3,     lightSensor,         sensorLightActive)
bool on = true;
task stop()
{
	while(true) {
		if(SensorValue(lightSensor) < 80) {
			on = false;
			motor[motorC] = 0;
			motor[motorB] = 0;
		}
	}
}

task display()
{
	while(true) {
		nxtDisplayCenteredTextLine(0, "Sonar Reading");
		nxtDisplayCenteredBigTextLine(2, "%d", SensorValue(sonarSensor));
		wait1Msec(200);
	}
}

task main()
{
	motor[motorC] = 100;
	motor[motorB] = 100;
	wait1Msec(1000);
	//StartTask(stop);
	StartTask(display);
  int sonarValue;
  int distance = 40;
	int lv = 30;
	int v = 30;
	int dif = 30;
  while(on)
  {
    sonarValue = SensorValue(sonarSensor);
    v = sonarValue;
    int x = 20;
    int y = 80;

    if(SensorValue(sonarSensor) != -1 && SensorValue(sonarSensor) < distance) {
			if(abs(v-lv)<dif) {
		  	motor[motorC] = x;
		    motor[motorB] = y;
	  	} else {
		 		motor[motorC] = 0;
		    motor[motorB] = 100;
	  		wait1Msec(100);
	  		motor[motorC] = 100;
		    motor[motorB] = 100;
	  		wait1Msec(800);
			}
    } else {
    	motor[motorC] = y;
    	motor[motorB] = x;
  	}
		lv = v;
  }
}
