/*
    Programs the EEPROM with data from the serial port
*/

const int ledPin = 13;

byte incomingData[4];

const byte SPACE = 0x32;

void setup()
{

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Wait for the serial port
    while (!Serial)
    {
    }

    Serial.begin(9600);
    delay(1000);

    Serial.println("Port open and ready");
    digitalWrite(ledPin, HIGH);
}

void loop()
{
  // send data only when you receive data:

  int currentByte = 0;
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    byte incomingByte = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);

    if(incomingByte == SPACE)
    {
      Serial.println("I see a space!");
    }

    incomingData[currentByte++] = incomingByte;

    

    
  }

}
