#include "Particle.h"
#include "neopixel.h"
 
SYSTEM_MODE(AUTOMATIC);
 
// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D4
#define PIXEL_COUNT 3
#define PIXEL_TYPE WS2812
int ButtonPIN = D3;
int ButtonLast = LOW;
int ButtonState;
 
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
 
// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);
 
void setup()
{
 
  strip.begin();
  strip.show();// Initialize all pixels to 'off'
  pinMode(ButtonPIN, INPUT_PULLDOWN);
  ButtonState = 0;
}
 
void loop()
{
    int ButtonNow = digitalRead(ButtonPIN);
    if(ButtonNow == HIGH && ButtonLast == LOW) {
      ButtonState = ButtonState +1;
      if(ButtonState > 0){
        ButtonState = 0;
      }
    }
    ButtonNow = ButtonLast;
    if(ButtonState == 1) {
    int delay1;
    int R1;
    int R2;
    int R3;
    int G1;
    int G2;
    int G3;
    int B1;
    int B2;
    int B3;
 
   
   
    delay1 = random(100);
    R1 = random(256);
    R2 = random(256);
    R3 = random(256);
    G1 = random(256);
    G2 = random(256);
    G3 = random(256);
    B1 = random(256);
    B2 = random(256);
    B3 = random(256);
 
   
    int LED1 = strip.Color( R1 , G1,  B1);
    int LED2  = strip.Color(  R2,  G2,   B2);
    int LED3 = strip.Color(  R3,  G3,   B3);
 
   
    strip.setPixelColor(0, LED1);
   
    strip.setPixelColor(1, LED2);
 
    strip.setPixelColor(2, LED3);
    strip.show();
    delay(delay1);
    }
}
