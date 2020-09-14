#include "Tubo.h"
#pragma once
class Pila
{
private:
	int cantidadBol;
	Tubo* tope;
	
public:
	Pila();
	void setCantBol(int can);
	int getCantBol();
	void push(sf::CircleShape shape2, string color);
	Tubo* pop();
	Tubo*& top();
};

