//Ventilator code 
//Version 0.7

//Breath Cycle parameters
int Inhalation_time_set[] = {1500, 1380, 1290, 1200, 1130, 1060, 1000, 950, 900}; //in milli seconds
int current_Inhalation_time = Inhalation_time_set[0];
const int current_Hold_Pause_time = 300; //Hold time does not change ever
int Exhalation_time_set[] = {3200, 2930, 2700, 2500, 2330, 2170, 2030, 1910, 1800}; //in milli seconds
int current_Exhalation_time = Exhalation_time_set[0];

//Air Volume control potentiometer parameters
int Actuator_displacement[] = {20, 40, 60, 80, 100}; //in mm
int corrent_Actuator_displacement = Actuator_displacement[0];

//Debug variables
boolean debug_output = true; //If false no serial output, to see output on serial true it


//Pin Definations
const int POT_BTH = A0;
const int POT_AVC = A1;



//Motor Related
//define Pins
int Step   =  6;
int Dir    =  7;
int MS1    =  4;
int MS2    =  5;

//define variables
int   direction        = 0;      //direction is either "0" or "1" to choose direction
float cycle            = 1;      //cycle can be in decimal 1 is 360 rotation and 0.5 is 180 degree
float time_for_cycles  = 0;      //time for total cycle is in milisecond so it can be in decimal

int   SelectResolution = 0;      //Resolution table given below
int   StepsPerRevo     = 0;


/*                   SelectResolution   MS1   MS2   Microstep Resolution
                             0           L     L     Full Step (2 Phase)
                             1           H     L     Half Step
                             2           L     H     Quarter Step
                             3           H     H     Eigth Step                                            */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(POT_BTH, INPUT);
  pinMode(POT_AVC, INPUT);
  init_motor_parameter();

}

void loop() {
  // put your main code here, to run repeatedly:
  BCM_motion();

}

void BCM_motion() { //Breath cycle movement
  //First set motor paramter according to BCP
  set_BCM_parameter(set_breath_cycles_virtual_set());
  set_AVC_parameter(set_air_volume_control_set());
  //Now rotate motor accordingly
  motor_Expansion_actuator_Inhalation();
  BCM_motor_hold();
  motor_retraction_actuator_Exhalation();
}

void motor_Expansion_actuator_Inhalation() {
  debug_msg_print("Inhalation:" + String(corrent_Actuator_displacement) + ":" + String(current_Inhalation_time));
  motor_rotate(0 , corrent_Actuator_displacement , current_Inhalation_time);
}

void motor_retraction_actuator_Exhalation() {
  debug_msg_print("Exhalation:" + String(corrent_Actuator_displacement) + ":" + String(current_Exhalation_time));
  motor_rotate(1 , corrent_Actuator_displacement , current_Exhalation_time);
}

void BCM_motor_hold() {
  debug_msg_print("Hold:300");
  motor_stop();
  delay(300);
}

void init_motor_parameter() {
  pinMode(Step, OUTPUT);
  pinMode(Dir , OUTPUT);
  pinMode(MS1  , OUTPUT);
  pinMode(MS2  , OUTPUT);

  if ( SelectResolution == 0 ) {
    digitalWrite(MS1 , LOW);
    digitalWrite(MS2 , LOW);
    StepsPerRevo =  200;
  }
  if ( SelectResolution == 1 ) {
    digitalWrite(MS1 , HIGH);
    digitalWrite(MS2 , LOW);
    StepsPerRevo =  400;       //200*2
  }
  if ( SelectResolution == 2 ) {
    digitalWrite(MS1 , LOW);
    digitalWrite(MS2 , HIGH);
    StepsPerRevo =  800;       //200*4
  }
  if ( SelectResolution == 3 ) {
    digitalWrite(MS1 , HIGH);
    digitalWrite(MS2 , HIGH);
    StepsPerRevo =  1600;       //200*8
  }
}

void motor_stop() {
  digitalWrite(Step , HIGH);
  delayMicroseconds(100);
  digitalWrite(Step , HIGH );
  delayMicroseconds(100);
}

void motor_rotate(int direction_pass, float cycles_pass, float time_for_cycles_pass) {

  if ( direction_pass == 0) {
    digitalWrite( Dir , HIGH );
  }
  else {
    digitalWrite( Dir , LOW );
  }

  float StepsProduCycle       = StepsPerRevo * cycles_pass;        //if steps per revolution is 200 and cycle is 2 then it is 400 means 360*2= 720 degree rotation
  float ConvertMicroSecCycle  = 1000 * time_for_cycles_pass;       //Convert in Microseconds for accuracy
  float OneCycleTime          = ConvertMicroSecCycle / cycles_pass; //For one ccle time
  float PulseTotaltime        = OneCycleTime / StepsPerRevo;       //one pulse Low and High time
  float Pulsetime             = PulseTotaltime / 2;                //Divide by 2, to divide pulse on off time
  //Serial.println(Pulsetime);
  for (int i = 0; i < StepsProduCycle ; i++) {
    digitalWrite(Step , HIGH);
    delayMicroseconds(Pulsetime);
    digitalWrite(Step , LOW );
    delayMicroseconds(Pulsetime);
  }

}

int set_air_volume_control_set() {
  int ADC_POT_AVC = analogRead(POT_AVC);
  int DIG_POT_AVC = map(ADC_POT_AVC , 0 , 1023, 0 , 360);
  switch (DIG_POT_AVC) {
    case 0 ... 72:
      return  1;
    case 73 ... 144:
      return  2;
    case 145 ... 216:
      return  3;
    case 217 ... 288:
      return  4;
    case 289 ... 360:
      return  5;
    default:
      return  0;  //0 means error
      break;
  }
}

int set_breath_cycles_virtual_set() {
  int ADC_POT_BCM = analogRead(POT_BTH);
  int DIG_ROT_BCM = map(ADC_POT_BCM , 0 , 1023, 0 , 360);
  switch (DIG_ROT_BCM) {
    case 0 ... 40:
      return  1;
    case 41 ... 80:
      return  2;
    case 81 ... 120:
      return  3;
    case 121 ... 160:
      return  4;
    case 161 ... 200:
      return  5;
    case 201 ... 240:
      return  6;
    case 241 ... 280:
      return  7;
    case 281 ... 320:
      return  8;
    case 321 ... 360:
      return  9;
    default:
      return  0;  //0 means error
      break;

  }
}

void set_AVC_parameter(int virtual_set) {
  if (virtual_set == 0) {
    debug_msg_print("Something wrong in setting virtual set");
  }
  else {
    corrent_Actuator_displacement = Actuator_displacement[virtual_set - 1];
  }
}

void set_BCM_parameter(int virtual_set) {
  if (virtual_set == 0) {
    debug_msg_print("Something wrong in setting virtual set");
  }
  else {
    current_Inhalation_time = Inhalation_time_set[virtual_set - 1];
    current_Exhalation_time = Exhalation_time_set[virtual_set - 1];
  }
}

void debug_msg_print(String debug_msg) {
  if (debug_output == true) {
    Serial.println(debug_msg);
  }

}
