#include "Soldado.h"

Soldado::Soldado()
{
}

Soldado::Soldado(string nombre,int vida,int fuerza) : nombre{nombre},vida{vida},fuerza{fuerza} {}

int Soldado::ataque(Soldado* soldado) {}
int Soldado::defensa(int ataque,Soldado* soldado) {}
string Soldado::getTipo() { return ""; }
size_t Soldado::getSize() { return sizeof(Soldado); }

Soldado::~Soldado()
{
}
