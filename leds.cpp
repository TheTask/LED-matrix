#include "leds.h"

// Create an instance of the Adafruit_NeoPixel class called 'leds'.
// Parameter 1 = number of pixels in the strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
Adafruit_NeoPixel leds::_leds( NUM_LEDS,LED_PIN,NEO_GRB + NEO_KHZ800 );


void leds::init()
{
    _leds.begin(); 
    _leds.setBrightness( config::BOARD_BRIGHTNESS );
    leds::clear();
}


void leds::clear()
{
  displayColor( colors::OFF );
}


void leds::displayDigit( bool* digit,uint32_t color )
{
  for( uint8_t row = 0; row < leds::HEIGHT; row++ )
  {
    uint8_t col_index = 0;

    for( col_index; col_index < 4; col_index++ )
    {
       _leds.setPixelColor( row * leds::WIDTH + col_index,colors::OFF );
    }

    for( uint8_t col = 0; col < 6; col++ )
    {
       if( digit[ row * 6 + col ] ) _leds.setPixelColor( row * leds::WIDTH + col_index,color );
       col_index++;
    }

    for( col_index; col_index < 14; col_index++ )
    {
       _leds.setPixelColor( row * leds::WIDTH + col_index,colors::OFF );
    }
  }

  _leds.show();
}

void leds::displayPixel( uint8_t pixelIndex,uint32_t color )
{
  _leds.setPixelColor( pixelIndex,color );
  _leds.show();
}

void leds::displayColor( uint32_t color )
{
  for( uint8_t i = 0; i < leds::SIZE; i++ )
  {
    _leds.setPixelColor( i,color );
  }
  _leds.show();
}
