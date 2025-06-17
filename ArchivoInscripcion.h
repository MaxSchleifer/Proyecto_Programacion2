#ifndef ARCHIVOINSCRIPCION_H
#define ARCHIVOINSCRIPCION_H

#include "Inscripcion.h"

class ArchivoInscripcion {
private:
    const char* nombreArchivo;

public:
    ArchivoInscripcion(const char* n = "inscripciones.dat");
    Inscripcion leer(int pos);
    bool grabar(const Inscripcion& i);
    int cantidad();
};

#endif