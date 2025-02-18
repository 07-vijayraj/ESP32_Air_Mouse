#include <BleMouse.h>
#include <Adafruit_MPU6050.h>

#define LEFTBUTTON 19
#define RIGHTBUTTON 17
#define SPEED 6


Adafruit_MPU6050 mpu;
BleMouse bleMouse;

bool sleepMPU = true;
long mpuDelayMillis;

void setup() {
  Serial.begin(115200);

  pinMode(LEFTBUTTON, INPUT_PULLUP);
  pinMode(RIGHTBUTTON, INPUT_PULLUP);

  bleMouse.begin();

  delay(1000);
  // Try to initialize MPU!
  if (!mpu.begin(0x68)) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  //Sleep MPU library till Bluetooth is connected as it seems to interrupt connection
  mpu.enableSleep(sleepMPU);
}

void loop() {
  if (bleMouse.isConnected()) {
    if (sleepMPU) {
      delay(3000);
      Serial.println("MPU6050 awakened!");
      sleepMPU = false;
      mpu.enableSleep(sleepMPU);
      delay(500);
    }

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

        // Apply a dead zone to ignore small gyro drifts
    float gyroX = g.gyro.x;
    float gyroY = g.gyro.y;
    float gyroZ = g.gyro.z;

    // Dead zone threshold (adjust as needed)
    float threshold = 0.01;

    if (abs(gyroX) < threshold) gyroX = 0;
    if (abs(gyroY) < threshold) gyroY = 0;
    if (abs(gyroZ) < threshold) gyroZ = 0;

    // Adjust axis mapping if necessary
    int moveX = gyroZ * -SPEED;
    int moveY = gyroY * SPEED;

    // Depending on how you connected the MPU6050
    // You might need to swap these axeses or make them positive or negative
    bleMouse.move(moveX, moveY, gyroX * SPEED);
    //bleMouse.move(g.gyro.z * -SPEED, g.gyro.y * +SPEED , g.gyro.x * +SPEED);

    if (!digitalRead(LEFTBUTTON)) {
      Serial.println("Left click");
      bleMouse.click(MOUSE_LEFT);
      delay(500);
    }

    if (!digitalRead(RIGHTBUTTON)) {
      Serial.println("Right click");
      bleMouse.click(MOUSE_RIGHT);
      delay(500);
    }
  }
}
