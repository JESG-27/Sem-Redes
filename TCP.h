#ifndef TCP_H
#define TCP_H
#include <iostream>
#include <iomanip>
#include "Conversiones.h"


using namespace std;


void TCP(FILE *archivo){
    unsigned char datos[70];
    int i,aux,*conv;
    long double auxd;

    fseek(archivo, 0, SEEK_SET);
    fseek(archivo, 35-sizeof(unsigned char), SEEK_CUR);


    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }

    cout<<endl<<endl;

    cout << "                               <<<<< TCP >>>>>" << endl;
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

    /////////////////////////////////////////////  IF DE SERVICIO Y PROTOCOLO  /////////////////////////////////////
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


    ////////////////////////////////////////////////  Número de secuencia  //////////////////////////////
    cout<<"     Numero de secuencia: "<<"(";
    auxd=ASCII_DEC(datos[4],datos[5],datos[6],datos[7]);
    cout<<") = "<<auxd<<endl<<endl;

    //////////////////////////////////////////////////  Número de acuse de recibo //////////////////////////
    cout<<"     Numero de acuse de recibo: "<<"(";
    auxd=ASCII_DEC(datos[8],datos[9],datos[10],datos[11]);
    cout<<") = "<<auxd<<endl<<endl;


     ///////////////////////////////////////////////// lONGITUD DE CABECERA  ///////////////////////////////
     aux=ASCII_DEC2(datos[12],0,3);

     cout<<"     Longitud de cabecera: "<<aux<<" palabras"<<endl<<endl;


    ///////////////////////////////////////////////////// RESERVADO  ///////////////////////////////////
    aux=ASCII_DEC2(datos[12],4,6);
    cout<<"     Reservado: "<<aux<<endl<<endl;


    /////////////////////////////////////////////////// BANDERAS ///////////////////////////////
    conv=ASCII_BIN(datos[12]);

    if(conv[7]==1)
    {
        cout<<"     NS: ACTIVO "<<endl<<endl;
    }
    conv=ASCII_BIN(datos[13]);

    if(conv[0]==1)
    {
        cout<<"     CWR: ACTIVO "<<endl<<endl;
    }
    else if(conv[1]==1)
    {
        cout<<"     ECE: ACTIVO"<<endl<<endl;
    }
    else if(conv[2]==1)
    {
        cout<<"     URG: ACTIVO "<<endl<<endl;
    }
    else if(conv[3]==1)
    {
        cout<<"     ACK: ACTIVO "<<endl<<endl;
    }
    else if(conv[4]==1)
    {
        cout<<"     PSH: ACTIVO "<<endl<<endl;
    }
    else if(conv[5]==1)
    {
        cout<<"     RST: ACTIVO "<<endl<<endl;
    }
    else if(conv[6]==1)
    {
        cout<<"     SYN: ACTIVO "<<endl<<endl;
    }
    else if(conv[7]==1)
    {
        cout<<"     FIN: ACTIVO "<<endl<<endl;
    }


    ///////////////////////////////////////////////   Tamano de ventana o ventana de recepcion  /////////////////////////////////
    aux=ASCII_DEC(datos[14],datos[15]);
    cout<<"     Tamano de ventana o ventana de recepcion:  "<< aux<<endl<<endl;

    //////////////////////////////////////////////////////   CHECKSUM  /////////////////////////////
    aux=ASCII_DEC(datos[16],datos[17]);
    cout<<"     Suma de verificacion:   ";
    cout << hex << "0x" << aux << endl<<endl;

    //////////////////////////////////////  Puntero urgente //////////////////////////
    aux=ASCII_DEC(datos[18],datos[19]);
    cout<<"     Puntero urgente:  "<< aux<<endl<<endl;

}

#endif
