
//TVC Code

#include <Servo.h> 
#include <I2Cdev.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
Servo xservo;
Servo yservo;

int p = 1;
int i = 0.1;
int d = 0.1;

void setup() {
   Serial.begin(115200);
   Wire.begin();
   mpu.begin();
   xservo.attach(4);  
   yservo.attach(5);  
   
}
void loop(){ 
  mpu.update();
  if (mpu.getAngleX() > 0){
    xservo.write((p * ((mpu.getAngleX()) - 85)));
  }
  else {
     xservo.write((mpu.getAngleX()) + 265);
  }
      yservo.write(((p * (86 + (-1 * mpu.getAngleY())))));
}
