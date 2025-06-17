#include <iostream>
#include <cstring>
#include "Curso.h"

using namespace std;

void Curso::cargar() {
    cout << "Número de curso: ";
    cin >> numeroCurso;
    cin.ignore();
    cout << "Descripción: ";
    cin.getline(descripcion, 90);
    cout << "Aula: ";
    cin >> aula;
    cin.ignore();
    cout << "Docente: ";
    cin.getline(docente, 40);
    cout << "Cantidad máxima de alumnos: ";
    cin >> maxAlumnos;
    cin.ignore();
}

void Curso::mostrar() const {
    cout << "Número de curso: " << numeroCurso << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "Aula: " << aula << endl;
    cout << "Docente: " << docente << endl;
    cout << "Máximo de alumnos: " << maxAlumnos << endl;
}

int Curso::getNumeroCurso() const { return numeroCurso; }