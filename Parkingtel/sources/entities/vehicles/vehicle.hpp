/**
 *  vehicle.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#pragma once

#include <iostream>

class Vehicle {
protected:
    std::string plate;
    std::string model;
public:
    Vehicle(const std::string& plate = "", const std::string& model = "");

    void set_plate(const std::string &plate) { this->plate = plate; };
    void set_model(const std::string &model) { this->model = model; };
    inline std::string get_plate() const { return plate; }
    inline std::string get_model() const { return model; }

    friend std::ostream& operator <<(std::ostream& os, const Vehicle& vehicle);
};
