#include "SoldadoSoporte.h"

SoldadoSoporte::SoldadoSoporte()
{
}

SoldadoSoporte::SoldadoSoporte(string nombre, int vida, int fuerza, int blindaje, int camuflaje) :
	Soldado{nombre,vida,fuerza}, blindaje{blindaje}, camuflaje{camuflaje} {}

int SoldadoSoporte::ataque(Soldado* soldado) {
	if (soldado->getTipo() == "asalto") 
		return fuerza * (15 + camuflaje);
	
	return fuerza * 10;
}

int SoldadoSoporte::defensa(int ataque, Soldado* soldado) {
	if(soldado->getTipo() == "asalto") {
		vida -= ataque/(blindaje*2);
	} else {
		vida -= ataque;
	}
	
	return vida;	
}

string SoldadoSoporte::getTipo() {
	return "soporte";
}

size_t SoldadoSoporte::getSize() { return sizeof(SoldadoSoporte); }

SoldadoSoporte::~SoldadoSoporte()
{
}
