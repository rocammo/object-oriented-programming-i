/**
 *  habitacion.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#include "habitacion.hpp"

Habitacion::Habitacion() {
    (*this).ocupada = false;
}

int Habitacion::getPlazas() const {
    return plazas;
}
void Habitacion::setPlazas(int plazas) {
    (*this).plazas = plazas;
}

bool Habitacion::isOcupada() const {
    return ocupada;
}
void Habitacion::setOcupada(bool ocupada) {
    (*this).ocupada = ocupada;
}

long Habitacion::getIdHabitacion() const {
    return idHabitacion;
}
void Habitacion::setIdHabitacion(int idHabitacion) {
    (*this).idHabitacion = idHabitacion;
}

int Habitacion::getNumHabitacion() const {
    return numHabitacion;
}
void Habitacion::setNumHabitacion(int numHabitacion) {
    (*this).numHabitacion = numHabitacion;
}
