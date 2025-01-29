#define trigPin1 7   // Trigger pin for sensor 1
#define echoPin1 6   // Echo pin for sensor 1
#define trigPin2 5   // Trigger pin for sensor 2
#define echoPin2 4   // Echo pin for sensor 2

long duration1, duration2; // Variables for pulse durations
int distance1, distance2; // Variables for calculated distances

void setup() {
  pinMode(trigPin1, OUTPUT); // Set trigger pins as output
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT); // Set echo pins as input
  pinMode(echoPin2, INPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Sensor 1 measurement
  digitalWrite(trigPin1, LOW); // Clear trigger pin
  delayMicroseconds(2); // Wait for stabilization
  digitalWrite(trigPin1, HIGH); // Send a high pulse for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH); // Measure echo pulse duration

  // Sensor 2 measurement
  digitalWrite(trigPin2, LOW); // Clear trigger pin
  delayMicroseconds(2); // Wait for stabilization
  digitalWrite(trigPin2, HIGH); // Send a high pulse for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH); // Measure echo pulse duration

  // Calculate distances (assuming speed of sound = 343 m/s)
  distance1 = duration1 * 0.034 / 2; // Distance in cm (round trip conversion)
  distance2 = duration2 * 0.034 / 2; // Distance in cm (round trip conversion)

  // Print distances to serial monitor
  Serial.print("Distance Sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  delay(100); // Delay between readings
}
