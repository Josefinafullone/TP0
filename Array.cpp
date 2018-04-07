#include <iostream>
#include <math.h>

#define DEFAULT_SIZE 100

class cVector
{
    size_t size;
    Complex* data; //HAY QUE CAMBIAR ESTO PARA QUE SEA POLIMORFICO.

    public:

    //Constructors
    cVector(size_t s) {size=s; data=new Complex[size];};
    cVector()         {size=DEFAULT_SIZE; data=new Complex[DEFAULT_SIZE];};

    //Operators
    Complex& operator[](size_t pos) {return data[pos];};

    size_t GetSize() {return size;};
};

//Hay que modificar las funciones DFT e IDFT porque estan hechas para un Array no polimorfico.
//(Array que apunta unicamente a tipo de dato Complejo)

/*void DFT(cVector &vector, size_t k)
{
    size_t i,v_len;
    double tmp;
    Complex result;
    Complex aux;

    v_len=vector.GetSize();

    for(i=0; i<v_len; i++)
    {
        tmp=(k*i*2*M_PI)/v_len;
        aux.SetRe(cos(tmp));
        aux.SetIm(-sin(tmp));
        result+=vector[i]*aux;
    }

    result.Muestra();
}

void IDFT(cVector &vector, size_t k)
{
    size_t i,v_len;
    double tmp;
    Complex result;
    Complex aux;

    v_len=vector.GetSize();

    for(i=0; i<v_len; i++)
    {
        tmp=(k*i*2*M_PI)/v_len;
        aux.SetRe(cos(tmp));
        aux.SetIm(sin(tmp));
        result+=vector[i]*aux;
    }
    result/=v_len;

    result.Muestra();
}*/

