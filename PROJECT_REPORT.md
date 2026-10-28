# SMART CONVEYOR BELT USING ARDUINO AND ULTRASONIC SENSOR

## 1. Abstract
This project demonstrates a smart conveyor control system using an Arduino Uno and an HC-SR04 ultrasonic sensor. The sensor checks whether an object is present near the detection point. If an object comes within the set distance, the controller stops the simulated conveyor, switches on a warning LED, sounds a buzzer, and moves a servo-operated diverter gate. When the area becomes clear, the system resumes automatically. The circuit is designed for testing in the Wokwi online simulator.

## 2. Objectives
- Detect objects automatically.
- Demonstrate automatic stop and restart logic.
- Provide visual and audible alerts.
- Demonstrate a servo-operated sorting/diverter gate.
- Understand the use of sensors and controllers in industrial automation.

## 3. Components required
| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno R3 | 1 | Main controller |
| HC-SR04 ultrasonic sensor | 1 | Object-distance detection |
| Micro servo motor | 1 | Diverter-gate demonstration |
| Green LED | 1 | Conveyor-running indication |
| Red LED | 1 | Object-detected indication |
| 220-ohm resistor | 2 | LED current limiting |
| Piezo buzzer | 1 | Audible warning |
| Jumper wires | As required | Connections |

## 4. Working principle
The HC-SR04 sends an ultrasonic pulse and measures the time taken for the echo to return. The Arduino converts this time into distance. If the measured distance is 15 cm or less, the Arduino marks an object as detected. The green LED turns off, the red LED turns on, the buzzer gives a short alert, and the servo moves to 90 degrees. When the distance becomes 18 cm or more, the system returns to the running state and the servo returns to zero degrees. Two different thresholds help prevent rapid ON/OFF switching near the detection boundary.

## 5. Pin connections
| Device pin | Arduino connection |
|---|---|
| HC-SR04 TRIG | D7 |
| HC-SR04 ECHO | D6 |
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| Servo signal (PWM) | D9 |
| Servo V+ | 5V in simulation |
| Servo GND | GND |
| Green LED anode | D4 through 220-ohm resistor |
| Green LED cathode | GND |
| Red LED anode | D3 through 220-ohm resistor |
| Red LED cathode | GND |
| Buzzer positive | D5 |
| Buzzer negative | GND |

## 6. Algorithm
1. Start the system.
2. Configure sensor, LED, buzzer, and servo pins.
3. Read the object distance.
4. If distance is 15 cm or less, stop the simulated belt and activate the warning outputs.
5. If distance is 18 cm or more, resume the simulated belt and reset the gate.
6. Display the current state and distance in the Serial Monitor.
7. Repeat continuously.

## 7. Applications
- Parcel and package handling demonstrations
- Object detection on conveyor systems
- Introductory industrial automation training
- Sorting-line control concepts
- Educational embedded-systems projects

## 8. Advantages
- Automatic object detection
- Simple and low-cost demonstration
- Easy to modify for different detection distances
- Combines sensing, control, and output indication
- Can be tested without physical hardware using Wokwi

## 9. Limitations and future scope
This simulation uses an LED to represent the conveyor motor status; it does not drive a physical belt. The servo demonstrates a diverter gate rather than industrial sorting machinery. Future versions can add a real conveyor motor and suitable motor driver, emergency-stop switch, speed control, item counter, load sensor, and display. For a physical build, use an appropriately rated external motor supply and motor driver, connect grounds correctly, and keep fingers and loose clothing away from moving parts.

## 10. Conclusion
The Smart Conveyor Belt simulation shows how a microcontroller and distance sensor can automate object detection and conveyor stop/restart behavior. The LEDs, buzzer, and servo provide clear feedback, making the project suitable for learning the basic principles of smart conveyor automation.
