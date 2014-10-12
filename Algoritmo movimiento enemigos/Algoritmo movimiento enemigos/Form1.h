#pragma once
#include <stdio.h>
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

	public:
		Form1(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Button^  button1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(168, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(355, 324);
			this->panel1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Hallar caminos";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 389);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 controlador= new GameController();

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
				 ImprimeJuego();
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 controlador->HallarCaminos();
		 }
};
}

