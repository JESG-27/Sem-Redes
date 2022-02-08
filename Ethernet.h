#ifndef ETHERNET_H
#define ETHERNET_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "IPv4.h"

using namespace std;

void ethernet(FILE *archivo)
{
    unsigned char palabra[70];
    size_t i=0;

    cout << setw(40) << "<<< ETHERNHET >>>" << endl << endl;

    cout << "Direccion MAC Destino:" << endl;
    for(i=0;i<=5;i++)
    {
        palabra[i]=fgetc(archivo);
        //printf ("%02x:",palabra[i]);
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)palabra[i] << ":";
    }
    cout << endl << endl;

    cout << "Direccion MAC Origen:" << endl;
    for(i=6;i<=11;i++)
    {
        palabra[i]=fgetc(archivo);
        //printf ("%02x:",palabra[i]);
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)palabra[i] << ":";
    }
    cout << endl << endl;


    cout << "Tipo de codigo:" << endl;
    for(i=12;i<=13;i++)
    {
        palabra[i]=fgetc(archivo);
        //printf ("%02x:",palabra[i]);
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)palabra[i] << ":";
    }

    // 0800 IPv4
    // 0806 ARP
    // 8035 RARP
    // 86DD IPv6
    
    cout << endl;

    if (palabra[13] == 0)
    {
        cout << "IPv4" << endl;
        IPv4(archivo);
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
    fseek(archivo, 0, SEEK_SET);
    fseek(archivo, 15-sizeof(unsigned char), SEEK_CUR);
    while (!feof(archivo))
    {
        i++;
        palabra[i]=fgetc(archivo);
        //printf ("%02x:",palabra[i]);
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)palabra[i] << ":";
    }

    cout << endl << endl;
    fclose(archivo);
}

#endif