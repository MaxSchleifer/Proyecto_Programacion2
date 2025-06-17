#include <fstream>
#include "ArchivoInscripcion.h"

ArchivoInscripcion::ArchivoInscripcion(const char* n) {
    nombreArchivo = n;
}

Inscripcion ArchivoInscripcion::leer(int pos) {
    Inscripcion i;
    std::ifstream file(nombreArchivo, std::ios::binary);
    if (file) {
        file.seekg(pos * sizeof(Inscripcion));
        file.read(reinterpret_cast<char*>(&i), sizeof(Inscripcion));
        file.close();
    }
    return i;
}

bool ArchivoInscripcion::grabar(const Inscripcion& i) {
    std::ofstream file(nombreArchivo, std::ios::app | std::ios::binary);
    if (!file) return false;
    file.write(reinterpret_cast<const char*>(&i), sizeof(Inscripcion));
    file.close();
    return true;
}

int ArchivoInscripcion::cantidad() {
    std::ifstream file(nombreArchivo, std::ios::binary | std::ios::ate);
    int bytes = file.tellg();
    file.close();
    return bytes / sizeof(Inscripcion);
}