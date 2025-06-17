#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"

class Inscripcion {
private:
    int legajo;
    int numeroCurso;
    Fecha fechaInscripcion;
    float importeMatricula;

public:
    void cargar();
    void mostrar() const;
    int getLegajo() const;
    int getNumeroCurso() const;
};

#endif