int trigPin = 13;
int echoPin = 11;
float pingTime; //Total time lab between trig and echo
float targetDistance;
float speedOfSound = 340.29; //In metres per second

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

}

void loop() {
  digitalWrite(trigPin,LOW); //Set trigger to low
  delayMicroseconds(2000); //Letting the signal settle
  digitalWrite(trigPin,HIGH); //Send a pulse
  delayMicroseconds(15); //Keep high for 15us
  digitalWrite(trigPin,LOW); //Set the pulse
  delayMicroseconds(10);

  pingTime = pulseIn(echoPin,HIGH); //Returns time delay in microseconds
  pingTime = pingTime/1000000; //pingTime in seconds
  targetDistance = speedOfSound*pingTime; //Twice the target distance in metres
  targetDistance = targetDistance/2;

  Serial.println(targetDistance);

  delay(100);

}
