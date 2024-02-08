const int trigPin = 9;
const int echoPin = 10;
const int light = 6;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(light, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if(distance < 150) {
    digitalWrite(light, HIGH);
  }
  else{
    digitalWrite(light, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(250);
}