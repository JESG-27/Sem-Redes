#ifndef ETHERNET_H
#define ETHERNET_H

#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

void ethernet(FILE *archivo)
{
    unsigned char palabra[70];
    //ArregloDinamico<unsigned char> palabra;
    size_t i;
    
    cout << setw(40) << "<<< ETHERNHET >>>" << endl << endl;

    cout << "Direccion MAC Destino:" << endl;
    for(i=0;i<=5;i++)
    {
        palabra[i]=fgetc(archivo);
        printf ("%02x:",palabra[i]);
    }
    cout << endl << endl;

    cout << "Direccion MAC Origen:" << endl;
    for(i=6;i<=11;i++)
    {
        palabra[i]=fgetc(archivo);
        printf ("%02x:",palabra[i]);
    }
    cout << endl << endl;


    cout << "Tipo de codigo:" << endl;
    for(i=12;i<=13;i++)
    {
        palabra[i]=fgetc(archivo);
        printf ("%02x:",palabra[i]);
    }

    // 0800 IPv4
    // 0806 ARP
    // 8035 RARP
    // 86DD IPv6
    
    cout << endl;
    if (palabra[13] == 0)
    {
        cout << "IPv4" << endl;
    }

    else if (palabra[13] == 6)
    {
        cout << "ARP" << endl;
    }

    else if (palabra[13] == 5)
    {
        cout << "RARP" << endl;
    }

    else if (palabra[13] == 'D')
    {
        cout << "IPv6" << endl;
    }

    cout << endl;

    cout << "Datos: " << endl;

    while (!feof(archivo))
    {
        i++;
        palabra[i]=fgetc(archivo);
        printf ("%02x:",palabra[i]);
    }
    cout << endl << endl;
    fclose(archivo);
}

#endif