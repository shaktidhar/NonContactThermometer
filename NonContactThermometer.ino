#include <SPI.h>
#include <Wire.h>
#include <stdint.h>

#include <Adafruit_MLX90614.h>

#include <FastLED.h>

#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define LED_PIN     7
#define NUM_LEDS    1
CRGB leds[NUM_LEDS];
 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN if required.
#define RST_PIN -1

SSD1306AsciiWire oled;

const int buttonPin = 6;  
int buttonState = 0;   

void setup()   
{

// Initiate the OLED screen. 
  Wire.begin();
  Wire.setClock(400000L);

#if RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
#endif // RST_PIN >= 0
    
  oled.setFont(Adafruit5x7);

// Initiate the button 

  pinMode(buttonPin, INPUT); 

  // initiate the LED 
  
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

// Needed for debugging. Safe to comment out.                   
  Serial.begin(57600);
// Needed for debugging. Safe to comment out.                   
  Serial.println("Adafruit MLX90614 test");  
  
  mlx.begin();

  oled.clear(); 

  oled.set2X();
  oled.println("ACUMEN");
  delay(500) ; 

 // Just for some fun during initialization. 
 // It can be tweaked at will. 
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(100);  
  leds[0] = CRGB(0, 255, 0);
  FastLED.show();
  delay(100);
  leds[0] = CRGB(0, 0, 255);
  FastLED.show();
  delay(100);
  leds[0] = CRGB(150, 0, 255);
  FastLED.show();
  delay(100);
  leds[0] = CRGB(255, 200, 20);
  FastLED.show();
  delay(100);
  leds[0] = CRGB(85, 60, 180);
  FastLED.show();
  delay(100);
  leds[0] = CRGB(50, 255, 20);
  FastLED.show();
  delay(100);
  
}
 
 
void loop() 
{
  // Needed for debugging. Safe to comment out.                   
  Serial.print(mlx.readObjectTempC()); 
  // Needed for debugging. Safe to comment out.                   
  Serial.println(" c");

  // read button state. 
  buttonState = digitalRead(buttonPin);

  // if button not pressed, keep checking temperature every second. 
  if (buttonState == HIGH) { 
  double dTemp = mlx.readObjectTempC() ; 
  
  oled.clear();
  oled.set1X(); 
  oled.println("Acumen Robotics"); 
  oled.set2X();
  oled.print(dTemp) ; 
  oled.println(" c");

  oled.set1X();

/* 
 *  Logic is: 
 *  if temperature less than 33.5 C, nothing to worry about. 
 *  If temperature more than 33.5 but upto 36 C , then it's normal human temperature. 
 *  Hence all clear. 
 *  When tmeperature goes above 36 C, uptil 40 C, it's a cause of concern. 
 *  If temperature is more than 40C, then it's not a human probably.
 *  This section of the code has trememdous potential for beautification. :/ 
 */
  if(dTemp < 33.5) { 
    // if all cool, switch on only the blue light. 
    leds[0] = CRGB(0, 0, 255); 
    oled.println("All seems cool"); 
  } else if (dTemp < 36.0 ) { 
    // if a normal human being, switch on only the greenlight. 
    leds[0] = CRGB(0, 255, 0);
    oled.println("Human*, Normal"); 
  } else if (dTemp <= 40.0 ) { 
    // if there is temperature over and above the normal for humans, switch on only the red light. 
    leds[0] = CRGB(255, 0, 0);
    oled.println("Human*, Unwell"); 
  } else if (dTemp > 40.0) { 
    // If temperature exceeds the highest possible human surface temperetaure, switch on white light. 
    leds[0] = CRGB(255, 255, 255);
    oled.println("Not Human, HOT"); 
  }
  
  FastLED.show();
  delay(1000);
     
  } else  { 

  } 

}
