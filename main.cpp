#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "Soldado.h"
#include "SoldadoAsalto.h"
#include "SoldadoSoporte.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//Guardar y leer
int guardarSoldados(string, vector<Soldado*>&);

int cargarSoldados(string, vector<Soldado*>&);

//Listar
void listarEquipo(vector<Soldado*>&);


//desplegar soldado
void desplegarSoldado(Soldado*);

int main(int argc, char** argv) {
	
	vector<Soldado*> equipo1;
	vector<Soldado*> equipo2;
	
	bool loop = true;
	while(loop) {
		
		cout << endl;
	
		cout<<"********MENU********" << endl
			<<"1) Crear soldado" << endl
			<<"2) Eliminar soldado" << endl
			<<"3) Listar soldados" << endl
			<<"4) Guardar soldados" << endl
			<<"5) Cargar soldados" << endl
			<<"6) Simulacion" << endl
			<<"7) Salida " << endl
			<<"Su eleccion: ";
	
		int opcion;
		cin >> opcion;
	
		while (!cin || (opcion < 1 || opcion > 7)) {
			cin.clear ();    // Restore input stream to working state
    		cin.ignore ( 100 , '\n' );    // Get rid of any garbage that user might have entered
   		 	cout << "Por favor, ingrese una opcion valida: ";
    		cin >> opcion; 
		}
		
		// limpiar el cin
		cin.ignore(100,'\n');
		
		switch(opcion) {
			case 1: {
				
				//NOMBRE
				cout << endl
					 << "***Crear Soldado***" << endl
					 << "Ingrese el nombre: ";
				
				string nombre;
				getline(cin,nombre);
				
				//VIDA
				cout << "Ingrese la vida: ";
				
				int vida;
				cin >> vida;
				
				while (!cin || vida <= 0) {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Ingrese un numero valido por favor";
					cin >> vida;
				}
				
				//Fuerza
				cout << "Ingrese la fuerza: ";
				
				int fuerza;
				cin >> fuerza;
				
				while (!cin || fuerza <= 0) {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Ingrese un numero valido por favor";
					cin >> fuerza;
				}
				
				//DECIDIR EL TIPO
				
				cout << "Escoja una especialidad: " << endl
					 << "1) Asalto" << endl
					 << "2) Soporte" << endl
					 << "Su eleccion: ";
				
				int especialidad;
				cin >> especialidad;
				
				while (!cin || (especialidad < 1 || especialidad > 2)) {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Ingrese un numero valido por favor";
					cin >> especialidad;
				}
				
				if (especialidad == 1) {
					
					//VELOCIDAD
					
					cout << "Ingrese la velocidad: ";
					int velocidad;
					cin >> velocidad;
					
					while (!cin || velocidad <= 0) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> velocidad;
					}
					
					// FUERZA EXTRA
					
					cout << "Ingrese la fuerza extra: ";
					int fuerzaE;
					cin >> fuerzaE;
					
					while (!cin || fuerzaE <= 0) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> fuerzaE;
					}
					
					// Eleccion de equipo
					
					cout << "Ingrese el equipo del soldado: " << endl
						 << "1) Equipo 1" << endl
						 << "2) Equipo 2" << endl
						 << "Su eleccion: ";
					
					int equipo;
					cin >> equipo;
					
					while (!cin || (equipo < 1 || equipo > 2) ) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> equipo;
					}
					
					if(equipo == 1) {
						
						cout << "Nuevo soldado de asalto equipo 1" << endl;
						
						equipo1.push_back(new SoldadoAsalto(nombre,vida,fuerza,velocidad,fuerzaE));
						
					} else {
						
						cout << "Nuevo soldado de asalto equipo 2" << endl;
						
						equipo2.push_back(new SoldadoAsalto(nombre,vida,fuerza,velocidad,fuerzaE));
						
					}
					
					
				} else {
					
					//BLINDAJE
					
					cout << "Ingrese el blindaje: ";
					int blindaje;
					cin >> blindaje;
					
					while (!cin || blindaje <= 0) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> blindaje;
					}
					
					//CAMUFALJE
					
					cout << "Ingrese el camuflaje: ";
					int camuflaje;
					cin >> camuflaje;
					
					while (!cin || camuflaje <= 0) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> camuflaje;
					}
					
					// Eleccion de equipo
					
					cout << "Ingrese el equipo del soldado: " << endl
						 << "1) Equipo 1" << endl
						 << "2) Equipo 2" << endl
						 << "Su eleccion: ";
					
					int equipo;
					cin >> equipo;
					
					while (!cin || (equipo < 1 || equipo > 2) ) {
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Ingrese un numero valido por favor";
						cin >> equipo;
					}
					
					if(equipo == 1) {
						
						cout << "Nuevo soldado de soporte equipo 1" << endl;
						
						equipo1.push_back(new SoldadoSoporte(nombre,vida,fuerza,blindaje,camuflaje));
						
					} else {
						
						cout << "Nuevo soldado de soporte equipo 2" << endl;
						
						equipo2.push_back(new SoldadoSoporte(nombre,vida,fuerza,blindaje,camuflaje));
						
					}
					
				}
				
				//limpiar el cin
				cin.ignore(100,'\n');
				
				break;
			}
			case 2: {
				
				cout << "***Eliminar soldados***" << endl
					 << "De que equipo desea eliminar soldados (1-2) ? :";
				
				int equipo;
				cin >> equipo;
				
				while (!cin || (equipo < 1 || equipo > 2)) {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Ingrese un equipo valido por favor: ";
					cin >> equipo;
				}
				
				vector<Soldado*> *pEquipo = nullptr;
				
				if (equipo == 1) {
					
					pEquipo = &equipo1;
					
				} else {
				
					pEquipo = &equipo2;
				
				}
				
				if (pEquipo->size() == 0) {
					cout << "Equipo vacio" << endl;
					break;
				} 
				
				//Listar soldados
				listarEquipo(*pEquipo);
				
				cout << endl
					 << "Que soldado desea borrar? :";
					
				int iSoldado;
				cin >> iSoldado;
				
				while (!cin || (iSoldado < 0 || iSoldado > pEquipo->size()-1)) {
					cin.clear();
					cin.ignore(100,'\n');
					cout << "Ingrese un indice valido por favor: ";
					cin >> iSoldado;
				}
				
				pEquipo->erase(pEquipo->begin() + iSoldado);
				
				break;
			}
			case 3: {
				
				cout << "***Listar soldados***" << endl
					 << "Soldados equipo 1: " << endl;
				
				listarEquipo(equipo1);
				
				cout << endl
					 << "Soldados equipo 2: " << endl;
				
				listarEquipo(equipo2);
					 
				break;
			}
			case 4: {
				
				cout << "***Guardar Soldados***" << endl;
				
				int guardados1 = guardarSoldados("equipo1.bin",equipo1);
				
				cout << guardados1 << " soldados guardados en el equipo 1" << endl;
				
				int guardados2 = guardarSoldados("equipo2.bin",equipo2);
				
				cout << guardados2 << " soldados guardados en el equipo 2" << endl;
				
				break;
			}
			case 5: {
				
				cout << "***Cargar soldados***" << endl;
				
				int leidos1 = cargarSoldados("equipo1.bin", equipo1);
				
				cout << leidos1 << " soldados leidos en el equipo 1" << endl;
				
			//	cout << "Size del equipo 1: " << equipo1.size() << endl;
				
				int leidos2 = cargarSoldados("equipo2.bin", equipo2);
				
				cout << leidos2 << " soldados leidos en el equipo 2" << endl;
				
			//	cout << "Size del equipo 2: " << equipo2.size() << endl;
				
				break;
			}
			case 6: {
				
				cout << "***Simulacion***" << endl;
				
				srand(time(NULL));
				
				bool turno = false;
				
				while(true) {
					
					turno = !turno;
					
					vector<Soldado*> *peAtacante = nullptr;
					vector<Soldado*> *peDefensor = nullptr;
					
					cout << endl;
					
					if (turno) {
						
						peAtacante = &equipo1;
						peDefensor = &equipo2;
						
						cout << "Ataca equipo 1: " << endl;
						
					} else {
						
						peAtacante = &equipo2;
						peDefensor = &equipo1;
						
						cout << "Ataca equipo 2: " << endl;
					}
					
					//SOLDADO ATACANTE
					int indice = rand()%peAtacante->size();
					
					Soldado* sAtacante = peAtacante->at(indice);
					
					cout << "Soldado atacante: ";
					
					desplegarSoldado(sAtacante);
					
					//SOLDADO DEFENSOR
					int indice2 = rand()%peDefensor->size();
					
					Soldado* sDefensor = peDefensor->at(indice2);
					
					cout << "Soldado defensor: ";
					
					desplegarSoldado(sDefensor);
					
					int fuerzaAtaque = sAtacante->ataque(sDefensor);
					
					int vidaResultante = sDefensor->defensa(fuerzaAtaque,sAtacante);
					
					cout << "Ataque realizado con fuerza: " << fuerzaAtaque
						 << "| vida resultante del defensor: " << vidaResultante << endl;
						 
					if(vidaResultante <= 0) {
						
						cout << "El soldado defensor ha muerto! " << endl;
						
						peDefensor->erase(peDefensor->begin() + indice2);
						
						if(peDefensor->size() == 0) {
							
							if(turno) {
								
								cout << "El equipo 1 ha ganado !" << endl;
								
							} else {
								
								cout << "El equipo 2 ha ganado !" << endl;
								
							}
							
							break;
						}
					} 
					
				}
				
				break;
			}
			case 7: {
				cout << "Saliendo ...";
				loop = false;
				break;
			}
		}
	}
	return 0;
	
}


int guardarSoldados(string nombreArchivo, vector<Soldado*>& equipo) {
	
 	ofstream file(nombreArchivo, ios::binary | ios::trunc);
 	
 	if(!file.is_open())
 		return -1;
 		
 	int tempSize = 0;
 	// el getSize es una función virtual. En cada uno de los hijos retorna sizeof(hijo)
 	// Ejemplo del sizeOf de boy seria:
 	// size_t getSize(){
 	// return sizeof(boy);
 	// }
 	
 	for(int i = 0 ; i < equipo.size(); i++ ) {
		
 		tempSize = equipo[i]->nombre.size();
 		file.write(reinterpret_cast<char*>(&tempSize), (int)sizeof(int) );
 		
 		file.write(equipo[i]->nombre.data(),tempSize);
 		
 		file.write(reinterpret_cast<char*>(&equipo[i]->vida), (int)sizeof(int) );
 		
 		file.write(reinterpret_cast<char*>(&equipo[i]->fuerza), (int)sizeof(int) );
 		
 		if(equipo[i]->getTipo() == "asalto") {
 			
 			SoldadoAsalto *sa = (SoldadoAsalto*)equipo[i]; 
 			
 			char tipo = 'a';
 			
 			file.write(&tipo,1);
 			
 			file.write(reinterpret_cast<char*>(&(sa->velocidad)), (int)sizeof(int) );
 			
 			file.write(reinterpret_cast<char*>(&(sa->fuerzaE)), (int)sizeof(int) );
 			
		} else {
			
			SoldadoSoporte *ss = (SoldadoSoporte*)equipo[i];
			
			char tipo = 's';
			
			file.write(&tipo,1);
			
			file.write(reinterpret_cast<char*>(&(ss->blindaje)), (int)sizeof(int) );
 			
 			file.write(reinterpret_cast<char*>(&(ss->camuflaje)), (int)sizeof(int) );
				
		}
	}
	 
 	file.close();
 	return equipo.size();
}

int cargarSoldados(string nombreArchivo, vector<Soldado*>& equipo) {
	
	int count = 0;
	
	equipo.clear();
	
	ifstream file(nombreArchivo, ios::binary);
    // Variable del tamaño del objeto que se cargará
 	int tempSize=0;
 	
 	while(!file.read( (char*) &tempSize, sizeof(int)).eof()) {
		
		//cout << "tempSize: " << tempSize << endl;
 		// Carga el objeto
 		
 		char* buffer = new char[tempSize+1];
 		
 		file.read(buffer, tempSize);
 		
 		buffer[tempSize] = 0;
 		
 		string nombre = buffer;
 		
 		int vida = 0;
 		int fuerza = 0;
 		
 		file.read((char*) &vida, sizeof(int));
 		file.read((char*) &fuerza, sizeof(int));
 		
 		char tipo = ' ';
 		
 		file.read((char*) &tipo, sizeof(char));
 		
 		if(tipo == 'a') {
 			
 			int velocidad = 0;
 			int fuerzaE = 0;
 			
 			file.read((char*) &velocidad, sizeof(int));
 			file.read((char*) &fuerzaE, sizeof(int));
 			
 			equipo.push_back(new SoldadoAsalto(nombre,vida,fuerza,velocidad,fuerzaE));
 			
	    } else {
	    	
	    	int blindaje = 0;
	    	int camuflaje = 0;
	    	
	    	file.read((char*) &blindaje, sizeof(int));
 			file.read((char*) &camuflaje, sizeof(int));
 			
 			equipo.push_back(new SoldadoSoporte(nombre,vida,fuerza,blindaje,camuflaje));
		}
 		
 		count++;
 		//cout << "nombre" << equipo.back()->nombre;
	}
	
 	file.close();
 	return count;
}

//Listar
void listarEquipo(vector<Soldado*>& equipo) {
	
	
	for(int i = 0; i < equipo.size(); i++) {
		cout << i << " :: ";
		desplegarSoldado(equipo[i]);
	}
	
}


//desplegar soldados
void desplegarSoldado(Soldado* soldado) {
	
	cout << "nombre: " << soldado->nombre 
		 << " | vida: " << soldado->vida
		 << " | fuerza: " << soldado->fuerza;
		
	if(soldado->getTipo() == "asalto") {
			
		SoldadoAsalto *sa = (SoldadoAsalto*) soldado;
			
		cout << " | velocidad: " << sa->velocidad
			 << " | fuerza Extra: " << sa->fuerzaE << endl;
			 
	} else {
			
		SoldadoSoporte *ss = (SoldadoSoporte*) soldado;
			
		cout << " | blindaje: " << ss->blindaje
			 << " | camuflaje: " << ss->camuflaje << endl;
			 
	}
	
	
}















