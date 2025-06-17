#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;
public:
    void cargar();
    void mostrar() const;
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif