#include <iostream>
#include "Fecha.h"

using namespace std;

void Fecha::cargar() {
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;
}

void Fecha::mostrar() const {
    cout << dia << "/" << mes << "/" << anio;
}

int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }