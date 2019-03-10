/**
 *  bike.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include "vehicle.hpp"

class Bike : public Vehicle {
public:
    Bike(const std::string& plate = "", const std::string& model = "") : Vehicle(plate, model) {}
};


