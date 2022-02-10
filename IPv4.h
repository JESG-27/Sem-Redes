#ifndef IPV4_H
#define IPV4_H
#include <iostream>
#include <iomanip>
#include "Conversiones.h"
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

    //////////////////////////////////////////////////////// VERSION //  Primer Byte primeros 4 bits
    conv = ASCII_BIN(datos[0]);
    
    cout << "Version: ";
    if (conv[2]==0)
    {
        /*for (i=0; i<4; i++)
        {
            cout << conv[i];
        }*/
        cout << setfill(' ') << setw(21) << "IPv4" << endl << endl;
    }

    else if(conv[2] == 1)
    {
        /*for (i=0; i<4; i++)
        {
            cout << conv[i];
        }*/
        cout << setfill(' ') << setw(21) << "IPv6" << endl << endl;
    }

    ///////////////////////////////////////////////////// Tamaño /////
    cout << "Tamano: ";
    /*for (i=4; i<=7; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[0], 4, 7);
    cout << setfill(' ') << setw(22) << dec << aux << endl << endl;

    ///////////////////////////////////////////////////// Tipo de Servicio ///
    conv = ASCII_BIN(datos[1]);

    cout << "Desglose de Bits: ";
    if (conv[0]==0 && conv[1]==0 && conv[2]==0) //000
    {
        cout << setfill(' ') << setw(12) << "De rutina" << endl;
    }

    else if (conv[0]==0 && conv[1]==0 && conv[2]==1) //001
    {
        cout  << setfill(' ') << setw(12)<< "Prioritario" << endl;
    }

    else if (conv[0]==0 && conv[1]==1 && conv[2]==0) //010
    {
        cout << setfill(' ') << setw(12) << "Inmediato" << endl;
    }

    else if (conv[0]==0 && conv[1]==1 && conv[2]==1) //011
    {
        cout << setfill(' ') << setw(12) << "Relampago" << endl;
    }

    else if (conv[0]==1 && conv[1]==0 && conv[2]==0) // 100
    {
        cout << setfill(' ') << setw(12) << "Invalidacion Relampago" << endl;
    }

    else if (conv[0]==1 && conv[1]==0 && conv[2]==1) //101
    {
        cout << setfill(' ') << setw(12) << "Proceso de llamada critica y de emergencia" << endl;
    }

    else if (conv[0]==1 && conv[1]==1 && conv[2]==0) //110
    {
        cout << setfill(' ') << setw(12) << "Control de trabajo de internet" << endl;
    }

    else if (conv[0]==1 && conv[1]==1 && conv[2]==1) //111
    {
        cout << setfill(' ') << setw(12) << "Control de red" << endl;
    }
    cout << endl;

    cout << "Retardo: ";
    if (conv[3]==0)
    {
        cout << setfill(' ') << setw(21) << "Normal" << endl;
    }
    else if (conv[3]==1)
    {
        cout << setfill(' ') << setw(21) << "Bajo" << endl;
    }
    cout << endl;

    cout << "Rendimiento: ";
    if (conv[4]==0)
    {
        cout << setfill(' ') << setw(17) << "Normal" << endl;
    }
    else if (conv[4]==1)
    {
        cout << setfill(' ') << setw(17) << "Alto" << endl;
    }
    cout << endl;

    cout << "Fiabilidad: ";
    if (conv[4]==0)
    {
        cout << setfill(' ') << setw(18) << "Normal" << endl;
    }
    else if (conv[4]==1)
    {
        cout << setfill(' ') << setw(18) << "Alta" << endl;
    }
    cout << endl;

    //////////////////////////////////////////// Longitud Total //
    conv = ASCII_BIN(datos[2], datos[3]);

    cout << "Longitud Total: ";
    /*for (i=0; i<16; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[2], datos[3]);
    cout << setfill(' ') << setw(14) << dec << aux << endl << endl;

    ////////////////////////////////////////// Identificador ///
    conv = ASCII_BIN(datos[4], datos[5]);

    cout << "Identificador: ";
    /*for (i=0; i<16; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[4], datos[5]);
    cout << setfill(' ') << setw(15) << dec << aux << endl << endl;

    ////////////////////////////////////////////// Flags ///
    conv = ASCII_BIN(datos[6]);

    cout << "Flags: ";
    for (i=0; i<=2; i++)
    {
        //cout << conv[i];
        if (i==1)
        {
            if (conv[i]==0)
            {
                cout << setfill(' ') << setw(23) << "Divisible" << " - ";
            }
            else
            {
                cout << setfill(' ') << setw(23) << "No divisible (DF)" << " - ";
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

    cout << "Posicion de Fragmento: ";
    /*for (i=3; i<16; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[6], datos[7], 3, 15);
    cout << setfill(' ') << setw(7) << dec << aux << endl << endl;

    ///////////////////////////////////////// Tiempo de Vida ///
    conv = ASCII_BIN(datos[8]);

    cout << "Tiempo de Vida: ";
    /*for (i=0; i<8; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[8]);
    cout << setfill(' ') << setw(14) << dec << aux << endl << endl;

    //////////////////////////////////////// Protocolo ////
    conv = ASCII_BIN(datos[9]);

    cout << "Protocolo: ";
    /*for (i=0; i<8; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[9]);
    switch (aux)
    {
    case 1:
        cout << setfill(' ') << setw(19) << "ICMPv4";
        break;
    case 6:
        cout << setfill(' ') << setw(19) << "TCP";
        break;
    case 17:
        cout << setfill(' ') << setw(19) << "UDP";
        break;
    case 58:
        cout << setfill(' ') << setw(19) << "ICMPv6";
        break;
    case 118:
        cout << setfill(' ') << setw(19) << "STP";
        break;
    case 121:
        cout << setfill(' ') << setw(19) << "SMP";
        break;
    
    default:
        break;
    }
    cout << endl << endl;

    /////////////////////////////////// Head checksum  //////
    conv = ASCII_BIN(datos[10], datos[11]);

    cout << "Checksum: ";
    /*for (i=0; i<16; i++)
    {
        cout << conv[i];
    }*/
    aux = ASCII_DEC(datos[10], datos[11]);
    cout << setfill(' ') << setw(19) << hex << "0x" << aux << endl << endl;
    

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
