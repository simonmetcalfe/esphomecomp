#include "empty_sensor_hub.h"
#include "esphome/core/log.h"

namespace esphome
{
    namespace empty_sensor_hub
    {

        static const char *TAG = "empty_sensor_hub.component";

        void EmptySensorHub::setup()
        {
        }

        void EmptySensorHub::dump_config()
        {
            for (auto *sensor : this->sensor1_)
            {
                LOG_SENSOR("  ", "Plant 1", sensor);
            }

            for (auto *sensor : this->sensor2_)
            {
                LOG_SENSOR("  ", "Plant 2", sensor);
            }

            for (auto *sensor : this->sensor3_)
            {
                LOG_SENSOR("  ", "Plant 3", sensor);
            }

            for (auto *sensor : this->sensor4_)
            {
                LOG_SENSOR("  ", "Plant 4", sensor);
            }

            for (auto *text_sensor : this->text_sensors_)
            {
                LOG_TEXT_SENSOR("  ", "Status", text_sensor);
            }

            for (auto *binary_sensor : this->binary_sensors_)
            {
                LOG_BINARY_SENSOR("  ", "Tank", binary_sensor);
            }
        }

    } // namespace empty_sensor_hub
} // namespace esphome