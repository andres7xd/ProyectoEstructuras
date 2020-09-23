#include "Tubo.h"

Tubo::Tubo() {
	pilas = NULL;
	sig = NULL;
	ant = NULL;
	idTubo = NULL;
}

Tubo::Tubo(Pila* b, Tubo* s, Tubo* a, int id, sf::Sprite sf) {
	pilas = b;
	sig = s;
	ant = a;
	idTubo = id;
	sprite = sf;

}





void Tubo::setAnt(Tubo* a) {
	ant = a;
}
void Tubo::setSig(Tubo* s) {
	sig = s;
}
void Tubo::setId(int id) {
	idTubo = id;
}

void Tubo::setPila(Pila* b) {
	pilas = b;
}

void Tubo::setSf(sf::Sprite sf) {
	sprite = sf;
}


sf::Sprite Tubo::getSf() {
	return sprite;
}

Tubo* Tubo::getAnt() {
	return ant;
}

Tubo* Tubo::getSig() {
	return sig;
}

int Tubo::getId() {
	return idTubo;
}

Pila* Tubo::getPila() {
	return pilas;
}



