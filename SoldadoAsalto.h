#ifndef SOLDADOASALTO_H
#define SOLDADOASALTO_H

#include "Soldado.h"

class SoldadoAsalto : public Soldado
{
	public:
		SoldadoAsalto();
		
		SoldadoAsalto(string,int,int,int,int);
		
		int velocidad;
		int fuerzaE;
		
		virtual int ataque(Soldado*);
		virtual int defensa(int,Soldado*);
		virtual string getTipo();
		virtual size_t getSize();
		
		~SoldadoAsalto();
	protected:
};

#endif
