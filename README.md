# Arduino Second Timer
Some light code to make timing your circuits much easier and lighter.

In a recent discussion on one fo the Arduino groups on Facebook we discussed the disadvantages of using millis() to time code rather than delay().

Of course, delay() has the huge disadvantage of locking up your code until the delay is complete. This may be okay ion the simplest of projects, but, for example, if you try to flash two lights at differrent rates, or you try to remain in control of a motor while a light flashes you will run in to difficulties!

The main disadvantage we briefly discussed with millis() was the need to create multiple unsigned long variables. A new such variable is required for each timer. In my own experience I know that this can make code 'clunky', difficult to read and debug, and an absolute headache to work with. Another disadvantage was that the maths involved (although simple when understood) can appear to be daunting, not very friendly to new users.

This code makes life much easier. It requires four unsigned long variables no matter how many timed events your code includes. It counts in seconds for ease as I believe most basic projects tend to stick to second timings (I'll be looking at writing a version that works with milliseconds and possibly microseconds too). Multiple test cases can be added with no further variables and, although there is an extra condition to add to each test, the maths involved is farily simple. See the below example of a test condition:

if(startLoopSeconds%3 == 0 && startLoopSeconds == endLoopSeconds){
Serial.println("Three seconds have passed since the last three second message.");
}

The startLoopSeconds and endLoopSeconds variables are built into the code. The only part of this line the user would have to change to alter the timing is the number 3 (this condition tests for 3 seconds passing). Of course, a variable could also be used. The rest of the test condition should remain the same to avoid code running multiple times.

To use the code you will need to place three ections of it into your own code, as follows:

Section one - at the start of your code before the setup() loop:

unsigned long startLoopSeconds = 0;
unsigned long endLoopSeconds = 0;
unsigned long previousMillis = millis();
unsigned long previousMillisOld;


Section two - at the start of your void() loop:

if(millis() - previousMillis >= 1000){
startLoopSeconds++;
endLoopSeconds = startLoopSeconds;
previousMillisOld = previousMillis;
previousMillis = millis();
}


Section three - at the end of your void() loop:

if(millis() - previousMillisOld >= 1000){
  endLoopSeconds++;
}

It's taken a bit of trial and error to get a working system and this is the first version that does as required. There may well be room for improvement, so don't hesitate to let me know if you believe that to be the case.
