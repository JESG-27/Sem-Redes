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
    
    cout << "Version: ";
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
    cout << "Tamano: ";
    for (i=4; i<=7; i++)
    {
        cout << conv[i];
    }
    int tam = ASCII_DEC(datos[0], 4);
    cout << dec << " " << tam;
    cout << endl;

    ///////////////////////////////////////////////////// Tipo de Servicio ///
    conv = ASCII_BIN(datos[1]);

    cout << "Desglose de Bits: ";
    if (conv[0]==0 && conv[1]==0 && conv[2]==0) //000
    {
        cout << "De rutina" << endl;
    }

    else if (conv[0]==0 && conv[1]==0 && conv[2]==1) //001
    {
        cout << "Prioritario" << endl;
    }

    else if (conv[0]==0 && conv[1]==1 && conv[2]==0) //010
    {
        cout << "Inmediato" << endl;
    }

    else if (conv[0]==0 && conv[1]==1 && conv[2]==1) //011
    {
        cout << "Relampago" << endl;
    }

    else if (conv[0]==1 && conv[1]==0 && conv[2]==0) // 100
    {
        cout << "Invalidacion Relampago" << endl;
    }

    else if (conv[0]==1 && conv[1]==0 && conv[2]==1) //101
    {
        cout << "Proceso de llamada critica y de emergencia" << endl;
    }

    else if (conv[0]==1 && conv[1]==1 && conv[2]==0) //110
    {
        cout << "Control de trabajo de internet" << endl;
    }

    else if (conv[0]==1 && conv[1]==1 && conv[2]==1) //111
    {
        cout << "Control de red" << endl;
    }


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
    cout << endl;

    //////////////////////////////////////////// Longitud Total //
    conv = ASCII_BIN(datos[2], datos[3]);

    cout << "Longitud Total: ";
    for (i=0; i<16; i++)
    {
        cout << conv[i];
    }
    cout << " ";
    int longitud = ASCII_DEC(datos[2], datos[3]);
    cout << dec << longitud << endl;

    ////////////////////////////////////////// Identificador ///
    conv = ASCII_BIN(datos[4], datos[5]);

    cout << "Identificador: ";
    for (i=0; i<16; i++)
    {
        cout << conv[i];
    }
    cout << " ";
    longitud = ASCII_DEC(datos[4], datos[5]);
    cout << longitud << endl;

    ////////////////////////////////////////////// Flags ///
    conv = ASCII_BIN(datos[6]);

    cout << "Flags: ";
    for (i=0; i<=2; i++)
    {
        cout << conv[i];
    }
    cout << endl;

    ////////////////////////// Posición de Fragmento //
    conv = ASCII_BIN(datos[6], datos[7]);

    cout << "Posicio de Fragmento: ";
    for (i=3; i<16; i++)
    {
        cout << conv[i];
    }
    cout << endl;

    ///////////////////////////////////////// Tiempo de Vida ///
    conv = ASCII_BIN(datos[8]);

    cout << "Tiempo de Vida: ";
    for (i=0; i<8; i++)
    {
        cout << conv[i];
    }
    cout << " ";
    int num = ASCII_DEC(datos[8]);
    cout << dec << num;
    cout << endl;

    //////////////////////////////////////// Protocolo ////
    conv = ASCII_BIN(datos[9]);

    cout << "Protocolo: ";
    for (i=0; i<8; i++)
    {
        cout << conv[i];
    }
    cout << endl;

    /////////////////////////////////// Headchecksum  //////
    conv = ASCII_BIN(datos[10], datos[11]);

    cout << "Headchecksum: ";
    for (i=0; i<16; i++)
    {
        cout << conv[i];
    }
    cout << endl;

    ////////////////////////////////// IP Origen /////



    ////////////////////////////////// IP Destino /////

}

#endif
