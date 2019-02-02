// 2 Ultrasonic sensors and a buzzer

int trigPin1=2;
int echoPin1=3;

int trigPin2=4;
int echoPin2=5;

int buzzer=6;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(buzzer, OUTPUT);
   
}

void loop() {
  long duration1, distance1;  //Sensor 1
  digitalWrite(buzzer,LOW);
  digitalWrite(trigPin1, LOW);  // Clear trig pin
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW); 
  duration1 = pulseIn(echoPin1, HIGH); //echo high
  distance1 = (duration1/2) / 29.1;
  
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
    if(distance1 < 50)
     { 
        digitalWrite(buzzer, HIGH);
        delay(100);
     }
  digitalWrite(echoPin1, LOW);
  delay(250);
  
long duration2, distance2;   //Sensor 2
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= (duration2/2) / 29.1;
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
    if(distance2 < 40)
     { 
        digitalWrite(buzzer, HIGH);
        delay(100);
     }
  digitalWrite(echoPin2, LOW);
  delay(250);
}
