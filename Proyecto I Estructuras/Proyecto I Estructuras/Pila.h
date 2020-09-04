#include "Tubo.h"
#pragma once
class Pila
{
private:
	Tubo* tope;
public:
	Pila();
	void push(sf::CircleShape shape2);
	sf::CircleShape pop();
	Tubo*& top();
};

