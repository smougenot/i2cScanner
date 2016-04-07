#include "i2cScanner.h"

// Scan the I2C bus between addresses from_addr and to_addr.
// On each address, call the callback function with the address and result.
// If result==0, address was found, otherwise, address wasn't found
// (can use result to potentially get other status on the I2C bus, see twi.c)
// Assumes Wire.begin() has already been called
void scanI2CBus(byte from_addr, byte to_addr,
                void(*callback)(byte address, byte result)) {
    byte rc;
    byte data = 0; // not used, just an address to feed to twi_writeTo()
    for (byte addr = from_addr; addr <= to_addr; addr++) {
        Wire.beginTransmission(addr);
        rc = Wire.endTransmission();
//    rc = twi_writeTo(addr, &data, 0, 1, 0);
        callback(addr, rc);
    }
}

// Called when address is tested in scanI2CBus()
// Feel free to change this as needed
// (like adding I2C comm code to figure out what kind of I2C device is there)
void scanI2CDisplayResult(byte addr, byte result) {
    Serial.print("addr: ");
    Serial.print(addr, DEC);
    Serial.print((result == 0) ? " found!" : "       ");
    Serial.print((addr % 4) ? "\t" : "\n");
}
