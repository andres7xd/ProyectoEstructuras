#include "Pila.h"
Pila::Pila() {
	tope = NULL;
	cantidadBol = 0;
	tuboComp = false;
}
void Pila::setCantBol(int can) {
	cantidadBol = can;
}
void Pila::setTComp(bool c)
{
	tuboComp = c;
}
int Pila::getCantBol() {
	return cantidadBol;
}
bool Pila::getTComp()
{
	return tuboComp;
}
void Pila::push(sf::CircleShape shape, string color)
{
	Bola* aux = NULL;
	float suma = 0;
	if (!tope)
	{
		suma = 0;
		Bola* nuevo = new Bola();
		nuevo = new Bola(1, color, NULL, NULL,shape);
		tope = nuevo;
		//ini = nuevo;
	}
	else {
		suma = 0;
		int num = 0;
		num = tope->getIdTubo();
		num += 1;
		Bola* nuevo = new Bola();
		//tope->setSig(nuevo);
		nuevo = new Bola(num, color, NULL, tope,shape);
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
Bola* Pila::pop()
{
	Bola* aux = new Bola();
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
Bola*& Pila::top()
{
	return tope;
}

				
