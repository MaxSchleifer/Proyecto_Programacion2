#ifndef ARCHIVOALUMNO_H
#define ARCHIVOALUMNO_H

#include "Alumno.h"

class ArchivoAlumno {
private:
    const char* nombreArchivo;

public:
    ArchivoAlumno(const char* n = "alumnos.dat");
    Alumno leer(int pos);
    bool grabar(const Alumno& a);
    int buscarPorLegajo(int legajo);
    int cantidad();
};

#endif