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

public:
	GameController(void);
	~GameController(void);
	
	void ImprimeJuego(System::Drawing::Graphics ^C,int ancho,int alto);
	bool Añade_bala(int ancho, int alto, int max_balas);
	void HallarCaminos();
	bool MoverJugador(Direccion dir);
	bool JugadorEstaMoviendose();
	void RecontruyeMapa();
	void GeneraMonstruos(int cantidad);
	void MueveEnemigos();

};

