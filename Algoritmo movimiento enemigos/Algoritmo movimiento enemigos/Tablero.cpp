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
					switch(tablero[i][j]){
					case PARED_EXTERIOR:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::Black);	break;
					case NORMAL:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::DarkGray);	break;
					case PARED:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);	break;
					case GENERADOR:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::Peru);	break;
					case RECORRIDO:
						b= gcnew System::Drawing::SolidBrush(System::Drawing::Color::Yellow);	break;
					}
					C->FillRectangle(b,x,y,anchoBloque,altoBloque);
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