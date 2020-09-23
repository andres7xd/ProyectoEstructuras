#include "ListaTubo.h"


ListaTubo::ListaTubo() {
	ini = NULL;
}


Tubo*& ListaTubo::getIni() {
	return ini;
}


void ListaTubo::AgregarTubo(Pila* b, sf::Sprite sprite) {

	
	 Tubo * aux = NULL, * dato = NULL;
	if (ini == NULL)
	{
		ini = new class Tubo(b, NULL, NULL, 1,  sprite);
	}
	else
	{
		aux = ini;
		
		while (aux->getSig() != NULL) {
			aux = aux->getSig();
		}
		int n = 0;
		n = aux->getId();
		n += 1;
	
		
		
			dato = new class Tubo(b,NULL,aux,n,sprite);
			aux->setSig(dato);
			
		
		
	}

}
