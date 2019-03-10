/**
 *  habitacion.hpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#pragma once

class Habitacion {
private:
    int plazas;
    bool ocupada;
private:
    long idHabitacion;
    int numHabitacion;
public:
    Habitacion();

    int getPlazas() const;
    void setPlazas(int plazas);

    bool isOcupada() const;
    void setOcupada(bool ocupada);

    long getIdHabitacion() const;
    void setIdHabitacion(int idHabitacion);

    int getNumHabitacion() const;
    void setNumHabitacion(int numHabitacion);
};


