#import "leds.h"

uint32_t color = 0;

void setup() {
  leds::init();

}

void loop() 
{
  leds::displayColor( colors::GREEN );
  delay( 10000 );
  leds::displayColor( colors::RED );
  delay( 10000 );
  leds::displayColor( colors::BLUE );
  delay( 10000 );
  leds::displayColor( colors::MAGENTA );
  delay( 10000 );
  leds::displayColor( colors::YELLOW );
  delay( 10000 );
  leds::displayColor( colors::CYAN );
  delay( 10000 );
  leds::displayColor( colors::WHITE );
  delay( 10000 );
}
