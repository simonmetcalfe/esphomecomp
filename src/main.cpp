/**
 * Example Arduino sketch demonstrating plant_data library usage.
 *
 * This shows how the same library can be used in:
 * 1. A standalone Arduino project (this file)
 * 2. An ESPHome component (components/plant_compound_sensor/)
 */

#include <Arduino.h>
#include "plant_data.h"

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.println("Plant Data Library Example");
  Serial.println("==========================");

  plant_data::init();
}

void loop()
{
  plant_data::update();

  Serial.print("Temperature: ");
  Serial.print(plant_data::get_temperature());
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(plant_data::get_humidity());
  Serial.println(" %");

  Serial.print("Soil Moisture: ");
  Serial.print(plant_data::get_soil_moisture());
  Serial.println(" %");

  Serial.print("Status: ");
  Serial.println(plant_data::get_status());

  Serial.println("---");

  delay(1000);
}
