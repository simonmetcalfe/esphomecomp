#include "esphome/core/log.h"
#include "plant_compound_sensor.h"
#include "esphome_connector.h"

namespace esphome
{
  namespace plant_compound_sensor
  {

    static const char *TAG = "plant_compound_sensor.sensor";

    void PlantCompoundSensor::setup()
    {
    }

    void PlantCompoundSensor::loop()
    {
    }

    void PlantCompoundSensor::update()
    {
      if (this->cplant1_ != nullptr)
        this->cplant1_->publish_state(static_cast<float>(get_temperature()));
      if (this->cplant2_ != nullptr)
        this->cplant2_->publish_state(static_cast<float>(get_humidity()));
      if (this->cplant3_ != nullptr)
        this->cplant3_->publish_state(static_cast<float>(get_soil_moisture()));
      if (this->cplant4_ != nullptr)
        this->cplant4_->publish_state(8.0f);
    }

    void PlantCompoundSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "Plant compound sensor");
    }

  } // namespace plant_compound_sensor
} // namespace esphome