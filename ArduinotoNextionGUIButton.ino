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

void loop () {
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
      if(field==3)id=strtoul(pch,NULL,16); // Change so HEX changes to number not letter
      if(field==4)value=atoi(pch);
      pch = strtok(NULL, " ");

    }

    Serial.println(page);
    Serial.println(id);
    Serial.println(value);
    if(page==1 && id==0 && value==0){
      myNextion.sendCommand("page 4");
    }
    if(page==2 && id==2 && value==0){
     myNextion.sendCommand("n0.val+=1"); 
    }
    if(page==3 && id==2 && value==0){
      myNextion.sendCommand("n1.val+=1") ;
    }
    if(page==4 && id==3 && value==0){
      myNextion.sendCommand("page 5");
    }
    if (page==4 && id==3 && value==1){
      myNextion.sendCommand("page 5");
    }
    if(page==5 && id==2 && value==0){
      myNextion.sendCommand("page 1");
    }
    if(page==5 && id==3 && value==0){
      myNextion.sendCommand("page 0");
    }
  }

}
