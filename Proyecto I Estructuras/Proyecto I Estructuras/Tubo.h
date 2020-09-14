#include <iostream>
#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include <SFML/Audio.hpp>
#include "MenuInicio.h"

using namespace std;
#pragma once
class Tubo
{
private:
	int idTubo;
	string color;
	Tubo* sig;
	Tubo* ant;
	sf::CircleShape shape;
public:
	Tubo();
	Tubo(int idT, string col, Tubo* s, Tubo* a, sf::CircleShape sp);
	void setIdTubo(int idT);
	void setColor(string col);
	void setShape(sf::CircleShape sp);
	void setSig(Tubo* s);
	void setAnt(Tubo* a);
	int getIdTubo();
	string getColor();
	sf::CircleShape getShape();
	Tubo* getSig();
	Tubo* getAnt();
};

