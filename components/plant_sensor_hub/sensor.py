import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    DEVICE_CLASS_MOISTURE,
    STATE_CLASS_MEASUREMENT,
    UNIT_PERCENT,
)

from . import CONF_PLANT_SENSOR_HUB_ID, PlantSensorHub

DEPENDENCIES = ["plant_sensor_hub"]

CONF_PLANT_INDEX = "plant_index"
CONF_MOISTURE = "moisture"
CONF_WATER_COUNT = "water_count"

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(CONF_PLANT_SENSOR_HUB_ID): cv.use_id(PlantSensorHub),
            cv.Required(CONF_PLANT_INDEX): cv.int_range(min=0, max=3),
            cv.Optional(CONF_MOISTURE): sensor.sensor_schema(
                unit_of_measurement=UNIT_PERCENT,
                accuracy_decimals=1,
                device_class=DEVICE_CLASS_MOISTURE,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_WATER_COUNT): sensor.sensor_schema(
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
        }
    ),
    cv.has_at_least_one_key(CONF_MOISTURE, CONF_WATER_COUNT),
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    hub = await cg.get_variable(config[CONF_PLANT_SENSOR_HUB_ID])
    plant_index = config[CONF_PLANT_INDEX]

    if CONF_MOISTURE in config:
        sens = await sensor.new_sensor(config[CONF_MOISTURE])
        cg.add(hub.register_moisture_sensor(plant_index, sens))

    if CONF_WATER_COUNT in config:
        sens = await sensor.new_sensor(config[CONF_WATER_COUNT])
        cg.add(hub.register_water_count_sensor(plant_index, sens))
