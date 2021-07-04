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
   {
  Serial.begin(9600);
  Serial.println("\t\t\t\t\tWelcome To ATM.");
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("Please Insert your card to the reader...");
  Serial.println();

  pinMode(LED_PIN,OUTPUT);
  pinMode(RED_LED,OUTPUT);
}

 lcd.begin(16, 2);//initializing LCD
  lcd.setCursor(0,0);
  lcd.print("Enter the PIN :");
  lcd.setCursor(2,1);
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
}

void loop()

 {
  keypad.getKey();
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  Serial.println();
  Serial.print("Your UID Tag is : ");
  Serial.println(strID);
  Serial.print("Message \t: ");

  //Test LED
 if (strID.indexOf("97:EF:C8:3A") >= 0)   //card-97:EF:C8:3A   tag-3B:7E:44:1B  ID:54:43:07:1A
  //int a=strID.indexOf("54:43:07:1A");
  {
    
    digitalWrite(LED_PIN,HIGH);
    delay(1000);
    digitalWrite(LED_PIN,LOW);
    Serial.println("Access granted");
    delay(500);
    { 
       Serial.println();
       Serial.print("\t\tAccount Number \t:");
       Serial.println("004456632556");
       Serial.print("\t\tIFS Code \t:");
       Serial.println("SBIN1230098");
       Serial.print("\t\tAccount Type \t:");
       Serial.println("Savings Account");
       Serial.print("\t\tBranch Name \t:");
       Serial.println("COFFEE BOARD LAYOUT");
       Serial.print("\t\tCustomer Name \t:");
       Serial.println("Mr.RAVI KUMAR.P");
       Serial.print("\t\tPhone No \t:");
       Serial.println("8310917416");\
       Serial.println();
       Serial.print("\t\t\t====ACCOUNT SUMMERY====");
       Serial.println();
       Serial.println();
       Serial.print("\t\t\tSanctioned Limit \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tAvailable Balance \t:");
       Serial.println("9,500.50Rs");
       Serial.print("\t\t\tMOD Balance \t\t:");  //Multi option deposit scheme,linked with savings Acc.
       Serial.println("0.00Rs");
       Serial.print("\t\t\tUncleared Balance \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tLien Amount \t\t:");  //Acc. is frozen or the amt cannot be withdrawed.
       Serial.println("0.00Rs");     
       Serial.println("---------------------------------------------------------------------");  
    }
    
    Serial.println();
    delay(3000);
  }
    else if (strID.indexOf("55:19:66:1F") >= 0)   
  //int a=strID.indexOf("54:43:07:1A");
  {
    digitalWrite(LED_PIN,HIGH);
    delay(1000);
    digitalWrite(LED_PIN,LOW);
    Serial.println("Access granted");
    delay(500);
    { 
       Serial.println();
       Serial.print("\t\tAccount Number \t:");
       Serial.println("005568955532");
       Serial.print("\t\tIFS Code \t:");
       Serial.println("SBIN1230789");
       Serial.print("\t\tAccount Type \t:");
       Serial.println("Savings Account");
       Serial.print("\t\tBranch Name \t:");
       Serial.println("YELLAHANKA");
       Serial.print("\t\tCustomer Name \t:");
       Serial.println("Mr.Shanawaz");
       Serial.print("\t\tPhone No \t:");
       Serial.println("9861355568");\
       Serial.println();
       Serial.print("\t\t\t====ACCOUNT SUMMERY====");
       Serial.println();
       Serial.println();
       Serial.print("\t\t\tSanctioned Limit \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tAvailable Balance \t:");
       Serial.println("20,590.50Rs");
       Serial.print("\t\t\tMOD Balance \t\t:");  //Multi option deposit scheme,linked with savings Acc.
       Serial.println("0.00Rs");
       Serial.print("\t\t\tUncleared Balance \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tLien Amount \t\t:");  //Acc. is frozen or the amt cannot be withdrawed.
       Serial.println("0.00Rs");     
       Serial.println("---------------------------------------------------------------------");        
    }
    
    Serial.println();
    delay(3000);
  }
   else if (strID.indexOf("54:43:07:1A") >= 0)   
  int a=strID.indexOf("54:43:07:1A");
  {
    digitalWrite(LED_PIN,HIGH);
    delay(1000);
    digitalWrite(LED_PIN,LOW);
    Serial.println("Access granted");
    delay(500);
    { 
       Serial.println();
       Serial.print("\t\tAccount Number \t:");
       Serial.println("004456632556");
       Serial.print("\t\tIFS Code \t:");
       Serial.println("SBIN1230098");
       Serial.print("\t\tAccount Type \t:");
       Serial.println("Savings Account");
       Serial.print("\t\tBranch Name \t:");
       Serial.println("COFFEE BOARD LAYOUT");
       Serial.print("\t\tCustomer Name \t:");
       Serial.println("Mr.RAVI KUMAR.P");
       Serial.print("\t\tPhone No \t:");
       Serial.println("8310917416");\
       Serial.println();
       Serial.print("\t\t\t====ACCOUNT SUMMERY====");
       Serial.println();
       Serial.println();
       Serial.print("\t\t\tSanctioned Limit \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tAvailable Balance \t:");
       Serial.println("9,500.50Rs");
       Serial.print("\t\t\tMOD Balance \t\t:");  //Multi option deposit scheme,linked with savings Acc.
       Serial.println("0.00Rs");
       Serial.print("\t\t\tUncleared Balance \t:");
       Serial.println("0.00Rs");
       Serial.print("\t\t\tLien Amount \t\t:");  //Acc. is frozen or the amt cannot be withdrawed.
       Serial.println("0.00Rs");     
       Serial.println("---------------------------------------------------------------------");        
    }
    
    Serial.println();
    delay(3000);
  }
  
  else
  //if(strID.indexOf("54:43:07:1A") >= 1);
  {
    digitalWrite(RED_LED,HIGH);
    delay(1000);
    digitalWrite(RED_LED,LOW);
    Serial.println(" Access denied! \n \t\t\tPlease come after Sometime..");
    Serial.println("======================================================================");
    delay(3000);
  }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

}

//take care of some special events
void keypadEvent(KeypadEvent eKey){
  switch (keypad.getState())
  {
    case PRESSED:
  lcd.print(eKey);
  switch (eKey){
    case '*': checkPassword(); break;   //* is to validate password   
    case '#': password.reset(); break;  //# is to reset password attempt
    default: password.append(eKey);
     }
  }
}
 
void checkPassword()
{ 
  if (password.evaluate())
  {
  lcd.setCursor(2,2);
    lcd.print("Access Granted.");
    delay(5000);
    lcd.clear();
  }
  else
  {
     lcd.setCursor(2,3);
    lcd.print("INVALID PIN!");
    delay(5000);
    lcd.clear();
  }
    //delay(2000);
  // lcd.clear();  
}
