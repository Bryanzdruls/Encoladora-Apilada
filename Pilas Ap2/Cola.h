#pragma once
#include "Nodo.h"
#include "pila.h"
class cola
{
private:
    //atributos
    int tope, limite, *Vcola;
public:
    //metodos
    cola(int);
    void encolar(int); //set
    int desencolar(); //get
    void encolarOrdenado(int);
    void ordenarCola();
    bool ColaLlena();
    bool ColaVacia();
    void llenarCola(cola*);
   // void sumarPilaCola(pila_lista*, cola*);
    void invertirCola();
    void MostrarCola();
};