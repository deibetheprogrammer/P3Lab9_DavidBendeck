#include "SoldadoAsalto.h"

SoldadoAsalto::SoldadoAsalto()
{
}

SoldadoAsalto::SoldadoAsalto(string nombre,int vida,int fuerza,int velocidad, int fuerzaE) : 
	Soldado{nombre,vida,fuerza},velocidad{velocidad},fuerzaE{fuerzaE} {}

int SoldadoAsalto::ataque(Soldado* soldado) {
	if (soldado->getTipo() == "asalto") 
		return fuerza * 10;
	
	return fuerza * (10 +(velocidad*2));
}

int SoldadoAsalto::defensa(int ataque, Soldado* soldado) {
	if(soldado->getTipo() == "asalto") {
		vida -= ataque;
	} else {
		vida -= ataque/fuerzaE;
	}
	
	return vida;	
}

string SoldadoAsalto::getTipo() {
	return "asalto";
}

size_t SoldadoAsalto::getSize() { return sizeof(SoldadoAsalto); }

SoldadoAsalto::~SoldadoAsalto()
{
}
