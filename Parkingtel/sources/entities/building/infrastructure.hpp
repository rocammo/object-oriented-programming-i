/**
 *  infrastructure.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include "entities/vehicles/vehicle.hpp"

#define NUM_FLOORS 5
#define NUM_PLACES 20

class Place {
private:
    Vehicle* vehicle;
    bool empty;
    bool reserved;
public:
    Place();

    void pushVehicle(Vehicle* vehicle);
    const Vehicle& pullVehicle();

    inline Vehicle* get_vehicle() { return vehicle; }
    inline bool get_empty() const { return empty; }
    inline bool get_reserved() const { return reserved; }

    void set_reserved(bool reserved) { this->reserved = reserved; }
};

class Floor {
private:
    Place places[NUM_PLACES];
public:
    inline Place* get_place(int num_place) { return &places[num_place]; }
};
