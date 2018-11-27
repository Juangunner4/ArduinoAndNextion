

#include <SoftwareSerial.h>
#include <Nextion.h>

SoftwareSerial nextion(3,2);// Nextion TX pin 3 and RX pin 2 to Arduino

Nextion myNextion(nextion, 9600); // Create a Nextion object named myNextion using the nextion port @ 9600bps

char charstring[80];
char*pch;

int field, event, page, id, value;

void setup() {
  Serial.begin(9600);
  myNextion.init();

}

void loop() {
  String message = myNextion.listen(75);
  if (message == "65 1 4 1 ffff ffff ffff"); {
    myNextion.sendCommand("bt1.txt='Y'");
    myNextion.sendCommand("ref bt1");
  }
}
