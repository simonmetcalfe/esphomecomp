import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

MULTI_CONF = True

CONF_PLANT_SENSOR_HUB_ID = "plant_sensor_hub_id"
CONF_NUM_PLANTS = "num_plants"

plant_sensor_hub_ns = cg.esphome_ns.namespace("plant_sensor_hub")
PlantSensorHub = plant_sensor_hub_ns.class_("PlantSensorHub", cg.PollingComponent)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(PlantSensorHub),
        cv.Optional(CONF_NUM_PLANTS, default=4): cv.int_range(min=1, max=4),
    }
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add(var.set_num_plants(config[CONF_NUM_PLANTS]))
