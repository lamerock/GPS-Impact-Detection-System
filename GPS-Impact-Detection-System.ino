/*
 * Sketch Name: GPS-Impact-Detection-System
 * Description: This code integrates a GPS module and an FSR (Force-Sensing Resistor) to detect impact events and send an SMS with the location information.
 * The code uses the SoftwareSerial library to communicate with the GPS module and the GSM module.
 * When an impact is detected, the code retrieves the GPS coordinates and sends an SMS to a specified phone number with the location information.
 * Adjust the FSR_THRESHOLD value according to your FSR sensitivity.
 * Make sure to connect the GPS module and GSM module to the correct pins on the Arduino board.
 * Author: Gerard James B. Paglingayen
 * Version: 1.0.0
 * Created: June 5, 2023
 * Last Modified: June 5, 2023
 * License: MIT License
 * Repository: https://github.com/lamerock/GPS-Impact-Detection-System
 */

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#define FSR_PIN A0
#define FSR_THRESHOLD 500 // Adjust this threshold according to your FSR sensitivity

const int RXPin = 2;
const int TXPin = 3;
const uint32_t GPSBaud = 9600; // Default baud of GPS module is 9600

TinyGPSPlus gps; // The TinyGPS++ object
SoftwareSerial gpsSerial(RXPin, TXPin); // The serial interface to the GPS device

SoftwareSerial gsmSerial(9, 10); // RX, TX for GSM module
String locationURL = "";

const char* phoneNumber = ""; // Enter the mobile number you want to send the SMS to

void setup() {
  Serial.begin(9600);
  gsmSerial.begin(9600);
  gpsSerial.begin(GPSBaud);
  Serial.println(F("Arduino - GPS Impact Detection System"));
  pinMode(FSR_PIN, INPUT_PULLUP);
  Serial.println("Ready");
}

void loop() {
  int fsrReading = analogRead(FSR_PIN);
  if (fsrReading > FSR_THRESHOLD) {
    delay(50); // Debounce
    if (analogRead(FSR_PIN) > FSR_THRESHOLD) {
      // Impact detected
      String message = "LOCATION:\n";
      message += locationURL;

      Serial.println(message);
      sendSMS(phoneNumber, "My Name is Juan Dela Cruz. I got into an accident.");
      delay(2000);
      sendSMS(phoneNumber, message);
      Serial.println("Message sent");

      delay(30000); // Wait for 30 seconds before sending another SMS (adjust as needed)
      Serial.println("Waiting for impact");
    }
  }

  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      if (gps.location.isValid()) {
        locationURL = "https://www.google.com/maps/place/" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
        Serial.println(locationURL);
      } else {
        locationURL = "Location: INVALID";
        Serial.println(locationURL);
      }
    }
  }

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS data received. Check wiring."));
  }
}

void sendSMS(const char* phoneNumber, const char* message) {
  Serial.println("Sending SMS...");
  delay(3000);
  gsmSerial.println("AT+CMGF=1"); // Set SMS text mode
  delay(100);
  gsmSerial.print("AT+CMGS=\""); // Set recipient number
  gsmSerial.print(phoneNumber);
  gsmSerial.println("\"");
  delay(100);
  gsmSerial.println(message); // Set SMS content
  delay(100);
  gsmSerial.println((char)26); // Send the SMS
  delay(1000);
}
