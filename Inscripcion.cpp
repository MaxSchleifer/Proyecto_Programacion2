#include <iostream>
#include "Inscripcion.h"

using namespace std;

void Inscripcion::cargar() {
    cout << "Legajo del alumno: ";
    cin >> legajo;
    cout << "Número de curso: ";
    cin >> numeroCurso;
    cout << "Fecha de inscripción:" << endl;
    fechaInscripcion.cargar();
    cout << "Importe de matrícula: ";
    cin >> importeMatricula;
}

void Inscripcion::mostrar() const {
    cout << "Legajo del alumno: " << legajo << endl;
    cout << "Número de curso: " << numeroCurso << endl;
    cout << "Fecha de inscripción: ";
    fechaInscripcion.mostrar();
    cout << "\nImporte de matrícula: $" << importeMatricula << endl;
}

int Inscripcion::getLegajo() const { return legajo; }
int Inscripcion::getNumeroCurso() const { return numeroCurso; }