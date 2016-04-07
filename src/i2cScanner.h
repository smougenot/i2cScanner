/**
 * I2CScanner -- I2C bus scanner for Arduino
 * Usefull when you do not find your device : just run the scanner to display
 * Inspired by : Tod E. Kurt, http://todbot.com/blog/
 *
 */

#ifndef __I2C_SCANNER_H__
#define __I2C_SCANNER_H__


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


#include "Wire.h"
//extern "C" { 
//#include "utility/twi.h"  // from Wire library, so we can do bus scanning
//}

static const int gpio_pin[] = {5, 4, 0, 2, 14, 12, 13}; //this array maps internal IO references to GPIO numbers
static const byte start_address = 8;       // lower addresses are reserved to prevent conflicts with other protocols
static const byte end_address = 119;       // higher addresses unlock other modes, like 10-bit addressing

// Scan the I2C bus between addresses from_addr and to_addr.
// On each address, call the callback function with the address and result.
// If result==0, address was found, otherwise, address wasn't found
// (can use result to potentially get other status on the I2C bus, see twi.c)
// Assumes Wire.begin() has already been called
void scanI2CBus(byte from_addr, byte to_addr,
                void(*callback)(byte address, byte result));

// Called when address is found in scanI2CBus()
// Feel free to change this as needed
// (like adding I2C comm code to figure out what kind of I2C device is there)
void scanI2CDisplayResult(byte addr, byte result);


#endif