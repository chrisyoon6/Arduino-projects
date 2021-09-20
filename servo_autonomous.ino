// --------------------------------------------------------------------------------------
// Author: Chris Yoon
// Date: March 06, 2021
// --------------------------------------------------------------------------------------

#include <NewPing.h>
#include <Servo.h> 
/* pin locations on Arduino UNO */
#define VCC_PIN 13
#define TRIGGER_PIN 12    
#define ECHO_PIN 11      
#define GROUND_PIN 10
#define MAX_DISTANCE 200  // fmaximum distance set to 200 cm

#define ANGLE_OPEN 105
#define ANGLE_CLOSE 0
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // initialize NewPing
Servo myservo;  // create servo object to control a servo

/*
 * Purpose: Setup for the Arduino - set up pin modes, and initialize output
 * Return: none
 */
void setup()
{
  Serial. begin(9600);            // set data transmission rate to communicate with computer
  
  pinMode(ECHO_PIN, INPUT) ;  
  pinMode(TRIGGER_PIN, OUTPUT) ;
  pinMode(GROUND_PIN, OUTPUT);    
  pinMode(VCC_PIN, OUTPUT);     
  
  digitalWrite(GROUND_PIN,LOW);   // tell pin 10 to output LOW (OV, or ground)
  digitalWrite(VCC_PIN, HIGH) ;   // tell pin 13 to output HIGH (+5V)
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

bool isOpen = true;
int turn = ANGLE_CLOSE; // pos. of servo (open, close)

/*
 * Purpose: Program loop: turns the servo motor if ultrasonic sensor detects an object nearby
 * Return: none
 */
void loop() 
{  
  delay(100);                            
  int DISTANCE_IN_CM = sonar.ping_cm();   // read and update from sonar
  
  if (DISTANCE_IN_CM < 10){

    if (isOpen){    // each turn reverses from one pos to another
      turn = ANGLE_CLOSE; 
    }
    else{
      turn = ANGLE_OPEN;
    }
      /* update state */
      delay(3000); 
      myservo.write(turn);   // updates servo position with angle
      delay(3000); 
      isOpen = !isOpen;                   
  }

  Serial.print("Ping: ");                 
  Serial.print(DISTANCE_IN_CM);          
  Serial.println("cm");                   
  Serial.print(turn);
}
