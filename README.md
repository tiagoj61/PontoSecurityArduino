# Arduino BLE System for Work Attendance

## Overview
This project implements an Arduino-based system for work attendance management. It allows users to connect via Bluetooth Low Energy (BLE) and confirm their presence using a mobile application. The Arduino acts as the central device, responsible for handling Bluetooth connections and controlling a confirmation indicator (LED).

### Key Features:
- Bluetooth connectivity via BLE module.
- LED indicator to show connection status.
- Simple and efficient data communication between Arduino and the mobile app.

---

## How It Works
1. **Connection Setup**:
   - The Arduino board initializes the BLE module and sets up the communication channel via serial port.
   - The user connects to the BLE module using the mobile app.

2. **Confirmation Process**:
   - When the app sends a signal to the Arduino:
     - Sending `1` will turn on the LED, indicating a successful connection.
     - Sending `0` will turn off the LED, resetting the status.

3. **Feedback**:
   - The Arduino provides serial feedback to the app for confirmation of the received commands.

---

## Code Explanation
Here is the core functionality implemented in the Arduino code:

```cpp
#define ledPin 13
int data = 0;

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  digitalWrite(ledPin, LOW); // Turn off the LED initially
  Serial.print(78); // Send initial signal (optional, replace as needed)
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available from the BLE
    data = Serial.read(); // Read the received data

    if (data == '0') {
      digitalWrite(ledPin, LOW); // Turn off the LED
    } else if (data == '1') {
      Serial.print(78); // Optional feedback (modify if needed)
      digitalWrite(ledPin, HIGH); // Turn on the LED
    }
  }
}
```

### Explanation:
- **LED Control**:
  - The LED connected to pin 13 acts as a visual indicator of the connection status.
- **Serial Communication**:
  - The BLE module communicates with the Arduino through the serial interface, and the Arduino listens for commands (`0` or `1`) to control the LED.
- **Feedback**:
  - The Arduino sends serial feedback (character `78`) for confirmation, which can be processed by the mobile app.

---

## Hardware Requirements
- Arduino board (e.g., Arduino Uno, Nano)
- BLE module
- LED with a current-limiting resistor
- Connecting wires

---

## Setup and Installation
1. **Hardware Setup**:
   - Connect the BLE module to the Arduino:
   - Connect the LED to pin 13 with the resistor.

2. **Upload Code**:
   - Open the Arduino IDE.
   - Paste the provided code.
   - Select the correct board and port.
   - Upload the code to the Arduino.

3. **Pair BLE Module**:
   - Use a BLE-compatible app on your smartphone.
   - Pair with the BLE module and send `1` or `0` to test the functionality.

---

## Testing and Usage
- **Initial Test**:
  - Power up the Arduino.
  - Connect to the BLE module using the mobile app.
  - Send `1` and verify the LED lights up.
  - Send `0` and verify the LED turns off.

- **Deployment**:
  - Integrate with the mobile application for seamless user experience.
  - Ensure BLE connection reliability for real-time operation.
