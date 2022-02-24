#ifndef ICMPV4_H
#define ICMPV4_H
#include <iostream>
#include <stdio.h>

using namespace std;


void ICMPv4(unsigned char tipo,unsigned char codigo){
     cout<<endl;
    cout<<"             <<<<<<< ICMPv4 >>>>>>>"<<endl;

    cout<<"     Tipo de mensaje: ";
   switch(tipo){
        case 0:
            cout<<"Echo Reply (respuesta de eco)";
        break;
        case 3:
             cout<<"Destination Unreacheable (destino inaccesible)";
        break;
        case 4:
             cout<<"Source Quench (disminución del tráfico desde el origen)";
        break;
        case 5:
             cout<<"Redirect (redireccionar - cambio de ruta)";
        break;
        case 8:
             cout<<"Echo (solicitud de eco) ";
        break;
        case 11:
             cout<<"Time Exceeded (tiempo excedido para un datagrama)";
        break;
        case 12:
             cout<<"Parameter Problem (problema de parámetros)";
        break;
        case 13:
             cout<<"Timestamp (solicitud de marca de tiempo)";
        break;
        case 14:
             cout<<"Timestamp Reply (respuesta de marca de tiempo) ";
        break;
        case 15:
             cout<<"Information Request (solicitud de información) - obsoleto- ";
        break;
        case 16:
             cout<<"Information Reply (respuesta de información) - obsoleto- ";
        break;
        case 17:
             cout<<"Addressmask (solicitud de máscara de dirección)";
        break;
        case 18:
             cout<<"Addressmask Reply (respuesta de máscara de dirección";
        break;

        default:
            break;
   }
   cout<<endl;

 cout<<"     Codigo de error: ";
   switch(codigo){
        case 0:
            cout<<"No se puede llegar a la red ";
        break;
        case 1:
             cout<<"No se puede llegar al host o aplicación de destino";
        break;
        case 2:
             cout<<"El destino no dispone del protocolo solicitado ";
        break;
        case 3:
             cout<<"No se puede llegar al puerto destino o la aplicación destino no está libre ";
        break;
        case 4:
             cout<<"Se necesita aplicar fragmentación, pero el flag correspondiente indica lo contrario ";
        break;
        case 5:
             cout<<"La ruta de origen no es correcta ";
        break;
        case 6:
             cout<<"No se conoce la red destino ";
        break;
        case 7:
             cout<<"No se conoce el host destino ";
        break;
        case 8:
             cout<<"El host origen está aislado";
        break;
        case 9:
             cout<<"La comunicación con la red destino está prohibida por razones administrativas ";
        break;
        case 10:
             cout<<"La comunicación con el host destino está prohibida por razones administrativas ";
        break;
        case 11:
             cout<<"No se puede llegar a la red destino debido al Tipo de servicio";
        break;
        case 12:
             cout<<"No se puede llegar al host destino debido al Tipo de servicio ";
        break;

        default:
            break;
   }
   cout<<endl;









}





#endif // ICMPV4_H
