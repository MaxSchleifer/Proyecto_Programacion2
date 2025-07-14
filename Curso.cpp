#include <iostream>
#include <cstring>
#include "Curso.h"

using namespace std;

void Curso::cargar() {
    cout << "Numero de curso: ";
    cin >> numeroCurso;
    cin.ignore();
    cout << "Descripcion: ";
    cin.getline(descripcion, 90);
    cout << "Aula: ";
    cin >> aula;
    cin.ignore();
    cout << "Docente: ";
    cin.getline(docente, 40);
    cout << "Cantidad maxima de alumnos: ";
    cin >> maxAlumnos;
    cin.ignore();
}

void Curso::mostrar() const {
    cout << "Numero de curso: " << numeroCurso << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Aula: " << aula << endl;
    cout << "Docente: " << docente << endl;
    cout << "Maximo de alumnos: " << maxAlumnos << endl;
}

int Curso::getNumeroCurso() const { return numeroCurso; }
