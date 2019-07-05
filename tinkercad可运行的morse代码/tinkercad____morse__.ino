#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/

//include "Arduino.h"
//#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}

//#include <Morse.h>
Morse morse(13);
int incomingByte = 0;
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  
  while (Serial.available()>0)
  {
    incomingByte = Serial.read();
    switch(incomingByte)
    {
      case 'a': morse.dot();morse.dash();delay(3000);break;
      case 'b': morse.dash();morse.dot();morse.dot();morse.dot();delay(3000);break;
      case 'c': morse.dash();morse.dot();morse.dash();morse.dot();delay(3000);break;
      case 'd': morse.dash();morse.dot();morse.dot();delay(3000);break;
      case 'e': morse.dot();delay(3000);break;
      case 'f': morse.dot(); morse.dot(); morse.dash(); morse.dot();delay(3000);break;
      case 'g': morse.dash(); morse.dash(); morse.dot();delay(3000);break;
      case 'h': morse.dot(); morse.dot(); morse.dot(); morse.dot();delay(3000);break;
      case 'i': morse.dot(); morse.dot();delay(3000);break;
      case 'j': morse.dot(); morse.dash(); morse.dash(); morse.dash();delay(3000);break;
      case 'k': morse.dash(); morse.dot(); morse.dash();delay(3000);break;
      case 'l': morse.dot(); morse.dash(); morse.dot(); morse.dot();delay(3000);break;
      case 'm': morse.dash(); morse.dash();delay(3000);break;
      case 'n': morse.dash(); morse.dot();delay(3000);break;
      case 'o': morse.dash(); morse.dash(); morse.dash();delay(3000);break;
      case 'p': morse.dot(); morse.dash(); morse.dash(); morse.dot();delay(3000);break;
      case 'r': morse.dot(); morse.dash(); morse.dot();delay(3000);break;
      case 's': morse.dot(); morse.dot(); morse.dot();delay(3000);break;
      case 't': morse.dash();delay(3000);break;
      case 'u': morse.dot(); morse.dot(); morse.dash();delay(3000);break;
      case 'v': morse.dot(); morse.dot(); morse.dot(); morse.dash();delay(3000);break;
      case 'w': morse.dot(); morse.dash(); morse.dash();delay(3000);break;
      case 'x': morse.dash(); morse.dot(); morse.dot(); morse.dash();delay(3000);break;
      case 'y': morse.dash(); morse.dot(); morse.dash(); morse.dash();delay(3000);break;
      case 'z': morse.dash(); morse.dash(); morse.dot(); morse.dot();delay(3000);break;
      case ' ': delay(7000);break;
    }

  }

}
