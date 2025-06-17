#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "ArchivoAlumno.h"
#include "ArchivoCurso.h"
#include "ArchivoInscripcion.h"

using namespace std;

void menu() {
    cout << "=== Sistema de Gestión Escolar ===\n";
    cout << "1. Cargar Alumno\n";
    cout << "2. Listar Alumnos\n";
    cout << "3. Cargar Curso\n";
    cout << "4. Listar Cursos\n";
    cout << "5. Cargar Inscripción\n";
    cout << "6. Listar Inscripciones\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    ArchivoAlumno archAlu;
    ArchivoCurso archCurso;
    ArchivoInscripcion archInsc;

    int opcion;
    do {
        menu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                Alumno a;
                a.cargar();
                archAlu.grabar(a);
                break;
            }
            case 2: {
                for (int i = 0; i < archAlu.cantidad(); i++) {
                    Alumno a = archAlu.leer(i);
                    a.mostrar();
                    cout << "------------------\n";
                }
                break;
            }
            case 3: {
                Curso c;
                c.cargar();
                archCurso.grabar(c);
                break;
            }
            case 4: {
                for (int i = 0; i < archCurso.cantidad(); i++) {
                    Curso c = archCurso.leer(i);
                    c.mostrar();
                    cout << "------------------\n";
                }
                break;
            }
            case 5: {
                Inscripcion i;
                i.cargar();
                archInsc.grabar(i);
                break;
            }
            case 6: {
                for (int i = 0; i < archInsc.cantidad(); i++) {
                    Inscripcion ins = archInsc.leer(i);
                    ins.mostrar();
                    cout << "------------------\n";
                }
                break;
            }
        }
    } while (opcion != 0);

    cout << "Gracias por usar el sistema.\n";
    return 0;
}