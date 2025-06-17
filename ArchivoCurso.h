#ifndef ARCHIVOCURSO_H
#define ARCHIVOCURSO_H

#include "Curso.h"

class ArchivoCurso {
private:
    const char* nombreArchivo;

public:
    ArchivoCurso(const char* n = "cursos.dat");
    Curso leer(int pos);
    bool grabar(const Curso& c);
    int buscarPorNumeroCurso(int numeroCurso);
    int cantidad();
};

#endif