#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not eneble!
#endif

BluetoothSerial myinternalBT;
String voice;
char c;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myinternalBT.begin("diareddy");
}

void loop() {
  // put your main code here, to run repeatedly:

  while (myinternalBT.available()) {
    delay(10);                //delay added to make it stable
    c = myinternalBT.read();  //get new command
    if ((c >= 65) && (c <= 90))
      c += 32;

    voice += c;  //to make a string of command
  }
  if (voice.length() > 0) {
    Serial.println(voice);
    if ((voice == "what is your name")) {
      delay(600);
      myinternalBT.println("My name is Nagalakshmi, vishisht innovators");

    } else if (voice == "hello max how are you")  //1
    {
      delay(600);
      myinternalBT.println("I am fine , i am Excited for the expo");
    } else {
      myinternalBT.println("i cant get you");
      delay(600);
      voice = "";
    }
    voice = "";
  }
}
