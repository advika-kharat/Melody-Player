/*Melody Player by Advika Kharat*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 21, 1, 3, 17, 16);

#define NOTE_REST 0
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


const int BUZZZER_PIN = 15;
int touch_pin1 =0;
int touch_pin2 =0;
int touch_pin3 =0;
int touch_pin4 =0;

void setup() {
  pinMode(2, OUTPUT);
  lcd.begin(16, 2);
}

void jingleBells(){
  int melody[] = {
    NOTE_E6, NOTE_E6, NOTE_E6,
    NOTE_E6, NOTE_E6, NOTE_E6,
    NOTE_E6, NOTE_G6, NOTE_C6, NOTE_D6,
    NOTE_E6,
    NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6,
    NOTE_F6, NOTE_E6, NOTE_E6, NOTE_E6, NOTE_E6,
    NOTE_E6, NOTE_D6, NOTE_D6, NOTE_E6,
    NOTE_D6, NOTE_G6
  };

  int noteDurations[] = {
    8, 8, 4,
    8, 8, 4,
    8, 8, 8, 8,
    2,
    8, 8, 8, 8,
    8, 8, 8, 16, 16,
    8, 8, 8, 8,
    4, 4
  };

  int size = sizeof(noteDurations) / sizeof(int);  
  digitalWrite(2, HIGH); 
  delay(500); 
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZZER_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.5;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  }
}

void twinkleTone(){
    int twinkleMelody[] = {
      NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
      NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
      NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
      NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
      NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
      NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
    };

    int twinkleNoteDurations[] = {
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2
    };

  int size = sizeof(twinkleNoteDurations) / sizeof(int);  
  digitalWrite(2, HIGH); 
  delay(500); 
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / twinkleNoteDurations[thisNote];
    tone(BUZZZER_PIN, twinkleMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.25;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  }
}

void mary(){
    int maryHadALittleLambMelody[] = {
      NOTE_E6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_E6,
      NOTE_D6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_G6, NOTE_G6,
      NOTE_E6, NOTE_D6, NOTE_C6, NOTE_D6, NOTE_E6, NOTE_E6, NOTE_E6,
      NOTE_E6, NOTE_D6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6
    };

    int maryHadALittleLambNoteDurations[] = {
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 2
    };
  int size = sizeof(maryHadALittleLambNoteDurations) / sizeof(int);  
  digitalWrite(2, HIGH);
  delay(500); 
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / maryHadALittleLambNoteDurations[thisNote];
    tone(BUZZZER_PIN, maryHadALittleLambMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.25;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  }

}

void hbd(){
    int happyBirthdayMelody[] = {
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
      NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
      NOTE_C4, NOTE_C4, NOTE_C4, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_C4
    };

    int happyBirthdayNoteDurations[] = {
      4, 4, 4, 4, 4, 2,
      4, 4, 4, 4, 4, 2,
      4, 4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 8
    };

  int size = sizeof(happyBirthdayNoteDurations) / sizeof(int);  
  digitalWrite(2, HIGH); 
  delay(500); 
  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / happyBirthdayNoteDurations[thisNote];
    tone(BUZZZER_PIN, happyBirthdayMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.25;
    delay(pauseBetweenNotes);
    noTone(BUZZZER_PIN);
  }
}

// the loop function runs over and over again forever
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);

  touch_pin1 = touchRead(T9);
  touch_pin2 = touchRead(T6);
  touch_pin3 = touchRead(T8);
  touch_pin4 = touchRead(T7);
  
  if (touch_pin1 < 50) {
    lcd.print("Mary had a");
    lcd.setCursor(3, 1);
    lcd.print("little lamb");
    mary();
    lcd.clear();
  }
  else if (touch_pin2 < 50) {
    lcd.print("Jingle Bells");
    jingleBells();
    lcd.clear();
  }
  else if (touch_pin3 < 50) {
    lcd.print("Twinkle Twinkle");
    lcd.setCursor(3, 1);
    lcd.print("little star");
    twinkleTone();
    lcd.clear();
  }
  else if (touch_pin4 < 50) {
    lcd.print("Happy Birthday");
    hbd();
    lcd.clear();
  }
  digitalWrite(2, LOW);
}
