#include <Servo.h>

NIL_WORKING_AREA(waThread4, 200);
NIL_THREAD(Thread4, arg) {

  Servo myservo;  // create servo object to control a servo 

    int servoEventStatus=0;
  byte servoIncrease=1;
  myservo.attach(IO6);  // attaches the servo on pin IO6 to the servo object 


  while (TRUE) {
    Serial.println(servoIncrease);
    Serial.println(servoEventStatus);
    servoEventStatus+=getParameter(PARAM_SERVO)*servoIncrease;
    if ((servoEventStatus>180 && servoIncrease>0) || (servoEventStatus<1 && servoIncrease<0)) {
      servoIncrease*=-1;
    }
    myservo.write(servoEventStatus); 

    nilThdSleepMilliseconds(400);

  }

}





