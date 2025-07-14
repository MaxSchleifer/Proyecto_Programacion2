#pragma once
#include <string>
#include "Curso.h"

class ArchivoCurso {
private:
    std::string _nombreArchivo;

public:
    ArchivoCurso(std::string nombreArchivo = "cursos.dat");
    bool Guardar(Curso curso);
    bool Guardar(Curso curso, int posicion);
    int BuscarPorNumero(int numeroCurso);
    Curso Leer(int posicion);
    int CantidadRegistros();
    void LeerTodos(int cantidadRegistros, Curso* vector);
};
