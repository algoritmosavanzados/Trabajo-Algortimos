#pragma once
#include "Tablero.h"
#include <stack>
#include <queue>

enum Direccion {IZQUIERDA,DERECHA,ARRIBA,ABAJO};

class CPersonaje
{
protected:
	bool casillaIsValid(CTablero* tablero,int f,int c);
	int col,fil,w,h;

public:
	int f,c;
	bool moviendose;
	Direccion dir;
	CPersonaje(int f,int c);
	~CPersonaje(void);
	virtual void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto) abstract;

};

class CJugador : public CPersonaje
{
public:
	CJugador(int f,int c);
	void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto);
	bool MueveteHacia(Direccion dir,CTablero* tablero);
};

class CEnemigo : public CPersonaje
{
private:
	void DFS(CTablero* tablero,vector<vector<bool>> explorados,int f,int c,int fObjetivo,int cObjetivo,
		int &menor, stack<pair<int,int>> recorrido,stack<pair<int,int>> &solucion);
	void BFS(CTablero* tablero,vector<vector<int>> &explorados,int fila,int col,pair<int,int> objetivo,bool &cond,queue<pair<int,int>> &pendientes);
	void armaRecorrido(stack<pair<int,int>> &recorrido,vector<vector<int>>distancias,int f,int c);
	vector<Direccion> camino;

public:
	CEnemigo(int f,int c);
	void Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto);
	stack<pair<int,int>> hallaMejorCamino(CTablero* tablero,int fObjetivo,int cObjetivo);
	void avanza(CTablero* tablero,int fO,int cO);
	bool colision(CJugador* jugador);
};

class CBala : public CPersonaje
{
private:
	Direccion direc;
public:
	CBala(int f, int c, int ancho, int alto,Direccion direccion);
	void Imprimete(System::Drawing::Graphics ^C, CTablero* tablero, int ancho, int alto);
	bool muevete(CTablero* tablero);
	bool Colision(CEnemigo *enemigo);

};