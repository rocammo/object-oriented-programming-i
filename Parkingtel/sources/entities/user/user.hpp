/**
 *  user.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include <iostream>
#include <vector>

#include "entities/vehicles/vehicle.hpp"
#include "entities/user/ticket.hpp"

class User {
private:
    std::string dni;
    bool admin;

    std::vector<Vehicle> parked_vehicles;
    std::vector<Ticket> tickets;

public:
    User(const std::string &dni, bool admin);

    void giveTicket(const Ticket& ticket);
    void printTickets();
    void parkVehicle(const Vehicle& vehicle);
    void showParkedVehicles();

    void remove(const Vehicle& vehicle);

    inline const std::string &getDni() const { return dni; }
    inline bool isAdmin() const { return admin; }
};
