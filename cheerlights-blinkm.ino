// use the ThingSpeak library
#include "ThingSpeak/ThingSpeak.h"

// enables HTTP requests
TCPClient client;

// cheerlights channel
unsigned long cheerLightsChannelNumber = 1417;

// runs once at the beginning
void setup() {
    // start the ThingSpeak client
    ThingSpeak.begin(client);

    // join i2c bus
    Wire.begin();
    
    // turn off any blinkm scripts
    Wire.beginTransmission(0x00);
    Wire.write('o');
    Wire.endTransmission();
}

// runs continuously
void loop() {
    // Read the latest value from field 1 of channel 1417
    String cheerlights_color = ThingSpeak.readStringField(cheerLightsChannelNumber, 1);

    // change the color to the cheerlights color
    changeColor(cheerlights_color);
    
    // wait 3 seconds before checking for another color
    delay(3000);
}

// transmit to the I2C
void transmitColor(byte red, byte green, byte blue) {
    // begin transmission to 0x00, which will send to all connected I2Cs
    Wire.beginTransmission(0x00);
    // fade to a color
    Wire.write('c');
    // set the RGB bytes
    Wire.write(red);
    Wire.write(green);
    Wire.write(blue);
    // send the transmission
    Wire.endTransmission();  
}

// set color based on name
void changeColor(String color_name) {
    if (color_name == "red") {
        transmitColor(0xff, 0x00, 0x00);
    } else if (color_name == "green") {
        transmitColor(0x00, 0x80, 0x00);
    } else if (color_name == "blue") {
        transmitColor(0x00, 0x00, 0xff);
    } else if (color_name == "cyan") {
        transmitColor(0x00, 0xff, 0xff);
    } else if (color_name == "white") {
        transmitColor(0xff, 0xff, 0xff);
    } else if (color_name == "oldlace") {
        transmitColor(0xfd, 0xf5, 0xe6);
    } else if (color_name == "warmwhite") {
        transmitColor(0xfd, 0xf5, 0xe6);
    } else if (color_name == "purple") {
        transmitColor(0x80, 0x00, 0x80);
    } else if (color_name == "magenta") {
        transmitColor(0xff, 0x00, 0xff);
    } else if (color_name == "yellow") {
        transmitColor(0xff, 0xff, 0x00);
    } else if (color_name == "orange") {
        transmitColor(0xff, 0xa5, 0x00);
    } else if (color_name == "pink") {
        transmitColor(0xff, 0xc0, 0xcb);
    }
}

