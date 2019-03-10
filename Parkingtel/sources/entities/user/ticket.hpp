/**
 *  ticket.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include <iostream>

class Ticket {
private:
    std::string plate;
    std::string model;

    int entry_time;
    int departure_time;

    const float price_per_minute = 0.05;
    float total_amount;
public:
    Ticket(const std::string &plate, const std::string &model);

    float calculateAmount(int entry_time, int departure_time);
    void print();
};


