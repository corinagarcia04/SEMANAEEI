#include <iostream>
using namespace std;
#include <vector>
#include "Tienda.h"
#include "Usuario.h"
#include "Modulo.h"

void displayTiendas(vector<Tienda> lista)
{
    cout << "Lista de tiendas disponibles: " << endl
         << endl;

    for (int i = 0; i < lista.size(); i++)
    {
        cout << "(" << i + 1 << ")   " << lista[i].nombreTienda() << endl;
    }
}

void displayMenu()
{
    cout << "Menú" << endl;
    cout << "(1) Producto" << endl;
    cout << "(2) Tienda" << endl;
    cout << "(3) Cancelar" << endl;
    cout << "Ingresa la opcion deseada: ";
}

void displayMetodoEntrega(int &metodo)
{
    cout << endl
         << "Método de entrega" << endl
         << endl;
    cout << "(1) Servicio a domicilio" << endl;
    cout << "(2) Reserva en la tienda" << endl;
    cout << "(3) Entrega en módulo" << endl;
    cout << "Opción: ";
    cin >> metodo;
}

int displayTotalProductos(vector<Tienda> lista, int &opcionProducto)
{
    int num = 1;
    int tienda;
    cout << "Lista de productos disponibles: " << endl;
    for (int i = 0; i < lista.size(); i++)
    {
        lista[i].listaProductosB(num);
    }
    cout << endl
         << "Opción: ";
    cin >> opcionProducto;
    if (opcionProducto >= 1 && opcionProducto <= 3)
    {
        tienda = 0;
    }
    else if (opcionProducto >= 4 && opcionProducto <= 6)
    {
        tienda = 1;
        opcionProducto = opcionProducto - 3;
    }
    else if (opcionProducto >= 7 && opcionProducto <= 9)
    {
        tienda = 2;
        opcionProducto = opcionProducto - 6;
    }
    return tienda;
}

void costoTotal(int SelProd, Tienda &lista, int &cobroTotal, int &cobroTotalPuntos, int &puntosGanados)
{
    cobroTotal = cobroTotal + lista.productCosto(SelProd);
    cobroTotalPuntos = cobroTotalPuntos + lista.productPuntos(SelProd);
    lista.setCant(SelProd);
    puntosGanados = puntosGanados + lista.productObtPuntos(SelProd);
}
void metododePago(int cobroTotal, int cobroTotalPuntos, int puntosGanados, Usuario user, int &metodoPago)
{
    cout << "El costo total es de: " << endl;
    cout << cobroTotal << " pesos o " << cobroTotalPuntos << " puntos" << endl;
    cout << puntosGanados << " puntos ganados por la compra" << endl;
    cout << "Total de puntos para canjear: " << user.puntos() << endl;
    bool controlPago = true;
    while (controlPago)
    {
        cout << endl
             << "Método de pago" << endl
             << endl;
        cout << "(1) Tarjete de crédito" << endl;
        cout << "(2) Canjear puntos" << endl;
        cout << "(3) Efectivo" << endl;
        cout << "Opción: ";
        cin >> metodoPago;

        if (metodoPago == 1)
        {
            if (user.saldo() > cobroTotal)
            {
                user.setSaldo(user.saldo() - cobroTotal);
                controlPago = false;
                cout << endl
                     << "Compra realizada existosamente" << endl;
                
            }
            else
            {
                cout << endl
                     << "Insuficiente para realizar el pago" << endl;
            }
        }
        else if (metodoPago == 2)
        {
            if (user.puntos() > cobroTotalPuntos)
            {
                user.setPuntos(user.puntos() - cobroTotalPuntos);
                controlPago = false;
                cout << endl
                     << "Compra realizada existosamente" << endl;
                cout << endl << "Puntos restantes: " << user.puntos();
            }
            else
            {
                cout << endl
                     << "Insuficiente para realizar el pago" << endl;
            }
        }
        else if(metodoPago == 3) {
            controlPago = false;
            cout << endl << "Lleve lo más que se puede el monto exacto de la compra" << endl;
        }
    }
}

int main()
{
    vector<Tienda> lista;
    int cant = 0;
    // Registro de las tiendas y sus respectivo productos
    Tienda tienda("Tienda María", "Cristobal Colon", "103", "Santa Catarina", "Nuevo León", "México", "81 2301 3012", "8:00", "20:00");
    Producto prod1("Coca cola", "CC01", 17, 20, 40, 2), prod2("Fanta", "FA02", 20, 20, 40, 2), prod3("Pepsi", "PP002", 13, 19, 38, 2);
    Usuario user("Pablo", "Hernández", "Cristobal Colon", "222", "Santa Catarina", "Nuevo León", "México", "81 1032 2103", 800, 5000);
    Modulo modulo("Número 2", "Cúbiculo 7", "Cristobal Colon", "153", "Santa Catarina", "Nuevo León", "México", "CRiSTCo27Re");
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;
    tienda = Tienda("Carnicería el Pepe", "Cristobal Colon", "040", "Santa Catarina", "Nuevo León", "México", "81 1912 4099", "9:00", "18:00");
    prod1 = Producto("Carne", "C001", 15, 50, 100, 7);
    prod2 = Producto("Pollo", "P001", 13, 55, 110, 7);
    prod3 = Producto("Pescado", "PE01", 10, 40, 85, 6);
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;
    tienda = Tienda("Dulcería Lalo", "Cristobal Colon", "900", "Santa Catarina", "Nuevo León", "México", "81 4040 1021", "8:00", "21:00");
    prod1 = Producto("Paletas","P001", 40, 12, 24, 1);
    prod2 = Producto("Chocolate","CC01", 30, 15, 30, 2);
    prod3 = Producto("Bombones","BB01", 15, 23, 46, 2);
    lista.push_back(tienda);
    lista[cant].registroProducto(prod1);
    lista[cant].registroProducto(prod2);
    lista[cant].registroProducto(prod3);
    cant++;
    vector<int> TiendaRecap;
    vector<int> ProducRecap;

    bool verificador = true;
    bool controlRep = true;
    bool casoVerificador = true;
    int opcionMenu;         // Opcion del menu principal
    int opcionProducto;     // Opcion del menu de productos
    int opcionTienda;       // Opcion del menu de tiendas
    string validadorCompra; // Validador para saber si el usuario quiere seguir comprando
    int metodoPago;
    int metodoEntrega;
    int cobroTotal = 0;
    int cobroTotalPuntos = 0;
    int puntosGanados = 0;
    do
    {

        bool casoVerificador = true;
        displayMenu();
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            while (casoVerificador)
            {
                cout << endl;
                // Se despliega la lista de productos
                if (controlRep)
                {
                    opcionTienda = displayTotalProductos(lista, opcionProducto);
                }
                else
                {
                    lista[opcionTienda].listaProductosA();
                    cout << endl
                         << "Opción: ";
                    cin >> opcionProducto;
                }
                TiendaRecap.push_back(opcionTienda);
                ProducRecap.push_back(opcionProducto - 1);
                // Hacer sumatoria del precio del producto al total de la compra
                // Validar si el usuario quiere seguir comprando
                cout << "Desea seguir comprando? (s/n): ";
                cin >> validadorCompra;
                if (validadorCompra == "n")
                { // Si el usuario no quiere seguir comprando
                    verificador = false;
                    casoVerificador = false;
                }
                else
                {
                    controlRep = false;
                }
            }
            break;
        case 2:
            while (casoVerificador)
            {
                cout << endl;
                // Se despliega la lista de tiendas
                if (controlRep)
                {
                    displayTiendas(lista);
                    cout << "Opción: ";
                    cin >> opcionTienda;
                }
                cout << endl
                     << endl;
                lista[opcionTienda - 1].listaProductosA();
                // Se pide al usuario que ingrese el producto que desea comprar
                cout << endl
                     << "Opción: ";
                cin >> opcionProducto;
                TiendaRecap.push_back(opcionTienda-1);
                ProducRecap.push_back(opcionProducto - 1);
                // Hacer sumatoria del precio del producto al total de la compra
                // Validar si el usuario quiere seguir comprando
                cout << "Desea seguir comprando? (s/n): ";
                cin >> validadorCompra;
                if (validadorCompra == "n")
                { // Si el usuario no quiere seguir comprando
                    verificador = false;
                    casoVerificador = false;
                }
                else
                {
                    controlRep = false;
                }
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
    if (opcionMenu != 3)
    {
        // Sale del do while y se hace el proceso de pago
        cout << "Inicia proceso de pago" << endl;
        displayMetodoEntrega(metodoEntrega);
        for (int i = 0; i < TiendaRecap.size(); i++)
        {
            costoTotal(ProducRecap[i], lista[TiendaRecap[i]], cobroTotal, cobroTotalPuntos, puntosGanados);
        }
        metododePago(cobroTotal, cobroTotalPuntos, puntosGanados, user, metodoPago);
        if (metodoEntrega == 3)
        {
            modulo.info();
        }else{
            cout << "Llava de identificador para recoger pedido: " <<modulo.getKey() << endl;
        }
        
    }
    cout<< endl << "Gracias por su compra vuelva pronto" << endl;
    return 0;
}