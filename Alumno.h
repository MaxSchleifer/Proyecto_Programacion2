#ifndef ALUMNO_H
#define ALUMNO_H

#include "Fecha.h"
#include <string>

class Alumno {
private:
    int _legajo;
    char _DNI[9];
    char _nombre[20];
    char _apellido[20];
    char _telefono[15];
    char _direccion[100];
    char _email[50];
    Fecha _fechaNacimiento;

public:
    Alumno();
    Alumno(int legajo, const char* DNI, const char* nombre, const char* apellido,
           const char* telefono, const char* direccion, const char* email, Fecha fechaNacimiento);

    int getLegajo() const;
    const char* getDNI() const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getTelefono() const;
    const char* getDireccion() const;
    const char* getEmail() const;
    Fecha getFechaNacimiento() const;

    void setLegajo(int legajo);
    void setDNI(const char* DNI);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setTelefono(const char* telefono);
    void setDireccion(const char* direccion);
    void setEmail(const char* email);
    void setFechaNacimiento(Fecha fecha);

    std::string toCSV() const;
    void cargar();
    void mostrar() const;
};

#endif
