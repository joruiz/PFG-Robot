/* LedStripColorTester: Example Arduino sketch that lets you
 * type in a color on a PC and see it on the LED strip.
 *
 * To use this, you will need to plug an Addressable RGB LED
 * strip from Pololu into pin 12.  After uploading the sketch,
 * select "Serial Monitor" from the "Tools" menu.  In the input
 * box, type a color and press enter.
 *
 * The format of the color should be "R,G,B!" where R, G, and B
 * are numbers between 0 and 255 representing the brightnesses
 * of the red, green, and blue components respectively.
 *
 * For example, to get green, you could type:
 *   40,100,0!
 *
 * You can leave off the exclamation point if you change the
 * Serial Monitor's line ending setting to be "Newline" instead
 * of "No line ending".
 *
 * Please note that this sketch only transmits colors to the
 * LED strip after it receives them from the computer, so if
 * the LED strip loses power it will be off until you resend
 * the color.
 */
 
#include <PololuLedStrip.h>

// Create an ledStrip object and specify the pin it will use.
PololuLedStrip<12> ledStrip;

// Create a buffer for holding the colors (3 bytes per color).
#define LED_COUNT 29
rgb_color colors[LED_COUNT];

void setup()
{
  // Start up the serial port, for communication with the PC.
  Serial.begin(115200);
  Serial.println("Ready to receive colors."); 
}

void loop()
{
  // Read the color from the computer.
      rgb_color color;
      color.red = 255;
      color.green = 0;
      color.blue = 0;
      
      rgb_color color2;
      color2.red = 255;
      color2.green = 255;
      color2.blue = 255;

  for(uint16_t i = 0; i < LED_COUNT; i=i+2)
  {
     colors[i] = color;
  }
  
  for(uint16_t i = 1; i < LED_COUNT; i=i+2)
  {
     colors[i] = color2;
  }

  // Write to the LED strip.
      ledStrip.write(colors, LED_COUNT); 
      
  delay(500);
  
  for(uint16_t i = 1; i < LED_COUNT; i=i+2)
  {
     colors[i] = color;
  }
  
  for(uint16_t i = 0; i < LED_COUNT; i=i+2)
  {
     colors[i] = color2;
  }
  
  ledStrip.write(colors, LED_COUNT);
  
  delay(500);
}
