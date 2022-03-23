#ifndef ICMPV6_H
#define ICMPV6_H


void ICMPv6(unsigned char tipo,unsigned char codigo, unsigned char chek1, unsigned char chek2){
int aux;
cout<<endl;
cout<<endl;
cout<<"             <<<<<< ICMPv6 >>>>>>"<<endl;
cout<<"     Tipo: ";

//////////////////////////////////////////////  Tipo y Codigo /////////////////////
 switch(tipo){
    case 1:
        cout<<"Mensaje de destino inalcanzable"<<endl;
        cout<<"Codigo: ";

        if(codigo==0)
        {
                cout<<"No existe ruta de destino"<<endl;
        }
        else if(codigo==1)
        {
                cout<<"Comunicacion con el destino administrativamente prohibida"<<endl;
        }
        else if(codigo==2)
        {
                cout<<"No asignado"<<endl;
        }
        else if(codigo==3)
        {
                cout<<"Direccion inalcanzable"<<endl;
        }

    break;

    case 2:
        cout<<"Mensaje de paquete demasiado grande"<<endl;
    break;

    case 3:
        cout<<"Tiempo de mensaje excedido"<<endl;
        cout<<"Codigo: ";
        if(codigo==0)
        {
                cout<<"El limite de salto excedio"<<endl;
        }
        else if(codigo==1)
        {
                cout<<"Tiempo de reensamble de fragmento excedido"<<endl;
        }

    break;

    case 4:
        cout<<"Mensaje de problema de parametro"<<endl;
        cout<<"Codigo: ";
        if(codigo==0)
        {
                cout<<"Campo erronea en cabecera"<<endl;
        }
        else if(codigo==1)
        {
                cout<<"Tipo de cabecera siguiente desconocida"<<endl;
        }
        else if(codigo==2)
        {
                cout<<"Opcion IPv6 desconocida"<<endl;
        }

    break;

    case 128:
     cout<<"Mensaje del pedido de ECHO"<<endl;

    break;
    case 129:
        cout<<"Mensaje de respuesta de ECHO"<<endl;

    break;
    case 133:
        cout<<"Mensaje de solicitud de router"<<endl;

    break;
    case 134:
        cout<<"Mensaje de anuncio del router"<<endl;

    break;
    case 135:
        cout<<"Mensaje de solicitud vecino"<<endl;

    break;
    case 136:
     cout<<"Mensaje de anuncio de vecino"<<endl;

    break;
    case 137:
     cout<<"Reoriente el mensaje"<<endl;

    break;

    default:
    break;

}

//////////////////////////////   Checksum  ////////////////////////////////
cout<<"     Checksum: ";
aux = ASCII_DEC(chek1,chek2);
cout<<hex<<aux;

}


#endif // ICMPV6_H_INCLUDED
