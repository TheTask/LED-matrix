
#include "leds.h"

uint32_t colors_arr[] = { colors::RED,colors::YELLOW,colors::GREEN,colors::CYAN,colors::BLUE,colors::MAGENTA }; 
int currentColorIndex = 0;
uint8_t r, g, b;
uint8_t targetR, targetG, targetB;
uint32_t transitionSpeed = 5; 

void setup() 
{
  leds::init();
  extractRGB( colors_arr[ currentColorIndex ],&r,&g,&b );
  setNextTargetColors();
}

void loop() 
{
  bool transitionComplete = transitionColor( &r,&g,&b,targetR,targetG,targetB,transitionSpeed );
  leds::displayColor( getColor( r,g,b ) );


  if( transitionComplete ) 
  {
    currentColorIndex = ( currentColorIndex + 1 ) % ( sizeof( colors_arr ) / sizeof( colors_arr[ 0 ] ) );
    setNextTargetColors();
  }

  delay( 10 ); 
}

void extractRGB( uint32_t color,uint8_t* r,uint8_t* g,uint8_t* b ) 
{
  *g = ( color >> 16 ) & 0xFF;
  *r = ( color >> 8 ) & 0xFF;
  *b = color & 0xFF;
}

void setNextTargetColors() 
{
  extractRGB( colors_arr[ ( currentColorIndex + 1 ) % ( sizeof( colors_arr ) / sizeof( colors_arr[ 0 ] ) ) ],&targetR,&targetG,&targetB );
}

bool transitionColor( uint8_t* r,uint8_t* g,uint8_t* b,uint8_t targetR,uint8_t targetG,uint8_t targetB,uint32_t speed ) 
{
  bool rComplete = transitionComponent( r,targetR,speed );
  bool gComplete = transitionComponent( g,targetG,speed );
  bool bComplete = transitionComponent( b,targetB,speed );
  return rComplete && gComplete && bComplete;
}

bool transitionComponent( uint8_t* component,uint8_t targetComponent,uint32_t speed ) 
{
  if( *component < targetComponent ) 
  {
    *component += min(speed, targetComponent - *component );
  } 
  else if( *component > targetComponent ) 
  {
    *component -= min( speed,*component - targetComponent );
  }
  return *component == targetComponent;
}

uint32_t getColor( uint8_t r,uint8_t g,uint8_t b ) 
{
  return ( ( uint32_t )g << 16 ) | ( ( uint32_t )r << 8 ) | b;
}
