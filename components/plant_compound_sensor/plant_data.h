#pragma once

/**
 * Plant data simulation library (header-only)
 * Shared between ESPHome component and standalone Arduino projects.
 */

#include <Arduino.h>
#include <string.h>

namespace plant_data {

inline int temperature = 0;
inline int humidity = 0;
inline int soil_moisture = 0;
inline char status_str[8] = "good";

inline const char *status_states[] = {"good", "bad", "ugly"};
inline int current_status_index = 0;

inline unsigned long last_update_ms = 0;
inline const unsigned long UPDATE_INTERVAL_MS = 3000;

inline bool initialized = false;

inline void init()
{
  if (initialized) return;
  initialized = true;
  randomSeed(analogRead(0));
  temperature = 20 + random(15);
  humidity = 40 + random(40);
  soil_moisture = 30 + random(50);
  strcpy(status_str, status_states[0]);
}

inline void update()
{
  init();
  
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

inline int get_temperature() { 
  init();
  return temperature; 
}

inline int get_humidity() { 
  init();
  return humidity; 
}

inline int get_soil_moisture() { 
  init();
  return soil_moisture; 
}

inline const char* get_status() { 
  init();
  return status_str; 
}

} // namespace plant_data
