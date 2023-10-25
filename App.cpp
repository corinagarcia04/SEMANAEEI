#include <iostream>
using namespace std;
#include <vector>
#include "Tienda.h"
int main()
{
    vector<Tienda> lista;
    int cant = 0;
    //Registro de las tiendas y sus respectivo productos
    Tienda tienda("Tienda María","Cristobal Colon", "103","Santa Catarina","Nuevo León","México","81 2301 3012", "8:00", "20:00");
    Producto prod1("Coca cola","CC01",17,20,40,2), prod2("Fanta","FA02",20,20,40,2), prod3("Pepsi","PP002",13,19,38,2);
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;
    tienda = Tienda("Carnicería el Pepe","Cristobal Colon", "040","Santa Catarina","Nuevo León","México","81 1912 4099","9:00","18:00");
    prod1 =  Producto("Carne", "C001",15,50,100,7);
    prod2 =  Producto("Pollo", "P001",13,55,110,7);
    prod3 =  Producto("Pescado", "PE01",10,40,85,6);
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;
    tienda = Tienda("Dulcería Lalo","Cristobal Colon", "900","Santa Catarina","Nuevo León","México","81 4040 1021","8:00","21:00");
    prod1 =  Producto("Paletas", "P001",40,12,24,1);
    prod2 =  Producto("Chocolate", "CC01",30,15,30,2);
    prod3 =  Producto("Bombones", "BB01",15,23,46,2);
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;

    
    return 0;
}