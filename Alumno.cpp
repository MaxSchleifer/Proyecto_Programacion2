#include "Alumno.h"
#include <iostream>
#include <cstring>
#include <string>

Alumno::Alumno() {
    _legajo = 0;
    strcpy(_DNI, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_telefono, "");
    strcpy(_direccion, "");
    strcpy(_email, "");
    _fechaNacimiento = Fecha();
}

Alumno::Alumno(int legajo, const char* DNI, const char* nombre, const char* apellido,
               const char* telefono, const char* direccion, const char* email, Fecha fechaNacimiento) {
    _legajo = legajo;
    strcpy(_DNI, DNI);
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);
    strcpy(_telefono, telefono);
    strcpy(_direccion, direccion);
    strcpy(_email, email);
    _fechaNacimiento = fechaNacimiento;
}

// Getters
int Alumno::getLegajo() const { return _legajo; }
const char* Alumno::getDNI() const { return _DNI; }
const char* Alumno::getNombre() const { return _nombre; }
const char* Alumno::getApellido() const { return _apellido; }
const char* Alumno::getTelefono() const { return _telefono; }
const char* Alumno::getDireccion() const { return _direccion; }
const char* Alumno::getEmail() const { return _email; }
Fecha Alumno::getFechaNacimiento() const { return _fechaNacimiento; }

// Setters
void Alumno::setLegajo(int legajo) { _legajo = legajo; }
void Alumno::setDNI(const char* DNI) { strcpy(_DNI, DNI); }
void Alumno::setNombre(const char* nombre) { strcpy(_nombre, nombre); }
void Alumno::setApellido(const char* apellido) { strcpy(_apellido, apellido); }
void Alumno::setTelefono(const char* telefono) { strcpy(_telefono, telefono); }
void Alumno::setDireccion(const char* direccion) { strcpy(_direccion, direccion); }
void Alumno::setEmail(const char* email) { strcpy(_email, email); }
void Alumno::setFechaNacimiento(Fecha fecha) { _fechaNacimiento = fecha; }

std::string Alumno::toCSV() const {
    return std::to_string(_legajo) + "," + _DNI + "," + _nombre + "," + _apellido + "," +
           _telefono + "," + _direccion + "," + _email + "," + _fechaNacimiento.toString();
}

void Alumno::cargar() {
    std::cout << "Legajo: ";
    std::cin >> _legajo;
    std::cin.ignore();

    std::cout << "DNI: ";
    std::cin.getline(_DNI, 9);

    std::cout << "Nombre: ";
    std::cin.getline(_nombre, 20);

    std::cout << "Apellido: ";
    std::cin.getline(_apellido, 20);

    std::cout << "Telefono: ";
    std::cin.getline(_telefono, 15);

    std::cout << "Direccion: ";
    std::cin.getline(_direccion, 100);

    std::cout << "Email: ";
    std::cin.getline(_email, 50);

    std::cout << "Fecha de Nacimiento (dia mes anio): ";
    int d, m, a;
    std::cin >> d >> m >> a;
    _fechaNacimiento = Fecha(d, m, a);
    std::cin.ignore();
}

void Alumno::mostrar() const {
    std::cout << "Legajo: " << _legajo << std::endl;
    std::cout << "DNI: " << _DNI << std::endl;
    std::cout << "Nombre: " << _nombre << std::endl;
    std::cout << "Apellido: " << _apellido << std::endl;
    std::cout << "Telefono: " << _telefono << std::endl;
    std::cout << "Direccion: " << _direccion << std::endl;
    std::cout << "Email: " << _email << std::endl;
    std::cout << "Fecha Nacimiento: " << _fechaNacimiento.toString() << std::endl;
}
