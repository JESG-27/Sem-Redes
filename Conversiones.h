#ifndef CONVERSIONES_H
#define CONVERSIONES_H
#include <iostream>
#include <cmath>

using namespace std;

int decimal=0;

int *ASCII_BIN(unsigned char entrada)
{
    int i;
    int m[8], top, bottom;
    static int conv[8];

    for(i=0;i<8;i++)
    {
        m[i]=entrada%2;
        entrada = entrada/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom] = m[top];
    }

    return conv;
}

int *ASCII_BIN(unsigned char entrada, unsigned char entrada2)
{
    size_t i;
    int m[8], top, bottom;
    static int conv[16];
    static int prt1[8];
    static int prt2[8];

    for(i=0;i<8;i++)
    {
        m[i]=entrada%2;
        entrada = entrada/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        prt1[bottom] = m[top];
        conv[bottom]=prt1[bottom];
    }

    for(i=0;i<8;i++)
    {
        m[i]=entrada2%2;
        entrada2 = entrada2/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        prt2[bottom] = m[top];
        conv[bottom+8]=prt2[bottom];
    }

    return conv;
}

int ASCII_DEC(unsigned char entrada)
{
    size_t i;
    int m[8], conv[8], top, bottom, decimal=0;

    for(i=0;i<8;i++)
    {
        m[i]=entrada%2;
        entrada = entrada/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom] = m[top];
    }

    for (i=0;i<8;i++)
    {
        switch (i)
        {
        case 0:
            if (conv[i]==1)
            {
                decimal=decimal+128;
            }
        break;

        case 1:
            if (conv[i]==1)
            {
                decimal=decimal+64;
            }
        break;

        case 2:
            if (conv[i]==1)
            {
                decimal=decimal+32;
            }
        break;

        case 3:
            if (conv[i]==1)
            {
                decimal=decimal+16;
            }
        break;

        case 4:
            if (conv[i]==1)
            {
                decimal=decimal+8;
            }
        break;

        case 5:
            if (conv[i]==1)
            {
                decimal=decimal+4;
            }
        break;

        case 6:
            if (conv[i]==1)
            {
                decimal=decimal+2;
            }
        break;

        case 7:
            if (conv[i]==1)
            {
                decimal=decimal+1;
            }
        break;

        default:break;
        }
    }
    return decimal;
}

int ASCII_DEC(unsigned char entrada, int inicio, int final)
{
    size_t i;
    int m[8], conv[8], top, bottom, decimal=0;
    //int conv[8];

    for(i=0;i<8;i++)
    {
        m[i]=entrada%2;
        entrada = entrada/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom] = m[top];
    }

    for (i=inicio;i<=final;i++)
    {
        switch (i)
        {
        case 0:
            if (conv[i]==1)
            {
                decimal=decimal+128;
            }
        break;

        case 1:
            if (conv[i]==1)
            {
                decimal=decimal+64;
            }
        break;

        case 2:
            if (conv[i]==1)
            {
                decimal=decimal+32;
            }
        break;

        case 3:
            if (conv[i]==1)
            {
                decimal=decimal+16;
            }
        break;

        case 4:
            if (conv[i]==1)
            {
                decimal=decimal+8;
            }
        break;

        case 5:
            if (conv[i]==1)
            {
                decimal=decimal+4;
            }
        break;

        case 6:
            if (conv[i]==1)
            {
                decimal=decimal+2;
            }
        break;

        case 7:
            if (conv[i]==1)
            {
                decimal=decimal+1;
            }
        break;
        }
    }
    return decimal;
}

int ASCII_DEC(unsigned char prt1, unsigned char prt2)
{
    size_t i;
    int m[8], conv[16], top, bottom, decimal=0;

    for(i=0;i<8;i++)
    {
        m[i]=prt1%2;
        prt1 = prt1/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom] = m[top];
    }

    for(i=0;i<8;i++)
    {
        m[i]=prt2%2;
        prt2 = prt2/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom+8] = m[top];
    }

    for (i=0;i<16;i++)
    {
        switch (i)
        {
        case 0:
            if (conv[i]==1)
            {
                decimal=decimal+32768;
            }
        break;

        case 1:
            if (conv[i]==1)
            {
                decimal=decimal+16384;
            }
        break;

        case 2:
            if (conv[i]==1)
            {
                decimal=decimal+8192;
            }
        break;

        case 3:
            if (conv[i]==1)
            {
                decimal=decimal+4096;
            }
        break;

        case 4:
            if (conv[i]==1)
            {
                decimal=decimal+2048;
            }
        break;

        case 5:
            if (conv[i]==1)
            {
                decimal=decimal+1024;
            }
        break;

        case 6:
            if (conv[i]==1)
            {
                decimal=decimal+512;
            }
        break;

        case 7:
            if (conv[i]==1)
            {
                decimal=decimal+256;
            }
        break;

        case 8:
            if (conv[i]==1)
            {
                decimal=decimal+128;
            }
        break;

        case 9:
            if (conv[i]==1)
            {
                decimal=decimal+64;
            }
        break;

        case 10:
            if (conv[i]==1)
            {
                decimal=decimal+32;
            }
        break;

        case 11:
            if (conv[i]==1)
            {
                decimal=decimal+16;
            }
        break;

        case 12:
            if (conv[i]==1)
            {
                decimal=decimal+8;
            }
        break;

        case 13:
            if (conv[i]==1)
            {
                decimal=decimal+4;
            }
        break;

        case 14:
            if (conv[i]==1)
            {
                decimal=decimal+2;
            }
        break;

        case 15:
            if (conv[i]==1)
            {
                decimal=decimal+1;
            }
        break;

        default:break;
        }
    }
    return decimal;
}

int ASCII_DEC(unsigned char prt1, unsigned char prt2, int inicio, int final)
{
    size_t i;
    int m[8], conv[16], top, bottom, decimal=0;

    for(i=0;i<8;i++)
    {
        m[i]=prt1%2;
        prt1 = prt1/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom] = m[top];
    }

    for(i=0;i<8;i++)
    {
        m[i]=prt2%2;
        prt2 = prt2/2;
    }

    for(bottom=0,top =7; bottom<8; bottom++,top--)
    {
        conv[bottom+8] = m[top];
    }

    for (i=inicio;i<=final;i++)
    {
        switch (i)
        {
        case 0:
            if (conv[i]==1)
            {
                decimal=decimal+32768;
            }
        break;

        case 1:
            if (conv[i]==1)
            {
                decimal=decimal+16384;
            }
        break;

        case 2:
            if (conv[i]==1)
            {
                decimal=decimal+8192;
            }
        break;

        case 3:
            if (conv[i]==1)
            {
                decimal=decimal+4096;
            }
        break;

        case 4:
            if (conv[i]==1)
            {
                decimal=decimal+2048;
            }
        break;

        case 5:
            if (conv[i]==1)
            {
                decimal=decimal+1024;
            }
        break;

        case 6:
            if (conv[i]==1)
            {
                decimal=decimal+512;
            }
        break;

        case 7:
            if (conv[i]==1)
            {
                decimal=decimal+256;
            }
        break;

        case 8:
            if (conv[i]==1)
            {
                decimal=decimal+128;
            }
        break;

        case 9:
            if (conv[i]==1)
            {
                decimal=decimal+64;
            }
        break;

        case 10:
            if (conv[i]==1)
            {
                decimal=decimal+32;
            }
        break;

        case 11:
            if (conv[i]==1)
            {
                decimal=decimal+16;
            }
        break;

        case 12:
            if (conv[i]==1)
            {
                decimal=decimal+8;
            }
        break;

        case 13:
            if (conv[i]==1)
            {
                decimal=decimal+4;
            }
        break;

        case 14:
            if (conv[i]==1)
            {
                decimal=decimal+2;
            }
        break;

        case 15:
            if (conv[i]==1)
            {
                decimal=decimal+1;
            }
        break;

        default:break;
        }
    }
    return decimal;
}

int BIN_DEC(char arreglo[])
{
    char temp[2];
    int i,x,total=0,decimal[20];
    int potencia[20]={1,2,4,8,16,32,64,128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};

    for(i=0;arreglo[i]!='\0';i++);
    int limite=i;
    i--;
    for(x=0;x<limite;x++,i--)
    {
        temp[0]=arreglo[i];
        decimal[x]=atoi(temp);
        decimal[x]*=potencia[x];
        total+=decimal[x];
    }
    return total;
}

#endif
