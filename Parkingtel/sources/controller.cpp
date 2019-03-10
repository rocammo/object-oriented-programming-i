/**
 *  controller.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "controller.hpp"

#include <iostream>

void Controller::on() {
    // creates admin user
    User admin("12345678A", true);
    users.push_back(admin);

    char dni[10];

    int opcion = 0;
    do {
        system("clear"); // windows: system("cls")

        std::cout << "Bienvenido/a a Parkingtel!" << "\n" << std::endl;

        std::cout << "Elija una opcion:" << std::endl;
        std::cout << "1. Iniciar sesion." << std::endl;
        std::cout << "2. Salir." << "\n" << std::endl;

        std::cout << "=> ";
        std::cin >> opcion;

        system("clear"); // windows: system("cls")

        switch(opcion) {
            case 1:
                user = 0;

                std::cout << "Introduzca DNI: (admin:12345678A) ";
                std::cin >> dni;

                User client(dni, false);

                std::vector<User>::iterator it;
                bool found = false;
                for (it = users.begin(); it != users.end() && !found; it++, user++) {
                    if (client.getDni().compare((*it).getDni()) == 0) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    users.push_back(client);
                }
                if (!(*it).isAdmin()) {
                    cli_menu();
                } else {
                    admin_menu();
                }

                break;
        }
    } while (opcion != 2);
}

void Controller::cli_menu() {
    int opcion = 0;
    do {
        system("clear");

        std::cout << ":: SISTEMA DE ESTACIONAMIENTO INTELIGENTE ::" << "\n" << std::endl;

        std::cout << "Elija una opcion:" << std::endl;
        std::cout << "1. Aparcar vehiculo." << std::endl;
        std::cout << "2. Retirar vehiculo." << std::endl;
        std::cout << "3. Ver mis recibos." << std::endl;
        std::cout << "4. Ver mis vehiculos aparcados." << std::endl;
        std::cout << "5. Cerrar sesion." << "\n" << std::endl;

        std::cout << "=> ";
        std::cin >> opcion;

        system("clear"); // windows: system("cls")

        switch(opcion) {
            case 1: {
                Vehicle vehicle = parking.park();
                if (vehicle.get_plate().compare("") != 0) {
                    Ticket ticket(vehicle.get_plate(), vehicle.get_model());
                    ticket.calculateAmount(0, 100 + rand() % 448);
                    users[user].giveTicket(ticket);
                    users[user].parkVehicle(vehicle);
                }
                break;
            }
            case 2: {
                Vehicle vehicle = parking.unpark();
                if (vehicle.get_plate().compare("") != 0) users[user].remove(vehicle);
                break;
            }
            case 3:
                users[user].printTickets();
                std::cout << "\nTeclee ENTER para continuar...\n" << std::endl;
                std::cin.ignore();
                std::getchar();
                break;
            case 4:
                users[user].showParkedVehicles();
                std::cout << "\nTeclee ENTER para continuar...\n" << std::endl;
                std::cin.ignore();
                std::getchar();
        }
    } while(opcion != 5);
}

void Controller::admin_menu() {
    int opcion = 0;
    do {
        system("clear"); // windows: system("cls")

        std::cout << ":: SISTEMA DE ESTACIONAMIENTO INTELIGENTE ::" << "\n" << std::endl;

        std::cout << "-- ADMINISTRADOR --" << std::endl;
        std::cout << "Elija una opcion:" << std::endl;
        std::cout << "1. Aparcar vehiculo." << std::endl;
        std::cout << "2. Retirar vehiculo." << std::endl;
        std::cout << "3. Reservar plaza." << std::endl;
        std::cout << "4. Estado actual." << std::endl;
        std::cout << "5. Historial de movimientos." << std::endl;
        std::cout << "6. Cerrar sesion." << "\n" << std::endl;

        std::cout << "=> ";
        std::cin >> opcion;

        system("clear"); // windows: system("cls")

        switch(opcion) {
            case 1: {
                Vehicle vehicle = parking.park();
                if (vehicle.get_plate().compare("") != 0) users[user].parkVehicle(vehicle);
                break;
            }
            case 2: {
                Vehicle vehicle = parking.unpark();
                if (vehicle.get_plate().compare("") != 0) users[user].remove(vehicle);
                break;
            }
            case 3:
                int floor, place;
                do {
                    std::cout << "Sotano (0 ~ 4): ";
                    std::cin >> floor;
                } while (floor < 0 || floor > 4);
                do {
                    std::cout << "Plaza (1 ~ 20): ";
                    std::cin >> place;
                } while (place < 1 || place > 20);
                parking.reserve_place(floor, place);
                break;
            case 4:
                parking.current_status();
                std::cout << "\nTeclee ENTER para continuar...\n" << std::endl;
                std::cin.ignore();
                std::getchar();
                break;
            case 5:
                parking.logs();
                std::cout << "\nTeclee ENTER para continuar...\n" << std::endl;
                std::cin.ignore();
                std::getchar();
                break;
        }
    } while(opcion != 6);
}
