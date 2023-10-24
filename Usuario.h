#ifndef Usuario_h
#define Usuario_h

#include <iostream>
using namespace std;

class Usuario {
    private:
    string nombre;
    string apellido;
    string direccion;
    string cantPuntos;
    public:
    Usuario();
    Usuario(string, string, string, string);
};

Usuario :: Usuario() {
    nombre = "";
    apellido = "";
    direccion = "";
    cantPuntos = "";
}

Usuario :: Usuario(string nombre, string apellido, string direccion, string cantPuntos) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    this->cantPuntos = cantPuntos;
}


#endif /* Usuario_h */