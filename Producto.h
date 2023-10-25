#ifndef Producto_h
#define Producto_h

class Producto
{
private:
    string nomProd;
    string id;
    int cant;
    int precio;
    int precioCP;
    int puntos;
public:
    Producto();
    Producto(string,string,int, int,int,int);
    void info();
    int cantidad();
    int costo();
    int costoPuntos();
    int obtenerPuntos();
    void setCant(int);
};

Producto::Producto()
{
    this->nomProd = "";
    this->id = "";
    this->cant = 0;
    this->precio = 0;
    this->precioCP = 0;
    this->puntos = 0;
}
Producto::Producto(string nomProd,string id, int cant, int precio, int precioCP, int puntos)
{
    this->nomProd = nomProd;
    this->id = id;
    this->cant = cant;
    this->precio = precio;
    this->precioCP = precioCP;
    this->puntos = puntos;
}

void Producto::info()
{
    cout << "Nombre: " << nomProd << endl;
    cout << "Cantidad disponible: " << cant << endl;
    cout << "Precio: " << precio << " pesos" << endl;
    cout << "PrecioCP: " << precioCP << " puntos" << endl << endl;
}

int Producto::cantidad()
{
    return cant;
}

int Producto::costo()
{
    return precio;
}

int Producto::costoPuntos()
{
    return precioCP;
}

int Producto::obtenerPuntos()
{
    return puntos;
}

void Producto::setCant(int cant1)
{
    this->cant = cant1;
}
#endif