/*
    Proof of concept thing that uses the light sensor to gather data and send
    it to a servo
*/

#include <Servo.h>

int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;
const int sensorPin = A0;

const int ledPin = 13;

Servo myServo;
const int servoPin = 9;

void setup()
{
    pinMode(ledPin, OUTPUT);
    
    // Wait for the serial port
    while(!Serial) {}

    Serial.begin(115200);
    delay(1000);

    Serial.println("attaching to the servo");
    myServo.attach(servoPin);
    Serial.println("done");

    // Reset the servo back to a normal location
    Serial.println("resetting servo");
    myServo.write(0);
    delay(750);
    myServo.write(180);
    delay(750);
    myServo.write(90);


    Serial.println("starting calibration loop");
    digitalWrite(ledPin, HIGH);

    int startTime = millis();
    int endTime = startTime + 5000;
    while (millis() < endTime)
    {
        sensorVal = analogRead(sensorPin);
        if (sensorVal > sensorHigh)
        {
            sensorHigh = sensorVal;
        }
        if (sensorVal < sensorLow)
        {
            sensorLow = sensorVal;
        }
    }

    digitalWrite(ledPin, LOW);

    Serial.print("high val: ");
    Serial.print(sensorHigh);
    Serial.print(", low val: ");
    Serial.println(sensorLow);

}

void loop()
{
    sensorVal = analogRead(sensorPin);
    int angle = map(sensorVal, sensorLow, sensorHigh, 0, 179);
    //Serial.print("read value: ");
    //Serial.print(sensorVal);
    //Serial.print(", mapped to angle: ");
    //Serial.println(angle);

    myServo.write(angle);

    // Drop the angle to the serial port so the PC can get it
    Serial.println(angle);

    delay(100);



}
