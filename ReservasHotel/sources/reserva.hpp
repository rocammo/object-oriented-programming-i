/**
 *  reserva.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#pragma once

#include "hotel.hpp"

class Reserva {
public:
    static Habitacion reservarHabitacion(Hotel& hotel);
    static Habitacion cancelarReserva(Hotel& hotel);
};


