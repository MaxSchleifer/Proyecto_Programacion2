#include "Inscripcion.h"
#include <iostream>
#include <string>

Inscripcion::Inscripcion() {
    _legajo = 0;
    _numeroCurso = 0;
    _fechaInscripcion = Fecha();
    _importeMatricula = 0.0f;
}

Inscripcion::Inscripcion(int legajo, int numeroCurso, Fecha fechaInscripcion, float importeMatricula) {
    _legajo = legajo;
    _numeroCurso = numeroCurso;
    _fechaInscripcion = fechaInscripcion;
    _importeMatricula = importeMatricula;
}

// Getters
int Inscripcion::getLegajo() const { return _legajo; }
int Inscripcion::getNumeroCurso() const { return _numeroCurso; }
Fecha Inscripcion::getFechaInscripcion() const { return _fechaInscripcion; }
float Inscripcion::getImporteMatricula() const { return _importeMatricula; }

// Setters
void Inscripcion::setLegajo(int legajo) { _legajo = legajo; }
void Inscripcion::setNumeroCurso(int numeroCurso) { _numeroCurso = numeroCurso; }
void Inscripcion::setFechaInscripcion(Fecha fecha) { _fechaInscripcion = fecha; }
void Inscripcion::setImporteMatricula(float importe) { _importeMatricula = importe; }

std::string Inscripcion::toCSV() const {
    return std::to_string(_legajo) + "," + std::to_string(_numeroCurso) + "," +
           _fechaInscripcion.toString() + "," + std::to_string(_importeMatricula);
}

void Inscripcion::cargar() {
    std::cout << "Legajo del alumno: ";
    std::cin >> _legajo;

    std::cout << "Numero de curso: ";
    std::cin >> _numeroCurso;

    std::cout << "Fecha de inscripcion (dia mes anio): ";
    int d, m, a;
    std::cin >> d >> m >> a;
    _fechaInscripcion = Fecha(d, m, a);

    std::cout << "Importe de matricula: ";
    std::cin >> _importeMatricula;
    std::cin.ignore();
}

void Inscripcion::mostrar() const {
    std::cout << "Legajo alumno: " << _legajo << std::endl;
    std::cout << "Numero curso: " << _numeroCurso << std::endl;
    std::cout << "Fecha inscripcion: " << _fechaInscripcion.toString() << std::endl;
    std::cout << "Importe matricula: $" << _importeMatricula << std::endl;
}
