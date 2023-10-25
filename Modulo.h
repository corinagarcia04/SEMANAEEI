#ifndef Modulo_h
#define Modulo_h

#include <iostream>
using namespace std;
class Modulo
{
private:
    string numMod;
    string espacio;
    // Dirección
    string calle;
    string codPostal;
    string ciudad;
    string estado;
    string pais;
    string key;

public:
    Modulo();
    Modulo(string, string, string, string, string, string, string, string);
    void info();
    string getKey();
};

Modulo::Modulo()
{
    this->numMod = "";
    this->espacio = "";
    this->calle = "";
    this->codPostal = "";
    this->ciudad = "";
    this->estado = "";
    this->pais = "";
    this->key = "";
}

Modulo::Modulo(string numMod, string espacio, string calle, string codPostal, string ciudad, string estado, string pais, string key)
{
    this->numMod = numMod;
    this->espacio = espacio;
    this->calle = calle;
    this->codPostal = codPostal;
    this->ciudad = ciudad;
    this->estado = estado;
    this->pais = pais;
    this->key = key;
}

void Modulo::info()
{
    cout << endl << "Ubicación del módulo: "<< endl << endl;
    cout << "Módulo: " << numMod << endl;
    cout << "Espacio: " << espacio << endl;
    cout << "Dirección: " << calle << " " << codPostal << " " << ciudad << " " << estado << " " << pais << endl;
    cout << "Llave de acceso: " << key << endl << endl;
}

string Modulo::getKey()
{
    return key;
}
#endif