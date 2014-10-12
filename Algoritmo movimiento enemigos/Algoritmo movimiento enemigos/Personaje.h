#pragma once
#include "Tablero.h"
#include <stack>

enum Direccion {IZQUIERDA,DERECHA,ARRIBA,ABAJO};

class CPersonaje
{
protected:
	bool casillaIsValid(CTablero* tablero,int f,int c);

public:
	int f,c;
	CPersonaje(int f,int c);
	~CPersonaje(void);
	virtual void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto) abstract;

};

class CJugador : public CPersonaje
{
public:
	CJugador(int f,int c);
	void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto);
	void MueveteEnDireccion(Direccion dir,CTablero* tablero);
};

class CEnemigo : public CPersonaje
{
private:
	void DFS(CTablero* tablero,vector<vector<bool>> explorados,int f,int c,int fObjetivo,int cObjetivo,
		int &menor, stack<pair<int,int>> recorrido,stack<pair<int,int>> &solucion);
public:
	CEnemigo(int f,int c);
	void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto);
	stack<pair<int,int>> hallaMejorCamino(CTablero* tablero,int fObjetivo,int cObjetivo);
};