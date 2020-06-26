#ifndef SOLDADO_H
#define SOLDADO_H
#include<string>

using std::string;

class Soldado
{
	public:
		Soldado();
		
		Soldado(string,int,int);
		
		string nombre;
		int vida;
		int fuerza;
		
		virtual int ataque(Soldado*);
		virtual int defensa(int,Soldado*);
		virtual string getTipo();
		virtual size_t getSize();
		
		~Soldado();
	protected:
};

#endif
