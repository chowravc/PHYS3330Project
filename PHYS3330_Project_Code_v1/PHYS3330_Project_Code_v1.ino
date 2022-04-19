// Delay period before every iteration
int delayPeriod = 100;

// Analog input pins being used for the password lock
int passPin1 = A1;
int passPin2 = A2;
int passPin3 = A3;

// Integers to store read values from analog pins
int passDig1;
int passDig2;
int passDig3;

// Runs at the start of the code
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// Repeats every few milliseconds
void loop() {
  
  // Delay for a few milliseconds
  delay(delayPeriod);
  
  // This part checks the input values from the potentiometer password
  passDig1 = analogRead(passPin1);
  passDig2 = analogRead(passPin2);
  passDig3 = analogRead(passPin3);

  // If the value is below 200 (1.0 V) for all three pins
  if (passDig1 < 200 && passDig2 < 200 && passDig3 < 200) {
    // Turn on the on-board LED
    digitalWrite(LED_BUILTIN, HIGH);
  }
  // If the value is above 200 (1.0 V) for any of the three pins
  else{
    // Turn off the on-board LED
    digitalWrite(LED_BUILTIN, LOW);
  }
}
