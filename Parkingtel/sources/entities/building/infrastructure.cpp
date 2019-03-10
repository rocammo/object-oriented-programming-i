/**
 *  infrastructure.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "infrastructure.hpp"

Place::Place() {
    this->vehicle = nullptr;
    this->empty = true;
    this->reserved = false;
}

void Place::pushVehicle(Vehicle* vehicle) {
    this->vehicle = vehicle;
    this->empty = false;
}

const Vehicle& Place::pullVehicle() {
    Vehicle vehicle_aux = *vehicle;
    this->vehicle = nullptr;
    this->empty = true;
    return vehicle_aux;
}
