#include "Pila.h"
Pila::Pila() {
	tope = NULL;
}
void Pila::push(sf::CircleShape shape)
{
	Tubo* aux = NULL;
	float suma = 0;
	if (!tope)
	{
		suma = 0;
		Tubo* nuevo = new Tubo();
		nuevo = new Tubo(1, NULL, NULL,shape);
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
		nuevo = new Tubo(num, NULL, tope,shape);
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
sf::CircleShape Pila::pop()
{
	Tubo* aux = new Tubo();
	int numI;
	sf::CircleShape shape(0);
	if (!tope) return shape;
	aux = tope;
	tope = aux->getAnt();
	numI = aux->getIdTubo();
	shape = aux->getShape();
	delete aux;
	return shape;
}
Tubo*& Pila::top()
{
	return tope;
}

				
