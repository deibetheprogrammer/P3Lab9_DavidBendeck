#ifndef SOLDADOSOPORTE_H
#define SOLDADOSOPORTE_H

#include "Soldado.h"

class SoldadoSoporte : public Soldado
{
	public:
		SoldadoSoporte();
		
		SoldadoSoporte(string,int,int,int,int);
		
		int blindaje;
		int camuflaje;
		
		virtual int ataque(Soldado*);
		virtual int defensa(int,Soldado*);
		virtual string getTipo();
		virtual size_t getSize();
		
		~SoldadoSoporte();
	protected:
};

#endif
