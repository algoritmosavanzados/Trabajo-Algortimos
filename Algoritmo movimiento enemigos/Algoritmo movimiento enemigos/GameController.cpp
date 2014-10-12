#include "stdafx.h"
#include "GameController.h"


GameController::GameController(void)
{
	tablero=new CTablero();
	jugador=new CJugador(7,7);
	enemigos.push_back(new CEnemigo(11,1));
	enemigos.push_back(new CEnemigo(1,13));
	enemigos.push_back(new CEnemigo(3,8));
	enemigos.push_back(new CEnemigo(11,11));
}


GameController::~GameController(void)
{
}

void GameController::ImprimeJuego(System::Drawing::Graphics ^C,int ancho,int alto){
	tablero->Imprimete(C,ancho,alto);
	jugador->Imprimete(C,tablero,ancho,alto);
	for(int i=0;i<enemigos.size();i++)
		enemigos[i]->Imprimete(C,tablero,ancho,alto);
	
}

void GameController::HallarCaminos(){
	for(int i=0;i<enemigos.size();i++){
		stack<pair<int,int>> camino=enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
		while(!camino.empty()){
			pair<int,int> coord=camino.top();
			tablero->cambiarBloque(coord.first,coord.second,RECORRIDO);
			camino.pop();
		}
	}

}

void GameController::MoverJugador(){
}

void GameController::RecontruyeMapa(){
}

void GameController::GeneraMonstruos(int cantidad){
}
