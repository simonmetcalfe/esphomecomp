#pragma once

/**
 * Plant data simulation library
 * 
 * This can be used standalone in Arduino projects or within ESPHome.
 * Call plant_data_update() periodically to refresh values.
 */

// Initialize the plant data system (called automatically on first access)
void plant_data_init();

// Update values if enough time has passed (call from loop)
void plant_data_update();

// Getters for sensor values
int plant_get_temperature();
int plant_get_humidity();
int plant_get_soil_moisture();
const char* plant_get_status();

