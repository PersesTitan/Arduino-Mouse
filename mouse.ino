#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Mouse.h>
#include <Keyboard.h>

MPU6050 mpu(Wire);

//값을 저정
float bx = 0.0;
float by = 0.0;
float bz = 0.0;

void setup() {
  Serial.begin(19200);
  // Serial.begin(9600);
  Wire.begin();
  mpu.begin();
//  Keyboard.begin();
  // mpu.calcGyroOffsets(true);
  mpu.setGyroOffsets(-0.57, 1.31, 1.49);

  Mouse.begin();
  bx = mpu.getAngleX();
  by = mpu.getAngleY();
  bz = mpu.getAngleZ();
}

void loop() {
  mpu.update();
  float ax = mpu.getAngleX();
  float ay = mpu.getAngleY();
  float az = mpu.getAngleZ();

  float x = ax - bx;
  float y = ay - by;
  float z = az - bz;

  bx = mpu.getAngleX();
  by = mpu.getAngleY();
  bz = mpu.getAngleZ();

  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.print(z);
  Serial.println();

  // Mouse.move(x, y);
  // Mouse.move(1, 0, 0);
  // Keyboard.write('a');
  delay(50);
}
