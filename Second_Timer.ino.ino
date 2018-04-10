/*
 * Second Timer
 * ============
 * 
 * This code enables you to use millis() without having to store multiple unsigned long int variables to keep track of your timers.
 * It also makes it easire to enter the necessary calculations.
 * It could be adapted to work directly with milliseconds, microseconds and even the other way to minutes, hours and days.
 */

//Important variables - Place this section at the top of your code.
int startLoopSeconds = 0;
int endLoopSeconds = 0;
unsigned long previousMillis = millis();
unsigned long previousMillisOld;
//End of important variables.


void setup(){
  
}

void loop(){

//Time check - Put this code at the start of your main loop().
if(millis() - previousMillis >= 1000){
startLoopSeconds++;
endLoopSeconds = startLoopSeconds;
previousMillisOld = previousMillis;
previousMillis = millis();
}
//End of time check

//Add your code here

//End of loop timer - Place this at the end of your main loop().
if(millis() - previousMillisOld >= 1000){
  endLoopSeconds++;
}
//End of end of loop timer.

}
