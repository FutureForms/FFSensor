#include <FFSensor.h>
#include <FFS_MLX_SPI.h>

#include "calibration.h"

#define FFS_ENABLE_PIN  10

FFS_MLX_SPI mlx(FFS_ENABLE_PIN);
FFSensor sensor(mlx, calibration);

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  sensor.requestAndReadMeasurement(10);
  float forceX = sensor.x();
  float forceY = sensor.y();
  float forceZ = sensor.z();
  Serial.print(forceX);
  Serial.print(",");
  Serial.print(forceY);
  Serial.print(",");
  Serial.println(forceZ);
}
