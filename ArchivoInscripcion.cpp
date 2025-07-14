#include "ArchivoInscripcion.h"
#include <cstdio>

ArchivoInscripcion::ArchivoInscripcion(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoInscripcion::Guardar(Inscripcion inscripcion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&inscripcion, sizeof(Inscripcion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoInscripcion::Guardar(Inscripcion inscripcion, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Inscripcion) * posicion, SEEK_SET);
    bool ok = fwrite(&inscripcion, sizeof(Inscripcion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoInscripcion::BuscarPorLegajoYCurso(int legajo, int numeroCurso) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Inscripcion inscripcion;
    int i = 0;
    while(fread(&inscripcion, sizeof(Inscripcion), 1, pArchivo)) {
        if(inscripcion.getLegajo() == legajo &&
           inscripcion.getNumeroCurso() == numeroCurso) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Inscripcion ArchivoInscripcion::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return Inscripcion();
    }
    Inscripcion inscripcion;
    fseek(pArchivo, sizeof(Inscripcion) * posicion, SEEK_SET);
    fread(&inscripcion, sizeof(Inscripcion), 1, pArchivo);
    fclose(pArchivo);
    return inscripcion;
}

int ArchivoInscripcion::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Inscripcion);
    fclose(pArchivo);
    return cantidad;
}

void ArchivoInscripcion::LeerTodos(int cantidadRegistros, Inscripcion* vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(Inscripcion), 1, pArchivo);
    }
    fclose(pArchivo);
}
