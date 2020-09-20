#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include <SFML/Audio.hpp>
#include "MenuInicio.h"

using namespace std;
class Bola
{
private:
	int idTubo;
	string color;
	Bola* sig;
	Bola* ant;
	sf::CircleShape shape;
public:
	Bola();
	Bola(int idT, string col, Bola* s, Bola* a, sf::CircleShape sp);
	void setIdTubo(int idT);
	void setColor(string col);
	void setShape(sf::CircleShape sp);
	void setSig(Bola* s);
	void setAnt(Bola* a);

	int getIdTubo();
	string getColor();
	sf::CircleShape getShape();
	Bola* getSig();
	Bola* getAnt();
};

