int r=12;
int y=11;
int g= 10;
int ir1, ir2;
int r1=8 , r2=9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(r1,INPUT);
pinMode(r2,INPUT);
pinMode(r,OUTPUT);
pinMode(y,OUTPUT);
pinMode(g,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
ir1=digitalRead(r1);


ir2=digitalRead(r2);


if(ir1==LOW && ir2==HIGH)
{
  digitalWrite(r, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
  

}
else if(ir2==LOW && ir1==HIGH)
{
  digitalWrite(g, HIGH);
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);

}
else if(ir1==LOW && ir2==LOW)
{
 digitalWrite(g, LOW);
  digitalWrite(r, LOW);
  digitalWrite(y, HIGH);
}
else
{
  digitalWrite(g, LOW);
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
}
  



}