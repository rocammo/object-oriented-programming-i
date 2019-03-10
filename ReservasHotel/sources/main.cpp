/**
 *  main.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   14 ene. 2019
*/

#include <iostream>
#include "hotel.hpp"
#include "cliente.hpp"
#include "reserva.hpp"

#define NUM_HABITACIONES 15

int menu(Hotel& hotel, Cliente& cliente);

int main() {
    bool running = true;
    srand(time(NULL)); // semilla aleatoriedad

    Hotel hotel("Lucas Abad", NUM_HABITACIONES);
    Cliente cliente;
    while (running) {
        running = (menu(hotel, cliente) != 6) ? true : false;
    }


    return 0;
}

int menu(Hotel& hotel, Cliente& cliente) {
    static int num_reservas = 0;

    std::cout << "┌─────────────────────────────┐" << std::endl;
    std::cout << "│            MENU             │" << std::endl;
    std::cout << "┌─────────────────────────────┐" << std::endl;
    std::cout << "│ 1. Reservar una habitacion. │" << std::endl;
    std::cout << "│ 2. Cancelar una reserva.    │" << std::endl;
    std::cout << "├─────────────────────────────┤" << std::endl;
    std::cout << "│ 3. Mis datos.               │" << std::endl;
    std::cout << "│ 4. Mis reservas.            │" << std::endl;
    std::cout << "│ 5. Ver estado del hotel.    │" << std::endl;
    std::cout << "├─────────────────────────────┤" << std::endl;
    std::cout << "│ 6. Salir.                   │" << std::endl;
    std::cout << "└─────────────────────────────┘" << std::endl;
    std::cout << std::endl;

    int opcion;
    do {
        std::cout << "> ";
        std::cin >> opcion;
    } while (opcion < 1 || opcion > 6);

    switch(opcion) {
        case 1:
            if (num_reservas < hotel.getNumHabitaciones()) {
                cliente.agregarReserva(Reserva::reservarHabitacion(hotel));
                std::cout << "La reserva ha sido realizada con exito.\n"
                          << "Gracias por confiar en nosotros."
                          << std::endl;
                num_reservas++;
            } else {
                std::cout << "La reserva no ha podido realizarse.\n"
                          << "El hotel esta completo. Disculpe las molestias."
                          << std::endl;
            }

            break;
        case 2:
            if (num_reservas > 0) {
                cliente.borrarReserva(Reserva::cancelarReserva(hotel));
                std::cout << "La reserva ha sido cancelada con exito.\n"
                          << "Gracias por confiar en nosotros."
                          << std::endl;
                num_reservas--;
            } else {
                std::cout << "La reserva no ha podido cancelarse.\n"
                          << "El hotel no tiene ninguna reserva."
                          << std::endl;
            }

            break;
        case 3:
            int opcion;
            do {
                std::cout << "Que desea? (1:Ver perfil, 2:Editar perfil) ";
                std::cin >> opcion;
            } while (opcion != 1 && opcion != 2);

            if (opcion == 1) {
                std::cout << cliente << std::endl;
            } else {
                std::cin >> cliente;
            }

            break;
        case 4:
            cliente.verReservas();
            break;
        case 5:
            std::cout << hotel << std::endl;
            break;
    }

    std::cout << "\n" << std::endl;

    return opcion;
}