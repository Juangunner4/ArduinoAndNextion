

#include <Nextion.h>
#include <SoftwareSerial.h>

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
  String message = myNextion.listen(); // Check for message
  field=0;
  message.toCharArray(charstring,80);

  if(message != ""){ //if message is received...
    Serial.println(charstring); //...Print out
    pch = strtok(charstring, " ");
    while(pch != NULL) {
      field++;

      if(field==1)event=atoi(pch);
      if(field==2)page=atoi(pch);
      if(field==3)id=strtol(pch,NULL,16);
      if(field==4)value=atoi(pch);
      pch = strtok(NULL, " ");
    }
   if(message=="65 1 7 1 ffff ffff ffff"){
    myNextion.sendCommand("n0.val+=1"); 
   }
   if(message=="65 
  }
}
