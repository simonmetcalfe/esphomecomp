/**
 * Example Arduino sketch demonstrating plant_data library usage.
 *
 * This shows how the same library can be used in:
 * 1. A standalone Arduino project (this file)
 * 2. An ESPHome component (components/plant_compound_sensor/)
 *
 * To use in a standalone Arduino project, copy plant_data.h and plant_data.cpp
 * from components/plant_compound_sensor/ into your project.
 */

#include <Arduino.h>
#include "plant_data.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Plant Data Library Example");
  Serial.println("==========================");

  plant_data_init();
}

void loop()
{
  plant_data_update();

  Serial.print("Temperature: ");
  Serial.print(plant_get_temperature());
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(plant_get_humidity());
  Serial.println(" %");

  Serial.print("Soil Moisture: ");
  Serial.print(plant_get_soil_moisture());
  Serial.println(" %");

  Serial.print("Status: ");
  Serial.println(plant_get_status());

  Serial.println("---");

  delay(1000);
}
