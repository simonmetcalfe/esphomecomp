#include "plant_sensor_hub_number.h"
#include "esphome/core/log.h"

namespace esphome {
namespace plant_sensor_hub {

static const char *const TAG = "plant_sensor_hub.number";

void PlantSensorHubNumber::setup() {
  float value;
  if (!restore_value_) {
    value = initial_value_;
  } else {
    pref_ = this->template make_entity_preference<float>();
    if (!pref_.load(&value)) {
      value = initial_value_;
    }
  }
  publish_state(value);
}

void PlantSensorHubNumber::control(float value) {
  if (optimistic_)
    publish_state(value);

  if (restore_value_)
    pref_.save(&value);
}

}  // namespace plant_sensor_hub
}  // namespace esphome
