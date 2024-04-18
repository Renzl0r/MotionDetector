// Define constants for the PIR sensor pin, photoresistor pin, and LED pin
const int pirPin = 2;
const int photoPin = A0;
const int ledPin = 13;
const int nightThreshold = 300; // Adjust this value according to your lighting conditions

void setup() {
  // Initialize the PIR sensor pin and photoresistor pin as inputs
  pinMode(pirPin, INPUT);
  pinMode(photoPin, INPUT);
  
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication (optional)
  Serial.begin(9600);
}

void loop() {
  // Read the values from the PIR sensor and photoresistor
  int motionValue = digitalRead(pirPin);
  int lightValue = analogRead(photoPin);
  
  // Print the values to the serial monitor (optional)
  Serial.print("Motion: ");
  Serial.print(motionValue);
  Serial.print(", Light: ");
  Serial.println(lightValue);
  
  // Check if motion is detected and it's dark (below the threshold)
  if (motionValue == HIGH && lightValue < nightThreshold) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
  }
  
  // Add a delay to avoid reading the sensor too quickly
  delay(100);
}
