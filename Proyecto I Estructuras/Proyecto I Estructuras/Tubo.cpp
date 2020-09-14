#include "Tubo.h"
Tubo::Tubo()
{
	idTubo = 0;
	color = "";
	sig = NULL;
	ant = NULL;

	//shape = NULL;
}
Tubo::Tubo(int idT, string col, Tubo* s, Tubo* a, sf::CircleShape sp)
{
	idTubo = idT;
	color = col;
	sig = s;
	ant = a;
	shape = sp;
}
void Tubo::setIdTubo(int idT) 
{ 
	idTubo = idT; 
}
void Tubo::setColor(string col)
{
	color = col;
}
void Tubo::setShape(sf::CircleShape sp)
{
	shape = sp;
}
void Tubo::setSig(Tubo* s) 
{ 
	sig = s; 
}
void Tubo::setAnt(Tubo* a) 
{ 
	ant = a; 
}
int Tubo::getIdTubo() 
{ 
	return idTubo; 
}
string Tubo::getColor()
{
	return color;
}
sf::CircleShape Tubo::getShape() 
{
	return shape;
}
Tubo* Tubo::getSig() 
{ 
	return sig; 
}
Tubo* Tubo::getAnt() 
{ 
	return ant; 
}