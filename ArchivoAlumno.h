#pragma once
#include <string>
#include "Alumno.h"

class ArchivoAlumno {
private:
    std::string _nombreArchivo;

public:
    ArchivoAlumno(std::string nombreArchivo = "alumnos.dat");
    bool Guardar(Alumno alumno);
    bool Guardar(Alumno alumno, int posicion);
    int BuscarPorLegajo(int legajo);
    Alumno Leer(int posicion);
    int CantidadRegistros();
    void LeerTodos(int cantidadRegistros, Alumno* vector);
};
