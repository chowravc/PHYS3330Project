// Delay period before every iteration
int delayPeriod = 100;

// Threshold value for password
int passThresh = 500;

// Threshold value for photodetector
int pDThresh = 5;

// Digital output pins being used for outputs
int passLED = 7;

// Analog input pins being used for the password lock
int passPin = A0;

// Speaker pin
int buzzer = 2;

// Pins to get photodetector inputs
int pD1 = A1;
int pD2 = A2;
int pD3 = A3;

// Pin to power laser diodes
int laserPin = 13;

// Integers to store read values from analog pins
int passVal;

// Boolean to store if the correct password is inputted
bool passcode;

// Integers to store photodetector inputs
int pDVal1;
int pDVal2;
int pDVal3;

// Booleans to store if photodetectors are below thresh
int pDBool1;
int pDBool2;
int pDBool3;

// Music stuff
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// change this to make the song slower or faster
int tempo = 200;
int succTempo = 200;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int angeryMelody[] = {
  NOTE_D5,32,
};

int succMelody[] = {
  NOTE_FS4,8, REST,8, NOTE_A4,8, NOTE_CS5,8, REST,8,NOTE_A4,8, REST,8, NOTE_FS4,8, //1
  NOTE_D4,8, NOTE_D4,8, NOTE_D4,8, REST,8, REST,4, REST,8, NOTE_CS4,8,
  NOTE_D4,8, NOTE_FS4,8, NOTE_A4,8, NOTE_CS5,8, REST,8, NOTE_A4,8, REST,8, NOTE_F4,8,
  NOTE_E5,-4, NOTE_DS5,8, NOTE_D5,8, REST,8, REST,4,
  
  NOTE_GS4,8, REST,8, NOTE_CS5,8, NOTE_FS4,8, REST,8,NOTE_CS5,8, REST,8, NOTE_GS4,8, //5
  REST,8, NOTE_CS5,8, NOTE_G4,8, NOTE_FS4,8, REST,8, NOTE_E4,8, REST,8,
  NOTE_E4,8, NOTE_E4,8, NOTE_E4,8, REST,8, REST,4, NOTE_E4,8, NOTE_E4,8,
  NOTE_E4,8, REST,8, REST,4, NOTE_DS4,8, NOTE_D4,8,
  };

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int angeryNotes = sizeof(angeryMelody) / sizeof(angeryMelody[0]) / 2;
int succNotes = sizeof(succMelody) / sizeof(succMelody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void angery() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < angeryNotes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = angeryMelody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, angeryMelody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void success() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < succNotes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = succMelody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, succMelody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

// Runs at the start of the code
void setup() {
//  pinMode(LED_BUILTIN, OUTPUT);

  // Set up password LED pin
  pinMode(passLED, OUTPUT);

  // Set up laser pin
  pinMode(laserPin, OUTPUT);

  // Set up serial monitor
  Serial.begin(9600);
}

// Repeats every few milliseconds
void loop() {
  
  // Delay for a few milliseconds
  delay(delayPeriod);

  //
  // Password Checker
  //
  
  // This part checks the input values from the potentiometer password
  passVal = analogRead(passPin);

  // Get boolean for whether the correct password is inputted
  passcode = passVal > passThresh;

  // If the value is above passThresh for all three pins
  if (passcode){
    // Turn on the on-board LED
    digitalWrite(passLED, HIGH);

    // Stop music
    noTone(buzzer);

    // Play the lick
    success();

    // Stop music
    noTone(buzzer);
  }
  // If the value is above passThresh for any of the three pins
  else{
    // Turn off the on-board LED
    digitalWrite(passLED, LOW);
  }

  //
  // Laserdiode
  //

  // If password was not inputted
  if (passcode != true){
    // Turn on the laser diodes
    digitalWrite(laserPin, HIGH);
  }
  // If password was inputted
  else{
    // Turn off the laser diodes
    digitalWrite(laserPin, LOW);
  }

  //
  // Photodetector
  //

  // If password was not inputted
  if (passcode != true){
    // Keep checking photodetector on the laser diodes
    // Read each of the photodetector readings
    pDVal1 = analogRead(pD1);
    pDVal2 = analogRead(pD2);
    pDVal3 = analogRead(pD3);

    // Print photodetector readings to serial monitor
    Serial.println();
    Serial.println(pDVal1);
    Serial.println(pDVal2);
    Serial.println(pDVal3);

    // Check if any are below the threshold
    pDBool1 = pDVal1 < pDThresh;
    pDBool2 = pDVal2 < pDThresh;
    pDBool3 = pDVal3 < pDThresh;

    // If any of those are low
    if (pDBool1 || pDBool2 || pDBool3){
      angery();
    }
  }
  // If password was inputted
  else{
    // Do nothing, turn off buzzer
    noTone(buzzer);
  }
}
