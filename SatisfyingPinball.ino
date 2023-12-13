// Jens Maker Adventures
// Code for my satisfying steel marble launching toy
// 13-12-2023

#define stepPin 2
#define dirPin 5 
#define rotaryPinA 7
#define rotaryPinB 6

// TMC2208 or similar stepper controller is necessary to control the stepper motor

int speedMax = 300; // us delay between steps. This is the lowest we can go for max speed
int speedMin = 3500; // us
int speed = 2500; // us

bool aLastState = false;
 
void setup() {
  Serial.begin(9600);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(rotaryPinA,INPUT);
  pinMode(rotaryPinB,INPUT);
  digitalWrite(dirPin,HIGH); // Set the motor to move in the right direction
}

void loop() {
  if(speed>(speedMin-200)) // disable motion if speed is set low enough
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(speed);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(speed); 
  }

  if(digitalRead(rotaryPinA) != aLastState) // movement detected
  {
    if(digitalRead(rotaryPinB) != aLastState) //clockwise
    {
      
      if(speed < speedMin) {speed = speed + 100;}
      else { speed = speedMin;}
    }
    else // counterclockwise
    {
      if(speed > speedMax) {speed = speed - 100;} 
      else { speed = speedMax;}
    }
    aLastState = digitalRead(rotaryPinA);
  }  
}