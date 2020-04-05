// Stepper motor run code with a4988 driver
// by Superb

const int stepPin = 3;
 int dirPin = 4; 
int dirButton = 2;
int state = HIGH;
int reading;
int previous = LOW;
int stepDelay=1000;


long time = 0;
long debounce = 200;


void setup() {
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
pinMode(dirButton, INPUT_PULLUP);



}

void loop() {
  reading = digitalRead(dirButton);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }

  digitalWrite(dirPin, state);

  previous = reading;

digitalWrite(stepPin, HIGH);
delayMicroseconds(stepDelay);
digitalWrite(stepPin, LOW);
delayMicroseconds(stepDelay);
}



