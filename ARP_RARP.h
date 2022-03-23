#ifndef ARP_RARP_H_INCLUDED
#define ARP_RARP_H_INCLUDED
#include <iomanip>
#include "Conversiones.h"

using namespace std;

void ARP(FILE *archivo){

    unsigned char datos[70];
    size_t i=0, cont=0;
    int *conv, aux, hard, proto;
    string temp = "";

    cout << endl;
    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cont=i;

    cout << setw(40) << setfill(' ') << "<<< ARP >>>" << endl << endl;

    //////////////////////////////////////////////////////////////////// <<<<<<<< Tipo de hardware >>>>>
    aux= ASCII_DEC(datos[0],datos[1]);

     cout << "       Tipo de hardware: ";
       switch(aux){
        case 1:
            cout<<"Ethernet (10Mb)";
        break;
        case 6:
             cout<<"IEEE 802 Networks";
        break;
        case 7:
             cout<<"ARCNET";
        break;
        case 15:
             cout<<"Frame Relay";
        break;
        case 16:
             cout<<"Asynchrounous Transfer Mode (ATM) ";
        break;
        case 17:
             cout<<"HDLC";
        break;
        case 18:
             cout<<"Fibre Channel";
        break;
        case 19:
             cout<<"Asynchrounous Transfer Mode (ATM)";
        break;
        case 20:
             cout<<"Serial Line";
        break;

        default:
            break;
   }
    cout << endl;

   ////////////////////////////////////////////////////// Tipo de Protocolo
   cout << "       Tipo de Protocolo: ";
   if (datos[3] == 00)
   {
       cout << "IPv4" << endl;
   }

   else if (datos[3] == 06)
   {
       cout << "ARP" << endl;
   }

   else if (datos[3] == 35)
   {
       cout << "RARP" << endl;
   }

   else 
   {
       cout << "IPv6" << endl;
   }

    ///////////////////////////////////////////////////// Longitud direccion hardware
    hard = ASCII_DEC(datos[4]);
    cout << "       Longitud direccon de hardware: " << hard << " Bytes" << endl;


    //////////////////////////////////////////////////// Longitud direccion protocolo
    proto = ASCII_DEC(datos[5]);
    cout << "       Longitud direccon de protocolo: " << proto << " Bytes" << endl;


    ////////////////////////////////////////////////// C�digo de operaci�n
    aux = ASCII_DEC(datos[6], datos[7]);
    cout << "       Codigo de Operacion: ";

    switch (aux)
    {
        case 1:
        cout << "ARP Request";
        break;

        case 2:
        cout << "ARP Reply";
        break;

        case 3:
        cout << "RARP Request";
        break;

        case 4:
        cout << "RARP Reply";
        break;

        default:
        break;
    }
    cout << endl;

    ///////////////////////////////////////////////////////// Direccion hardware del emisor
    cout << "       Direccion MAC Hardware Emisor: ";
    for (i=8; i<8+hard; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i] << ":";
    }
    aux = i;

    /////////////////////////////////////////////////////// Direccion IP del emisor
    cout << endl;
    cout << "       Direccion IP Emisor: ";
    for (i=aux; i<aux+proto; i++)
    {
        cout << dec << (unsigned int)datos[i] << ".";
    }
    aux = i;

    //////////////////////////////////////////////////////////// Direccion hardware del receptor
    cout << endl << "       Direccion MAC Hardware Receptor: ";
    for (i=aux; i<aux+hard; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i] << ":";
    }
    aux = i;

    ////////////////////////////////////////////////////////////// Direccion IP del receptor
    cout << endl;
    cout << "       Direccion IP Receptor: ";
    for (i=aux; i<aux+proto; i++)
    {
        cout << dec << (unsigned int)datos[i] << ".";
    }
    cout << endl << endl;
}

void RARP(FILE *archivo){

    unsigned char datos[70];
    size_t i=0, cont=0;
    int *conv, aux, hard, proto;
    string temp = "";

    cout << endl;
    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cont=i;

    cout << setw(40) << setfill(' ') << "<<< RARP >>>" << endl << endl;

    //////////////////////////////////////////////////////////////////////// <<<<<<<< Tipo de hardware >>>>>
    aux= ASCII_DEC(datos[0],datos[1]);

     cout << "       Tipo de hardware: ";
       switch(aux){
        case 1:
            cout<<"Ethernet (10Mb)";
        break;
        case 6:
             cout<<"IEEE 802 Networks";
        break;
        case 7:
             cout<<"ARCNET";
        break;
        case 15:
             cout<<"Frame Relay";
        break;
        case 16:
             cout<<"Asynchrounous Transfer Mode (ATM) ";
        break;
        case 17:
             cout<<"HDLC";
        break;
        case 18:
             cout<<"Fibre Channel";
        break;
        case 19:
             cout<<"Asynchrounous Transfer Mode (ATM)";
        break;
        case 20:
             cout<<"Serial Line";
        break;

        default:
            break;
   }
    cout << endl;

   // Tipo de Protocolo
   cout << "       Tipo de Protocolo: ";
   if (datos[3] == 00)
   {
       cout << "IPv4" << endl;
   }

   else if (datos[3] == 06)
   {
       cout << "ARP" << endl;
   }

   else if (datos[3] == 35)
   {
       cout << "RARP" << endl;
   }

   else 
   {
       cout << "IPv6" << endl;
   }

    // Longitud direccion hardware
    hard = ASCII_DEC(datos[4]);
    cout << "       Longitud direccon de hardware: " << hard << " Bytes" << endl;

    // Longitud direccion protocolo
    proto = ASCII_DEC(datos[5]);
    cout << "       Longitud direccon de protocolo: " << proto << " Bytes" << endl;

    // C�digo de operaci�n
    aux = ASCII_DEC(datos[6], datos[7]);
    cout << "       Codigo de Operacion: ";

    switch (aux)
    {
    case 1:
        cout << "ARP Request";
        break;
    case 2:
        cout << "ARP Reply";
        break;
    case 3:
        cout << "RARP Request";
        break;
    case 4:
        cout << "RARP Reply";
        break;
    default:
        break;
    }
    cout << endl;

    //Direccion hardware del emisor
    cout << "       Direccion MAC Hardware Emisor: ";
    for (i=8; i<8+hard; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i] << ":";
    }
    aux = i;

    // Direccion IP del emisor
    cout << endl;
    cout << "       Direccion IP Emisor: ";
    for (i=aux; i<aux+proto; i++)
    {
        cout << dec << (unsigned int)datos[i] << ".";
    }
    aux = i;

    // Direccion hardware del receptor
    cout << endl << "       Direccion MAC Hardware Receptor: ";
    for (i=aux; i<aux+hard; i++)
    {
        cout << hex << uppercase << setfill('0') << setw(2) << (unsigned int)datos[i] << ":";
    }
    aux = i;

    // Direccion IP del receptor
    cout << endl;
    cout << "       Direccion IP Receptor: ";
    for (i=aux; i<aux+proto; i++)
    {
        cout << dec << (unsigned int)datos[i] << ".";
    }
    cout << endl;
}


#endif // ARP_RARP_H_INCLUDED
