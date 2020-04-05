//ref_link: https://rudysarduinoprojects.wordpress.com/2019/07/08/fun-with-arduino-37-control-a-nema-17-stepper-motor-with-easy-driver/

#define NUM_POSITIONS     3
#define ENABLE_PIN       A0 // LOW = driver enabled
#define M1_PIN           A1 // M1 microstepping mode
#define M2_PIN           A2 // M2 microstepping mode
#define DIR_PIN          A3 // to DIR pin of driver
#define STEP_PIN         A4 // to DIR pin of driver
#define POTM_PIN         A5 // Used to change speed
#define POS_1_PIN         9 // LOW = go to pos 1
#define POS_2_PIN         8 // LOW = go to pos 2
#define POS_3_PIN        12 // LOW = go to pos 3
#define ZERO_PIN          6 // LOW = start find zero routine
#define ZERO_FOUND_PIN    7 // LOW = zero switch found
#define ONOFF_LED_PIN    13 // Motor running LED
#define DIR_LED_PIN       4 // Motor direction LED
#define PULSES_PER_REV  200 // Pulses per revolution

// Define number of positions, and steps from zero to each position
unsigned long tt_position[NUM_POSITIONS + 1] = {0,50,300,550};

byte dir, current_pos, new_pos, rpm, rpm_old;
unsigned long timeoflaststep;

#include <EEPROM.h>

void motor_enable() {
  digitalWrite(ENABLE_PIN,    LOW); // LOW = driver enabled
  digitalWrite(ONOFF_LED_PIN, HIGH);
  digitalWrite(DIR_PIN,       dir);
}

void motor_idle() {
  digitalWrite(ENABLE_PIN,    HIGH); // HIGH = driver disabled
  digitalWrite(ONOFF_LED_PIN, LOW);
}

void find_zero() {
  Serial.println("Finding zero sensor");
  dir = 0;
  motor_enable();
  while(digitalRead(ZERO_FOUND_PIN) == HIGH) {
    if ((micros() - timeoflaststep) > stepinterval()) {
      timeoflaststep = micros();
      digitalWrite(STEP_PIN, HIGH);
      //  delayMicroseconds(10); // only needed if step pulse is too short to be detected
      digitalWrite(STEP_PIN, LOW);
    }
  }
  motor_idle();
  Serial.println("Zero sensor found");
  Serial.println();
  current_pos = 0;
  new_pos = 1;
}

unsigned long stepinterval() { // calculates step timing based on potmeter input
  rpm = map(analogRead(POTM_PIN), 0, 1024, 1, 21) * 10; // max 200 rpm, else pulses get lost
  if(rpm != rpm_old) {
    Serial.print("RPM
    Serial.println(rpm);
    rpm_old = rpm;
  }
  return 60000000UL / PULSES_PER_REV / rpm;
}

void rotate(unsigned int numsteps) { 
  Serial.print("movingos ");
  Serial.print(new_pos);  
  Serial.print(" pulses ");
  Serial.print(numsteps);
  Serial.print(" dir ");
  Serial.println(dir);
  motor_enable();
  while(numsteps > 0) {
    if ((micros() - timeoflaststep) > stepinterval()) {
      timeoflaststep = micros();
      digitalWrite(STEP_PIN, HIGH);
      //  delayMicroseconds(10); // only needed if step pulse is too short to be detected
      digitalWrite(STEP_PIN, LOW);
      numsteps--;
    }
  }
  motor_idle();
  Serial.print("pos  Serial.print(new_pos);
  Serial.println(" reached");  
}

void setup() {
  pinMode(ZERO_PIN,      INPUT_PULLUP);
  pinMode(ZERO_FOUND_PIN,INPUT_PULLUP);
  pinMode(POS_1_PIN,     INPUT_PULLUP);
  pinMode(POS_2_PIN,     INPUT_PULLUP);
  pinMode(POS_3_PIN,     INPUT_PULLUP);
  pinMode(M1_PIN,        OUTPUT);
  pinMode(M2_PIN,        OUTPUT);
  pinMode(DIR_PIN,       OUTPUT);
  pinMode(STEP_PIN,      OUTPUT);
  pinMode(ENABLE_PIN,    OUTPUT);
  pinMode(ONOFF_LED_PIN, OUTPUT);
  pinMode(DIR_LED_PIN,   OUTPUT);
  digitalWrite(M1_PIN,   LOW); // set M1,M2 to 0,0 for no microstepping
  digitalWrite(M2_PIN,   LOW);
  motor_idle();
  current_pos = EEPROM.read(0);
  if(current_pos > NUM_POSITIONS) {
    current_pos = 1;
    EEPROM.write(0,1);
  }
  new_pos = current_pos;
  Serial.begin(9600);
  Serial.println();
  Serial.print("Currentry position = ");
  Serial.println(current_pos);
  Serial.println();
  Serial.println("If memory position is NOT according");
  Serial.println("to reality, then find zero first!");
  Serial.println();
}

void loop() {

  stepinterval(); // read speed and show RPM on serial monitor

  if(digitalRead(ZERO_PIN)  == 0) find_zero();
  if(digitalRead(POS_1_PIN) == 0) new_pos = 1;
  if(digitalRead(POS_2_PIN) == 0) new_pos = 2;  
  if(digitalRead(POS_3_PIN) == 0) new_pos = 3;

  if(new_pos != current_pos) {
    if(new_pos > current_pos) {
      dir = 1;
      rotate(tt_position[new_pos] - tt_position[current_pos]);
    }
    else {
      dir = 0;
      rotate(tt_position[current_pos] - tt_position[new_pos]);
    }
    current_pos = new_pos;
    EEPROM.write(0, current_pos);
  }
}