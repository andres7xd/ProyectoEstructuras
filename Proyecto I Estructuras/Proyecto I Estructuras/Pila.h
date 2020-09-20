#include "Bola.h"
#pragma once
class Pila
{
private:
	int cantidadBol;
	Bola* tope;
	bool tuboComp;//Verificador si esta lleno de bolas del mismo color
	
public:
	Pila();
	void setCantBol(int can);
	void setTComp(bool c);
	int getCantBol();
	bool getTComp();
	void push(sf::CircleShape shape2, string color);
	Bola* pop();
	Bola*& top();
};

