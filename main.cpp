#include <iostream>
#include <stdio.h>
#include "Ethernet.h"


using namespace std;

int main()
{
    // Definir el archivo
    // llamar a las funciones y mandarles el archivo
    // ethernet(archivo)

    FILE *archivo = fopen("Paquetes_Redes/ethernet_1.bin","rb+");

    if (archivo == NULL)
    {
        cout << "Error: No se encontro el archivo" <<  endl;
    }

    else
    {
        ethernet(archivo);
    }

    system ("PAUSE");
    return 0;
}