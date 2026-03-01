#pragma once

#include "esphome/components/number/number.h"
#include "esphome/core/component.h"
#include "esphome/core/entity_base.h"
#include "esphome/core/preferences.h"

namespace esphome {
namespace plant_sensor_hub {

class PlantSensorHubNumber : public number::Number, public Component {
 public:
  void setup() override;
  void set_optimistic(bool optimistic) { optimistic_ = optimistic; }
  void set_initial_value(float v) { initial_value_ = v; }
  void set_restore_value(bool v) { restore_value_ = v; }

 protected:
  void control(float value) override;

  bool optimistic_{true};
  float initial_value_{0};
  bool restore_value_{true};
  ESPPreferenceObject pref_;
};

}  // namespace plant_sensor_hub
}  // namespace esphome
