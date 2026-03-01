#include "plant_sensor_hub.h"
#include "esphome/core/log.h"

namespace esphome {
namespace plant_sensor_hub {

static const char *const TAG = "plant_sensor_hub";

void PlantSensorHub::register_moisture_sensor(size_t plant_index, sensor::Sensor *s) {
  if (plant_index < MAX_PLANTS) {
    plants_[plant_index].moisture = s;
  }
}

void PlantSensorHub::register_water_count_sensor(size_t plant_index, sensor::Sensor *s) {
  if (plant_index < MAX_PLANTS) {
    plants_[plant_index].water_count = s;
  }
}

void PlantSensorHub::register_plant_state_sensor(size_t plant_index, text_sensor::TextSensor *s) {
  if (plant_index < MAX_PLANTS) {
    plants_[plant_index].state = s;
  }
}

void PlantSensorHub::register_binary_sensor(int type, binary_sensor::BinarySensor *s) {
  switch (type) {
    case 0:
      tank_empty_ = s;
      break;
    case 1:
      alarm_ = s;
      break;
    case 2:
      watering_active_ = s;
      break;
  }
}

void PlantSensorHub::setup() {
  ESP_LOGI(TAG, "Plant Sensor Hub: %zu plants", num_plants_);
}

void PlantSensorHub::update() {
  // Placeholder: publish mock data until real hardware/driver is integrated
  if (tank_empty_ != nullptr) {
    tank_empty_->publish_state(false);  // Tank not empty
  }
  if (alarm_ != nullptr) {
    alarm_->publish_state(false);  // Alarm off
  }
  if (watering_active_ != nullptr) {
    watering_active_->publish_state(false);  // Not watering
  }

  for (size_t i = 0; i < num_plants_ && i < MAX_PLANTS; i++) {
    if (plants_[i].moisture != nullptr) {
      plants_[i].moisture->publish_state(45.0f + (i * 5.0f));  // Mock moisture %
    }
    if (plants_[i].water_count != nullptr) {
      plants_[i].water_count->publish_state(static_cast<float>(i * 3));  // Mock count
    }
    if (plants_[i].state != nullptr) {
      plants_[i].state->publish_state("ok");  // Mock state
    }
  }
}

void PlantSensorHub::dump_config() {
  ESP_LOGI(TAG, "Plant Sensor Hub:");
  ESP_LOGI(TAG, "  Num plants: %zu", num_plants_);
  if (tank_empty_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "Tank empty", tank_empty_);
  }
  if (alarm_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "Alarm", alarm_);
  }
  if (watering_active_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "Watering active", watering_active_);
  }
  for (size_t i = 0; i < num_plants_ && i < MAX_PLANTS; i++) {
    if (plants_[i].moisture != nullptr) {
      LOG_SENSOR("  ", "Plant moisture", plants_[i].moisture);
    }
    if (plants_[i].water_count != nullptr) {
      LOG_SENSOR("  ", "Plant water count", plants_[i].water_count);
    }
    if (plants_[i].state != nullptr) {
      LOG_TEXT_SENSOR("  ", "Plant state", plants_[i].state);
    }
  }
}

}  // namespace plant_sensor_hub
}  // namespace esphome
