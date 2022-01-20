#pragma once
class pila
{
private:
	//Atributos.
	int limite, tope, *vec;

	//Metodos.
public:
	pila(int);
	void apilar(int);//Set.
	int desapilar(); //Get.
	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila*);
	void mostrarPila();
};

