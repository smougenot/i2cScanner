#include "i2cScanner.h"

// standard Arduino setup()
void setup() {
    Wire.begin();

    Serial.begin(9600);
    Serial.println("\nI2CScanner ready!");

    Serial.print("starting scanning of I2C bus from ");
    Serial.print(start_address, DEC);
    Serial.print(" to ");
    Serial.print(end_address, DEC);
    Serial.println("...");

    // start the scan, will call "scanFunc()" on result from each address
    scanI2CBus(start_address, end_address, scanI2CDisplayResult);

    Serial.println("\ndone");
}

// standard Arduino loop()
void loop() {
    Serial.print("loop does :");
    delay(300);
    Serial.println(" nothing");
}
