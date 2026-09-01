int r=3;
int y= 4;
int g = 5;
void setup() {
  pinMode(r ,OUTPUT);
pinMode(y ,OUTPUT);
pinMode(g ,OUTPUT);
  
  }


void loop() {
  // Nothing here
  digitalWrite(r, HIGH);
    delay(5000);
    digitalWrite(r, HIGH);
    delay(1000);
     digitalWrite(y, HIGH);
    delay(500);
    digitalWrite(r,LOW);
     digitalWrite(y,LOW);
     digitalWrite(g,HIGH);
     delay(5000);
      digitalWrite(g,LOW);


     }