/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */
int FAR = 100;
int OK = 50;

int loops=0;
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);    
  pinMode(3, OUTPUT);
  // Leds
  pinMode(4, OUTPUT);//OK
  pinMode(5, OUTPUT);//FAR
  pinMode(6, OUTPUT);//NEAROK
  
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(200);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  delay(200);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  delay(200);
  digitalWrite(6,LOW);  
  
}

void loop() {
  // Générer une impulsion de 10µs
  digitalWrite(3,LOW);
  delayMicroseconds(2);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  // Ensuite on lit l'état :
  
  int delta=pulseIn(2,HIGH,38*1000);
  
  int distance = delta/58;
  if(distance == OK) 
    digitalWrite(4,HIGH);
  else
    digitalWrite(4,LOW);
  if (distance > FAR)
    digitalWrite(5,HIGH);
  else
    digitalWrite(5,LOW);
  if ((distance < FAR) && (distance != OK))
    digitalWrite(6,HIGH);
  else
    digitalWrite(6,LOW);
    
  Serial.print(loops++);
  Serial.print(" ");
  Serial.print("t:");
  Serial.print(micros());
  
  Serial.print(" ");
  Serial.println(distance);
  delay(100);
  


}



