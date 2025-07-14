#include "ArchivoAlumno.h"
#include <cstdio>

ArchivoAlumno::ArchivoAlumno(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoAlumno::Guardar(Alumno alumno) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&alumno, sizeof(Alumno), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoAlumno::Guardar(Alumno alumno, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Alumno) * posicion, SEEK_SET);
    bool ok = fwrite(&alumno, sizeof(Alumno), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoAlumno::BuscarPorLegajo(int legajo) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Alumno alumno;
    int i = 0;
    while(fread(&alumno, sizeof(Alumno), 1, pArchivo)) {
        if(alumno.getLegajo() == legajo) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Alumno ArchivoAlumno::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return Alumno();
    }
    Alumno alumno;
    fseek(pArchivo, sizeof(Alumno) * posicion, SEEK_SET);
    fread(&alumno, sizeof(Alumno), 1, pArchivo);
    fclose(pArchivo);
    return alumno;
}

int ArchivoAlumno::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Alumno);
    fclose(pArchivo);
    return cantidad;
}

void ArchivoAlumno::LeerTodos(int cantidadRegistros, Alumno* vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(Alumno), 1, pArchivo);
    }
    fclose(pArchivo);
}
