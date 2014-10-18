#include "stdafx.h"
#include "Personaje.h"
#include <queue>

CPersonaje::CPersonaje(int f,int c)
{
	this->f=f;
	this->c=c;
	w=h=64;
	col=0;
	moviendose=false;
}


CPersonaje::~CPersonaje(void)
{
}

bool CPersonaje::casillaIsValid(CTablero* tablero,int f,int c){
	return  (f>=0 && f<tablero->f) &&
			(c>=0 && c<tablero->c) &&
			(tablero->esNormal(f,c));
}

//--------------------------------------

CJugador::CJugador(int f,int c) : CPersonaje(f,c){
	dir=ABAJO;
	fil=11;
}

void Muevete(){
}

bool CJugador::MueveteHacia(Direccion dir,CTablero* tablero){
	if(this->dir!=dir){
		this->dir=dir;
		switch(dir){
			case IZQUIERDA:	fil=9;	break;
			case DERECHA:	fil=11;	break;
			case ARRIBA:	fil=8;	break;
			case ABAJO:		fil=10;	break;
		}
		return false;
	}



	int i=f,j=c;
	switch(dir){
		case IZQUIERDA:	j--;	break;
		case DERECHA:	j++;	break;
		case ARRIBA:	i--;	break;
		case ABAJO:		i++;	break;
	}


	if(casillaIsValid(tablero,i,j)){
			moviendose=true;
		switch(dir){
			case IZQUIERDA:	fil=9;	break;
			case DERECHA:	fil=11;	break;
			case ARRIBA:	fil=8;	break;
			case ABAJO:		fil=10;	break;
		}
		this->dir=dir;
		return true;
	}else{
		this->dir=dir;
		return false;
	}

}

void CJugador::Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto){
	int anchoElipse=ancho/tablero->c;
	int altoElipse=alto/tablero->f;
	int y=f * altoElipse;
	int x=anchoElipse * this->c;
	/*System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green);
	C->FillEllipse(b,x,y,anchoElipse,altoElipse);*/
	int dx=0,dy=0;
	if(moviendose && MueveteHacia(dir,tablero)){
		col++;
		switch(dir){
			case IZQUIERDA:	dx-=col*anchoElipse/3;		break;
			case DERECHA:	dx+=col*anchoElipse/3;		break;
			case ARRIBA:	dy-=col*altoElipse/3;		break;
			case ABAJO:		dy+=col*altoElipse/3;		break;
		}
		if(col>=3){
			col=0;	moviendose=false;
			switch(dir){
				case IZQUIERDA:	this->c--;	break;
				case DERECHA:	this->c++;	break;
				case ARRIBA:	f--;	break;
				case ABAJO:		f++;	break;
			}
		}
	}

	System::Drawing::Rectangle porcion=System::Drawing::Rectangle(col*w,fil*h,w,h);
	System::Drawing::Bitmap ^bmp=gcnew System::Drawing::Bitmap("sprite_personaje.png");

	System::Drawing::Rectangle zonaMostrar= System::Drawing::Rectangle(x+dx,y+dy,anchoElipse,altoElipse);
	C->DrawImage(bmp,zonaMostrar,porcion,System::Drawing::GraphicsUnit::Pixel);

	//C->DrawImage(bmp,x+dx,y+dy,porcion,System::Drawing::GraphicsUnit::Pixel);
	delete bmp;
	
}

//-----------------------------------------

CEnemigo::CEnemigo(int f,int c) : CPersonaje(f,c){
	moviendose=false;
	fil=11;
	dir=ABAJO;
}

void CEnemigo::Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto){
	int anchoElipse=ancho/tablero->c;
	int altoElipse=alto/tablero->f;
	int y=f * altoElipse;
	int x=anchoElipse * this->c;
	/*System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green);
	C->FillEllipse(b,x,y,anchoElipse,altoElipse);*/
	int dx=0,dy=0;
	if(moviendose){
		col++;
		switch(dir){
			case IZQUIERDA:	dx-=col*anchoElipse/6;		break;
			case DERECHA:	dx+=col*anchoElipse/6;		break;
			case ARRIBA:	dy-=col*altoElipse/6;		break;
			case ABAJO:		dy+=col*altoElipse/6;		break;
		}
		if(col>=6){
			col=0;	moviendose=false;
			switch(dir){
				case IZQUIERDA:	this->c--;	break;
				case DERECHA:	this->c++;	break;
				case ARRIBA:	f--;	break;
				case ABAJO:		f++;	break;
			}
		}
	}

	System::Drawing::Rectangle porcion=System::Drawing::Rectangle(col*w,fil*h,w,h);
	System::Drawing::Bitmap ^bmp=gcnew System::Drawing::Bitmap("enemigo.png");

	System::Drawing::Rectangle zonaMostrar= System::Drawing::Rectangle(x+dx,y+dy,anchoElipse,altoElipse);
	C->DrawImage(bmp,zonaMostrar,porcion,System::Drawing::GraphicsUnit::Pixel);

	delete bmp;
}


//void CEnemigo::hallaMejorCamino(CTablero* tablero,int fObjetivo,int cObjetivo){
//	vector<vector<int>> distancias;
//	distancias.resize(tablero->f);
//	for(int i=0;i<distancias.size();i++)
//		distancias[i].resize(tablero->c,-1);
//	distancias[f][c]=0;
//	bool cond=true;
//	queue<pair<int,int>> pendientes;
//	BFS(tablero,distancias,f,c,make_pair(fObjetivo,cObjetivo),cond,pendientes);
//	stack<pair<int,int>> recorrido;
//	armaRecorrido(recorrido,distancias,fObjetivo,cObjetivo);
//	dir=recorrido.top();
//
//	switch(dir){
//			case IZQUIERDA:	fil=9;	break;
//			case DERECHA:	fil=11;	break;
//			case ARRIBA:	fil=8;	break;
//			case ABAJO:		fil=10;	break;
//		}
//
//	moviendose=true;
//}


stack<pair<int,int>> CEnemigo::hallaMejorCamino(CTablero* tablero,int fObjetivo,int cObjetivo){
	/*---------DFS--------
	vector<vector<bool>> explorados;
	explorados.resize(tablero->f);
	for(int i=0;i<explorados.size();i++)
		explorados[i].resize(tablero->c,false);

	stack<pair<int,int>> solucion,recorrido;
	int menor=0;
	DFS(tablero,explorados,f,c,fObjetivo,cObjetivo,menor,recorrido,solucion);
	return solucion;
	----------------------*/
	vector<vector<int>> distancias;
	distancias.resize(tablero->f);
	for(int i=0;i<distancias.size();i++)
		distancias[i].resize(tablero->c,-1);
	distancias[f][c]=0;
	bool cond=true;
	queue<pair<int,int>> pendientes;
	BFS(tablero,distancias,f,c,make_pair(fObjetivo,cObjetivo),cond,pendientes);
	stack<pair<int,int>> recorrido;
	armaRecorrido(recorrido,distancias,fObjetivo,cObjetivo);

	recorrido.pop();
	if(!recorrido.empty()){
			pair<int,int> coord=recorrido.top();
			int f=coord.first,c=coord.second;
			vector<pair<int,int>> posibilidades;
			posibilidades.push_back(make_pair(f,c+1)); // DERECHA
			posibilidades.push_back(make_pair(f,c-1)); // IZQUIERDA
			posibilidades.push_back(make_pair(f+1,c)); // ABAJO
			posibilidades.push_back(make_pair(f-1,c)); // ARRIBA
			

			for(int j=0;j<posibilidades.size();j++){
				pair<int,int> coord=posibilidades[j];
				int fCaso=coord.first;
				int cCaso=coord.second;
				if(fCaso==this->f && cCaso==this->c){
					this->dir=(Direccion)j;
					this->moviendose=true;
					
				switch(dir){
						case IZQUIERDA:	fil=9;	break;
						case DERECHA:	fil=11;	break;
						case ARRIBA:	fil=8;	break;
						case ABAJO:		fil=10;	break;
					}

				}
			}
	}

	return recorrido;
}



void CEnemigo::DFS(CTablero* tablero,vector<vector<bool>> explorados,int f,int c,int fObjetivo,int cObjetivo,
	int &menor, stack<pair<int,int>> recorrido,stack<pair<int,int>> &solucion){
	explorados[f][c]=true;
	recorrido.push(make_pair(f,c));
	if(c==cObjetivo && f==fObjetivo){
		int n=recorrido.size();
		if(n<menor || menor==0){
			menor=n;
			solucion=recorrido;
		}
		return;
	}

	vector<pair<int,int>> posibilidades;
	posibilidades.push_back(make_pair(f-1,c)); // IZQUIERDA
	posibilidades.push_back(make_pair(f,c-1)); // ARRIBA
	posibilidades.push_back(make_pair(f+1,c)); // DERECHA
	posibilidades.push_back(make_pair(f,c+1)); // ABAJO

	for(int i=0;i<posibilidades.size();i++){
		pair<int,int> coord=posibilidades[i];
		int fCaso=coord.first;
		int cCaso=coord.second;
		if(!explorados[fCaso][cCaso] && casillaIsValid(tablero,fCaso,cCaso)){
			recorrido.push(make_pair(fCaso,cCaso));
			DFS(tablero,explorados,fCaso,cCaso,fObjetivo,cObjetivo,menor,recorrido,solucion);
			recorrido.pop();
		}
	}
}


void CEnemigo::BFS(CTablero* tablero,vector<vector<int>> &explorados,int fila,int col,pair<int,int> objetivo,bool &cond,queue<pair<int,int>> &pendientes){
	
	int c=col,fObjetivo=objetivo.first,cObjetivo=objetivo.second;
	if(fila==fObjetivo && c==cObjetivo){
		cond=false;
		return;
	}

	vector<pair<int,int>> posibilidades;
	posibilidades.push_back(make_pair(fila-1,c)); // IZQUIERDA
	posibilidades.push_back(make_pair(fila,c-1)); // ARRIBA
	posibilidades.push_back(make_pair(fila+1,c)); // DERECHA
	posibilidades.push_back(make_pair(fila,c+1)); // ABAJO

	for(int i=0;i<posibilidades.size();i++){
		pair<int,int> coord=posibilidades[i];
		int fCaso=coord.first;
		int cCaso=coord.second;
		if(explorados[fCaso][cCaso]==-1 && casillaIsValid(tablero,fCaso,cCaso)){
			int distancia=explorados[fila][c];
			explorados[fCaso][cCaso]=distancia+1;
			pendientes.push(make_pair(fCaso,cCaso));
		}
	}
	while(!pendientes.empty() && cond){
		pair<int,int> siguiente=pendientes.front();
		pendientes.pop();
		BFS(tablero,explorados,siguiente.first,siguiente.second,objetivo,cond,pendientes);
	}
}

//void CEnemigo::armaRecorrido(stack<Direccion> &recorrido,vector<vector<int>>distancias,int f,int c){
//
//	if(distancias[f][c]==0)	return;
//
//	vector<pair<int,int>> posibilidades;
//	posibilidades.push_back(make_pair(f,c-1)); // IZQUIERDA
//	posibilidades.push_back(make_pair(f-1,c)); // ARRIBA
//	posibilidades.push_back(make_pair(f,c+1)); // DERECHA
//	posibilidades.push_back(make_pair(f+1,c)); // ABAJO
//
//	for(int i=0;i<posibilidades.size();i++){
//		pair<int,int> coord=posibilidades[i];
//		int fCaso=coord.first;
//		int cCaso=coord.second;
//		if(distancias[fCaso][cCaso]==distancias[f][c]-1){
//			switch(i){
//				case IZQUIERDA:	recorrido.push(DERECHA);	break;
//				case DERECHA:	recorrido.push(IZQUIERDA);	break;
//				case ARRIBA:	recorrido.push(ABAJO);		break;
//				case ABAJO:		recorrido.push(ARRIBA);		break;
//			}
//			//recorrido.push((Direccion)i);
//			armaRecorrido(recorrido,distancias,fCaso,cCaso);
//			break;
//		}
//	}
//}
//

void CEnemigo::armaRecorrido(stack<pair<int,int>> &recorrido,vector<vector<int>>distancias,int f,int c){
	recorrido.push(make_pair(f,c));

	if(distancias[f][c]==0)	return;

	vector<pair<int,int>> posibilidades;
	posibilidades.push_back(make_pair(f-1,c)); // IZQUIERDA
	posibilidades.push_back(make_pair(f,c-1)); // ARRIBA
	posibilidades.push_back(make_pair(f+1,c)); // DERECHA
	posibilidades.push_back(make_pair(f,c+1)); // ABAJO

	for(int i=0;i<posibilidades.size();i++){
		pair<int,int> coord=posibilidades[i];
		int fCaso=coord.first;
		int cCaso=coord.second;
		if(distancias[fCaso][cCaso]==distancias[f][c]-1){
			armaRecorrido(recorrido,distancias,fCaso,cCaso);
			break;
		}
	}
}


void CEnemigo::avanza(CTablero* tablero,int fO,int cO){
	if(camino.empty())
		hallaMejorCamino(tablero,fO,cO);

	if(!moviendose){
		dir=camino.front();
		camino.pop_back();
		moviendose=true;
	}
}

bool CEnemigo::colision(CJugador* jugador){
	
	if ((jugador->f == f) && (jugador->c == c)){
		f = -1; c == -1;
		return true;
	}
	return false;
}

//--------------------------------------

CBala::CBala(int f, int c, int ancho, int alto,Direccion direccion ) : CPersonaje(f, c){
	 direc = direccion;
}

void CBala::Imprimete(System::Drawing::Graphics ^C, CTablero* tablero, int ancho, int alto){
	
	int anchoElipse = ancho / tablero->c;
	int altoElipse = alto / tablero->f;
	int y = f * (alto / tablero->f);
	int x = (ancho / tablero->c) * c;
	
	System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Blue);
	C->FillEllipse(b, x + anchoElipse / 3, y + altoElipse / 3, anchoElipse / 3, altoElipse / 3);
}
bool CBala::muevete(CTablero* tablero){
	int i = f, j = c;
	switch (direc){
		case IZQUIERDA:	j--;	break;
		case DERECHA:	j++;	break;
		case ARRIBA:	i--;	break;
		case ABAJO:		i++;	break;
	}
	if (casillaIsValid(tablero, i, j)){
		f = i;	c = j;
	}
	else{ f = -1; c = -1;  }
	return true;

}

bool CBala::Colision(CEnemigo *enemigo){
	if ((enemigo->f == f) && (enemigo->c == c)){
		f = -1; c == -1;
		return true;
	}
	return false;
}
//-----