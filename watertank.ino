/*
  water tank 

  turn on water tank solenoid valve when low is triggered until the high triggers. 

*/

// pin assignment
int sensorhighpin = 3;
int sensorlowpin = 2;
int valvesignalpin = 4;

// state variables
int state_sensorhigh;
int state_sensorlow;
int state_valve_open = HIGH;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  // Serial.begin(9600);
  // set pinmode
  pinMode(sensorhighpin, INPUT);
  pinMode(sensorlowpin, INPUT);
  pinMode(valvesignalpin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  state_sensorhigh = digitalRead(sensorhighpin);
  state_sensorlow = digitalRead(sensorlowpin);
  // print out the state of the button:
  // Serial.print(state_sensorhigh);
  // Serial.println(state_sensorlow);
  if (state_sensorlow && state_sensorhigh) { // water line below both
    // turn on valve
    // Serial.println("flowing water");
    state_valve_open = HIGH;
    digitalWrite(valvesignalpin, HIGH);

    while (state_sensorhigh==HIGH) {
      // keep valve on until the high sensor is triggered
      // Serial.println("keep flowing water");
      state_sensorhigh = digitalRead(sensorhighpin);
      state_sensorlow = digitalRead(sensorlowpin);
    }
  }

  if (state_valve_open==HIGH) {
    state_valve_open = LOW;
    digitalWrite(valvesignalpin, LOW);
  }
  // Serial.print("idling");
  delay(1);  // delay in between reads for stability
}
