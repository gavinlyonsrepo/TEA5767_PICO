/*
 * Project Name: Library for the TEA5767HN FM radio Stereo Module
 * File: examples/Simple_Radio_FM/main.cpp
 * Description: Simple test of the library , setup and tune to a frequency 
 * Toolchain :: Rpi PICO ,rp2040, SDK C++
 * Created DEC 2022
 * Description: See URL for full details.
 * URL: https://github.com/gavinlyonsrepo/TEA5767_PICO
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "tea5767/tea5767.hpp"

TEA5767N radio;

int main() {

  busy_wait_ms(100);
  //  Init I2C (I2C Address, i2c_type,  SDA pin, SCLK pin, I2C CLKspeed)
  radio.begin(TEA5767_I2C_ADDRESS, i2c0, 4, 5, 100);
  busy_wait_ms(1000);

  // Tune to this station , 94.8 Classic hits FM
  radio.selectFrequency(94.8);
 
  while(1)
  {
    busy_wait_ms(100); // Wait here forever
  };
  
}
 
