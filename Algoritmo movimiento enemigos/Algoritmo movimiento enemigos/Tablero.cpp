#include "stdafx.h"
#include "Tablero.h"


CTablero::CTablero(void)
{
	freopen("in.txt","rt",stdin);
				freopen("out.txt","wt",stdout);

			
				scanf("%d %d",&f,&c);
				tablero.resize(f);
				for(int i=0;i<f;i++){
					tablero[i].resize(c);
					for(int j=0;j<c;j++){
						int a;
						scanf("%d",&a);
						tablero[i][j]=a;
					}
				}

}


CTablero::~CTablero(void)
{
}


void CTablero::Imprimete(System::Drawing::Graphics ^C,int ancho,int alto){
			int anchoBloque=ancho/c;
			int altoBloque=alto/f;
			int x=0,y=0;
			for(int i=0;i<tablero.size();i++){
				tablero[i].resize(c);
				for(int j=0;j<tablero[i].size();j++){
					System::Drawing::SolidBrush ^b;
					//System::Drawing::Bitmap ^bmp;
					switch(tablero[i][j]){
					case PARED_EXTERIOR:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(173,112,55));	break;
						//bmp=gcnew  System::Drawing::Bitmap("pared.png");		break;
					case NORMAL:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(184,189,85));	break;
						//bmp=gcnew  System::Drawing::Bitmap("normal.png");		break;
					case PARED:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(191,135,75));	break;
						//bmp=gcnew  System::Drawing::Bitmap("pared.png");		break;
					case GENERADOR:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(105,181,134));	break;
						//bmp=gcnew  System::Drawing::Bitmap("pared.png");		break;
					case RECORRIDO:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow);	break;
						//bmp=gcnew  System::Drawing::Bitmap("pared.png");		break;
					}
					C->FillRectangle(b,x,y,anchoBloque,altoBloque);
					//System::Drawing::Rectangle zonaMostrar= System::Drawing::Rectangle(x,y,anchoBloque,altoBloque);
					//System::Drawing::Rectangle porcion= System::Drawing::Rectangle(0,0,60,60);
					//C->DrawImage(bmp,zonaMostrar,porcion,System::Drawing::GraphicsUnit::Pixel);
					x+=anchoBloque;	
				}
				y+=altoBloque;
				x=0;
			}
}

bool CTablero::esNormal(int f,int c){
	return (tablero[f][c]==NORMAL || tablero[f][c]==RECORRIDO);
}

void CTablero::cambiarBloque(int f,int c,Casilla tipo){
	tablero[f][c]=tipo;
}

Casilla CTablero::getTipoCasilla(int f,int c){
	return (Casilla) tablero[f][c];
}


vector<pair<int,int>> CTablero::getSpawnPoints(){
	vector<pair<int,int>> resultado;
	for(int i=0;i<tablero.size();i++){
		for(int j=0;j<tablero[i].size();j++){
			if(tablero[i][j]==GENERADOR)
				resultado.push_back(make_pair(i,j));
		}
	}
	return resultado;
}