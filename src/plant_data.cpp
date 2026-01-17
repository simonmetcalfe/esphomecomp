// Standalone Arduino implementation
// Keep in sync with components/plant_compound_sensor/plant_data.inc

#include <Arduino.h>
#include <string.h>
#include "plant_data.h"

static int temperature = 0;
static int humidity = 0;
static int soil_moisture = 0;
static char status_str[8] = "good";

static const char *status_states[] = {"good", "bad", "ugly"};
static int current_status_index = 0;

static unsigned long last_update_ms = 0;
static const unsigned long UPDATE_INTERVAL_MS = 3000;

static bool initialized = false;

void plant_data_init()
{
  if (initialized) return;
  initialized = true;
  randomSeed(analogRead(0));
  temperature = 20 + random(15);
  humidity = 40 + random(40);
  soil_moisture = 30 + random(50);
  strcpy(status_str, status_states[0]);
}

void plant_data_update()
{
  plant_data_init();
  
  unsigned long current_ms = millis();

  if (current_ms - last_update_ms >= UPDATE_INTERVAL_MS)
  {
    last_update_ms = current_ms;

    temperature = 20 + random(15);
    humidity = 40 + random(40);
    soil_moisture = 30 + random(50);

    current_status_index = (current_status_index + 1) % 3;
    strcpy(status_str, status_states[current_status_index]);
  }
}

int plant_get_temperature() { 
  plant_data_init();
  return temperature; 
}

int plant_get_humidity() { 
  plant_data_init();
  return humidity; 
}

int plant_get_soil_moisture() { 
  plant_data_init();
  return soil_moisture; 
}

const char* plant_get_status() { 
  plant_data_init();
  return status_str; 
}
