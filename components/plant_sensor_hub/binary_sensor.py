import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID

from . import CONF_PLANT_SENSOR_HUB_ID, PlantSensorHub

DEPENDENCIES = ["plant_sensor_hub"]

CONF_TYPE = "type"

# Use int to avoid ESPHome codegen enum qualification bug
BINARY_SENSOR_TYPES = {
    "tank_empty": 0,
    "alarm": 1,
    "watering_active": 2,
}

CONFIG_SCHEMA = (
    binary_sensor.binary_sensor_schema()
    .extend(
        {
            cv.GenerateID(CONF_PLANT_SENSOR_HUB_ID): cv.use_id(PlantSensorHub),
            cv.Required(CONF_TYPE): cv.one_of(*BINARY_SENSOR_TYPES.keys(), lower=True),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    hub = await cg.get_variable(config[CONF_PLANT_SENSOR_HUB_ID])
    var = cg.new_Pvariable(config[CONF_ID])
    await binary_sensor.register_binary_sensor(var, config)
    cg.add(hub.register_binary_sensor(BINARY_SENSOR_TYPES[config[CONF_TYPE]], var))
