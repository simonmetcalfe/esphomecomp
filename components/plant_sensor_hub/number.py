import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import number
from esphome.const import (
    CONF_ID,
    CONF_MODE,
    CONF_RESTORE_VALUE,
    DEVICE_CLASS_DISTANCE,
    DEVICE_CLASS_MOISTURE,
    UNIT_CENTIMETER,
    UNIT_EMPTY,
    UNIT_PERCENT,
)

from . import CONF_PLANT_SENSOR_HUB_ID, PlantSensorHub, plant_sensor_hub_ns

DEPENDENCIES = ["plant_sensor_hub"]

CONF_PLANT_INDEX = "plant_index"
CONF_TYPE = "type"

# Type: (min, max, step, default, unit, device_class, restore_default)
# restore_default=False for volatile vars (C++ decides whether to save)
NUMBER_TYPES = {
    "pot_size": (10, 80, 5, 25, UNIT_CENTIMETER, DEVICE_CLASS_DISTANCE, True),
    "min_moisture": (10, 45, 5, 30, UNIT_PERCENT, DEVICE_CLASS_MOISTURE, True),
    "max_moisture": (55, 90, 5, 80, UNIT_PERCENT, DEVICE_CLASS_MOISTURE, True),
    "leak_threshold": (0, 5, 1, 0, UNIT_EMPTY, None, False),  # volatile
}

PlantSensorHubNumber = plant_sensor_hub_ns.class_(
    "PlantSensorHubNumber", number.Number, cg.Component
)

CONFIG_SCHEMA = (
    number.number_schema(
        PlantSensorHubNumber,
        unit_of_measurement=UNIT_PERCENT,
        device_class=DEVICE_CLASS_MOISTURE,
    )
    .extend(
        {
            cv.GenerateID(CONF_PLANT_SENSOR_HUB_ID): cv.use_id(PlantSensorHub),
            cv.Required(CONF_PLANT_INDEX): cv.int_range(min=0, max=3),
            cv.Required(CONF_TYPE): cv.one_of(*NUMBER_TYPES.keys(), lower=True),
            cv.Optional(CONF_MODE, default="BOX"): cv.enum(
                number.NUMBER_MODES, upper=True
            ),
            cv.Optional(CONF_RESTORE_VALUE): cv.boolean,
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    hub = await cg.get_variable(config[CONF_PLANT_SENSOR_HUB_ID])
    type_key = config[CONF_TYPE]
    type_data = NUMBER_TYPES[type_key]
    min_val, max_val, step_val, default_val, unit, device_class = type_data[:6]
    restore_default = type_data[6] if len(type_data) > 6 else True
    restore_value = config.get(CONF_RESTORE_VALUE, restore_default)

    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await number.register_number(
        var,
        config,
        min_value=min_val,
        max_value=max_val,
        step=step_val,
    )

    cg.add(var.set_optimistic(True))
    cg.add(var.set_initial_value(default_val))
    cg.add(var.set_restore_value(restore_value))

    if unit:
        cg.add(var.traits.set_unit_of_measurement(unit))
    if device_class:
        cg.add(var.traits.set_device_class(device_class))

    type_int = list(NUMBER_TYPES.keys()).index(type_key)
    cg.add(hub.register_number(config[CONF_PLANT_INDEX], type_int, var))
