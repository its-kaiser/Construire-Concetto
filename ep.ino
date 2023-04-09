#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

int buzzer = 8;
float currentAngle;
float Change_in_AngleX;
float Change_in_AngleY;
float Change_in_AngleZ;
float angleX;
float angleY;
float angleZ;
float angleX1;
float angleY1;
float angleZ1;
float currentAngleX;
float currentAngleY;
float currentAngleZ;

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Replace 4 and 5 with the SDA and SCL pin used on your ESP8266 board
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("  accY : ");Serial.print(mpu6050.getAccY());
    Serial.print("  accZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("  gyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("  gyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("  accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("  gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("  gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("  angleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================");
    timer = millis();

    angleX = mpu6050.getAngleX();
    angleY = mpu6050.getAngleY();
    angleZ = mpu6050.getAngleZ();
    
    delay(1000);

    angleX1 = mpu6050.getAngleX();
    angleY1 = mpu6050.getAngleY();
    angleZ1 = mpu6050.getAngleZ();

    delay(1000);
  }
  Change_in_AngleX = angleX1 - angleX;
  Change_in_AngleY = angleY1 - angleY;
  Change_in_AngleZ = angleZ1 - angleZ;
  
  if(true){
    if(currentAngleX == angleX && Change_in_AngleX > 10){
         digitalWrite(buzzer,HIGH);
     }
     if(currentAngleY == angleY && Change_in_AngleY > 10){
         digitalWrite(buzzer,HIGH);
     }
     if(currentAngleZ == angleZ && Change_in_AngleZ > 10){
         digitalWrite(buzzer,HIGH);
     }
  }
  else if(true){
  
    if(5<Change_in_AngleX<10){
      Serial.println("Person is kinda walking");
    }
    if(5<Change_in_AngleY<10){
      Serial.println("Person is kinda walking");
    }
    if(5<Change_in_AngleZ<10){
      Serial.println("Person is kinda walking");
    }
  }
  else if(Change_in_AngleX<5){
    Serial.println("Person is at rest kinda position");
  }
}
