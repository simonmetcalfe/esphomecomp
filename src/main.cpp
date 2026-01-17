#include <Arduino.h>
#include <string.h>
#include "esphome_connector.h"

// Simulated sensor values
int temperature = 0;
int humidity = 0;
int soil_moisture = 0;

// Status string - cycles through states
char status[8] = "good";

static const char *status_states[] = {"good", "bad", "ugly"};
static int current_status_index = 0;

static unsigned long last_update_ms = 0;
static const unsigned long UPDATE_INTERVAL_MS = 3000;

void setup()
{
  randomSeed(analogRead(0));
  temperature = 20 + random(15);
  humidity = 40 + random(40);
  soil_moisture = 30 + random(50);
  strcpy(status, status_states[0]);
}

void loop()
{
  unsigned long current_ms = millis();

  if (current_ms - last_update_ms >= UPDATE_INTERVAL_MS)
  {
    last_update_ms = current_ms;

    // Randomize integers within reasonable ranges
    temperature = 20 + random(15);   // 20-34
    humidity = 40 + random(40);      // 40-79
    soil_moisture = 30 + random(50); // 30-79

    // Cycle status
    current_status_index = (current_status_index + 1) % 3;
    strcpy(status, status_states[current_status_index]);
  }
}

// ESPHome connector functions
int get_temperature() { return temperature; }
int get_humidity() { return humidity; }
int get_soil_moisture() { return soil_moisture; }
const char *get_status() { return status; }
