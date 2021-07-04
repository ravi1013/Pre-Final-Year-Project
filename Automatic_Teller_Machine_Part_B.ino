// Full code is not added.
/**                  Project Title-AUTOMATIC TELLER MACHINE.            
 *                   
 *            PART-B 
 *            
 *          ->It gives two options or services,either the user can use keypad to access the account                      
 *                                    (or)
 *              He/She can access the account by Provided Card,which is scanned by RFID Reader.                   
 *   
 *          ->This includes a 4*4 Keypad which is displayed on LCD and 
 *                Consists of RFID reader which displays entire Bank Account details on Serial Monitor.  
 *          ->The microcontroller/Processor board used is Arduino ATMega2560.      
 */
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53   //sda-10(53),sck-13(52),mosi-11(51),miso-12(50),gnd-gnd,rst-9(49),3.3v-3.3v9
#define RST_PIN 49
#define LED_PIN A0
#define RED_LED A1

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(44, 42, 39, 41, 43, 45);//RS,EN,D4,D5,D6,D7

#include <Password.h> 
#include <Keypad.h> //header for keypad commands enabling

Password password = Password( "45B0" );

const byte ROWS = 4; // Four rows
const byte COLS = 4; //  columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'D','C','B','A'},

  {'#','9','6','3'},

  {'0','8','5','2'},

  {'*','7','4','1'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 36,34,32,30};

// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 28,26,24,22 };

// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
}

void loop()

 {
}
