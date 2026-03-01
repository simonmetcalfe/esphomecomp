import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_ID

from . import CONF_PLANT_SENSOR_HUB_ID, PlantSensorHub

DEPENDENCIES = ["plant_sensor_hub"]

CONF_PLANT_INDEX = "plant_index"

CONFIG_SCHEMA = (
    text_sensor.text_sensor_schema()
    .extend(
        {
            cv.GenerateID(CONF_PLANT_SENSOR_HUB_ID): cv.use_id(PlantSensorHub),
            cv.Required(CONF_PLANT_INDEX): cv.int_range(min=0, max=3),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    hub = await cg.get_variable(config[CONF_PLANT_SENSOR_HUB_ID])
    var = cg.new_Pvariable(config[CONF_ID])
    await text_sensor.register_text_sensor(var, config)
    cg.add(hub.register_plant_state_sensor(config[CONF_PLANT_INDEX], var))
