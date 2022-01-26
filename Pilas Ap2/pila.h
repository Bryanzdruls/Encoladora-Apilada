#pragma once
class pila
{
private:
	//Atributos.
	int limite, tope, *vec;

	//Metodos.
public:
	pila(int);//Constructor.
	void apilar(int);//Set.
	int desapilar(); //Get.
	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila*);//Pasar datos, de pila llena a pila vacia.
	void mostrarPila();
};

