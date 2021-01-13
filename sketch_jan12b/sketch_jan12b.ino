
int switchState = 0;

int greenState = HIGH;

void setup() {

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}


void setAll(int state)
{
  for(int n = 3; n < 6; n++)
  {
    digitalWrite(n, state);
  }
}

void loop() {

 switchState = digitalRead(2);

 if (switchState == LOW)
 {
    digitalWrite(3, greenState);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    // Set up the green for the next frame
    if(greenState == LOW)
    {
      greenState = HIGH;
    }
    else
    {
      greenState = LOW;
    }

    delay(150);
    
 }
 else
 {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    delay(250);

    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

    delay(500);

    int delayTime = 500;
    for( int count = 0; count < 15; count++)
    {
      setAll(LOW);
      delay(delayTime);
      setAll(HIGH);
      delay(delayTime);

      delayTime = delayTime / 1.3;
    }

    setAll(HIGH);
    delay(1000);

    setAll(LOW);
    delay(2000);

    
 }

}
