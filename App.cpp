#include <iostream>
using namespace std;
#include <vector>
#include "Tienda.h"

void displayTiendas(vector<Tienda> lista) {
    cout << "Lista de tiendas disponibles: " << endl << endl;

    for(int i = 0; i<lista.size();i++)
    {
        cout << "(" << i + 1 << ")   "<< lista[i].nombreTienda() << endl;
    }
}

void displayMenu() {
    cout << "(1) Producto" << endl;
    cout << "(2) Tienda" << endl;
    cout << "(3) Cancelar" << endl;
    cout << "Ingresa la opcion deseada: ";
}

int displayTotalProductos(vector<Tienda> lista, int &opcionProducto)
{
    int num = 1;
    int opcionProducto;
    int tienda;
    cout << "Lista de productos disponibles: " << endl;
    for(int i = 0; i < lista.size();i++)
    {
        lista[i].listaProductosB(num);
    }
    cin >> opcionProducto;
    if(opcionProducto >= 1 && opcionProducto <= 3)
    {
        tienda = 0;
    }
    else if(opcionProducto >= 4 && opcionProducto <= 6)
    {
        tienda = 1;
        opcionProducto = opcionProducto - 3;
    }
    else if(opcionProducto >= 7 && opcionProducto <= 9)
    {
        tienda = 2;
        opcionProducto = opcionProducto - 6;
    }
    return tienda;
}


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
    vector<int> TiendaRecap;
    vector<int> ProducRecap;

    bool verificador = true;
    int opcionMenu; // Opcion del menu principal
    int opcionProducto; // Opcion del menu de productos
    int opcionTienda; // Opcion del menu de tiendas
    string validadorCompra; // Validador para saber si el usuario quiere seguir comprando
    do {
        displayMenu();
        cin >> opcionMenu;
        switch (opcionMenu) {
            case 1:
                // Se despliega la lista de productos
                opcionTienda = displayTotalProductos(lista,opcionProducto);
                TiendaRecap.push_back(opcionTienda);
                ProducRecap.push_back(opcionProducto-1);
                // Hacer sumatoria del precio del producto al total de la compra
                // Validar si el usuario quiere seguir comprando
                cout << "Desea seguir comprando? (s/n): ";
                cin >> validadorCompra;
                if (validadorCompra == "n") { // Si el usuario no quiere seguir comprando
                    verificador = false;
                }
                break;
            case 2:
                // Se despliega la lista de tiendas
                displayTiendas(lista);
                cout << endl;
                // Revisa qué tienda escogió el usuario y muestra los productos de esa tienda
                // cin >> opcionTienda;
                // if (opcionTienda == 1) {
                //     // muestra productos de tienda A
                //     lista[opcionTienda-1].listaProductos();
                // } else if (opcionTienda == 2) {
                //     // muestra productos de tienda B
                //     lista[opcionTienda-1].listaProductos();
                // } else if (opcionTienda == 3) {
                //     // muestra productos de tienda C
                //     lista[opcionTienda-1].listaProductos();
                // } 
                lista[opcionTienda-1].listaProductosA();
                // Se pide al usuario que ingrese el producto que desea comprar
                cin >> opcionProducto;
                TiendaRecap.push_back(opcionTienda);
                ProducRecap.push_back(opcionProducto-1);
                // Hacer sumatoria del precio del producto al total de la compra
                // Validar si el usuario quiere seguir comprando
                cout << "Desea seguir comprando? (s/n): ";
                cin >> validadorCompra;
                if (validadorCompra == "n") { // Si el usuario no quiere seguir comprando
                    verificador = false;
                }

                break;
            case 3:
                cout << "Operacion finalizada" << endl;
                verificador = false;
                break;
            default:
                cout << "Opcion inválida" << endl;
                break;
        }
    } while (verificador);
    // Sale del do while y se hace el proceso de pago 
    cout << "Inicia proceso de pago" << endl;
    return 0;
}