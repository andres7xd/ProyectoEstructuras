#include "Bola.h"
Bola::Bola()
{
	idTubo = 0;
	color = "";
	sig = NULL;
	ant = NULL;

	//shape = NULL;
}
Bola::Bola(int idT, string col, Bola* s, Bola* a, sf::CircleShape sp)
{
	idTubo = idT;
	color = col;
	sig = s;
	ant = a;
	shape = sp;
}
void Bola::setIdTubo(int idT)
{
	idTubo = idT;
}
void Bola::setColor(string col)
{
	color = col;
}
void Bola::setShape(sf::CircleShape sp)
{
	shape = sp;
}
void Bola::setSig(Bola* s)
{
	sig = s;
}
void Bola::setAnt(Bola* a)
{
	ant = a;
}
int Bola::getIdTubo()
{
	return idTubo;
}
string Bola::getColor()
{
	return color;
}
sf::CircleShape Bola::getShape()
{
	return shape;
}
Bola* Bola::getSig()
{
	return sig;
}
Bola* Bola::getAnt()
{
	return ant;
}