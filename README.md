# Arduino Water Level Indicator with LEDs and Buzzer

## 📌 Project Overview

This project demonstrates a **water level indicator** using an **Arduino**, a **water level sensor**, **three LEDs**, and a **buzzer**. The system continuously monitors the water level and provides **visual (LEDs)** and **audio (buzzer)** alerts based on predefined thresholds.

It is suitable for beginners and can be used in **water tanks, labs, or small automation projects**.

---

## 🧰 Components Used

* Arduino Uno (or compatible)
* Water Level Sensor (Analog output)
* 3 LEDs (Low, Medium, High level)
* 3 × 220Ω resistors (for LEDs)
* Buzzer
* Breadboard
* Jumper wires

---

## 🔌 Pin Configuration

| Component        | Arduino Pin |
| ---------------- | ----------- |
| Water Sensor     | A0          |
| Low Level LED    | D10         |
| Medium Level LED | D11         |
| High Level LED   | D12         |
| Buzzer           | D13         |

---

## ⚙️ Working Principle

1. The **water sensor** outputs an analog value depending on the water level.
2. The Arduino reads the sensor value multiple times and calculates an **average** to reduce noise.
3. Based on the sensor value:

   * **Low LED** turns ON for low water level
   * **Medium LED** turns ON for medium level
   * **High LED** turns ON for high/full level
   * **Buzzer** alerts when the tank is full or critically low
4. Sensor readings are also displayed on the **Serial Monitor**.

---

## 🧠 Code Explanation

### 1️⃣ Variable Declaration

```cpp
int waterSensorPin = A0;
int low_led = 10;
int med_led = 11;
int high_led = 12;
int buzzer = 13;
```

Defines pins for the water sensor, LEDs, and buzzer.

---

### 2️⃣ Setup Function

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(low_led, OUTPUT);
  pinMode(med_led, OUTPUT);
  pinMode(high_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
```

* Initializes serial communication at **9600 baud rate**
* Sets LEDs and buzzer pins as outputs

---

### 3️⃣ Sensor Averaging Function

```cpp
int getAverageSensorValue() {
  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(waterSensorPin);
    delay(5);
  }
  return sum / 10;
}
```

* Reads the sensor **10 times**
* Averages the readings to get stable and accurate values

---

### 4️⃣ Main Loop Logic

```cpp
int sensorValue = getAverageSensorValue();
```

* Fetches the averaged sensor value

```cpp
Serial.print("Water Level: ");
Serial.println(sensorValue);
```

* Displays water level readings on Serial Monitor

---

### 5️⃣ Level Conditions

#### 🔴 High Water Level (≥ 360)

```cpp
digitalWrite(high_led, HIGH);
digitalWrite(buzzer, HIGH);
```

* High-level LED turns ON
* Buzzer beeps as an overflow alert

#### 🟡 Medium Water Level (≥ 270)

```cpp
digitalWrite(med_led, HIGH);
```

* Medium-level LED turns ON

#### 🟢 Low Water Level (≥ 170)

```cpp
digitalWrite(low_led, HIGH);
```

* Low-level LED turns ON

#### ⚠️ Very Low / Empty Level (< 170)

```cpp
digitalWrite(buzzer, HIGH);
```

* Buzzer alerts for critically low water

---

## 📊 Water Level Thresholds

| Sensor Value | Indication                    |
| ------------ | ----------------------------- |
| ≥ 360        | Tank Full (High LED + Buzzer) |
| ≥ 270        | Medium Level (Medium LED)     |
| ≥ 170        | Low Level (Low LED)           |
| < 170        | Empty / Critical (Buzzer)     |

> ⚠️ *Thresholds may vary depending on the water sensor used and should be calibrated.*

---

## 🚀 Applications

* Water tank monitoring
* Overflow prevention systems
* Home automation projects
* Educational Arduino projects

---

## 🔧 Possible Improvements

* Add an **LCD display** for percentage level
* Control a **relay** to automatically stop the motor
* Add **IoT (ESP8266/ESP32)** for mobile monitoring

---

## 👨‍💻 Author

**Muhammad Abdullah**
Arduino & Robotics Project

---

## 📜 License

This project is open-source and free to us
