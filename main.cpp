#include <iostream>
#include "ArchivoAlumno.h"
#include "ArchivoCurso.h"
#include "ArchivoInscripcion.h"

void mostrarMenu() {
    std::cout << "\n--- SISTEMA DE GESTION ESCOLAR ---\n";
    std::cout << "1. Cargar Alumno\n";
    std::cout << "2. Listar Alumnos\n";
    std::cout << "3. Cargar Curso\n";
    std::cout << "4. Listar Cursos\n";
    std::cout << "5. Cargar Inscripcion\n";
    std::cout << "6. Listar Inscripciones\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione opcion: ";
}

int main() {
    ArchivoAlumno archAlu("alumnos.dat");
    ArchivoCurso archCurso("cursos.dat");
    ArchivoInscripcion archInsc("inscripciones.dat");

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion) {
            case 1: {
                Alumno a;
                a.cargar();
                archAlu.Guardar(a);
                break;
            }
            case 2: {
                int cant = archAlu.CantidadRegistros();
                Alumno* alumnos = new Alumno[cant];
                archAlu.LeerTodos(cant, alumnos);

                for(int i = 0; i < cant; i++) {
                    alumnos[i].mostrar();
                    std::cout << "------------------\n";
                }
                delete[] alumnos;
                break;
            }
            case 3: {
                Curso c;
                c.cargar();
                archCurso.Guardar(c);
                break;
            }
            case 4: {
                int cant = archCurso.CantidadRegistros();
                Curso* cursos = new Curso[cant];
                archCurso.LeerTodos(cant, cursos);

                for(int i = 0; i < cant; i++) {
                    cursos[i].mostrar();
                    std::cout << "------------------\n";
                }
                delete[] cursos;
                break;
            }
            case 5: {
                Inscripcion i;
                i.cargar();
                archInsc.Guardar(i);
                break;
            }
            case 6: {
                int cant = archInsc.CantidadRegistros();
                Inscripcion* inscripciones = new Inscripcion[cant];
                archInsc.LeerTodos(cant, inscripciones);

                for(int i = 0; i < cant; i++) {
                    inscripciones[i].mostrar();
                    std::cout << "------------------\n";
                }
                delete[] inscripciones;
                break;
            }
        }
    } while(opcion != 0);

    return 0;
}
