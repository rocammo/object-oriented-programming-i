/**
 *  cliente.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#include "cliente.hpp"

#include <iostream>
#include <iomanip>

Cliente::~Cliente() {
    reservas.clear();
}

void Cliente::agregarReserva(const Habitacion& habitacion) {
    reservas.push_back(habitacion);
}

void Cliente::borrarReserva(const Habitacion& habitacion) {
    int i = 0;
    std::vector<Habitacion>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); it++, i++) {
        if ((*it).getIdHabitacion() == habitacion.getIdHabitacion()) {
            reservas.erase(reservas.begin() + i);
            break;
        }
    }
}

void Cliente::verReservas() {
    std::cout << "┌─────────────────────────────┐" << std::endl;
    std::cout << "│         MIS RESERVAS        │" << std::endl;
    std::cout << "┌─────────────────────────────┐" << std::endl;
    int i = 0;
    std::vector<Habitacion>::iterator it;
    for (it = reservas.begin(); it != reservas.end(); it++, i++) {
        std::cout << "│[" << (*it).getIdHabitacion() << "]  "
                  << "Habitacion" << " " << std::setfill('0') << std::setw(3) << ((*it).getNumHabitacion() + 1) << " "
                  << "(" << (*it).getPlazas() << "p.)" << "│"
                  << std::endl;
    }
    if (i == 0) std::cout << "   No tiene ninguna reserva." << std::endl;
    else std::cout << "└─────────────────────────────┘" << std::endl;
    std::cout << "\n" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Cliente& cliente) {
    os << "┌─────────────────────────────┐" << "\n";
    os << "│           MIS DATOS         │" << "\n";
    os << "┌─────────────────────────────┐" << "\n";
    os << " · Nombre: " << cliente.nombre     << "\n";
    os << " · DNI:    " << cliente.dni        << "\n";
    os << " · Telef.: "; if (cliente.telefono != -1) os << cliente.telefono; os << "\n";
    os << "└─────────────────────────────┘" << "\n";
    os << "\n\n";

    return os;
}

std::istream& operator>>(std::istream& is, Cliente& cliente) {
    std::cout << "┌─────────────────────────────┐" << "\n";
    std::cout << "│           MIS DATOS         │" << "\n";
    std::cout << "┌─────────────────────────────┐" << "\n";
    std::cout << " · Nombre: "; is >> cliente.nombre;
    std::cout << " · DNI:    "; is >> cliente.dni;
    std::cout << " · Telef.: "; is >> cliente.telefono;
    std::cout << "└─────────────────────────────┘" << "\n";
    std::cout << "\n\n";

    return is;
}
