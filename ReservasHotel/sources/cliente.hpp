/**
 *  cliente.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#pragma once

#include <string>
#include <vector>
#include "habitacion.hpp"

class Cliente {
private:
    std::string nombre;
    std::string dni;
    int telefono;

    std::vector<Habitacion> reservas;
public:
    Cliente(const std::string& nombre = "", const std::string& dni = "", int telefono = -1)
        : nombre(nombre), dni(dni), telefono(telefono) { }
    ~Cliente();

    void agregarReserva(const Habitacion& habitacion);
    void borrarReserva(const Habitacion& habitacion);
    void verReservas();

    friend std::ostream& operator <<(std::ostream& os, const Cliente& cliente);
    friend std::istream& operator >>(std::istream& is, Cliente& cliente);
};


