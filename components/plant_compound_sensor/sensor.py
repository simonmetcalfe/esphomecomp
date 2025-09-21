import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, UNIT_EMPTY, ICON_EMPTY

plant_compound_sensor_ns = cg.esphome_ns.namespace("plant_compound_sensor")
PlantCompoundSensor = plant_compound_sensor_ns.class_(
    "PlantCompoundSensor", cg.PollingComponent
)

CONF_SENSOR1 = "plant1"
CONF_SENSOR2 = "plant2"
CONF_SENSOR3 = "plant3"
CONF_SENSOR4 = "plant4"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(PlantCompoundSensor),
        cv.Optional(CONF_SENSOR1): sensor.sensor_schema(
            PlantCompoundSensor,
            unit_of_measurement=UNIT_EMPTY,
            icon=ICON_EMPTY,
            accuracy_decimals=1,
        ).extend(),
        cv.Optional(CONF_SENSOR2): sensor.sensor_schema(
            PlantCompoundSensor,
            unit_of_measurement=UNIT_EMPTY,
            icon=ICON_EMPTY,
            accuracy_decimals=1,
        ).extend(),
        cv.Optional(CONF_SENSOR3): sensor.sensor_schema(
            PlantCompoundSensor,
            unit_of_measurement=UNIT_EMPTY,
            icon=ICON_EMPTY,
            accuracy_decimals=1,
        ).extend(),
        cv.Optional(CONF_SENSOR4): sensor.sensor_schema(
            PlantCompoundSensor,
            unit_of_measurement=UNIT_EMPTY,
            icon=ICON_EMPTY,
            accuracy_decimals=1,
        ).extend(),
    }
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    if CONF_SENSOR1 in config:
        sens = await sensor.new_sensor(config[CONF_SENSOR1])
        cg.add(var.set_sensor1(sens))

    if CONF_SENSOR2 in config:
        sens = await sensor.new_sensor(config[CONF_SENSOR2])
        cg.add(var.set_sensor2(sens))

    if CONF_SENSOR3 in config:
        sens = await sensor.new_sensor(config[CONF_SENSOR3])
        cg.add(var.set_sensor3(sens))

    if CONF_SENSOR4 in config:
        sens = await sensor.new_sensor(config[CONF_SENSOR4])
        cg.add(var.set_sensor4(sens))
