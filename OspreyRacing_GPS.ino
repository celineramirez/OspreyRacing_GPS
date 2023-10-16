#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <SPI.h>
#include <SD.h>

// GPS pins
int RXPin = 2;
int TXPin = 3;

//NEO-6M baud constant
int GPSBaud = 9600;

// initialize GPS serial
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);

  // init SD card
    if (!SD.begin(4)) {
    Serial.println("failed to initialize SD");
    while (1);
  }
  
  // CSV data file on SD
  file = SD.open("data.csv", FILE_WRITE);
}

void loop()
{
  // write GPS data to csv data file on SD
  while (gpsSerial.available() > 0) {
    data = gpsSerial.read();
    file.write(data);
  }
}
