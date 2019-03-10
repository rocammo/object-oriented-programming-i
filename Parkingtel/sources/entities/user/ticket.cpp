/**
 *  ticket.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "ticket.hpp"

Ticket::Ticket(const std::string &plate, const std::string &model) {
    (*this).plate = plate;
    (*this).model = model;
    (*this).total_amount = -1;
}

float Ticket::calculateAmount(int entry_time, int departure_time) {
    // time in minutes
    int time_in = departure_time - entry_time;
    // cost
    total_amount = time_in * price_per_minute;

    return total_amount;
}

void Ticket::print() {
    if (total_amount != -1) {
        std::cout << total_amount;
    }
}