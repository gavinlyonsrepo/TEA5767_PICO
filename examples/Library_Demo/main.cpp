/*
 * Project Name: Library for the TEA5767HN FM radio Stereo Module
 * File: Library_Demo/main.cpp 
 * Description: main test file for library , runs through a series of tests of
 * some of the functions. 
 * Toolchain :: Rpi PICO ,rp2040, SDK C++
 * Created DEC 2022
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/TEA5767_PICO
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "tea5767/tea5767.hpp"

TEA5767N radio;

// This code shows some of the uses of the TEA5767N API.
// Test 1 Sets the radio station
// Test 2 Mutes the radio
// Test 2b mute left & right channel
// Test 3 turn on and off radio 
// Test 4 Search up
// Test 5 Search Down
// Test 6 Select Station rea freq and signal level

int main() {
  // Some test variables 
  uint8_t isBandLimitReached = 0;
  float freq;
  uint8_t signalLevel = 0;

  // Initialize chosen serial port, 38400 default baudrate.
  stdio_init_all();  
  busy_wait_ms(1000);
  printf("TEA5767 Start \r\n");

  // Init I2C
  radio.begin(TEA5767_I2C_ADDRESS,i2c0, 4, 5, 100); 
  busy_wait_ms(1000);

  // Test 1 Sets the radio station
  radio.selectFrequency(94.8); // 94.8 classic hits FM
  busy_wait_ms(5000);
  
  //Test 2 Mutes the radio
  radio.mute();
  printf("Mute \r\n");
  busy_wait_ms(2000);
  //Un mutes the radio
  printf("UnMute \r\n");
  radio.turnTheSoundBackOn();
  busy_wait_ms(2000);
  
  //  Test 2b mute left & right channel
  printf("Stereo or Mono? :: ");
  if (radio.isStereo()) 
       printf("Stereo \r\n");
  else 
       printf("Mono \r\n");

  //Mutes right channel
  printf("Mute right \r\n");
  radio.muteRight();
  busy_wait_ms(2000);
  
  //Should go mono
  printf("Stereo or Mono? :: ");
  if (radio.isStereo()) 
       printf("Stereo \r\n");
  else 
       printf("Mono \r\n");

  //Unmutes right channel
   printf("unMute right \r\n");
  radio.turnTheRightSoundBackOn();
  busy_wait_ms(2000);

  //Mutes left channel
  printf("Mute left \r\n");
  radio.muteLeft();

  //Should also be mono
  printf("Stereo or Mono? :: ");
  if (radio.isStereo()) 
       printf("Stereo \r\n");
  else 
       printf("Mono \r\n");
  busy_wait_ms(2000);

  //Unmutes left channel
  printf("unMute left \r\n");
  radio.turnTheLeftSoundBackOn();
  busy_wait_ms(2000);

  // Test 3 turn on and off radio 
  //Turns the radio off
  radio.setStandByOn();
  busy_wait_ms(2000);

  //Turns the radio on
  radio.setStandByOff();
  busy_wait_ms(2000);
  
  // test 4 Search up
  //Search Up is the default
  printf("Search Up in progress...\r\n ");
  radio.setSearchMidStopLevel();
  isBandLimitReached = radio.startsSearchMutingFromBeginning();
  printf("Band limit reached? :: ");
  if (isBandLimitReached)
     printf("Yes\r\n");
  else
     printf("No \r\n");
  busy_wait_ms(2000);

  freq = radio.readFrequencyInMHz();
  printf("Station found: %f MHz \r\n", freq);
  busy_wait_ms(2000);
 
  while (!isBandLimitReached) {
    
    printf("Search Up in progress...\r\n");
    //If you want listen to station search, use radio.searchNext() instead
    isBandLimitReached = radio.searchNextMuting();
    
    printf("Band limit reached? :: ");
    if (isBandLimitReached)
        printf("Yes\r\n");
    else
        printf("No \r\n");
    busy_wait_ms(2000);
    
  freq = radio.readFrequencyInMHz();
  printf("Station found: %f MHz \r\n ", freq);
  busy_wait_ms(2000);
  }
  
  // Test 5 Search Down
  printf("Band Limit Reached, searching down... \r\n");
  
  radio.setSearchDown(); // down
  radio.setSearchMidStopLevel();
  
  printf("Search Down in progress... \r\n");
  isBandLimitReached = radio.searchNextMuting();
  
  printf("Band limit reached? :: ");
  if (isBandLimitReached)
      printf("Yes\r\n");
  else
      printf("No \r\n");
  busy_wait_ms(2000);
  
  freq = radio.readFrequencyInMHz();
  printf("Station found: %f MHz \r\n", freq);
  busy_wait_ms(2000);
  
  while (!isBandLimitReached) {
    
    printf("Search Down in progress... \r\n ");
    isBandLimitReached = radio.searchNextMuting();
    printf("Band limit reached? ");
    if (isBandLimitReached)
        printf("Yes\r\n");
    else
        printf("No \r\n");
    busy_wait_ms(2000);
        
  freq = radio.readFrequencyInMHz();
  printf("Station found: %f MHz \r\n", freq);
  busy_wait_ms(2000);
  }
  
  // Test 6 Select Station rea freq and signal level
  radio.selectFrequency(94.8);

  //Read freq in MHz
  freq = radio.readFrequencyInMHz();
  printf("Station selected: %f Mhz \r\n", freq);
  
  //Shows reception signal level
  signalLevel = radio.getSignalLevel();
  printf("Signal level: %u \r\n ", signalLevel);
  
  //Reception stereo or mono?
  printf("Stereo or Mono? :: ");
  if (radio.isStereo()) 
       printf("Stereo \r\n");
  else 
       printf("Mono \r\n");
  
}
 
