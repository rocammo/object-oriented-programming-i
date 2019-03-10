/**
 *  vehicle.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "vehicle.hpp"

Vehicle::Vehicle(const std::string &plate, const std::string &model) {
    this->plate = plate;
    this->model = model;
}

std::ostream& operator <<(std::ostream& os, const Vehicle& vehicle) {
    return (os << vehicle.plate << " | " << vehicle.model << "\n");
}
