#include <iostream>
#include <cstring>
#include "Alumno.h"

using namespace std;

void Alumno::cargar() {
    cout << "Legajo: ";
    cin >> legajo;
    cin.ignore();
    cout << "DNI: ";
    cin.getline(DNI, 9);
    cout << "Nombre: ";
    cin.getline(nombre, 20);
    cout << "Apellido: ";
    cin.getline(apellido, 20);
    cout << "Telefono: ";
    cin.getline(telefono, 15);
    cout << "Direccion: ";
    cin.getline(direccion, 100);
    cout << "Email: ";
    cin.getline(email, 50);
    cout << "Fecha de nacimiento:";
    fechaNacimiento.cargar();
}

void Alumno::mostrar() const {
    cout << "Legajo: " << legajo << endl;
    cout << "DNI: " << DNI << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Email: " << email << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrar();
    cout << endl;
}

int Alumno::getLegajo() const { return legajo; }
const char* Alumno::getDNI() const { return DNI; }
