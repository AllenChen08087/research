#include <RemoteXY.h>
#include <WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define PIN 6  // OneWire pin
OneWire oneWire(PIN);
DallasTemperature sensors(&oneWire);

RemoteXY remoteXY;

const int motor1_A = 2;
const int motor1_B = 3;
const int motor2_A = 4;
const int motor2_B = 5;

void setup() {
  pinMode(motor1_A, OUTPUT);
  pinMode(motor1_B, OUTPUT);
  pinMode(motor2_A, OUTPUT);
  pinMode(motor2_B, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  RemoteXY_Handler();
  sensors.requestTemperatures();
  float value = sensors.getTempCByIndex(0);

  int input = remoteXY.switch_1;
  int int_time1 = 1000;
  int int_time2 = 10000;

  if (input == 1) {
    digitalWrite(motor1_A, HIGH);
    digitalWrite(motor1_B, LOW);
    digitalWrite(motor2_A, HIGH);
    digitalWrite(motor2_B, LOW);
    delay(int_time1);
  } else {
    digitalWrite(motor1_A, LOW);
    digitalWrite(motor1_B, LOW);
    digitalWrite(motor2_A, LOW);
    digitalWrite(motor2_B, LOW);
    delay(int_time2);
  }

  Serial.println("cycle complete");
  Serial.println(value);
}
