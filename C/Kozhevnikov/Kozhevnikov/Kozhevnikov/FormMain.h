#pragma once
#include <windows.h> 
#include <string>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include "BookTree.h"

namespace Kozhevnikov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Drawing::Imaging;





	/// <summary>
	/// Сводка для FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{

	
	public:
		FormMain(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ button2;











	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolTip^ toolTip1;





	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Control;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(1000, 588);
			this->button2->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 28);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Кнопочка";
			this->toolTip1->SetToolTip(this->button2, L"Текст");
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormMain::button2_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Location = System::Drawing::Point(9, 12);
			this->panel1->Margin = System::Windows::Forms::Padding(0, 3, 0, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1182, 549);
			this->panel1->TabIndex = 11;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 20);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormMain::pictureBox1_Paint);
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipTitle = L"Книга";
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 729);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->MaximizeBox = false;
			this->Name = L"FormMain";
			this->Text = L"FormMain";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion	



		/*
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		*/

		cli::array<Button^>^ b = gcnew cli::array<Button^>(100);
		
		struct bookBTree* root;

		struct bookBTree* addTree(struct bookBTree* p, Book w, int lev) {
			if (p == NULL) {
				
				p = (struct bookBTree*)malloc(sizeof(struct bookBTree));				
				p->key = w.udc;
				p->b = new Book(w.udc, w.authorFio, w.bookName, w.publishYear, w.count);
				p->level = lev;
				p->left = p->right = NULL;
			}
			else if (w.udc < p->key)
				p->left = addTree(p->left, w, lev++);
			else if (w.udc > p->key)
				p->right = addTree(p->right, w, lev++);
			else
			{
				p->b->count = p->b->count++;//Если id книг совпадает, то прибавим 1 к кол-ву книг в библиотеке			
			}
			return p;
		}

		void treeprint(struct bookBTree* p) {
			if (p != NULL) {
				treeprint(p->left);
				MessageBox::Show(System::Convert::ToString(p->key));

				treeprint(p->right);
			}
		}

		void drawTree(struct bookBTree* p,int x, float xOffset, int y, Graphics^ g, int & cnt, char d)
		{
			if (p != NULL) {
				System::Drawing::Pen^ p1 = gcnew System::Drawing::Pen(Color::Black, 2);
				System::Drawing::Brush^ b1 = gcnew System::Drawing::SolidBrush(Color::White);
				System::Drawing::Rectangle rect = System::Drawing::Rectangle(x, y, 50, 50);
				System::Drawing::Font^ f1 = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(2));
				//System::Drawing::Rectangle rect = System::Drawing::Rectangle(x, );
				System::Drawing::Point po1 = System::Drawing::Point(x, y);
				System::Drawing::Point po2 = System::Drawing::Point(x - xOffset, y - 100);
				if (d == 'l' && y > 0) {
					po1 = System::Drawing::Point(x+25, y+25);
					po2 = System::Drawing::Point(x + xOffset*2+ 25, y - 100 + 25);
					g->DrawLine(p1, po1, po2);
					g->FillEllipse(b1, x + int(xOffset * 2), y - 100, 50, 50);
				}
				if (d == 'r' && y > 0) {
					po1 = System::Drawing::Point(x+25, y+25);					
					po2 = System::Drawing::Point(x - xOffset*2 + 25, y - 100 + 25);
					g->DrawLine(p1, po1, po2);
					g->FillEllipse(b1, x-int(xOffset*2), y-100, 50, 50);
				}

				
				
				g->DrawEllipse(p1, rect);
				g->FillEllipse(b1,rect);
				b1 = gcnew System::Drawing::SolidBrush(Color::Black);
				//g->DrawString(System::Convert::ToString(p->key), f1, b1, x+10, y+51);

				drawTree(p->right, x+xOffset, xOffset/2, y+100,g, cnt, 'r');

				drawTree(p->left, x - xOffset, xOffset / 2, y + 100,g, cnt, 'l');
			}
		}

		void addToolTips(struct bookBTree* p, int x, float xOffset, int y, Graphics^ g, int& cnt)
		{
			if (p != NULL) {
				
				b[cnt] = gcnew System::Windows::Forms::Button();
				b[cnt]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				b[cnt]->Location = System::Drawing::Point(x+12, y+12);
				b[cnt]->Name = L"button" + System::Convert::ToString(cnt);
				b[cnt]->Size = System::Drawing::Size(34, 34);
				b[cnt]->TabIndex = 12;
				b[cnt]->Text = System::Convert::ToString(p->b->udc);
				b[cnt]->BackColor = System::Drawing::Color::White;
				b[cnt]->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				b[cnt]->FlatAppearance->BorderColor = System::Drawing::Color::White;
				//b[cnt]->UseVisualStyleBackColor = true;
				b[cnt]->Parent = panel1;
				toolTip1->SetToolTip(b[cnt], p->b->GetStr1());
				panel1->Controls->Add(b[cnt]);

				//g->DrawLine(p1, p2);
				cnt = cnt + 1;
				addToolTips(p->right, x + xOffset, xOffset / 2, y + 100, g, cnt);

				//MessageBox::Show(System::Convert::ToString(p->key));
				//System::String ^ str =  gcnew String(p->b->bookName.c_str());
				//MessageBox::Show(str);
				cnt = cnt + 1;
				addToolTips(p->left, x - xOffset, xOffset / 2, y + 100, g, cnt);
			}
		}

		void test()
		{
			treeInit();
		}

		void treeInit()
		{
					
			root = NULL;
			
			Book b1 = Book(193, "Михайлов П.В.", "Как перестать и начать", 2013, 32);
			root = addTree(root, b1, 0);
			
			b1 = Book(192, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(195, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(200, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(196, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(191, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);	

			b1 = Book(1, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(194, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(204, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(201, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(206, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(197, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(202, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);

			b1 = Book(204, "Михайлов П.В.", "Как перестать и начать да", 2013, 1);
			root = addTree(root, b1, 0);
		
			//treeprint(root);
		}


		/*
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		*/



	

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		Bitmap^ bmp = gcnew Bitmap(1100, 1000, PixelFormat::Format32bppArgb);
		Graphics^ g = Graphics::FromImage(bmp);
		double x = 500, y = 0;

		test();
		int cnt = 0;
		drawTree(root, x, x / 2, y, g, cnt, 'q');
		pictureBox1->Image = bmp;
		addToolTips(root, x, x / 2, y, g, cnt);
		panel1->Controls->Add(this->pictureBox1);

	}
	

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		cli::array<Button^>^ b = gcnew cli::array<Button^>(100);
		b[0] = gcnew System::Windows::Forms::Button();
		b[0]->Location = System::Drawing::Point(0, 12);
		b[0]->Name = L"button5";
		b[0]->Size = System::Drawing::Size(75, 44);
		b[0]->TabIndex = 12;
		b[0]->Text = L"button5";
		b[0]->UseVisualStyleBackColor = true;
		Controls->Add(b[0]);
	}
};



}
