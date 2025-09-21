#include "esphome/core/log.h"
#include "empty_compound_sensor.h"

namespace esphome
{
  namespace empty_compound_sensor
  {

    static const char *TAG = "empty_compound_sensor.sensor";

    void EmptyCompoundSensor::setup()
    {
    }

    void EmptyCompoundSensor::loop()
    {
    }

    void EmptyCompoundSensor::update()
    {
      if (this->plant1_ != nullptr)
        this->plant1_->publish_state(1.0f);
      if (this->plant2_ != nullptr)
        this->plant2_->publish_state(2.0f);
      if (this->plant3_ != nullptr)
        this->plant3_->publish_state(3.0f);
      if (this->plant4_ != nullptr)
        this->plant4_->publish_state(4.0f);
    }

    void EmptyCompoundSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "Empty compound sensor");
    }

  } // namespace empty_compound_sensor
} // namespace esphome