#include "Pila.h"
Pila::Pila() {
	tope = NULL;
	cantidadBol = 0;
}
void Pila::setCantBol(int can) {
	cantidadBol = can;
}
int Pila::getCantBol() {
	return cantidadBol;
}
void Pila::push(sf::CircleShape shape, string color)
{
	Tubo* aux = NULL;
	float suma = 0;
	if (!tope)
	{
		suma = 0;
		Tubo* nuevo = new Tubo();
		nuevo = new Tubo(1, color, NULL, NULL,shape);
		tope = nuevo;
		//ini = nuevo;
	}
	else {
		suma = 0;
		int num = 0;
		num = tope->getIdTubo();
		num += 1;
		Tubo* nuevo = new Tubo();
		//tope->setSig(nuevo);
		nuevo = new Tubo(num, color, NULL, tope,shape);
		tope = nuevo;
		/*aux = ini;
		while (aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		nuevo = new Tubo();
		suma = 0;
		nuevo = new Tubo(num, obtenerSumEmpVen(emp, suma), emp, NULL, aux);
		aux->setSig(nuevo);*/
	}
}
Tubo* Pila::pop()
{
	Tubo* aux = new Tubo();
	int numI;
	//sf::CircleShape shape(0);
	if (!tope) return NULL;
	aux = tope;
	tope = aux->getAnt();
	//numI = aux->getIdTubo();
	//shape = aux->getShape();
	//delete aux;
	return aux;
}
Tubo*& Pila::top()
{
	return tope;
}

				
