#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    
    unsigned char palabra;
    size_t i;

    FILE *archivo;

    if ((archivo = fopen("Paquetes_Redes/ethernet_1.bin","rb+")) == NULL)
    {
        cout << " Error: No se encontro el archivo" <<  endl;
    }

    else
    {
        cout << "Direccion MAC origen:" << endl;
        for(i=0;i<=5;i++)
        {
            palabra=fgetc(archivo);
            printf ("%02x:",palabra);
        }
        cout << endl << endl;

        cout << "Direccion MAC destino:" << endl;
        for(i=0;i<=5;i++)
        {
            palabra=fgetc(archivo);
            printf ("%02x:",palabra);
        }
        cout << endl << endl;


        cout << "Tipo de codigo:" << endl;
        for(i=0;i<=1;i++)
        {
            unsigned char tp1, tp2;

            palabra=fgetc(archivo);
            printf ("%02x:",palabra);

            // switch con las opciones de los diferentes tipos
            // 0800 IPv4
            // 0806 ARP
            // 8035 RARP
            // 86DD IPv6
   
            if (i == 0)
            {
                tp1 = palabra;
            }

            else
            {
                tp2 = palabra;
            }
            
        }
        cout << endl << endl;

        printf("Datos: ");
        while (!feof(archivo))
        {
            palabra=fgetc(archivo);
            printf ("%02x:",palabra);

        }
        cout << endl << endl;

    }
    fclose(archivo);
    return 0;
}