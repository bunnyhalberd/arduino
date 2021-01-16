/*
    This is project 03 from the starter kit!
*/

const int sensorPin = A0;
const float baselineTemp = 19.0;

void setup()
{
    // Open the serial port at 9600 baud
    Serial.begin(9600);

    for(int pinNumber = 2; pinNumber < 5; pinNumber++)
    {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void setLights(int light1, int light2, int light3)
{
        digitalWrite(2, light1);
        digitalWrite(3, light2);
        digitalWrite(4, light3);   
}

void loop()
{
    int sensorVal = analogRead(sensorPin);

    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);

    float voltage = (sensorVal / 1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);
    
    float temperature = (voltage - 0.5) * 100;
    Serial.print(", Degrees C: ");
    Serial.println(temperature);


    // Show something fun on the LEDs
    if(temperature < baselineTemp + 2)
    {
        setLights(LOW, LOW, LOW);
    }
    else if(temperature >= baselineTemp + 2 && temperature < baselineTemp + 4)
    {
        setLights(HIGH, LOW, LOW);
    }
    else if(temperature >= baselineTemp + 4 && temperature < temperature + 6)
    {
        setLights(HIGH, HIGH, LOW);
    }
    else
    {
        setLights(HIGH, HIGH, HIGH);
    }

    delay(1);

}

