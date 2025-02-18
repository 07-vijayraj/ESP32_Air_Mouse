# ESP32_Air_Mouse

An ESP32 air mouse is a wireless device that uses an ESP32 microcontroller and an Adafruit MPU6050 sensor to control a computer cursor by detecting hand movements. It senses motion with accelerometers and gyroscopes, processes this data to move the cursor, and connects to the computer using Bluetooth through the ESP32-BLE-Mouse library. This allows you to control the cursor in real time, making it useful for presentations or as an assistive device.


## Libraries:

* ESP32-BLE-Mouse -[https://github.com/sirfragles/ESP32-BLE-Mouse](https://github.com/sirfragles/ESP32-BLE-Mouse)
 * Adafruit MPU6050 [https://github.com/adafruit/Adafruit_MPU6050](https://github.com/adafruit/Adafruit_MPU6050)


## Steps

Please install these two libraries in your IDE before uploading the code:

-[Adafruit MPU6050]   
-[ESP32-BLE-Mouse] 

## Connections:
connects the pin according

| Components             | ESP32                                                                |
| ----------------- | ------------------------------------------------------------------ |
| MPU6050 SDA | pin21 |
| MPU6050 SCL | pin22 |
|   Button 1 |  pin18|
| Button 1 |  pin19|

