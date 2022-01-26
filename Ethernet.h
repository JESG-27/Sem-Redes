#ifndef ETHERNET_H
#define ETHERNET_H

#include <iostream>
#include <stdio.h>

using namespace std;

void ethernet(FILE *archivo)
{
    
    unsigned char palabra;
    size_t i;

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
            palabra=fgetc(archivo);
            printf ("%02x:",palabra);
            printf ("%c", palabra);

            // switch con las opciones de los diferentes tipos
            // 0800 IPv4
            // 0806 ARP
            // 8035 RARP
            // 86DD IPv6
   
        }
        cout << endl << endl;

        cout << "Datos: " << endl;
        while (!feof(archivo))
        {
            palabra=fgetc(archivo);
            printf ("%02x:",palabra);
        }
        cout << endl << endl;

    fclose(archivo);
}

#endif
