#include <iostream>
using namespace std;

#include "Tienda.h"
int main()
{
    Tienda tienda("Tienda María","Cristobal Colon", "103","Santa Catarina","Nuevo León","81 2301 3012", "8:00", "20:00");
    tienda.info();

    return 0;
}