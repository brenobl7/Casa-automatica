#include <Servo.h>
#define trigPin 6
#define echoPin 7
Servo servo;
Servo servomotor;

int verd = 8;
int azul = 10;
int verm = 11;
int sens = A0;
int gas = 0;
int leituraLdr;

float leituraTemp=0;
float temperatura;
float luminosidade;

void setup()
{
	Serial.begin(9600);
  	servomotor.attach(2);
   	
  	pinMode(verd, OUTPUT);
  	pinMode(azul, OUTPUT);
  	pinMode(verm, OUTPUT);
  	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	servo.attach(9);
  	pinMode(A5, INPUT);
  	pinMode(A4, INPUT);
  	pinMode(3, INPUT);
  	pinMode(5,OUTPUT);
  	pinMode(4,OUTPUT);
  	pinMode(12,OUTPUT);
  	pinMode(13,OUTPUT);
}

void loop()
//cortina
{
  
  leituraTemp = analogRead(A5)*5;
  temperatura =((leituraTemp/1023)-0.5)*100;
  Serial.print("Temperatura : ");
  Serial.println(temperatura);
      
  luminosidade = analogRead(A4);
  Serial.print("Leitura da Luminosidade : ");
  Serial.println(luminosidade);
  
  if(luminosidade <=500)
  {
	servomotor.write(30);
  }    
  if(luminosidade >=500)
  {
   servomotor.write(100);
  }
  //sensor de presença
  {
  digitalWrite(5, LOW);
  int read=digitalRead(3);
  if(read == HIGH)
  {
    digitalWrite(5,HIGH);
    delay(000); 
    tone (4, 80, 0);
  }
   if(read == LOW)
   {
   delay(0); 
  noTone(4);
   }
}
  //sensor portao garagem
  {
  long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 30) {
servo.write(100);
}
if (distance > 31) {
servo.write(0);
}
}
  //temperatura
  {
  leituraTemp = analogRead(A5)*5;
  temperatura=((leituraTemp/1023)-0.5)*100;
  Serial.print("Temperatura : ");
  Serial.println(temperatura);
  if (temperatura <= 29)
{
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
}
  if (temperatura >= 30)
{
    digitalWrite(13, LOW);
	digitalWrite(12, HIGH);
  }
}
  //detector de gas
  {
  gas=analogRead(sens);
  Serial.println(gas);
  delay(500);
  
  if (gas >= 610) {
    digitalWrite(verd, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(verm, HIGH);
  }
  else if(gas >= 490) {
    digitalWrite(verd, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(verm, HIGH);  
    delay(50);
    digitalWrite(verm, LOW);
    delay(50);
  }
  else if(gas >= 380) {
    digitalWrite(verd, LOW);
    digitalWrite(verm, LOW);
    digitalWrite(azul, HIGH);
  }
  else if(gas >= 307) {
    digitalWrite(verd, LOW);
    digitalWrite(verm, LOW);
    digitalWrite(azul, HIGH);
    delay(50);
    digitalWrite(azul, LOW);
    delay(50);
  }
  else if(gas <= 306) {
    digitalWrite(verd, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(verm, LOW);
  }
  }
}
        