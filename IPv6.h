#ifndef IPV6_H
#define IPV6_H
#include <iostream>
#include <iomanip>
#include "Conversiones.h"
#include "Icmpv6.h"
#include "TCPv6.h"
#include "UDPv6.h"

using namespace std;

void IPv6(FILE *archivo)
{
    unsigned char datos[70];
    size_t i=0, cont=0;
    int *conv, aux;
    char arreglo[20];
    string temp = "";

    cout << endl;
    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cont=i;

    cout << setw(40) << setfill(' ') << "<<< IPv6 >>>" << endl << endl;

    //////////////////////////////////////////////////////// VERSION //  Primer Byte primeros 4 bits
    conv = ASCII_BIN(datos[0]);

    cout << "Version: " << setfill(' ') << setw(21);
    if (conv[2]==0)
    {
        cout << "IPv4" << endl << endl;
    }

    else if(conv[2] == 1)
    {
        cout << "IPv6" << endl << endl;
    }

    //////////////////////////////////////////////// Clase de Trafico ///////////// primeros 2 Bytes posici�n 4-11
    conv = ASCII_BIN(datos[0], datos[1]);

    cout << "Prioridad: " << setfill(' ') << setw(19);

    if (conv[4]==0 && conv[5]==0 && conv[6]==0) //000
    {
        cout << "De rutina" << endl;
    }

    else if (conv[4]==0 && conv[5]==0 && conv[6]==1) //001
    {
        cout  << "Prioritario" << endl;
    }

    else if (conv[4]==0 && conv[5]==1 && conv[6]==0) //010
    {
        cout << "Inmediato" << endl;
    }

    else if (conv[4]==0 && conv[5]==1 && conv[6]==1) //011
    {
        cout << "Relampago" << endl;
    }

    else if (conv[4]==1 && conv[5]==0 && conv[6]==0) // 100
    {
        cout << "Invalidacion Relampago" << endl;
    }

    else if (conv[4]==1 && conv[5]==0 && conv[6]==1) //101
    {
        cout << "Proceso de llamada critica y de emergencia" << endl;
    }

    else if (conv[4]==1 && conv[5]==1 && conv[6]==0) //110
    {
        cout << "Control de trabajo de internet" << endl;
    }

    else if (conv[4]==1 && conv[5]==1 && conv[6]==1) //111
    {
        cout << "Control de red" << endl;
    }
    cout << endl;

    conv = ASCII_BIN(datos[0], datos[1]);
    cout << "Retardo: " << setfill(' ') << setw(21);
    if (conv[7]==0)
    {
        cout  << "Normal" << endl;
    }
    else if (conv[7]==1)
    {
        cout << "Bajo" << endl;
    }
    cout << endl;

    cout << "Rendimiento: " << setfill(' ') << setw(17);
    if (conv[8]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[8]==1)
    {
        cout << "Alto" << endl;
    }
    cout << endl;

    cout << "Fiabilidad: " << setfill(' ') << setw(18);
    if (conv[9]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[9]==1)
    {
        cout << "Alta" << endl;
    }
    cout << endl;


    ///////////////////////////////////////////////////// Etiqueta de Flujo Byte 2, 3, 4 iniciando Byte 2 bit 5
    conv = ASCII_BIN(datos[1]);

    for (i=4; i<8; i++)
    {
        arreglo[i-4]=conv[i];
    }

    conv = ASCII_BIN(datos[2], datos[3]);
    for (i=0; i<16; i++)
    {
        arreglo[i+4]=conv[i];
    }

    aux = BIN_DEC(arreglo);
    cout << "Etiqueta: " << setfill(' ') << setw(18)<< dec << aux << endl << endl;

    ///////////////////////////////////////////////////// Tamaño de Datos ////////////////////
    cout << "Longitud Total: " << setfill(' ') << setw(10) ;
    aux = ASCII_DEC(datos[4], datos[5]);
    cout << dec << aux << " Bytes" << endl << endl;

    //////////////////////////////////////////////////// Encabezado Siguiente ////////////////////
    cout << "Encabezado siguiente: " << setfill(' ') << setw(10);
    aux = ASCII_DEC(datos[6]);
    switch (aux)
    {
    case 1:
        cout << "ICMPv4" << endl;

        break;
    case 6:
        cout << "TCP";
        TCPv6(archivo);

        break;
    case 17:
        cout << "UDP";
        UDPv6(archivo);
        break;
    case 58:
        cout << "ICMPv6";

        ICMPv6(datos[40],datos[41],datos[42],datos[43]);

        break;
    case 118:
        cout << "STP";
        break;
    case 121:
        cout << "SMP";
        break;

    default:
        break;
    }
    cout << endl << endl;

    ///////////////////// Limite de Salto ////////

    cout << "Tiempo de Vida: " << setfill(' ') << setw(14);
    aux = ASCII_DEC(datos[7]);
    cout << dec << aux << " Saltos" << endl << endl;

    //////// Direcciones IPv6 ///////////
    //// Origen ////

    cout << "Direccion de origen : " << setfill(' ') << setw(14);
    for (i=8; i<24; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i];
        if (i%2!=0 && i!=23)
        {
            cout << ":";
        }
    }

    cout<<endl<<endl;

    cout << "Direccion de destino : " << setfill(' ') << setw(14);
    for (i=24; i<40; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i];
        if (i%2!=0 && i!=39)
        {
            cout << ":";
        }
    }
    cout<<endl;
}

#endif