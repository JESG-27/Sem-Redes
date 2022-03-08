#ifndef IPV4_H
#define IPV4_H
#include <iostream>
#include <iomanip>
#include "Conversiones.h"
#include "Icmpv4.h"
using namespace std;

void IPv4(FILE *archivo)
{
    unsigned char datos[70];
    size_t i=0, cont=0;
    int *conv, aux;
    string temp = "";

    cout << endl;
    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cont=i;

    cout << setw(40) << setfill(' ') << "<<< IPv4 >>>" << endl << endl;
    //////////////////////////////////////////////////////// VERSION //  Primer Byte primeros 4 bits
    conv = ASCII_BIN(datos[0]);

    cout << "Version: " << setfill(' ') << setw(21);
    if (conv[2]==0)
    {
        /*for (i=0; i<4; i++)
        {
            cout << conv[i];
        }*/
        cout << "IPv4" << endl << endl;
    }

    else if(conv[2] == 1)
    {
        /*for (i=0; i<4; i++)
        {
            cout << conv[i];
        }*/
        cout << "IPv6" << endl << endl;
    }

    ///////////////////////////////////////////////////// Tamaño /////
    cout << "Tamano: " << setfill(' ') << setw(22);
    /*for (i=4; i<=7; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[0], 4, 7);
    cout << dec << aux << " palabras" << endl << endl;

    ///////////////////////////////////////////////////// Tipo de Servicio ///
    conv = ASCII_BIN(datos[1]);

    cout << "Prioridad: " << setfill(' ') << setw(19);
    if (conv[0]==0 && conv[1]==0 && conv[2]==0) //000
    {
        cout << "De rutina" << endl;
    }

    else if (conv[0]==0 && conv[1]==0 && conv[2]==1) //001
    {
        cout  << "Prioritario" << endl;
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
    cout << endl;

    cout << "Retardo: " << setfill(' ') << setw(21);
    if (conv[3]==0)
    {
        cout  << "Normal" << endl;
    }
    else if (conv[3]==1)
    {
        cout << "Bajo" << endl;
    }
    cout << endl;

    cout << "Rendimiento: " << setfill(' ') << setw(17);
    if (conv[4]==0)
    {
        cout << "Normal" << endl;
    }
    else if (conv[4]==1)
    {
        cout << "Alto" << endl;
    }
    cout << endl;

    cout << "Fiabilidad: " << setfill(' ') << setw(18);
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


    cout << "Longitud Total: " << setfill(' ') << setw(14) ;
    aux = ASCII_DEC(datos[2], datos[3]);
    cout << dec << aux << " Bytes" << endl << endl;

    ////////////////////////////////////////// Identificador ///

    cout << "Identificador: "<< setfill(' ') << setw(15) ;
    aux = ASCII_DEC(datos[4], datos[5]);
    cout << dec << aux << endl << endl;

    ////////////////////////////////////////////// Flags ///
    conv = ASCII_BIN(datos[6]);

    cout << "Flags: " << setfill(' ') << setw(23);
    for (i=0; i<=2; i++)
    {
        //cout << conv[i];
        if (i==1)
        {
            if (conv[i]==0)
            {
                cout << "Divisible" << " - ";
            }
            else
            {
                cout << "No divisible (DF)" << " - ";
            }
        }

        else if (i==2)
        {
            if (conv[i]==0)
            {
                cout << "Ultimo fragmento";
            }
            else
            {
                cout << "Fragmento intermedio";
            }
        }
    }
    cout << endl << endl;

    ////////////////////////// Posición de Fragmento //
    conv = ASCII_BIN(datos[6], datos[7]);

    cout << "Posicion de Fragmento: " << setfill(' ') << setw(7);
    /*for (i=3; i<16; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[6], datos[7], 3, 15);
    cout << dec << aux << endl << endl;

    ///////////////////////////////////////// Tiempo de Vida ///

    cout << "Tiempo de Vida: " << setfill(' ') << setw(14);
    aux = ASCII_DEC(datos[8]);
    cout << dec << aux << endl << endl;

    //////////////////////////////////////// Protocolo ////

    cout << "Protocolo: " << setfill(' ') << setw(19);
    aux = ASCII_DEC(datos[9]);
    switch (aux)
    {
    case 1:
        cout << "ICMPv4"<<endl;


        ICMPv4(datos[20],datos[21]);
        cout << "     Checksum: ";
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[22];
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[23]<<endl;
////////        //checksum


        break;
    case 6:
        cout << "TCP";
        break;
    case 17:
        cout << "UDP";
        break;
    case 58:
        cout << "ICMPv6";
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

    /////////////////////////////////// Head checksum  //////
    conv = ASCII_BIN(datos[10], datos[11]);

    cout << "Checksum: " << setfill(' ') << setw(19);

    aux = ASCII_DEC(datos[10], datos[11]);
    cout << hex << "0x" << aux << endl << endl;


    ////////////////////////////////// IP Origen /////
    cout << "IP Origen: ";
    cout << setfill(' ') << setw(19);
    for (i=12; i<=15; i++)
    {
        aux = ASCII_DEC(datos[i]);
        cout << dec << aux;
        if (i!=15)
        {
            cout << ".";
        }
    }
    cout << endl << endl;

    ////////////////////////////////// IP Destino /////
    cout << "IP Destino: ";
    cout << setfill(' ') << setw(18);
    for (i=16; i<=19; i++)
    {
        aux = ASCII_DEC(datos[i]);
        cout << dec << aux;
        if (i!=19)
        {
            cout << ".";
        }
    }
    cout << endl;
}

#endif
