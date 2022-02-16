#include <iostream>
#include <stdio.h>
#include "Ethernet.h"
using namespace std;

int main()
{
    FILE *archivo = fopen("Paquetes_Redes/ethernet_ipv4_icmp.bin","rb+");
    // La ruta y/o del archivo se debe de modificar según el archivo que se quiera leer.
    // D:\CUCEI\4to_Semestre\SSPRCPC\Codigos\Paquetes_Redes\ethernet_ipv4_icmp_host_unreachable.bin

    if (archivo == NULL)
    {
        cout << "Error: No se encontro el archivo" <<  endl;
    }

    else
    {
        ethernet(archivo);
    }

    system ("PAUSE");
    system ("CLS");
    return 0;
}
