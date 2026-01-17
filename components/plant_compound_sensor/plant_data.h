#pragma once

/**
 * Plant data simulation library
 * Shared between ESPHome component and standalone Arduino projects.
 */

void plant_data_init();
void plant_data_update();

int plant_get_temperature();
int plant_get_humidity();
int plant_get_soil_moisture();
const char* plant_get_status();

