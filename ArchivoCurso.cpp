#include <fstream>
#include "ArchivoCurso.h"

ArchivoCurso::ArchivoCurso(const char* n) {
    nombreArchivo = n;
}

Curso ArchivoCurso::leer(int pos) {
    Curso c;
    std::ifstream file(nombreArchivo, std::ios::binary);
    if (file) {
        file.seekg(pos * sizeof(Curso));
        file.read(reinterpret_cast<char*>(&c), sizeof(Curso));
        file.close();
    }
    return c;
}

bool ArchivoCurso::grabar(const Curso& c) {
    std::ofstream file(nombreArchivo, std::ios::app | std::ios::binary);
    if (!file) return false;
    file.write(reinterpret_cast<const char*>(&c), sizeof(Curso));
    file.close();
    return true;
}

int ArchivoCurso::buscarPorNumeroCurso(int numeroCurso) {
    Curso c;
    std::ifstream file(nombreArchivo, std::ios::binary);
    int i = 0;
    while (file.read(reinterpret_cast<char*>(&c), sizeof(Curso))) {
        if (c.getNumeroCurso() == numeroCurso) {
            file.close();
            return i;
        }
        i++;
    }
    file.close();
    return -1;
}

int ArchivoCurso::cantidad() {
    std::ifstream file(nombreArchivo, std::ios::binary | std::ios::ate);
    int bytes = file.tellg();
    file.close();
    return bytes / sizeof(Curso);
}