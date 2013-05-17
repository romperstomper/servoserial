#include <Servo.h>

Servo servo1; 
int value;
const int MaxChars = 3; // an int string contains up to 5 digits and
 // is terminated by a 0 to indicate end of string
char strValue[MaxChars+1]; // must be big enough for digits and terminating null
int index = 0; // the index into the array storing the received digits
void setup() {

  servo1.attach(2);
  Serial.begin(9600);
  Serial.println("Ready");
  servo1.write(0);
}
void (*pseudoReset)(void)=0;

void loop() {
   if( Serial.available()){
     char ch = Serial.read();
     if(index < MaxChars && ch >= '0' && ch <= '9'){
       strValue[index++] = ch; // add the ASCII character to the string;
       }
   else{// here when buffer full or on the first non digit
     strValue[index] = 0; // terminate the string with a 0
     value = atoi(strValue); // use atoi to convert the string to an int
     index = 0;
   Serial.println(value);  
   servo1.write(value);
//   delay(1000);
//   pseudoReset ();
   delay(1000);
 }
 }
}
