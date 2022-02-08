#ifndef CONVERSIONES_H
#define CONVERSIONES_H
#include <iostream>
#include <cmath>

using namespace std;


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
        //cout<<m[top];
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

int BIN_DEC(int num[])
{
    
}


#endif