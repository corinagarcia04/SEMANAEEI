#ifndef Tienda_h
#define Tienda_h

#include "Producto.h"

class Tienda : public Producto
{
private:
    // Nombre de la tienda
    string nomTienda;
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
    vector<Producto> listaProd;
public:
    Tienda();
    Tienda(string nomTienda, string calle, string codPostal, string ciudad, string estado, string pais, string tel, string horaInicio, string horaFinal);
    void info();
    string nombreTienda();
    void registroProducto(Producto product);
    void listaProductosA();
    void listaProductosB(int &num);
    int productCosto(int indice);
    int productPuntos(int indice);
    int productCant(int indice);
    int productObtPuntos(int indice);
    void setCant(int indice);
};

Tienda::Tienda() {
    this->nomTienda = "";
    this->calle = "";
    this->codPostal = "";
    this->ciudad = "";
    this->estado = "";
    this->pais = "";
    this->tel = "";
    this->horaInicio = "";
    this->horaFinal = "";

}

Tienda::Tienda(string nomTienda, string calle, string codPostal, string ciudad, string estado, string pais, string tel, string horaInicio, string horaFinal)
{
    this->nomTienda = nomTienda;
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
    cout << "Nombre: " << nomTienda << endl;
    cout << "Dirección: " << calle << " " << codPostal << " " << ciudad << " " << estado << " " << pais << endl;
    cout << "Horario: " << horaInicio << " - " << horaFinal << endl;
    cout << "Teléfono: " << tel << endl << endl;
}

void Tienda::registroProducto(Producto product)
{
    listaProd.push_back(product);
}

void Tienda::listaProductosA()
{
    for(int i = 0; i< listaProd.size(); i++)
    {
        cout << "Producto " << i + 1  << endl;
        listaProd[i].info();
    }
}

void Tienda::listaProductosB(int &num)
{
    for(int i = 0; i< listaProd.size(); i++)
    {
        cout << "Producto " << num << endl;
        listaProd[i].info();
        num++;
    }
}

string Tienda::nombreTienda()
{
    return nomTienda;
}

int Tienda::productCosto(int indice)
{
    return listaProd[indice].costo();
}

int Tienda::productCant(int indice)
{
    return listaProd[indice].cantidad();
}

int Tienda::productObtPuntos(int indice)
{
    return listaProd[indice].obtenerPuntos();
}

int Tienda::productPuntos(int indice)
{
    return listaProd[indice].costoPuntos();
}

void Tienda::setCant(int indice)
{
    listaProd[indice].setCant(cantidad()-1);

}
#endif
