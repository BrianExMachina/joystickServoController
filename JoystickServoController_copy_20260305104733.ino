   #include<Servo.h> //inmport Servo library
  
   Servo servoY; //name servo motor 
      
   Servo servoX;

   int posX; // declare posX and posY outside of the "global scope" now they can be used anywhere
   int posY;

   #define joyvalX A3//  connect the joyvalX wire to pin 3 to one joystick

   #define joyvalY A2 // connect the joyvalY wire to pin 2 of another joystick 
  
void setup() {
    

   servoY.attach(2); // attach the servo signal wire to pin 2

   servoX.attach(6); //attach the servo signal wire to pin 6

   Serial.begin(9600);// begin serial monitor with a rate of 9600 bits per second

}

void loop() {
       //Everything for the joystick and servos goes inside the loop to run continuously

    int JoyX=analogRead(joyvalX); // movement from joystick x-axis is tracked and read by analog pin 3 A3

    int JoyY=analogRead(joyvalY);// movement from the joystick y-axis is tracked and read by analog pin 2 A2
      
   posX= map(JoyX,0,1023,0,180);

    posY= map(JoyY,0,1023,0,180);//when the joystick moves the values are read that change due to resistance
      //map converts those values into 10 bits 0-1023 then 0-180 degrees to control the servo when the joystick moves
    
    servoY.write(posY);
    delay(500);
    servoX.write(posX);

      delay(500);// a half second delay to keep track of the position

      Serial.println("posY:" ); Serial.println(posY);
       delay(500);
      Serial.println("posX:" );  Serial.println(posX);
     

}
