#pragma once
#include <stdio.h>
#include <time.h>
#include "GameController.h"



namespace Algoritmomovimientoenemigos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		GameController* controlador;


			 clock_t start;
	private: System::Windows::Forms::Label^  label2;

			 double tiempo;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labelBalas;
	private: System::Windows::Forms::Label^  labelPuntaje;
	private: System::Windows::Forms::Label^  labelTiempo;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Label^  msgCarga;

			 int max_num_balas ;
			 int cont,lastTime;
	private: System::Windows::Forms::Label^  lblPt;
	private: System::Windows::Forms::Label^  labelPtj;
	private: System::Windows::Forms::Label^  labelPerdiste;
	private: System::Windows::Forms::Button^  btnJugar;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public:
		Form1(void)
		{
			InitializeComponent();
			start = clock();
			cont=0;
			lastTime=0;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->msgCarga = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelBalas = (gcnew System::Windows::Forms::Label());
			this->labelPuntaje = (gcnew System::Windows::Forms::Label());
			this->labelTiempo = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelPerdiste = (gcnew System::Windows::Forms::Label());
			this->labelPtj = (gcnew System::Windows::Forms::Label());
			this->lblPt = (gcnew System::Windows::Forms::Label());
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnJugar);
			this->panel1->Controls->Add(this->lblPt);
			this->panel1->Controls->Add(this->labelPtj);
			this->panel1->Controls->Add(this->labelPerdiste);
			this->panel1->Controls->Add(this->msgCarga);
			this->panel1->Location = System::Drawing::Point(0, 65);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(758, 557);
			this->panel1->TabIndex = 0;
			// 
			// msgCarga
			// 
			this->msgCarga->AutoSize = true;
			this->msgCarga->BackColor = System::Drawing::Color::Black;
			this->msgCarga->Font = (gcnew System::Drawing::Font(L"Poplar Std", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->msgCarga->ForeColor = System::Drawing::Color::White;
			this->msgCarga->Location = System::Drawing::Point(263, 126);
			this->msgCarga->Name = L"msgCarga";
			this->msgCarga->Size = System::Drawing::Size(241, 32);
			this->msgCarga->TabIndex = 10;
			this->msgCarga->Text = L"Generando siguiente nivel...";
			this->msgCarga->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(133, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Balas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(324, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Tiempo restante";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(583, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Puntaje";
			// 
			// labelBalas
			// 
			this->labelBalas->AutoSize = true;
			this->labelBalas->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelBalas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelBalas->Location = System::Drawing::Point(205, 8);
			this->labelBalas->Name = L"labelBalas";
			this->labelBalas->Size = System::Drawing::Size(32, 25);
			this->labelBalas->TabIndex = 7;
			this->labelBalas->Text = L"x/x";
			// 
			// labelPuntaje
			// 
			this->labelPuntaje->AutoSize = true;
			this->labelPuntaje->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPuntaje->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelPuntaje->Location = System::Drawing::Point(523, 9);
			this->labelPuntaje->Name = L"labelPuntaje";
			this->labelPuntaje->Size = System::Drawing::Size(44, 25);
			this->labelPuntaje->TabIndex = 8;
			this->labelPuntaje->Text = L"xxxx";
			// 
			// labelTiempo
			// 
			this->labelTiempo->AutoSize = true;
			this->labelTiempo->Font = (gcnew System::Drawing::Font(L"Poplar Std", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelTiempo->ForeColor = System::Drawing::Color::Orange;
			this->labelTiempo->Location = System::Drawing::Point(362, 30);
			this->labelTiempo->Name = L"labelTiempo";
			this->labelTiempo->Size = System::Drawing::Size(40, 32);
			this->labelTiempo->TabIndex = 9;
			this->labelTiempo->Text = L"x/x";
			// 
			// timer2
			// 
			this->timer2->Interval = 500;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick_1);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, -6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(758, 76);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// labelPerdiste
			// 
			this->labelPerdiste->AutoSize = true;
			this->labelPerdiste->BackColor = System::Drawing::Color::Black;
			this->labelPerdiste->Font = (gcnew System::Drawing::Font(L"Poplar Std", 40, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPerdiste->ForeColor = System::Drawing::Color::White;
			this->labelPerdiste->Location = System::Drawing::Point(294, 158);
			this->labelPerdiste->Name = L"labelPerdiste";
			this->labelPerdiste->Size = System::Drawing::Size(184, 64);
			this->labelPerdiste->TabIndex = 11;
			this->labelPerdiste->Text = L"Perdiste!";
			this->labelPerdiste->Visible = false;
			// 
			// labelPtj
			// 
			this->labelPtj->AutoSize = true;
			this->labelPtj->BackColor = System::Drawing::Color::Black;
			this->labelPtj->Font = (gcnew System::Drawing::Font(L"Poplar Std", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->labelPtj->ForeColor = System::Drawing::Color::White;
			this->labelPtj->Location = System::Drawing::Point(345, 237);
			this->labelPtj->Name = L"labelPtj";
			this->labelPtj->Size = System::Drawing::Size(86, 32);
			this->labelPtj->TabIndex = 12;
			this->labelPtj->Text = L"Puntaje:";
			this->labelPtj->Visible = false;
			// 
			// lblPt
			// 
			this->lblPt->AutoSize = true;
			this->lblPt->BackColor = System::Drawing::Color::Black;
			this->lblPt->Font = (gcnew System::Drawing::Font(L"Poplar Std", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPt->ForeColor = System::Drawing::Color::White;
			this->lblPt->Location = System::Drawing::Point(362, 288);
			this->lblPt->Name = L"lblPt";
			this->lblPt->Size = System::Drawing::Size(0, 32);
			this->lblPt->TabIndex = 13;
			this->lblPt->Visible = false;
			// 
			// btnJugar
			// 
			this->btnJugar->BackColor = System::Drawing::Color::White;
			this->btnJugar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJugar->Font = (gcnew System::Drawing::Font(L"Poplar Std", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btnJugar->Location = System::Drawing::Point(320, 323);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(142, 42);
			this->btnJugar->TabIndex = 14;
			this->btnJugar->Text = L"Volver a jugar!";
			this->btnJugar->UseVisualStyleBackColor = false;
			this->btnJugar->Visible = false;
			this->btnJugar->Click += gcnew System::EventHandler(this, &Form1::btnJugar_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 663);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->labelTiempo);
			this->Controls->Add(this->labelPuntaje);
			this->Controls->Add(this->labelBalas);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->KeyPreview = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 controlador= new GameController();
				 max_num_balas = 40;

			 }

			void ImprimeJuego(){
				Graphics ^g=panel1->CreateGraphics();
				float gWidth = (int)g->VisibleClipBounds.Width;
				float gHeight = (int)g->VisibleClipBounds.Height;
				BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( gWidth + 1, gHeight + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, gWidth, gHeight));
				buffer->Graphics->Clear(this->BackColor);

				
				controlador->ImprimeJuego(buffer->Graphics,gWidth,gHeight);
				
			
				buffer->Render(g);
				delete g;
				delete buffer;

			}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(controlador->atraparonPersonaje()){
					timer1->Enabled=false;
					//MessageBox::Show(this,"Perdiste!");
					termina();
					return;
				}

				controlador->GeneraMonstruos();


				 ImprimeJuego();

				 controlador->MueveEnemigos();
				 controlador->masAmmo();
				 

				 controlador->atrapoAmmo();

				 

				 tiempo = ((int)clock() - start-lastTime) / CLOCKS_PER_SEC;
				 int tiempoRestante=controlador->tiempo-tiempo;
				 if(tiempoRestante<=0){
					 timer1->Enabled=false;
					 ReiniciarNivel();
					 return;
				 }


				 labelTiempo->Text = tiempoRestante.ToString();
				 if(controlador->tiempo - tiempo<=controlador->tiempo/4)	labelTiempo->ForeColor=Color::Red;
				 else labelTiempo->ForeColor=Color::Orange;

				 labelBalas->Text = (max_num_balas - controlador->Get_numBalas()).ToString() + "/" + max_num_balas.ToString();
				 labelPuntaje->Text = (controlador->puntaje).ToString();
			 }

			 void termina(){
				 
			Graphics ^g=panel1->CreateGraphics();
				float gWidth = (int)g->VisibleClipBounds.Width;
				float gHeight = (int)g->VisibleClipBounds.Height;
				BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( gWidth + 1, gHeight + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, gWidth, gHeight));
				buffer->Graphics->Clear(Color::Black);
				
				buffer->Render(g);
				delete g;
				delete buffer;

				 labelPerdiste->Visible=true;
				 lblPt->Visible=true;
				 labelPtj->Visible=true;
				 lblPt->Text=controlador->puntaje.ToString();
				 btnJugar->Visible=true;
			 }

	


private: System::Void Form1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { 
			char c = e->KeyChar;
			if(!controlador->JugadorEstaMoviendose()){
				if (c == 'a' || c == 'A'){
					controlador->MoverJugador(IZQUIERDA);
				}else if(c == 'd' || c == 'D'){
					controlador->MoverJugador(DERECHA);
				}else if(c == 'w' || c == 'W'){
					controlador->MoverJugador(ARRIBA);
				}else if(c == 's' || c == 'S'){
					controlador->MoverJugador(ABAJO);
				}else if(c == 'v' || c == 'V'){
					controlador->Añade_bala(panel1->Width, panel1->Height, max_num_balas); // este 20 es el maximo numero de balas q puedo disparar 
				}
			}
		 }

		void ReiniciarNivel(){

			controlador->RecontruyeMapa();
			controlador->tiempo+=5;
			controlador->rate+=1;
			timer2->Enabled=true;
			msgCarga->Visible=true;
		}

private: System::Void timer2_Tick_1(System::Object^  sender, System::EventArgs^  e) {
			 Graphics ^g=panel1->CreateGraphics();
				int gWidth = (int)g->VisibleClipBounds.Width;
				int gHeight = (int)g->VisibleClipBounds.Height;
				BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( gWidth + 1, gHeight + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, gWidth, gHeight));
				buffer->Graphics->Clear(Color::Black);

				int ancho=gWidth/2,alto=20;
				System::Drawing::SolidBrush ^pen=gcnew SolidBrush(Color::Yellow);
				buffer->Graphics->FillRectangle(pen,ancho-ancho/2,(gHeight-alto)/2,ancho*cont/5,alto);
				cont++;
				if(cont>=6){
					this->msgCarga->Visible=false;
					timer2->Enabled=false;
					timer1->Enabled=true;
					cont=0;
					lastTime=(int)clock()-start;
					return;
				}
				
			
				buffer->Render(g);
				delete g;
				delete buffer;


		 }
private: System::Void btnJugar_Click(System::Object^  sender, System::EventArgs^  e) {
			 delete controlador;
			 controlador=new GameController();

			 labelPerdiste->Visible=false;
				 lblPt->Visible=false;
				 labelPtj->Visible=false;
				 btnJugar->Visible=false;

			 timer2->Enabled=true;
		 }
};
}

