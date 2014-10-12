#include "stdafx.h"
#include "Personaje.h"


CPersonaje::CPersonaje(int f,int c)
{
	this->f=f;
	this->c=c;
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
}

void CJugador::MueveteEnDireccion(Direccion dir,CTablero* tablero){
	int i=f,j=c;
	switch(dir){
		case IZQUIERDA:	c--;	break;
		case DERECHA:	c++;	break;
		case ARRIBA:	f--;	break;
		case ABAJO:		f++;	break;
	}
	if(casillaIsValid(tablero,i,f)){
		f=i;	c=i;
	}
}

void CJugador::Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto){
	int anchoElipse=ancho/tablero->c;
	int altoElipse=alto/tablero->f;
	int y=f * altoElipse;
	int x=anchoElipse * c;
	System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green);
	C->FillEllipse(b,x,y,anchoElipse,altoElipse);
}

//-----------------------------------------

CEnemigo::CEnemigo(int f,int c) : CPersonaje(f,c){
}

void CEnemigo::Imprimete(System::Drawing::Graphics ^C,CTablero* tablero,int ancho,int alto){
	int anchoElipse=ancho/tablero->c;
	int altoElipse=alto/tablero->f;
	int y=f * altoElipse;
	int x=anchoElipse * c;
	System::Drawing::SolidBrush ^b = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Red);
	C->FillEllipse(b,x,y,anchoElipse,altoElipse);
}


stack<pair<int,int>> CEnemigo::hallaMejorCamino(CTablero* tablero,int fObjetivo,int cObjetivo){
	vector<vector<bool>> explorados;
	explorados.resize(tablero->f);
	for(int i=0;i<explorados.size();i++)
		explorados[i].resize(tablero->c,false);

	stack<pair<int,int>> solucion,recorrido;
	int menor=0;
	DFS(tablero,explorados,f,c,fObjetivo,cObjetivo,menor,recorrido,solucion);
	return solucion;
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