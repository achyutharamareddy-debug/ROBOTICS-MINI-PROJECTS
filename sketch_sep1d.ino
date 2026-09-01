int led=13;
int data;
int ir=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
data=digitalRead(ir);
Serial.println(data);

if(data==LOW)
{
  digitalWrite(led, HIGH);
}
else
{
  digitalWrite(led,LOW);
}


}