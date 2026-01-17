#pragma once

/**
 * Plant data simulation library (header-only)
 * Shared between ESPHome component and standalone Arduino projects.
 */

#include <cstring>
#include <cstdlib>

#ifdef ARDUINO
  #include <Arduino.h>
  #define PLANT_MILLIS() millis()
  #define PLANT_RANDOM(max) random(max)
  #define PLANT_RANDOM_SEED() randomSeed(analogRead(0))
#else
  // ESP-IDF / FreeRTOS
  #include "freertos/FreeRTOS.h"
  #include "freertos/task.h"
  #include "esp_random.h"
  #define PLANT_MILLIS() (xTaskGetTickCount() * portTICK_PERIOD_MS)
  #define PLANT_RANDOM(max) (esp_random() % (max))
  #define PLANT_RANDOM_SEED() // Not needed for esp_random
#endif

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
  PLANT_RANDOM_SEED();
  temperature = 20 + PLANT_RANDOM(15);
  humidity = 40 + PLANT_RANDOM(40);
  soil_moisture = 30 + PLANT_RANDOM(50);
  std::strcpy(status_str, status_states[0]);
}

inline void update()
{
  init();
  
  unsigned long current_ms = PLANT_MILLIS();

  if (current_ms - last_update_ms >= UPDATE_INTERVAL_MS)
  {
    last_update_ms = current_ms;

    temperature = 20 + PLANT_RANDOM(15);
    humidity = 40 + PLANT_RANDOM(40);
    soil_moisture = 30 + PLANT_RANDOM(50);

    current_status_index = (current_status_index + 1) % 3;
    std::strcpy(status_str, status_states[current_status_index]);
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
