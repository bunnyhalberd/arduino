/*
    This is project 06 from the starter kit
*/

int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
const int sensorPin = A0;

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    while (millis() < 5000)
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
}

void loop()
{
    sensorVal = analogRead(sensorPin);

    int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000);
    tone(8, pitch, 20);

    delay(10);
}
