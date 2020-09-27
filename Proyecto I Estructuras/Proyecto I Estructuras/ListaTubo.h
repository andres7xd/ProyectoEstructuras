#pragma once
#include "Tubo.h"
#include <SFML\Window\Keyboard.hpp>

class ListaTubo
{

public:
	void AgregarTubo(Pila* b, sf::Sprite sprite);
	Tubo*& getIni();
	ListaTubo();

private:

	Tubo* ini;


};


