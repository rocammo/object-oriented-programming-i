/**
 *  hotel.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#pragma once

#include <string>
#include "habitacion.hpp"

class Hotel {
private:
    std::string nombre;
    int numHabitaciones;
    Habitacion *habitaciones;
public:
    Hotel(const std::string& nombre, int numHabitaciones);
    ~Hotel();

    friend std::ostream& operator<<(std::ostream& os, const Hotel& hotel);

    inline int getNumHabitaciones() const { return numHabitaciones; }
    inline Habitacion& getHabitacion(int numHabitacion) const { return habitaciones[numHabitacion]; }
};


