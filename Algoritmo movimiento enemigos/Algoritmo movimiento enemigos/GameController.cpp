#include "stdafx.h"
#include "GameController.h"
#include <stdlib.h>
#include <time.h>

GameController::GameController(void)
{
	tablero=new CTablero();
	jugador=new CJugador(7,11);
	señuelo=NULL;
	puntaje = 0;
	tiempo=10;
	rate=5;
	/*enemigos.push_back(new CEnemigo(11,3));
	enemigos.push_back(new CEnemigo(1,13));
	enemigos.push_back(new CEnemigo(3,8));
	enemigos.push_back(new CEnemigo(11,11));*/

	spawn_points=tablero->getSpawnPoints();
	max_monstruos=10;
	srand((unsigned) time(NULL));
	bonusAmmo=NULL;
	HallarCaminos();

	//RecontruyeMapa();

}


GameController::~GameController(void)
{
}

void GameController::ImprimeJuego(System::Drawing::Graphics ^C,int ancho,int alto){
	tablero->Imprimete(C,ancho,alto);
	jugador->Imprimete(C,tablero,ancho,alto);
	if (balas.size() > 0){
		for (int i = 0; i < balas.size(); i++){
			balas[i]->Imprimete(C, tablero, ancho, alto);
			balas[i]->muevete(tablero);
			for (int j = 0; j < enemigos.size(); j++){
				if (balas[i]->Colision(enemigos[j])){
					puntaje += 10;
					enemigos.erase(enemigos.begin()+j);
				}
				
			}
		}
	}
	for (int i = 0; i < enemigos.size(); i++)
		enemigos[i]->Imprimete(C, tablero, ancho, alto);


	if(bonusAmmo!=NULL)
		bonusAmmo->Imprimete(C,tablero,ancho,alto);
	
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
	if(jugador!=NULL){
		for(int i=0;i<enemigos.size();i++){
			if(!enemigos[i]->moviendose){
				//enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
				enemigos[i]->hallaMejorCamino(tablero,jugador->f,jugador->c);
			

			}
		}
	}
}

bool GameController::Añade_bala(int ancho, int alto, int max_balas){
	CBala *bala;
	if (balas.size() == max_balas) return false;
	if(jugador!=NULL){
		bala = new CBala(jugador->f, jugador->c, ancho, alto, jugador->dir);
		balas.push_back(bala);
		return true;
	}else
		return false;
}


bool GameController::MoverJugador(Direccion dir){
	return jugador->MueveteHacia(dir,tablero);
}

void GameController::RecontruyeMapa(){
}

void GameController::GeneraMonstruos(){

	if(enemigos.size()<max_monstruos){
		int prob=rand()%100;
		if(prob<rate){
			int r=rand()%spawn_points.size();
			pair<int,int> selec=spawn_points[r];
			pair<int,int> casilla=dameCasillaNormalJuntoAGenerador(selec.first,selec.second);
			enemigos.push_back(new CEnemigo(casilla.first,casilla.second));
			enemigos[enemigos.size()-1]->hallaMejorCamino(tablero,jugador->f,jugador->c);
		}

	}

}

pair<int,int> GameController::dameCasillaNormalJuntoAGenerador(int f,int c){
	vector<pair<int,int>> posibilidades;
			posibilidades.push_back(make_pair(f,c+1)); // DERECHA
			posibilidades.push_back(make_pair(f,c-1)); // IZQUIERDA
			posibilidades.push_back(make_pair(f+1,c)); // ABAJO
			posibilidades.push_back(make_pair(f-1,c)); // ARRIBA
			

			for(int j=0;j<posibilidades.size();j++){
				pair<int,int> coord=posibilidades[j];
				int fCaso=coord.first;
				int cCaso=coord.second;
				if(fCaso>=0 && fCaso<tablero->f && cCaso>=0 && cCaso<tablero->c){
					if(tablero->getTipoCasilla(fCaso,cCaso)==NORMAL){
						return make_pair(fCaso,cCaso);
					}
				}
				
			}
}


bool GameController::atrapoAmmo(){
	if(bonusAmmo!=NULL){{
		if( bonusAmmo->colision(jugador)){
			//-----AGREGAR BALAS

			delete bonusAmmo;
			bonusAmmo=NULL;
			return true;
		}
	}
	}else
		return false;

}

bool GameController::JugadorEstaMoviendose(){
	if(jugador!=NULL)
		return jugador->moviendose;
	else
		return false;
}
int GameController::Get_numBalas(){
	return balas.size();
}

bool GameController::atraparonPersonaje(){
	bool cond=false;
	for(int i=0;i<enemigos.size();i++){
		if(enemigos[i]->colision(jugador)){
			cond=true;
			delete jugador;
			jugador=NULL;
			return true;
		}
	}
	return cond;
}


void GameController::masAmmo(){
	int prob=rand()%1000;
	if(prob<=5){
		int f=-0,c=0;
		while(tablero->getTipoCasilla(f,c)!=NORMAL){
			f=rand()%tablero->f;	c=rand()%tablero->c;
		}
		bonusAmmo=new CPowerUp(f,c);GameController;

	}
}