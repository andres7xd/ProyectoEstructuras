
#include "Pila.h"

using namespace std;
#pragma once
class Tubo
{
public:
	Tubo();
	Tubo(Pila* b, Tubo* s, Tubo* a, int id, sf::Sprite sprite);

	void setPila(Pila* b);
	void setSig(Tubo* s);
	void setAnt(Tubo* a);
	void setId(int id);
	void setSf(sf::Sprite Sprite);

	sf::Sprite getSf();
	Pila*& getPila();
	Tubo* getSig();
	Tubo* getAnt();
	int getId();

private:
	sf::Sprite sprite;
	Pila* pilas;
	Tubo* sig;
	Tubo* ant;
	int idTubo;
};

