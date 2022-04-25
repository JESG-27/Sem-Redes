#ifndef DNS_H
#define DNS_H

#include <iostream>
#include <iomanip>
#include "Conversiones.h"


using namespace std;


void DNS(FILE *archivo,int posicion){
    unsigned char datos[70];
    int i,aux,*conv;
    long double auxd;

    fseek(archivo, 0, SEEK_SET);
    fseek(archivo, posicion-sizeof(unsigned char), SEEK_CUR);


    while(!feof(archivo))
    {
        datos[i] = fgetc(archivo);
        i++;
    }
    cout<<endl;


    /// ID

    aux=ASCII_DEC(datos[0],datos[1]);
    cout<<"             ID de transaccion:   ";
    cout << hex << "0x" << aux << endl<<endl;

    ///BANDERAS

    conv = ASCII_BIN(datos[2], datos[3]);

    cout << "             QR: " << conv[0] << "  ";
    if (conv[0]==0)
    {
        cout << "Consulta" << endl << endl;
    }

    else if (conv[0]==1)
    {
        cout << "Respuesta" << endl << endl;
    }

    cout <<"             Op Code: " << conv[0] << "  ";

    if (conv[1]==0 && conv[2]==0 && conv[3]==0 && conv[4]==0)
    {
        cout << "Consulta estandar(QUERY)" << endl << endl;
    }

    else if (conv[1]==0 && conv[2]==0 && conv[3]==0 && conv[4]==1)
    {
        cout << "Consulta inversa(IQUERY)" << endl << endl;
    }

    else if (conv[1]==0 && conv[2]==0 && conv[3]==1 && conv[4]==0)
    {
        cout << "Solicitud del estado del servidor(STATUS)" << endl << endl;
    }


    if (conv[5]==1)
    {
        cout << "             AA: Activo" << endl << endl;
    }

    if (conv[6]==1)
    {
        cout << "             TC: Activo" << endl << endl;
    }

    if (conv[7]==1)
    {
        cout << "             RD: Activo" << endl << endl;
    }

    if (conv[8]==1)
    {
        cout << "             RA: Activo" << endl << endl;
    }
    // 9,10,11 reservados

    cout << "             Rcode: ";
    if (conv[12]==0 && conv[13]==0 && conv[14]==0 && conv[15]==0)
    {
        cout << "Sin errores" << endl << endl;
    }

    else if (conv[12]==0 && conv[13]==0 && conv[14]==0 && conv[15]==1)
    {
        cout << "Error de Formato" << endl << endl;
    }

    else if (conv[12]==0 && conv[13]==0 && conv[14]==2 && conv[15]==0)
    {
        cout << "Fallo en el servidor" << endl << endl;
    }

    else if (conv[12]==0 && conv[13]==0 && conv[14]==1 && conv[15]==1)
    {
        cout << "Error en nombre" << endl << endl;
    }

    else if (conv[12]==0 && conv[13]==1 && conv[14]==0 && conv[15]==0)
    {
        cout << "No implementado" << endl << endl;
    }

    else if (conv[12]==0 && conv[13]==1 && conv[14]==0 && conv[15]==1)
    {
        cout << "Rechazado" << endl << endl;
    }

    // Contadores

    // QDcount
    int QD = ASCII_DEC(datos[4], datos[5]);
    cout << "             Questions: " << dec << QD << endl << endl;


    // ANcount
    int AN = ASCII_DEC(datos[6], datos[7]);
    cout << "             Answers: " << dec << AN << endl << endl;

    // NScount
    int NS = ASCII_DEC(datos[8], datos[9]);
    cout << "             Authorities: " << dec << NS << endl << endl;

    // ARcount
    int AR = ASCII_DEC(datos[10], datos[11]);
    cout << "             Additionals: " << dec << AR << endl << endl;

    // Question
    int pos=12;
    cout << "             ";

    for (size_t j=0; j<QD; j++)
    {
        while(true)
        {
            aux = ASCII_DEC(datos[pos]);

            if (aux==0)
            {
                break;
            }

            int tam = aux;
            pos++;

            for (i=0; i<tam; i++)
            {
                cout << datos[pos];
                pos++;
            }

            aux = ASCII_DEC(datos[pos]);
            if (aux!=0)
            {
                cout << ".";
            }
        }

        // Tipo
        cout << endl;
        aux = ASCII_DEC(datos[pos+1], datos[pos+2]);
        cout << "             Tipo: ";
        switch (aux)
        {
            case 1: cout << "A";
            break;

            case 5: cout << "CNAME";
            break;

            case 13: cout << "HINFO";
            break;

            case 15: cout << "MX";
            break;

            case 22: cout << "NS";
            break;

            case 23: cout << "NS";
            break;

            default: break;
        }
        cout << endl;
        //printf ("%02x:",datos[29]);

        /// Clase
        aux = ASCII_DEC(datos[pos+3], datos[pos+4]);
        cout << "             Clase: ";
        switch (aux)
        {
            case 1: cout << "IN";
            break;

            case 3: cout << "CH";
            break;

            default: break;
        }

        cout << endl;
        pos=pos+4;
    }
    pos++;

    // Answer
    for (size_t j=0; j<AN; j++)
    {
        aux = ASCII_DEC(datos[pos], datos[pos+1]);
        int puntero = (aux-posicion);
        cout << "Puntero:" << puntero << endl;

        // Puntero
        while(true)
        {
            aux = ASCII_DEC(datos[puntero]);

            if (aux==0 || aux==192) // El archivo contiene un error de la longitud
            {
                break;
            }

            int tam = aux;
            puntero++;

            for (i=0; i<tam; i++)
            {
                cout << datos[puntero];
                puntero++;
            }

            aux = ASCII_DEC(datos[puntero]);
            if (aux!=0)
            {
                cout << ".";
            }
        }

        // Tipo
        cout << endl;
        aux = ASCII_DEC(datos[pos+2], datos[pos+3]);
        cout << "             Tipo: ";
        int tipo = aux;
        switch (aux)
        {
            case 1: cout << "A";
            break;

            case 5: cout << "CNAME";
            break;

            case 13: cout << "HINFO";
            break;

            case 15: cout << "MX";
            break;

            case 22: cout << "NS";
            break;

            case 23: cout << "NS";
            break;

            default: break;
        }
        cout << endl;

        /// Clase
        aux = ASCII_DEC(datos[pos+4], datos[pos+5]);
        cout << "             Clase: ";
        switch (aux)
        {
            case 1: cout << "IN";
            break;

            case 3: cout << "CH";
            break;

            default: break;
        }

        cout << endl;

        // TTL
        aux = ASCII_DEC(datos[pos+6], datos[pos+7], datos[pos+8], datos[pos+9]);
        cout << "Tiempo de Vida: " << dec << aux << " seg" << endl;

        // Longitud de Datos
        aux = ASCII_DEC(datos[pos+10], datos[pos+11]);
        cout << "Longitud de Datos: " << dec << aux << endl;
        int lgd = 0;
        lgd=aux;
        pos=pos+12;

        switch(tipo)
        {
            case 1:
                for (i=1; i<=lgd; i++)
                {
                    aux = ASCII_DEC(datos[pos+i]);
                    cout << dec << aux;
                    if (i!=lgd)
                    {
                        cout << ".";
                    }
                }
            break;

            case 5:
                for (i=1; i<=lgd; i++)
                {
                    cout << datos[pos+i];
                }
            break;

            case 13: cout << "HINFO";
            break;

            case 15: cout << "MX";
            break;

            case 22: cout << "NS";
            break;

            case 23: cout << "NS";
            break;

            default: break;
        }
        pos=pos+lgd;
        //cout << dec << pos;
        cout << endl;
    }

}
#endif
