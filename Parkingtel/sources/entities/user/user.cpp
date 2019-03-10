/**
 *  user.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "user.hpp"

User::User(const std::string &dni, bool admin) {
    (*this).dni = dni;
    (*this).admin = admin;
}

void User::giveTicket(const Ticket& ticket) {
    tickets.push_back(ticket);
}

void User::printTickets() {
    int i = 0;
    std::vector<Ticket>::iterator it;
    for(it = tickets.begin(); it != tickets.end(); it++, i++) {
        std::cout << "Recibo #" << i << ": ";
        (*it).print();
        std::cout << "€" << std::endl;
    }
}

void User::parkVehicle(const Vehicle &vehicle) {
    parked_vehicles.push_back(vehicle);
}

void User::showParkedVehicles() {
    std::vector<Vehicle>::iterator it;
    for(it = parked_vehicles.begin(); it != parked_vehicles.end(); it++) {
        std::cout << (*it);
    }
}

void User::remove(const Vehicle& vehicle) {
    bool found = false;
    std::vector<Vehicle>::iterator it;
    int i = 0;
    for(it = parked_vehicles.begin(); it != parked_vehicles.end(); it++, i++) {
        if ((*it).get_plate() == vehicle.get_plate()) {
            found = true;
            break;
        }
    }
    if (found) {
        parked_vehicles.erase(parked_vehicles.begin() + i);
        tickets.pop_back();
    }
}
