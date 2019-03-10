/**
 *  car.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include "vehicle.hpp"

class Car : public Vehicle {
public:
    Car(const std::string& plate = "", const std::string& model = "") : Vehicle(plate, model) {}
};


