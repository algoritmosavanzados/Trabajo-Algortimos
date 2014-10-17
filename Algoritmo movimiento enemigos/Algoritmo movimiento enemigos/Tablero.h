#pragma once
#include <stdio.h>
#include <vector>


enum Casilla {PARED_EXTERIOR,NORMAL,PARED,GENERADOR,RECORRIDO};

using namespace std;

class CTablero
{
private:
	vector<vector<int>> tablero;

public:
	int f,c;
	CTablero(void);
	~CTablero(void);
	void Imprimete(System::Drawing::Graphics ^c,int ancho,int alto);
	bool esNormal(int f,int c);
	Casilla getTipoCasilla(int f,int c);
	void cambiarBloque(int f,int c,Casilla tipo);

};

