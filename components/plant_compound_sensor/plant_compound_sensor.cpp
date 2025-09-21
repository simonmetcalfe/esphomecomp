#include "esphome/core/log.h"
#include "plant_compound_sensor.h"

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
        this->cplant1_->publish_state(1.0f);
      if (this->cplant2_ != nullptr)
        this->cplant2_->publish_state(2.0f);
      if (this->cplant3_ != nullptr)
        this->cplant3_->publish_state(3.0f);
      if (this->cplant4_ != nullptr)
        this->cplant4_->publish_state(4.0f);
    }

    void PlantCompoundSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "Plant compound sensor");
    }

  } // namespace plant_compound_sensor
} // namespace esphome