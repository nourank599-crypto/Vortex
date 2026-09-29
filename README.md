# 🤖 Line Follower Robot

An autonomous two-wheeled robot built with Arduino Uno and L298N Motor Driver that tracks black or white lines using dual IR reflectance sensors.

---

## 📸 Hardware Setup

![Line Follower Robot Hardware](images/robot-hardware.jpg)

---

## 🛠️ Components & Hardware Specifications

- **Microcontroller:** Arduino Uno R3
- **Motor Driver:** L298N Dual H-Bridge Motor Driver
- **Sensors:** 2x Infrared (IR) Line Tracking Sensor Modules
- **Chassis:** 2WD Smart Robot Car Chassis Kit
- **Motors:** 2x DC TT Gear Motors
- **Power Supply:** External Battery Pack (7.4V - 9V)

---

## 📌 Circuit Pinout & Connections

| Component | Pin / Interface | Arduino Uno Pin | Description |
| :--- | :--- | :--- | :--- |
| **IR Sensor 1** | OUT / Digital | **Pin 11** | Left Line Sensor |
| **IR Sensor 2** | OUT / Digital | **Pin 12** | Right Line Sensor |
| **L298N Driver** | IN1 | **Pin 4** | Motor A Direction Control 1 |
| **L298N Driver** | IN2 | **Pin 5** | Motor A Direction Control 2 |
| **L298N Driver** | ENA | **Pin A0** | Motor A Speed Control (PWM) |
| **L298N Driver** | IN3 | **Pin 7** | Motor B Direction Control 1 |
| **L298N Driver** | IN4 | **Pin 6** | Motor B Direction Control 2 |
| **L298N Driver** | ENB | **Pin A1** | Motor B Speed Control (PWM) |

---

## 🧠 Control Logic Truth Table

| Sensor 1 (Left) | Sensor 2 (Right) | Robot Action | Left Motor | Right Motor |
| :---: | :---: | :---: | :---: | :---: |
| `BLACK (0)` | `BLACK (0)` | **Forward** | Forward | Forward |
| `WHITE (1)` | `WHITE (1)` | **Forward** | Forward | Forward |
| `BLACK (0)` | `WHITE (1)` | **Turn Right** | Forward | Stop |
| `WHITE (1)` | `BLACK (0)` | **Turn Left** | Stop | Forward |

---

## 💻 Source Code Overview

The algorithm continuously polls the digital state of both IR line tracking sensors:
- **Forward:** Both motors drive forward at full speed PWM (`CAR_SPEED = 255`).
- **Turn Right:** Disables Motor B and drives Motor A forward.
- **Turn Left:** Disables Motor A and drives Motor B forward.

```cpp
// Sample Code snippet from Line_Follower.ino
if ((digitalRead(SENSOR1) == BLACK) && (digitalRead(SENSOR2) == BLACK)) {
    forward();
} else if ((digitalRead(SENSOR1) == BLACK) && (digitalRead(SENSOR2) == WHITE)) {
    right();
} else if ((digitalRead(SENSOR1) == WHITE) && (digitalRead(SENSOR2) == BLACK)) {
    left();
}
