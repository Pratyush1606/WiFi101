/*
 * This example check if the firmware loaded on the Wifi101
 * shield is updated.
 *
 * Circuit:
 * - WiFi101 Shield attached
 *
 * Created 29 July 2015 by Cristian Maglie
 * This code is in the public domain.
 */
#include <SPI.h>
#include <WiFi101.h>

void setup() {
  // Initialize serial
  Serial.begin(9600);

  // Wait for user to open the serial monitor
  // (this is needed for boards with native USB serial ports)
  while (!Serial) {
  }

  // Print a welcome message
  Serial.println("WiFi101 firmware check.");
  Serial.println();

  // Check for the presence of the shield
  Serial.print("WiFi101 shield: ");
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("NOT PRESENT");
    return; // don't continue
  }
  Serial.println("DETECTED");

  // Print firmware version on the shield
  String fv = WiFi.firmwareVersion();
  Serial.print("Firmware version installed: ");
  Serial.println(fv);

  // Print required firmware version
  Serial.print("Firmware version required : ");
  Serial.println(WIFI_FIRMWARE_REQUIRED);

  // Check if the required version is installed
  Serial.println();
  if (fv == WIFI_FIRMWARE_REQUIRED) {
    Serial.println("Check result: PASSED");
  } else {
    Serial.println("Check result: NOT PASSED");
    Serial.println(" - The firmware version on the shield do not match the");
    Serial.println("   required version for the library, you may experience");
    Serial.println("   issues or malfunctions.");
  }
}

void loop() {
  // do nothing
}

