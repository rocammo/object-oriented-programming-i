/**
 *  parking.cpp
 *
 *  @author: Rodrigo Casamayor <alu.89657@usj.es>
 *  @date:   27 oct. 2018
*/

#include "parking.hpp"

#include <iomanip>
#include <sstream>
#include <ctime>
#include <thread>
#include <chrono>

#include "../vehicles/car.hpp"
#include "../vehicles/bike.hpp"

Parking::Parking() {
    floors = new Floor[NUM_FLOORS];
}

Parking::~Parking() {
    delete [] floors;
}

const Vehicle& Parking::park() {
    std::string plate, model;
    std::cout << "Introduzca matricula: ";
    std::cin >> plate;
    std::cout << "Introduzca modelo: ";
    std::cin.ignore();
    std::getline(std::cin, model);

    char choice = '\0';
    do {
        std::cout << "Coche o moto? ('c':coche, 'm':moto) ";
        std::cin >> choice;
    } while(choice != 'c' && choice != 'm');

    Vehicle *vehicle = NULL;
    if (choice == 'c') vehicle = new Car(plate, model);
    else vehicle = new Bike(plate, model);

    try {
        bool found = false;
        for (int i = 0; i < NUM_FLOORS && !found; i++) {
            for (int j = 0; j < NUM_PLACES && !found; j++) {
                if (!floors[i].get_place(j)->get_empty() && !floors[i].get_place(j)->get_reserved()) {
                    if (plate.compare(floors[i].get_place(j)->get_vehicle()->get_plate()) == 0) throw 1;
                }
                if (floors[i].get_place(j)->get_empty() && !floors[i].get_place(j)->get_reserved()) {
                    log(plate, model, "Aparcado");
                    floors[i].get_place(j)->pushVehicle(vehicle);
                    std::cout << "\n[LOG] Vehiculo aparcado con exito }:)" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            std::cout << "\n[LOG] Todas las plazas estan ocupadas }:(" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    } catch (int error) {
        std::cout << "\n[LOG] Estas poniendome a prueba?? Hmmm... Este vehiculo ya lo he aparcado." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return Vehicle("", "");
    }

    return (*vehicle);
}

const Vehicle& Parking::unpark() {
    std::string plate;
    std::cout << "Introduzca matricula: ";
    std::cin >> plate;

    bool found = false;
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < NUM_PLACES; j++) {
            if (!floors[i].get_place(j)->get_empty()) {
                if (floors[i].get_place(j)->get_vehicle()->get_plate() == plate) {
                    log(plate, floors[i].get_place(j)->get_vehicle()->get_model(), "Retirado");
                    std::cout << "\n[LOG] Vehiculo retirado con exito }:)" << std::endl;
                    std::this_thread::sleep_for (std::chrono::seconds(2));
                    return floors[i].get_place(j)->pullVehicle();
                }
            }
        }
    }

    std::cout << "\n[LOG] Vehiculo no encontrado }:(" << std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(2));

    return Vehicle("", "");
}

void Parking::reserve_place(int floor, int place) {
    place--;
    if (!floors[floor].get_place(place)->get_reserved()) {
        if (floors[floor].get_place(place)->get_empty()) {
            floors[floor].get_place(place)->set_reserved(true);
            std::cout << "\n[LOG] Reserva realizada con exito }:(" << std::endl;
        } else {
            std::cout << "\n[LOG] (Plaza ocupada) No se ha podido realizar la reserva }:)" << std::endl;
        }
    } else {
        floors[floor].get_place(place)->set_reserved(false);
        std::cout << "\n[LOG] Reserva cancelada con exito }:)" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Parking::logs() {
    std::vector<std::string>::iterator it;
    for (it = logger.begin(); it != logger.end(); it++) {
        std::cout << *it << std::endl;
    }
}

void Parking::current_status() {
    for (int i = 0; i < NUM_FLOORS; i++) {
        std::cout << "Sotano " << i << ": ";
        for (int j = 0; j < NUM_PLACES; j++) {
            if (floors[i].get_place(j)->get_reserved()) {
                std::cout << "[R] ";
            } else if (floors[i].get_place(j)->get_empty()) {
                std::cout << "[ ] ";
            } else {
                std:: cout << "[#] ";
            }
        }
        std::cout << "\n";
    }
}

void Parking::log(const std::string& plate, const std::string& model, const std::string& note) {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
    std::string str(buffer);

    std::stringstream log;
    log << "[" << str << "]: " << plate << " | " << model << " (" << note << ")";
    logger.push_back(log.str());
}
