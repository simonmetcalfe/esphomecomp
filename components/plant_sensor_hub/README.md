# Plant Sensor Hub

Hub component for a plant watering system. Provides global binary sensors and per-plant sensors (moisture, water count, state).

## Configuration

```yaml
plant_sensor_hub:
  id: plant_hub
  num_plants: 4
  update_interval: 60s

sensor:
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    plant_index: 0
    moisture:
      name: Plant 1 Moisture
    water_count:
      name: Plant 1 Water Count

binary_sensor:
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    type: tank_empty
    name: Tank Empty
  - platform: plant_sensor_hub
    type: alarm
    name: Alarm
  - platform: plant_sensor_hub
    type: watering_active
    name: Watering Active

text_sensor:
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    plant_index: 0
    name: Plant 1 State

number:
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    plant_index: 0
    type: pot_size
    name: Plant 1 Pot Size
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    plant_index: 0
    type: min_moisture
    name: Plant 1 Min Moisture
  - platform: plant_sensor_hub
    plant_sensor_hub_id: plant_hub
    plant_index: 0
    type: max_moisture
    name: Plant 1 Max Moisture
```

## Number types (persistent, BOX mode)

- `pot_size` – 10–80 cm, step 5, default 25
- `min_moisture` – 10–45 %, step 5, default 30
- `max_moisture` – 55–90 %, step 5, default 80

## Binary sensor types

- `tank_empty` – Water tank is empty
- `alarm` – Alarm is active
- `watering_active` – System is currently watering

## Per-plant sensors

- `moisture` – Current soil moisture (%)
- `water_count` – Number of times watered
- `plant_index` (0–3) – Which plant slot

## Note

Currently publishes mock data. Integrate real hardware/driver in `plant_sensor_hub.cpp` `update()`.
