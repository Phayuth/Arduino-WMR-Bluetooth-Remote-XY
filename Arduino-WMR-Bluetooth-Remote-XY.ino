
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL Serial
#define REMOTEXY_SERIAL_SPEED 9600
#define REMOTEXY_ACCESS_PASSWORD "1234"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,4,0,0,0,32,0,10,13,0,
  5,32,10,17,30,30,2,26,16,1,
  0,56,26,12,12,2,31,76,0,1,
  0,74,26,12,12,2,31,82,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystickx; // =-100..100 x-coordinate joystick position 
  int8_t joysticky; // =-100..100 y-coordinate joystick position 
  uint8_t button_1; // =1 if button pressed, else =0 
  uint8_t button_2; // =1 if button pressed, else =0 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)


// Motor A
 
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
 
int enB = 3;
int in3 = 5;
int in4 = 4;
 
// Motor Speed Values - Start at zero
 
int MotorSpeed1 = 0;
int MotorSpeed2 = 0;
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
  RemoteXY_Handler ();
  RemoteXY.joystickx = 0;
  RemoteXY.joysticky = 0;
  RemoteXY_Init (); 
  if (RemoteXY_Init ())
  {
  Serial.println("Successfully Init");
  }
  
  // Set all the motor control pins to outputs
 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   
  // Start with motors disabled and direction forward
  
  // Motor A
  
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Motor B
  
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}
 
void loop() {
 
  // Determine if this is a forward or backward motion
  // Do this by reading the Verticle Value
  // Apply results to MotorSpeed and to Direction
  RemoteXY_Handler ();
 
  
  if (RemoteXY.joysticky > 100) RemoteXY.joysticky = 100;
  if (RemoteXY.joysticky < -100) RemoteXY.joysticky = -100;
  if (RemoteXY.joysticky < 0)
  {
    // This is Backward
 
    // Set Motor A backward
 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
 
    // Set Motor B backward
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
 
    //Determine Motor Speeds
 
    // As we are going backwards we need to reverse readings
 
    //RemoteXY.joysticky = RemoteXY.joysticky * -1;  // Make the number positive
  
    MotorSpeed1 = (-RemoteXY.joysticky)*2.55;
    MotorSpeed2 = (-RemoteXY.joysticky)*2.55;
 
  }
  
  else if (RemoteXY.joysticky > 0)
  {
    // This is Forward
 
    // Set Motor A forward
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
 
    // Set Motor B forward
 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
 
    //Determine Motor Speeds
 
    //MotorSpeed1 = map(RemoteXY.joysticky, 0, 100, 0, 255);
    //MotorSpeed2 = map(RemoteXY.joysticky, 0, 100, 0, 255); 
    MotorSpeed1 = RemoteXY.joysticky*2.55;
    MotorSpeed2 = RemoteXY.joysticky*2.55;
  }
  else
  {
    // This is Stopped
 
    MotorSpeed1 = 0;
    MotorSpeed2 = 0; 
 
  }
  
  // Now do the steering
  // The Horizontal position will "weigh" the motor speed
  // Values for each motor
  if (RemoteXY.button_1 == 1)
  {
    // Move Left
 
    // Set Motor A backward
 
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    // Set Motor B forward
 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
   
    //MotorSpeed1 = MotorSpeed1 - ((-RemoteXY.joystickx)*2.55);
    //MotorSpeed2 = MotorSpeed2 + ((-RemoteXY.joystickx)*2.55);
  
    MotorSpeed1 = 180;
    MotorSpeed2 = 180;
    
    // Don't exceed range of 0-255 for motor speeds
 
    if (MotorSpeed1 < 0) MotorSpeed1 = 0;
    if (MotorSpeed2 > 255) MotorSpeed2 = 255;
 
  }
  else if (RemoteXY.button_2 == 1)
  {
    // Move Right

    // Set Motor A forward
 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    // Set Motor B backward
 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    //MotorSpeed1 = MotorSpeed1 + ((RemoteXY.joystickx*2.55));
    //MotorSpeed2 = MotorSpeed2 - ((RemoteXY.joystickx*2.55));
 
    MotorSpeed1 = 180;
    MotorSpeed2 = 180;
    
    // Don't exceed range of 0-255 for motor speeds
 
    if (MotorSpeed1 > 255) MotorSpeed1 = 255;
    if (MotorSpeed2 < 0) MotorSpeed2 = 0;      
 
  }
 
  // Adjust to prevent "buzzing" at very low speed
 
  if (MotorSpeed1 < 8)MotorSpeed1 = 0;
  if (MotorSpeed2 < 8)MotorSpeed2 = 0;
 
  
  //Set the motor speeds
 
  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2); 


}