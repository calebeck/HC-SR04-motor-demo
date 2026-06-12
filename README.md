# HC-SR04-motor-demo
Experimenting with HC-SR04 Ultrasonic sensor, implementing a fallback to design to simulate a platform navigating obstacles and adjusting a motor's RPMs accordingly

# Hardware Required
1. ESP32-S3 Development Board
2. HC-SR04 Ultrasonic Sensor
3. Various Types of Stepper Motor

# Design and Logic Currently
1. if sensor detects an object that is further than 25cm away and or does not detect an object - move forward fast
2. if sensor detects an object that is between 10 and 25 cm away - move forward slowly
3. if sensor detects an object within 10 cm - backup
- send text to serial monitor every second displaying current motor logic
