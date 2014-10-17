#include "stdafx.h"
#include "GameController.h"


GameController::GameController(void)
{
	tablero=new CTablero();
	jugador=new CJugador(7,11);
	enemigos.push_back(new CEnemigo(11,3));
	enemigos.push_back(new CEnemigo(1,13));
	enemigos.push_back(new CEnemigo(3,8));
	enemigos.push_back(new CEnemigo(11,11));

	HallarCaminos();

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
	for(int i=0;i<tablero->f;i++)
		for(int j=0;j<tablero->c;j++)
			if(tablero->getTipoCasilla(i,j)==RECORRIDO)	tablero->cambiarBloque(i,j,NORMAL);	
	for(int i=0;i<enemigos.size();i++){
		enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
		
		/*while(!camino.empty()){
			Direccion coord=camino.top();
			tablero->cambiarBloque(coord.first,coord.second,RECORRIDO);
			camino.pop();
		}*/
	}
}

void GameController::MueveEnemigos(){
	for(int i=0;i<enemigos.size();i++){
		if(!enemigos[i]->moviendose){
			//enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
			enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
			

		}
	}
}

bool GameController::Añade_bala(int ancho, int alto, int max_balas){
	CBala *bala;
	if (balas.size() == max_balas) return false;

	bala = new CBala(jugador->f, jugador->c, ancho, alto, jugador->dir);
	balas.push_back(bala);
	return true;
}


bool GameController::MoverJugador(Direccion dir){
	return jugador->MueveteHacia(dir,tablero);
}

void GameController::RecontruyeMapa(){
}

void GameController::GeneraMonstruos(int cantidad){
}

bool GameController::JugadorEstaMoviendose(){
	return jugador->moviendose;
}