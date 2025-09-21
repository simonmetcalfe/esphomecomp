#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace plant_compound_sensor {

class PlantCompoundSensor : public sensor::Sensor, public PollingComponent {
  public:  
    void set_plant1(sensor::Sensor *cplant1) { cplant1_ = cplant1; }
    void set_plant2(sensor::Sensor *cplant2) { cplant2_ = cplant2; }
    void set_plant3(sensor::Sensor *cplant3) { cplant3_ = cplant3; }
    void set_plant4(sensor::Sensor *cplant4) { cplant4_ = cplant4; }

    void setup() override;
    void loop() override;
    void update() override;
    void dump_config() override;

  protected:
    sensor::Sensor *cplant1_;
    sensor::Sensor *cplant2_;
    sensor::Sensor *cplant3_;
    sensor::Sensor *cplant4_;
};

} //namespace plant_compound_sensor
} //namespace esphome