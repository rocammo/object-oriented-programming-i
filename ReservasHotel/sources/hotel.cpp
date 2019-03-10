/**
 *  hotel.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#include "hotel.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

Hotel::Hotel(const std::string& nombre, int numHabitaciones) {
    (*this).nombre = nombre;
    (*this).numHabitaciones = numHabitaciones;
    habitaciones = new Habitacion[numHabitaciones];

    long idHabitacion;
    bool nueva;
    for (int i = 0; i < numHabitaciones; ) {
        idHabitacion = 10000 + rand() % 90000;
        nueva = true;
        for (int j = 0; j < numHabitaciones; j++) {
            if (idHabitacion == habitaciones[j].getIdHabitacion()) {
                nueva = false;
            }
        }
        if (nueva) {
            habitaciones[i].setIdHabitacion(idHabitacion);
            habitaciones[i].setNumHabitacion(i);
            habitaciones[i].setPlazas(1 + (rand() % static_cast<int>(5 - 1 + 1)));
            i++;
        }
    }

    std::cout << " Hotel '" << nombre << "' (****).\n"
              << " Bienvenido/a!" << std::endl;
}

Hotel::~Hotel() {
    delete [] habitaciones;
}

std::ostream& operator<<(std::ostream &os, const Hotel &hotel) {
    os << "┌──────────────────────────────────────────────┐" << "\n";
    os << "│  Habitaciones  | N. Ocupa. | Ocupada |  Id.  │" << "\n";
    os << "└──────────────────────────────────────────────┘ " << "\n";
    for (int i = 0; i < hotel.numHabitaciones; i++) {
        os << "│ Habitacion " << std::setfill('0') << std::setw(3) << (hotel.habitaciones[i].getNumHabitacion() + 1) << " ";
        os << "│     " << hotel.habitaciones[i].getPlazas() << "     ";
        std::string ocupada = hotel.habitaciones[i].isOcupada() ? "Si" : "No";
        os << "│    " << ocupada << "   ";
        os << "│ " << hotel.habitaciones[i].getIdHabitacion() << " ";
        os << "│" << "\n";
    }
    os << "└──────────────────────────────────────────────┘ " << "\n";

    return os;
}