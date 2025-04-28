#include <Arduino.h>
#include <ESP32Servo.h>
#include <PS4Controller.h>

const uint8_t SERVO_PIN_LITTLE = 12;
const uint8_t SERVO_PIN_RING = 14;
const uint8_t SERVO_PIN_MIDDLE = 27;
const uint8_t SERVO_PIN_INDEX = 26;
const uint8_t SERVO_PIN_THUMB = 25;
const uint8_t SENSOR_LITTLE = 32;
const uint8_t SENSOR_RING = 15;
const uint8_t SENSOR_MIDDLE = 2;
const uint8_t SENSOR_INDEX = 0;
const uint8_t SENSOR_THUMB = 4;

Servo little, ring, middle, hitosasi, thumb;

bool prevCircleState = false;
bool prevCrossState = false;
bool prevSquareState = false;
bool prevTriangleState = false;
void setup() {
    // PS4.begin("08:B6:1F:ED:5E:34");
    Serial.begin(9600);
    little.attach(SERVO_PIN_LITTLE);
    ring.attach(SERVO_PIN_RING);
    middle.attach(SERVO_PIN_MIDDLE);
    hitosasi.attach(SERVO_PIN_INDEX);
    thumb.attach(SERVO_PIN_THUMB);
}

void loop() {
    int little_value, ring_value, middle_value, hitosasi_value, thumb_value;
    if (!PS4.isConnected()) {
        return;
    }

    little_value = map(analogRead(SENSOR_INDEX), 100, 1024, 0, 90);
    ring_value = map(analogRead(SENSOR_RING), 100, 1024, 0, 90);
    middle_value = map(analogRead(SENSOR_MIDDLE), 100, 1024, 0, 90);
    hitosasi_value = map(analogRead(SENSOR_INDEX), 100, 1024, 0, 90);
    thumb_value = map(analogRead(SENSOR_THUMB), 100, 1024, 0, 90);

    little.write(little_value);
    ring.write(ring_value);
    middle.write(middle_value);
    hitosasi.write(hitosasi_value);
    thumb.write(thumb_value);
}

//  // PS4.begin("08:B6:1F:ED:5E:34");
//   Serial.begin(9600);
//   little.attach(SERVO_PIN_LITTLE);
//   ring.attach(SERVO_PIN_RING);
//   middle.attach(SERVO_PIN_MIDDLE);
//   hitosasi.attach(SERVO_PIN_INDEX);
//   thumb.attach(SERVO_PIN_THUMB);
// }

// void loop()
// {
//   if (!PS4.isConnected())
//   {
//     return;
//   }

//   bool circlePressed = PS4.Circle();
//   bool crossPressed = PS4.Cross();
//   bool squarePressed = PS4.Square();
//   bool trianglePressed = PS4.Triangle();

//   if (circlePressed)
//   {
//     little.write(180); // 時計回りに回転
//     delay(500);        // 0.5秒回転（調整可）
//     little.write(90);  // 停止（中立の90にする）
//     little.write(0);   // 時計回りに回転
//     delay(500);        // 0.5秒回転（調整可）
//     little.write(90);  // 停止（中立の90にする）
//   }
//   if (crossPressed)
//   {
//     ring.write(180);
//     delay(500);
//     ring.write(90);
//     ring.write(0);
//     delay(500);
//     ring.write(90);
//   }

//   if (squarePressed)
//   {
//     middle.write(180);
//     delay(500);
//     middle.write(90);
//     middle.write(0);
//     delay(500);
//     middle.write(90);
//   }

//   if (trianglePressed)
//   {
//     hitosasi.write(180);
//     delay(500);
//     hitosasi.write(90);
//     hitosasi.write(0);
//     delay(500);
//     hitosasi.write(90);
//   }
//   if (circlePressed)
//   {
//     thumb.write(180);
//     delay(500);
//     thumb.write(90);
//     thumb.write(0);
//     delay(500);
//     thumb.write(90);
//   }
