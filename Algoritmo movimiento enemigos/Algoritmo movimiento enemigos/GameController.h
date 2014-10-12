#pragma once
#include "Personaje.h"
#include "Tablero.h"


class GameController
{
private:
	CJugador* jugador;
	vector<CEnemigo*> enemigos;
	CTablero* tablero;

public:
	GameController(void);
	~GameController(void);
	
	void ImprimeJuego(System::Drawing::Graphics ^C,int ancho,int alto);
	void HallarCaminos();
	void MoverJugador();
	void RecontruyeMapa();
	void GeneraMonstruos(int cantidad);


};

