//Define the pins for the ultrasonic sensor
const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4; 

long duration;
int distance;

void setup() {
  //Initialize serial communication
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  //Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  //Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Measure the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  //Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  //Check if the distance is below a certain threshold
  if (distance < 150) { 
    //If obstacle is detected, produce an audio prompt
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin); //Turn off the buzzer
  }
  delay(1000);
}