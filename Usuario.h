#ifndef Usuario_h
#define Usuario_h

#include <iostream>
using namespace std;

class Usuario
{
private:
    string nombre;
    string apellido;
    string calle;
    string codPostal;
    string ciudad;
    string estado;
    string pais;
    // Teléfono
    string tel;
    int cantPuntos;
    int cartera;

public:
    Usuario();
    Usuario(string, string, string,string, string, string,string, string, int, int);
    int puntos();
    int saldo();
};

Usuario ::Usuario()
{
    this->nombre = "";
    this->apellido = "";
    this->calle = "";
    this->codPostal = "";
    this->ciudad = "";
    this->estado = "";
    this->pais = "";
    this->tel = "";
    this->cantPuntos = 0;
    this->cartera = 0;
}

Usuario ::Usuario(string nombre, string apellido, string calle, string codPostal, string ciudad, string estado, string pais, string tel, int cantPuntos, int cartera)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->calle = calle;
    this->codPostal = codPostal;
    this->ciudad = ciudad;
    this->estado = estado;
    this->pais = pais;
    this->tel = tel;
    this->cantPuntos = cantPuntos;
    this->cartera = cartera;
}

int Usuario::puntos()
{
    return cantPuntos;
}

int Usuario::saldo()
{
    return cartera;
}
#endif /* Usuario_h */