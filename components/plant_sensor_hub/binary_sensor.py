import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID

from . import CONF_PLANT_SENSOR_HUB_ID, PlantSensorHub, plant_sensor_hub_ns

DEPENDENCIES = ["plant_sensor_hub"]

CONF_TYPE = "type"

BinarySensorType = plant_sensor_hub_ns.enum("BinarySensorType")
BINARY_SENSOR_TYPES = {
    "tank_empty": BinarySensorType.BINARY_SENSOR_TYPE_TANK_EMPTY,
    "alarm": BinarySensorType.BINARY_SENSOR_TYPE_ALARM,
    "watering_active": BinarySensorType.BINARY_SENSOR_TYPE_WATERING_ACTIVE,
}

CONFIG_SCHEMA = (
    binary_sensor.binary_sensor_schema()
    .extend(
        {
            cv.GenerateID(CONF_PLANT_SENSOR_HUB_ID): cv.use_id(PlantSensorHub),
            cv.Required(CONF_TYPE): cv.enum(BINARY_SENSOR_TYPES, lower=True),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    hub = await cg.get_variable(config[CONF_PLANT_SENSOR_HUB_ID])
    var = cg.new_Pvariable(config[CONF_ID])
    await binary_sensor.register_binary_sensor(var, config)
    cg.add(hub.register_binary_sensor(config[CONF_TYPE], var))
