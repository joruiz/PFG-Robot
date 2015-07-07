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
#define LED_COUNT 9
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
      color.red = 0;
      color.green = 255;
      color.blue = 0;
      
      rgb_color color2;
      color2.red = 255;
      color2.green = 255;
      color2.blue = 255;
    
      rgb_color color3;
      color3.red = 255;
      color3.green = 255;
      color3.blue = 0;
      
      rgb_color color4;
      color4.red = 0;
      color4.green = 255;
      color4.blue = 255;
      
      rgb_color color5;
      color5.red = 0;
      color5.green = 0;
      color5.blue = 255;
      
      rgb_color color6;
      color6.red = 255;
      color6.green = 0;
      color6.blue = 255;
      
      rgb_color color7;
      color7.red = 0;
      color7.green = 0;
      color7.blue = 0;
      
      
  for(uint16_t i = 0; i < LED_COUNT; i++)
  {
     colors[i] = color7;
  }
  
   colors[7] = color2;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
      
   colors[7] = color7;
   colors[2] = color3;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
      
   colors[2] = color7;
   colors[5] = color4;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
   
   colors[5] = color7;
   colors[3] = color5;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
   
   colors[3] = color7;
   colors[0] = color6;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
   
   colors[0] = color7;
   colors[8] = color;
   ledStrip.write(colors, LED_COUNT);
   delay(1000);
   
   colors[8] = color7;
   ledStrip.write(colors, LED_COUNT);
   delay(4000);

}
