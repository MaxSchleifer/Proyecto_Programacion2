#pragma once
#include <string>
#include "Inscripcion.h"

class ArchivoInscripcion {
private:
    std::string _nombreArchivo;

public:
    ArchivoInscripcion(std::string nombreArchivo = "inscripciones.dat");
    bool Guardar(Inscripcion inscripcion);
    bool Guardar(Inscripcion inscripcion, int posicion);
    int BuscarPorLegajoYCurso(int legajo, int numeroCurso);
    Inscripcion Leer(int posicion);
    int CantidadRegistros();
    void LeerTodos(int cantidadRegistros, Inscripcion* vector);
};
