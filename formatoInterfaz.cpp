#include <iostream>
using namespace std;

void displayTiendas() {
    cout << "Lista de tiendas disponibles: " << endl;
    cout << "1. Tienda A" << endl;
    cout << "2. Tienda B" << endl;
    cout << "3. Tienda C" << endl;
}

void displayMenu() {
    cout << "1. Producto" << endl;
    cout << "2. Tienda" << endl;
    cout << "3. Cancelar" << endl;
    cout << "Ingresa la opcion deseada: ";
}

void displayProductos() {
    cout << "Lista de productos disponibles: " << endl;
    cout << "1. Fresa" << endl;
    cout << "2. Platano" << endl;
    cout << "3. Huevo" << endl;
    cout << "Ingresa la opcion deseada: ";
}

int main()
{
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
                displayProductos();
                cin >> opcionProducto;
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
                displayTiendas();
                // Revisa qué tienda escogió el usuario y muestra los productos de esa tienda
                cin >> opcionTienda;
                if (opcionTienda == 1) {
                    // muestra productos de tienda A
                    displayProductos();
                } else if (opcionTienda == 2) {
                    // muestra productos de tienda B
                } else if (opcionTienda == 3) {
                    // muestra productos de tienda C
                } 
                // Se pide al usuario que ingrese el producto que desea comprar
                cin >> opcionProducto;
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
