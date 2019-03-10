/**
 *  controller.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include "entities/building/parking.hpp"
#include "entities/user/user.hpp"

/* user menu */
class Controller {
private:
    Parking parking;

    int user;
    std::vector<User> users;
public:
    void on();
private:
    void cli_menu();
    void admin_menu();
};


