int sensorpin=23;
int buzzer=15;
void setup() {
  // put your setup code here, to run once:
pinMode(sensorpin,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(sensorpin);
if(val==0){
  digitalWrite(buzzer,1);
  Serial.println("object");
}else{
  digitalWrite(buzzer,0);
  Serial.println("no object");
delay(1000);
}
}
