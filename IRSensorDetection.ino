#define irsen 25
#define buzzer 27
#define ledR 21
#define ledG 18

void setup() {
  // put your setup code here, to run once:
pinMode(irsen,INPUT);
pinMode(buzzer,OUTPUT);
pinMode(ledR,OUTPUT);
pinMode(ledG,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
if(digitalRead(irsen)==1){
  digitalWrite(ledG,1);
  digitalWrite(ledR,0);
  digitalWrite(buzzer,0);
  }
else{
  digitalWrite(ledG,0);
  digitalWrite(ledR,1);
  digitalWrite(buzzer,1);
}
}