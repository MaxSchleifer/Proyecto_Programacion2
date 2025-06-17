#ifndef ALUMNO_H
#define ALUMNO_H

#include "Fecha.h"

class Alumno {
private:
    int legajo;
    char DNI[9];
    char nombre[20];
    char apellido[20];
    char telefono[15];
    char direccion[100];
    char email[50];
    Fecha fechaNacimiento;

public:
    void cargar();
    void mostrar() const;
    int getLegajo() const;
    const char* getDNI() const;
};

#endif