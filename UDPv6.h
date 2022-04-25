
#ifndef UDPv6_H
#define UDPv6_H
#include <iostream>
#include <iomanip>
#include "Conversiones.h"
#include "DNS.h"
using namespace std;


void UDPv6(FILE *archivo){
    unsigned char datos[10];
    int i,aux,*conv;
    long double auxd;

    fseek(archivo, 0, SEEK_SET);
    fseek(archivo, 55-sizeof(unsigned char), SEEK_CUR);


    while( i<=10)
    {
        datos[i] = fgetc(archivo);
        i++;
    }




   cout<<endl<<endl;

    cout << "       <<<<<<<<<<<<<<<<<<<< UDP >>>>>>>>>>>>>>>>>>>>" << endl<<endl;
    ///////////// PUERTO ORIGEN-DESTINO

    aux=ASCII_DEC(datos[0],datos[1]);
    cout<<"     Puerto origen:  " << aux <<endl;
    if(0<=aux && aux<=1023)
    {
cout << left;
        cout << "       Puertos conocidos: " << endl<<endl;
        cout << setw(15) << "       Puerto";
        cout << setw(10) << "Servicio";
        cout << setw(10) << "Protocolo"<<endl;

        if(aux==20)
        {
            cout << setw(15) << "       20";
            cout << setw(10) << "FTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==21)
        {
            cout << setw(15) << "       21";
            cout << setw(10) << "FTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==22)
        {
            cout << setw(15) << "       22";
            cout << setw(10) << "SSH";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==23)
        {
            cout << setw(15) << "       23";
            cout << setw(10) << "TELNET";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==25)
        {
            cout << setw(15) << "       25";
            cout << setw(10) << "SMTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==53)
        {
            cout << setw(15) << "       53";
            cout << setw(10) << "DNS";
            cout << setw(10) << "TCP/UDP"<<endl;
            DNS(archivo,63);
        }
        else if(aux==67)
        {
            cout << setw(15) << "       67";
            cout << setw(10) << "DHCP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==68)
        {
            cout << setw(15) << "       68";
            cout << setw(10) << "DHCP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==69)
        {
            cout << setw(15) << "       69";
            cout << setw(10) << "TFTP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==80)
        {
            cout << setw(15) << "       80";
            cout << setw(10) << "HTTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==110)
        {
            cout << setw(15) << "       110";
            cout << setw(10) << "POP3";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==143)
        {
            cout << setw(15) << "       143";
            cout << setw(10) << "IMAP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==443)
        {
            cout << setw(15) << "       443";
            cout << setw(10) << "HTTPS";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==993)
        {
            cout << setw(15) << "       993";
            cout << setw(10) << "IMAP SSL";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==995)
        {
            cout << setw(15) << "       995";
            cout << setw(10) << "POP SSL";
            cout << setw(10) << "TCP"<<endl <<endl;
        }
        cout<<endl;
    }


    else if (1024<=aux && aux<=49151)
    {
        cout << "       Puerto registrado" << endl<<endl;
    }

    else if (49152<=aux && aux<=65535)
    {
        cout << "       Puerto dinamico o privado" << endl<<endl;
    }


    ///IF DE SERVICIO Y PROTOCOLO
    aux=ASCII_DEC(datos[2],datos[3]);
    cout<<"     Puerto destino:  "<<aux<<endl;

    if(0<=aux && aux<=1023)
    {
        cout << left;
        cout << "       Puertos conocidos: " << endl<<endl;
        cout << setw(15) << "       Puerto";
        cout << setw(10) << "Servicio";
        cout << setw(10) << "Protocolo"<<endl;

        if(aux==20)
        {
            cout << setw(15) << "       20";
            cout << setw(10) << "FTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==21)
        {
            cout << setw(15) << "       21";
            cout << setw(10) << "FTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==22)
        {
            cout << setw(15) << "       22";
            cout << setw(10) << "SSH";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==23)
        {
            cout << setw(15) << "       23";
            cout << setw(10) << "TELNET";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==25)
        {
            cout << setw(15) << "       25";
            cout << setw(10) << "SMTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==53)
        {
            cout << setw(15) << "       53";
            cout << setw(10) << "DNS";
            cout << setw(10) << "TCP/UDP"<<endl;
            DNS(archivo,63);
        }
        else if(aux==67)
        {
            cout << setw(15) << "       67";
            cout << setw(10) << "DHCP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==68)
        {
            cout << setw(15) << "       68";
            cout << setw(10) << "DHCP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==69)
        {
            cout << setw(15) << "       69";
            cout << setw(10) << "TFTP";
            cout << setw(10) << "UDP"<<endl;
        }
        else if(aux==80)
        {
            cout << setw(15) << "       80";
            cout << setw(10) << "HTTP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==110)
        {
            cout << setw(15) << "       110";
            cout << setw(10) << "POP3";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==143)
        {
            cout << setw(15) << "       143";
            cout << setw(10) << "IMAP";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==443)
        {
            cout << setw(15) << "       443";
            cout << setw(10) << "HTTPS";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==993)
        {
            cout << setw(15) << "       993";
            cout << setw(10) << "IMAP SSL";
            cout << setw(10) << "TCP"<<endl;
        }
        else if(aux==995)
        {
            cout << setw(15) << "       995";
            cout << setw(10) << "POP SSL";
            cout << setw(10) << "TCP"<<endl <<endl;
        }
        cout<<endl;
    }

    else if (1024<=aux && aux<=49151)
    {
        cout << "       Puerto registrado" << endl<<endl;
    }

    else if (49152<=aux && aux<=65535)
    {
        cout << "       Puerto dinamico o privado" << endl<<endl;
    }


    /////////////////////////////////////////////////// lONGITUD TOTAL  /////////////////////////////////
    aux=ASCII_DEC(datos[4],datos[5]);

    cout<<"     Longitud total: "<<aux<<" palabras"<<endl<<endl;

    /////////////////////////////////////////////////// CHECKSUM  /////////////////////////////
    aux=ASCII_DEC(datos[6],datos[7]);
    cout<<"     Suma de verificacion:   ";
    cout << hex << "0x" << aux << endl<<endl;

}

#endif
