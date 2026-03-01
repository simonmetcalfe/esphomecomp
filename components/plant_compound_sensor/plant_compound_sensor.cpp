#include "esphome/core/log.h"
#include "plant_compound_sensor.h"
#include "plant_data.h"

namespace esphome
{
  namespace plant_compound_sensor
  {

    static const char *TAG = "plant_compound_sensor.sensor";

    void PlantCompoundSensor::setup()
    {
      plant_data::init();
    }

    void PlantCompoundSensor::loop()
    {
      plant_data::update();
    }

    void PlantCompoundSensor::update()
    {
      if (this->cplant1_ != nullptr)
        this->cplant1_->publish_state(static_cast<float>(plant_data::get_temperature()));
      if (this->cplant2_ != nullptr)
        this->cplant2_->publish_state(static_cast<float>(plant_data::get_humidity()));
      if (this->cplant3_ != nullptr)
        this->cplant3_->publish_state(static_cast<float>(plant_data::get_soil_moisture()));
      if (this->cplant4_ != nullptr)
        this->cplant4_->publish_state(8.0f);

      /*
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

      */
    }

    void PlantCompoundSensor::dump_config()
    /*
    ESP_LOGD(TAG, "format", ...)	Debug	Detailed diagnostics
    ESP_LOGI(TAG, "format", ...)	Info	Normal status messages
    ESP_LOGW(TAG, "format", ...)	Warning	Warnings
    ESP_LOGE(TAG, "format", ...)	Error	Errors
    */

    {
      ESP_LOGI(TAG, "Plant compound sensor");
    }

  } // namespace plant_compound_sensor
} // namespace esphome
