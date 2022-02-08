#ifndef IPV4_H
#define IPV4_H
#include <iostream>
#include "Conversiones.h"
using namespace std;

void IPv4(FILE *archivo)
{
    unsigned char datos[70];
    size_t i=0, cont=0;
    int *conv;
    string temp = "";

    cout << endl;
    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cont=i;
    
    //////////////////////////////////////////////////////// VERSION //  Primer Byte primeros 4 bits 
    // IPv4 0100
    // IPv6 0110

    conv = ASCII_BIN(datos[0]);
    if (conv[2]==0)
    {
        for (i=0; i<4; i++)
        {
            cout << conv[i];
        }
        cout << " = IPv4" << endl;
    }

    else if(conv[2] == 1)
    {
        for (i=0; i<4; i++)
        {
            cout << conv[i];
        }
        cout << " = IPv6" << endl;
    }

    ///////////////////////////////////////////////////// Tamaño /////
    
    ///////////////////////////////////////////////////// Tipo de Servicio ///
    conv = ASCII_BIN(datos[1]);

    cout << "Desglose de Bits: ";
    if (conv[0]==0 && conv[1]==0 && conv[2]==0)
    {
        cout << "De rutina" << endl;
    }
    // Agregar demás casos de 4 bits

    cout << "Retardo: ";
    if (conv[3]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[3]==1)
    {
        cout << "Bajo" << endl;
    }

    cout << "Rendimiento: ";
    if (conv[4]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[4]==1)
    {
        cout << "Alto" << endl;
    }

    cout << "Fiabilidad: ";
    if (conv[4]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[4]==1)
    {
        cout << "Alta" << endl;
    }

    //////////////////////////////////////////// Longitud Total //
    conv = ASCII_BIN(datos[2], datos[3]);

    cout << "Longitud Total: ";
    for (i=0; i<16; i++)
    {
        cout << conv[i];
    }
    

}

#endif