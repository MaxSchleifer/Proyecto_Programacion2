#ifndef CURSO_H
#define CURSO_H

class Curso {
private:
    int numeroCurso;
    char descripcion[90];
    int aula;
    char docente[40];
    int maxAlumnos;

public:
    void cargar();
    void mostrar() const;
    int getNumeroCurso() const;
};

#endif