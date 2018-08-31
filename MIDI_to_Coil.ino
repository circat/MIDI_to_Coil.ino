//#include <Wire.h>
#include <MIDI.h>
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(10, 11); // RX, TX
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, MIDI);
//MIDI_CREATE_DEFAULT_INSTANCE();

const int coil1 =  9;
const int coil2 =  10;
const int coil3 =  11;
const int coil4 =  3;
int strenth =0;

void HandleNoteOn (byte channel, byte number, byte velocity) { 
  
   strenth = map(velocity, 0, 127, 1, 255); //35, seems to be the right value for putting all the coils on at velocity 127
  
  if (number == 48) { // Note C2
  analogWrite(coil1, strenth );
  delay(30);
  analogWrite(coil1, 1); 
  }
 if (number == 49) {
  analogWrite(coil2, strenth);
  delay(30);
 analogWrite(coil2, 1);
 }
 if (number == 50) {
  analogWrite(coil3, strenth);
  delay(30);
 analogWrite(coil3, 1);
 }
 if (number == 51) {
  analogWrite(coil4, strenth);
  delay(30);
 analogWrite(coil4, 1);
 }
}   
void setup()
{
    pinMode(coil1, OUTPUT);
    pinMode(coil2, OUTPUT); 
    pinMode(coil3, OUTPUT); 
    pinMode(coil4, OUTPUT);
    
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.turnThruOff();
    Serial.begin(115200);
    MIDI.setHandleNoteOn(HandleNoteOn);
}
    
void loop()
{
        MIDI.read();
        
}

