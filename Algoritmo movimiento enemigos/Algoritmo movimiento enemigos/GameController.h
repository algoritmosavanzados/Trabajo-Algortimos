#pragma once
#include "Personaje.h"
#include "Tablero.h"


class GameController
{
private:
	CJugador* jugador;
	vector<CEnemigo*> enemigos;
	CTablero* tablero;
	vector<CBala*> balas;
	int max_monstruos;
	vector<pair<int,int>> spawn_points;
	pair<int,int> dameCasillaNormalJuntoAGenerador(int f,int c);

public:
	GameController(void);
	~GameController(void);
	
	void ImprimeJuego(System::Drawing::Graphics ^C,int ancho,int alto);
	bool Añade_bala(int ancho, int alto, int max_balas);
	void HallarCaminos();
	bool MoverJugador(Direccion dir);
	bool JugadorEstaMoviendose();
	void RecontruyeMapa();
	void GeneraMonstruos();
	void MueveEnemigos();
	int Get_numBalas();
	bool atraparonPersonaje();
	int puntaje,tiempo,rate;




};

