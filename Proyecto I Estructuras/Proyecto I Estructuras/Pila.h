#include "Tubo.h"
#pragma once
class Pila
{
private:
	Tubo* tope;
public:
	Pila();
	void push(sf::CircleShape shape2);
	Tubo* pop();
	Tubo*& top();
};

