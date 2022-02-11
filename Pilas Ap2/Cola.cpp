#include "Cola.h"
#include "pila.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

cola::cola(int tam)
{
    limite = tam - 1;
    tope = -1;
    Vcola= new int[tam];
}

void cola::encolar(int d)
{
    tope++;
    Vcola[tope] = d;
}

int cola::desencolar()
{
    int r = Vcola[0], i = 1;
    while (i <= tope)
    {
        Vcola[i - 1] = Vcola[i];
        i++;
    }
    tope--;
    return r;
}

void cola::encolarOrdenado(int d)
{

}

void cola::ordenarCola()
{
    int r;
    cola* aux1 = new cola(limite);
    cola* aux2 = new cola(limite);

    if (tope > 0)
    {
        r = desencolar();
        while (!ColaVacia()) //encuentra al menor.
        {
            if (r < Vcola[0])
                aux1->encolar(desencolar());
            else
            {
                aux1->encolar(r);
                r = desencolar();
            }
        }
        encolar(r); //el menor se apila.
        r = aux1->desencolar();
        aux1->invertirCola();
        while (!aux1->ColaVacia())
        {
            if (r < aux1->Vcola[0])
            {
                aux2->encolar(r);
                r = aux1->desencolar();
            }
            else
            {
                aux2->encolar(aux1->desencolar());
            }
        }
        aux1->encolar(r);
        llenarCola(aux2);
        llenarCola(aux1);
        cout << "La Cola se ha ordenado correctamente." << endl;
    }
    else
    {
        cout << "La Cola solo tiene un dato" << endl;
    }
};

bool cola::ColaLlena()
{
    if (tope == limite)
        return true;
    else
        return false;
}

bool cola::ColaVacia()
{
    if (tope == -1)
        return true;
    else
        return false;
}

void cola::llenarCola(cola *a)
{
    while (a->ColaVacia() == false)
        encolar(a->desencolar());
}
/*
* void cola::sumarPilaCola(pila_lista* p1, cola* c2)
{
    int d1 = 0, d2 = 0, d3 = 0;

    while (!p1->pilaVacia() || !c2->ColaVacia())
    {
        if (!p1->pilaVacia() && !c2->ColaVacia())
        {
            d3 = p1->desapilar() + c2->desencolar();
        }
        else
        {
            if (p1->pilaVacia())
            {
                d3 = c2->desencolar();
            }
            else
            {
                if (c2->ColaVacia())
                {
                    d3 = p1->desapilar();
                }
            }
        }
        encolar(d3);
    }
    invertirCola();
}
*/

void cola::invertirCola()
{
    cola* aux1 = new cola(limite);
    cola* aux2 = new cola(limite);
    int r = 0;

    while (!ColaVacia())
    {
        r = desencolar();
        aux1->encolar(r);
    }
    aux2->llenarCola(aux1);
    llenarCola(aux2);
}
void cola::MostrarCola()
{
    int r = 0, i = 0;
    cola* Ca = new cola(limite + 1);
    while (!ColaVacia())
    {
        r = desencolar();
        cout << "El dato en la posicion " << i << " es:" << r << endl;
        Ca->encolar(r);
        i++;
    }
    llenarCola(Ca);
};