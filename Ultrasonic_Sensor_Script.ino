#include <Stepper.h>

// ultrasonic sensor GPIOs
const int trigPin = 4;
const int echoPin = 6;

// define variables to hold data for ultrasonic sensor
long duration;
int distance;

// stepper motor GPIOs
const int In1 = 43;
const int In2 = 44;
const int In3 = 1;
const int In4 = 2;

// the 28BYJ-48 motor has 2048 steps per full revolution
const int stepsPerRevolution = 2048;

// Initialize the stepper library on pins In1 through In4
Stepper myStepper(stepsPerRevolution, In1, In2, In3, In4);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 1. clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. read the echoPin to get the travel time of the sound wave
  duration = pulseIn(echoPin, HIGH);

  // 4. Calculate the distance (in centimeters)
  distance = duration * 0.034 / 2;

  // 5. if distance is within bounds print distance, otherwise print "no object"
  if (distance > 25) {
    Serial.print("Path is clear, moving FAST.");
    myStepper.setSpeed(15); // 15 RPM
    myStepper.step(50); // take 50 steps forward
    Serial.println();
  } else if (distance <= 25 && distance > 10) {
    Serial.print("Object near, moving SLOW.");
    myStepper.setSpeed(5); // 5 RPM
    myStepper.step(50); // take 50 steps forward
    Serial.println();
  } else {
    Serial.println("Object imminent. Stopping");
    myStepper.step(-50); // take 50 steps backward
  }

  // add short delay before taking next measurement
  delay(1000);
}
