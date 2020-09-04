#include "Tubo.h"
Tubo::Tubo()
{
	idTubo = 0;
	sig = NULL;
	ant = NULL;
	//shape = NULL;
}
Tubo::Tubo(int idT, Tubo* s, Tubo* a, sf::CircleShape sp)
{
	idTubo = idT;
	sig = s;
	ant = a;
	shape = sp;
}
void Tubo::setIdTubo(int idT) 
{ 
	idTubo = idT; 
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