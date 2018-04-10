/*
 * Second Timer
 * ============
 * 
 * This code enables you to use millis() without having to store multiple unsigned long variables to keep track of your timers.
 * It also makes it easire to enter the necessary calculations.
 * It could be adapted to work directly with milliseconds, microseconds and even the other way to minutes, hours and days.
 * 
 * This version has samples included. Feel free to remove the Serial.begin line in setup() and the test condition lines.
 */

//Important variables - Place this section at the top of your code.
unsigned long startLoopSeconds = 0;
unsigned long endLoopSeconds = 0;
unsigned long previousMillis = millis();
unsigned long previousMillisOld;
//End of important variables.


void setup(){
  
//Serial.begin for sample code - Feel free to remove this.
Serial.begin(9600);
//End of Serial.begin.

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


//Sample test conditions, delete these and replace with your own code.
if(startLoopSeconds%1 == 0 && startLoopSeconds == endLoopSeconds){
  Serial.println(String(startLoopSeconds) + " seconds since start.");
}
if(startLoopSeconds%3 == 0 && startLoopSeconds == endLoopSeconds){
Serial.println("Three seconds have passed since the last three second message.");
}
if(startLoopSeconds%10 == 0 && startLoopSeconds == endLoopSeconds){
Serial.println("Ten seconds have passed since the last ten second message.");
}
//End of sample test conditions.

//End of loop timer - Place this at the end of your main loop().
if(millis() - previousMillisOld >= 1000 || endLoopSeconds == 0){
  endLoopSeconds++;
}
//End of end of loop timer.

}
