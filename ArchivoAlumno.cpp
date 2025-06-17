#include <fstream>
#include "ArchivoAlumno.h"

ArchivoAlumno::ArchivoAlumno(const char* n) {
    nombreArchivo = n;
}

Alumno ArchivoAlumno::leer(int pos) {
    Alumno a;
    std::ifstream file(nombreArchivo, std::ios::binary);
    if (file) {
        file.seekg(pos * sizeof(Alumno));
        file.read(reinterpret_cast<char*>(&a), sizeof(Alumno));
        file.close();
    }
    return a;
}

bool ArchivoAlumno::grabar(const Alumno& a) {
    std::ofstream file(nombreArchivo, std::ios::app | std::ios::binary);
    if (!file) return false;
    file.write(reinterpret_cast<const char*>(&a), sizeof(Alumno));
    file.close();
    return true;
}

int ArchivoAlumno::buscarPorLegajo(int legajo) {
    Alumno a;
    std::ifstream file(nombreArchivo, std::ios::binary);
    int i = 0;
    while (file.read(reinterpret_cast<char*>(&a), sizeof(Alumno))) {
        if (a.getLegajo() == legajo) {
            file.close();
            return i;
        }
        i++;
    }
    file.close();
    return -1;
}

int ArchivoAlumno::cantidad() {
    std::ifstream file(nombreArchivo, std::ios::binary | std::ios::ate);
    int bytes = file.tellg();
    file.close();
    return bytes / sizeof(Alumno);
}