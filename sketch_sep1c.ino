int grn =12;
int   ylw =11;
int red=10;
char cmd;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(grn,OUTPUT);
pinMode(ylw,OUTPUT);
pinMode(red,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
cmd= Serial.read();
}
if(cmd=='r')
{
  digitalWrite(grn,LOW);
  digitalWrite(ylw,LOW);
   digitalWrite(red,HIGH);
}
if(cmd=='y')
{
  digitalWrite(grn,LOW);
  digitalWrite(ylw,HIGH);
   digitalWrite(red,LOW);
}
if(cmd=='g')
{
  digitalWrite(grn,HIGH);
  digitalWrite(ylw,LOW);
   digitalWrite(red,LOW);
}
}