
Overview
--------------------------------------------
* Name: TEA5767_PICO
* Description:  Library for TEA5767HN, Low-power FM stereo radio.
* Developed on and for
	1. Raspberry pi PICO RP2040
	2. SDK C++ compiler G++ for arm-none-eabi
	3. CMAKE , VScode
* Ported from mroger's arduino  [ library](https://github.com/mroger/TEA5767)

Hardware
----------------------

1. Picture of the Module used 

 ![image ](https://github.com/gavinlyonsrepo/TEA5767_PICO/blob/main/extra/images/radio.jpg)
 
The TEA5767HN is a single-chip electronically tuned FM stereo radio for low-voltage
applications with fully integrated Intermediate Frequency (IF) selectivity and
demodulation. The radio is completely adjustment-free and only requires a minimum of
small and low cost external components. The radio can be tuned to the European, US,
and Japanese FM bands.

The Module uses I2C for communication's.
Pins and I2C port can be set in the main.cpp. Default is I2C0 and GPIO4(data) GPIO5(clock)
If you want to use the other I2C port (I2C1) in addition to changing in the main.ccp,
The user must change it in library header as well( i2c_inst_t ).
Could not find a way around this.This is a 5 Volt device both VCC/Logic and the PICO is 3.3 volt logic device to safely connect radio module to PICO use level shifting to shift voltage logic levels.The module has 4.7 pull up resistors on the SDA and SCLK lines.
So no resistors should be needed on 5 volt bus line.
On the 3.3 V bus side of the level shift , the PICO has its pull up resistors enabled these are 50-80KOhms. You may require a pull up resistor (1K to 10K on this side of bus) although during  testing it worked fine without. It may depend on your Voltage shifting setup. 

1. Voltage shift setup used
 
 ![image ](https://github.com/gavinlyonsrepo/TEA5767_PICO/blob/main/extra/images/radio1.png)
 
 
 Software
----------------------

There are two  example main.cpp which contains tests showing library functions.
There is also the library files (tea5767.cpp and tea5767.hpp)

Switch between the two  examples by editing add_executable(${PROJECT_NAME} in CMakeLists.txt

1.  examples/Simple_Radio_FM/main.cpp
2.  examples/Library_Demo/main.cpp
