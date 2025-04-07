#include <FastLED.h>

#define DATA_PIN 4
#define  NUM_LEDS 64
CRGB leds[NUM_LEDS];
int ledState = 0;

// This function sets up the ledsand tells the controller about them
void LEDsetup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

}

void LEDLoop()
{
  if(ledState == 0)
  {
    return;
  }
  else
  {
    switch(ledState)
    {
      case 10:
        LEDDisable();
        break;
      case 1:
        LEDScenario1();
        break;
      case 2:
        LEDScenario2();
        break;
      default:
      break;
    }
  }

}

void LEDHangle(int action)
{
  if(action ==0)
  {
    ledState = action;
    LEDDisable();
  }
  else if(action >=1 && action < 10)
    ledState = action;
  else if(action >=10 && action <20)
  {
    
  }
}
void LEDDisable()
{
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::Black;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();
   }
   FastLED.show();
}
void LEDScenario1() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(100);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
   }
}
void LEDScenario2() {
   // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = CRGB::White;

      // Show the leds (only one of which is set to white, from above)


      // Wait a little bit
   }
    FastLED.show();
}