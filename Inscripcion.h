#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"

class Inscripcion {
private:
    int _legajo;
    int _numeroCurso;
    Fecha _fechaInscripcion;
    float _importeMatricula;

public:
    Inscripcion();
    Inscripcion(int legajo, int numeroCurso, Fecha fechaInscripcion, float importeMatricula);

    int getLegajo() const;
    int getNumeroCurso() const;
    Fecha getFechaInscripcion() const;
    float getImporteMatricula() const;

    void setLegajo(int legajo);
    void setNumeroCurso(int numeroCurso);
    void setFechaInscripcion(Fecha fecha);
    void setImporteMatricula(float importe);

    std::string toCSV() const;
    void cargar();
    void mostrar() const;
};

#endif
