#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/number/number.h"

namespace esphome {
namespace plant_sensor_hub {

static constexpr size_t MAX_PLANTS = 4;

// Number type indices: 0=pot_size, 1=min_moisture, 2=max_moisture, 3=leak_threshold (volatile)
struct PlantSensors {
  sensor::Sensor *moisture{nullptr};
  sensor::Sensor *water_count{nullptr};
  text_sensor::TextSensor *state{nullptr};
  number::Number *pot_size{nullptr};
  number::Number *min_moisture{nullptr};
  number::Number *max_moisture{nullptr};
  number::Number *leak_threshold{nullptr};
};

class PlantSensorHub : public PollingComponent {
 public:
  void set_num_plants(size_t n) { num_plants_ = n; }
  void register_moisture_sensor(size_t plant_index, sensor::Sensor *s);
  void register_water_count_sensor(size_t plant_index, sensor::Sensor *s);
  void register_plant_state_sensor(size_t plant_index, text_sensor::TextSensor *s);
  void register_binary_sensor(int type, binary_sensor::BinarySensor *s);
  void register_number(size_t plant_index, int type, number::Number *n);

  void setup() override;
  void update() override;
  void dump_config() override;

 protected:
  size_t num_plants_{4};
  PlantSensors plants_[MAX_PLANTS];
  binary_sensor::BinarySensor *tank_empty_{nullptr};
  binary_sensor::BinarySensor *alarm_{nullptr};
  binary_sensor::BinarySensor *watering_active_{nullptr};
};

}  // namespace plant_sensor_hub
}  // namespace esphome
