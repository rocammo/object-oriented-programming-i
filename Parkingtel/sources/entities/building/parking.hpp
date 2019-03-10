/**
 *  parking.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include <iostream>
#include <vector>

#include "entities/building/infrastructure.hpp"

class Parking {
private:
    Floor *floors;

    std::vector<std::string> logger;
public:
    Parking();
    ~Parking();

    const Vehicle& park();
    const Vehicle& unpark();
    void reserve_place(int floor, int place);

    void logs();
    void current_status();

    inline Floor& get_floor(int num_floor) const { return floors[num_floor]; }
private:
    void log(const std::string& plate, const std::string& model, const std::string& note);
};
