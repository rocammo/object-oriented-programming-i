/**
 *  reserva.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#include "reserva.hpp"

Habitacion Reserva::reservarHabitacion(Hotel& hotel) {
    /*
     * Dos metodos posibles:
     *  1. Elegir el numero de habitacion siguiendo el orden natural.
     *  2. Elegir el numero de habitacion aleatoriamente.
     *  */

    // Metodo 1.
//    for (int i = 0; i < hotel.getNumHabitaciones(); i++) {
//        if (!hotel.getHabitacion(i).isOcupada()) {
//            hotel.getHabitacion(i).setOcupada(true);
//        }
//    }

    // Metodo 2.
    bool exito = false;
    int numHabitacion;
    while (!exito) {
        numHabitacion = rand() % hotel.getNumHabitaciones();
        if (!hotel.getHabitacion(numHabitacion).isOcupada()) {
            hotel.getHabitacion(numHabitacion).setOcupada(true);
            exito = true;
        }
    }
    return hotel.getHabitacion(numHabitacion);
}

Habitacion Reserva::cancelarReserva(Hotel& hotel) {
    bool exito = false;
    int numHabitacion;
    while (!exito) {
        numHabitacion = rand() % hotel.getNumHabitaciones();
        if (hotel.getHabitacion(numHabitacion).isOcupada()) {
            hotel.getHabitacion(numHabitacion).setOcupada(false);
            exito = true;
        }
    }
    return hotel.getHabitacion(numHabitacion);
}