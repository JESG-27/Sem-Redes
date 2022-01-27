#include <iostream>
#include <stdio.h>
#include "Ethernet.h"
#include "Ethernet_2.h"


using namespace std;

int main()
{
    // Definir el archivo
    // llamar a las funciones y mandarles el archivo
    // ethernet(archivo)

    FILE *archivo = fopen("Paquetes_Redes/ethernet_2.bin","rb+");

    if (archivo == NULL)
    {
        cout << " Error: No se encontro el archivo" <<  endl;
    }

    else
    {
        cout << endl << "Prueba" << endl;
        ethernet_2(archivo);
    }

    return 0;
}