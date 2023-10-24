#ifndef Tienda_h
#define Tienda_h

#include "TipoProducto.h"

class Tienda
{
private:
    // Nombre de la tienda
    string nombre;
    // Dirección
    string calle;
    string codPostal;
    string ciudad;
    string estado;
    string pais;
    // Teléfono
    string tel;
    string horaInicio;
    string horaFinal;

public:
    Tienda();
    Tienda(string nombre, string calle, string codPostal, string ciudad, string estado, string pais, string tel, string horaInicio, string horaFinal);
    void info();
};

Tienda::Tienda()
{
    this->nombre = "";
    this->calle = "";
    this->codPostal = "";
    this->ciudad = "";
    this->estado = "";
    this->pais = "";
    this->tel = "";
    this->horaInicio = "";
    this->horaFinal = "";
}

Tienda::Tienda(string nombre, string calle, string codPostal, string ciudad, string estado, string pais, string tel, string horaInicio, string horaFinal)
{
    this->nombre = nombre;
    this->calle = calle;
    this->codPostal = codPostal;
    this->ciudad = ciudad;
    this->estado = estado;
    this->pais = pais;
    this->tel = tel;
    this->horaInicio = horaInicio;
    this->horaFinal = horaFinal;
}

void Tienda::info()
{
    cout << endl << "Información de la tienda: "<< endl << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Dirección: " << calle << " " << codPostal << " " << ciudad << " " << estado << " " << pais << endl;
    cout << "Horario: " << horaInicio << " - " << horaFinal << endl;
    cout << "Teléfono: " << tel << endl;
}

#endif