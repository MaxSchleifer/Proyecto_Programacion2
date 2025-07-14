#include "ArchivoCurso.h"
#include <cstdio>

ArchivoCurso::ArchivoCurso(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool ArchivoCurso::Guardar(Curso curso) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&curso, sizeof(Curso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoCurso::Guardar(Curso curso, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(Curso) * posicion, SEEK_SET);
    bool ok = fwrite(&curso, sizeof(Curso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoCurso::BuscarPorNumero(int numeroCurso) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return -1;
    }
    Curso curso;
    int i = 0;
    while(fread(&curso, sizeof(Curso), 1, pArchivo)) {
        if(curso.getNumeroCurso() == numeroCurso) {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Curso ArchivoCurso::Leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return Curso();
    }
    Curso curso;
    fseek(pArchivo, sizeof(Curso) * posicion, SEEK_SET);
    fread(&curso, sizeof(Curso), 1, pArchivo);
    fclose(pArchivo);
    return curso;
}

int ArchivoCurso::CantidadRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidad = ftell(pArchivo) / sizeof(Curso);
    fclose(pArchivo);
    return cantidad;
}

void ArchivoCurso::LeerTodos(int cantidadRegistros, Curso* vector) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL) {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++) {
        fread(&vector[i], sizeof(Curso), 1, pArchivo);
    }
    fclose(pArchivo);
}
