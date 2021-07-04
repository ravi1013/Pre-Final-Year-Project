/**                  Project Title-AUTOMATIC TELLER MACHINE.
 *                   
 *          PART-A
 *                             
 *       ->In this we can find Ultrasonic sensor,in which we have used for counting 
 *                          the number of people near the ATM machine while accessing the account in Bank.                       
 *       ->At the same time a command is given by the Speaker,how to access the account.
 *             (This is done by using SD_card Module + Speaker.)
 *       ->Extra feature added is Automatic Dark Light Sensor.
 *                (During night time the light is automatically ON with the help of LDR & RELAY sensors)
 *       ->The microcontroller board used is Arduino UNO.          
 */
#include <LiquidCrystal.h>
#include <SD.h>                           //include SD module library
#include <TMRpcm.h>                       //include speaker control library

#define SD_ChipSelectPin 10                //define CS pin
                                          //cs-4(14),sck-13,mosi-11,miso-12
TMRpcm tmrpcm;

//initialize the pins
const int trigPin = 6;
const int echoPin = 5;
const int buzzled = 7;
int count = 0;

//initialize the variables
long duration;
int distance;

#define LIGHT 2 // define pint 2 for sensor
#define RELAY 3 // define pin 3 as for relay

void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(buzzled,OUTPUT);

 tmrpcm.speakerPin = 9;             //define speaker pin. 
                                    //you must use pin 9 of the Arduino Uno and Nano
                                    //the library is using this pin
 Serial.begin(9600);

 Serial.println("\t\t\t\t\tWelcome To ATM.");
 Serial.println("\tDiplaying the Data entry of people entering in the Bank.");
 pinMode(LIGHT, INPUT_PULLUP);// define pin as Input  sensor
 pinMode(RELAY, OUTPUT);// define pin as OUTPUT for relay

}

void loop() {
  // put your main code here, to run repeatedly:
   int L =digitalRead(LIGHT);// read the sensor
      if(L == 1){
    digitalWrite(RELAY,LOW);// turn the relay ON
    Serial.println(" light is ON");
  }else{
     digitalWrite(RELAY,HIGH);// turn the relay OFF
     Serial.println("  === light is OFF");    
  }
  delay(500);
  */
digitalWrite(trigPin,HIGH);
delayMicroseconds(500);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH); /*it starts counting number of microseconds until echoPin goes High &
                                  store that value to the variable duration,
                                   now this duration is then converted to the distance by the formula*/
distance = (duration/2)/29.1;
delay(200);
if(distance<25)
{
  tone(buzzled,1000);
  count++;

  Serial.print("Distance = ");
Serial.print(distance);
Serial.print("cm");
Serial.println(" ");
Serial.print("Number of person = ");
Serial.print(count);
Serial.println(" ");
delay(500);
Serial.println(" ");
  {
 (!SD.begin(SD_ChipSelectPin));       //see if the card is present and can be initialized
                                  
  tmrpcm.setVolume(6);                    //0 to 7. Set volume level
  tmrpcm.play("1.wav");         //the sound file "1" will play each time the arduino powers up, or is reset
  }
}
else
noTone(buzzled);
}
