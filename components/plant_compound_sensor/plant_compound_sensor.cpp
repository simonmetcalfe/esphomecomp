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
      plant_data_init();
    }

    void PlantCompoundSensor::loop()
    {
      plant_data_update();
    }

    void PlantCompoundSensor::update()
    {
      if (this->cplant1_ != nullptr)
        this->cplant1_->publish_state(static_cast<float>(plant_get_temperature()));
      if (this->cplant2_ != nullptr)
        this->cplant2_->publish_state(static_cast<float>(plant_get_humidity()));
      if (this->cplant3_ != nullptr)
        this->cplant3_->publish_state(static_cast<float>(plant_get_soil_moisture()));
      if (this->cplant4_ != nullptr)
        this->cplant4_->publish_state(8.0f);
    }

    void PlantCompoundSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "Plant compound sensor");
    }

  } // namespace plant_compound_sensor
} // namespace esphome
