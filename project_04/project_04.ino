/*
    This is project 04 from the starter kit!

    What it does is pull the value from three sensors with colored tape over them
    and then makes the tri-color LED reflect those values.
*/

const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(greenLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);

}

void loop()
{
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);
    delay(5);

    Serial.print("Raw sensor values \t red: ");
    Serial.print(redSensorValue);
    Serial.print("\t green: ");
    Serial.print(greenSensorValue);
    Serial.print("\t blue: ");
    Serial.println(blueSensorValue);

    // Now let's go make the LED look like this
    redValue = redSensorValue / 4;
    greenValue = greenSensorValue / 4;
    blueValue = blueSensorValue / 4;

    Serial.print("mapped sensor values \t red: ");
    Serial.print(redValue);
    Serial.print("\t green: ");
    Serial.print(greenValue);
    Serial.print("\t blue: ");
    Serial.println(blueValue);

    analogWrite(redLEDPin, redValue);
    analogWrite(greenLEDPin, greenValue);
    analogWrite(blueLEDPin, blueValue);

}