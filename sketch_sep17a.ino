// Define the pins for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin
const int buzzerPin = 4; // Buzzer pin

// Variables for storing the distance and duration
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the trigger pin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  
  // Set the echo pin as an INPUT
  pinMode(echoPin, INPUT);
  
  // Set the buzzer pin as an OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse from the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is below a certain threshold (adjust as needed)
  if (distance < 150) { // Adjust the threshold value as needed
    // If obstacle is detected, produce an audio prompt
    tone(buzzerPin, 1000); // You can change the frequency and duration
    delay(500); // Delay for a short time
    noTone(buzzerPin); // Turn off the buzzer
  }

  // Wait for a short delay before taking the next measurement
  delay(1000);
}