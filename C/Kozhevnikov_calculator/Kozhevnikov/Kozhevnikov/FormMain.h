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
	/// —водка дл€ FormMain
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FormMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;


	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ button2;



	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(144, 206);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"=";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(224, 333);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormMain::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 54);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 26);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(192, 38);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 26);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(192, 70);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 26);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(50, 161);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 26);
			this->textBox4->TabIndex = 5;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(191, 145);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(132, 26);
			this->textBox5->TabIndex = 6;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(191, 177);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(132, 26);
			this->textBox6->TabIndex = 7;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"+", L"-", L"*", L"/", L"^", L"Reduct", L"Swap" });
			this->comboBox1->Location = System::Drawing::Point(50, 104);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(70, 28);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::comboBox1_SelectedIndexChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(50, 243);
			this->textBox7->Margin = System::Windows::Forms::Padding(4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(132, 26);
			this->textBox7->TabIndex = 8;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(191, 227);
			this->textBox8->Margin = System::Windows::Forms::Padding(4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(132, 26);
			this->textBox8->TabIndex = 9;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(191, 259);
			this->textBox9->Margin = System::Windows::Forms::Padding(4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(132, 26);
			this->textBox9->TabIndex = 10;
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipTitle = L"Ёто текст";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(50, 333);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormMain::button2_Click);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(365, 406);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"FormMain";
			this->Text = L"FormMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	



		int nod(int a, int b)//наибольший общий делитель
		{
			if (a < b) {
				a = a - b;//смена значений местами без третьей переменной
				b = b + a;
				a = b - a;
			}
			if (b == 0) return a;//модифицированный алгоритм ≈вклида
			else return nod(b, a % b);
		}

		int nok(int a, int b)//наименьшее общее кратное
		{
			return (a * b) / nod(a, b);
		}

		void reduction(int& a1, int& a2)//сокращение дроби
		{
			int temp = nod(abs(a1), a2);
			a1 /= temp;
			a2 /= temp;
		}

		void plus(int& a1, int& a2, int b1, int b2)// сложение дробей (a1 b1 - числители, a2 b2 - знаментаели)
		{
			int rez2 = nok(a2, b2);
			int rez1 = ((rez2 / a2) * a1) + ((rez2 / b2) * b1);
			reduction(rez1, rez2);
			a1 = rez1;
			a2 = rez2;
		}

		void minus(int& a1, int& a2, int b1, int b2)// разница дробей (a1 b1 - числители, a2 b2 - знаментаели)
		{
			int rez2 = nok(a2, b2);
			int rez1 = ((rez2 / a2) * a1) - ((rez2 / b2) * b1);
			//int temp = nod(abs(rez1), rez2);
			reduction(rez1, rez2);
			a1 = rez1;
			a2 = rez2;
		}

		void multiply(int& a1, int& a2, int b1, int b2)//умножение дробей
		{
			a1 *= b1;
			a2 *= b2;
			reduction(a1, a2);
		}

		void division(int& a1, int& a2, int b1, int b2)//деление дробей
		{
			multiply(a1, a2, b2, b1);
		}

		void myPow(int& a1, int& a2, int n)//возведение в целую степень
		{
			int tmpa1 = a1;
			int tmpa2 = a2;
			if (n > 0)
				for (int i = 1; i < n; i++)
				{
					a1 *= tmpa1;
					a2 *= tmpa2;
				}
			else if (n < 0)
			{
				n *= -1;
				mySwap(a1, a2);
				for (int i = 1; i < n; i++)
				{
					a1 *= tmpa2;
					a2 *= tmpa1;
				}
			}
			else
			{
				a1 = 1;
				a2 = 1;
			}
		}

		void mySwap(int& a1, int& a2)//ѕереворот дроби
		{
			a1 = a1 - a2;//смена значений местами без третьей переменной
			a2 = a2 + a1;
			a1 = a2 - a1;
		}

		int getCountNegative(int a, int a1, int a2)
		{
			int cnt = 0;
			if (a < 0) cnt++;
			if (a1 < 0) cnt++;
			if (a2 < 0) cnt++;
			return cnt % 2; //вернет 1 - дробь отрицательна€, 0 - положительна€
		}

		void intPartToNumerator(int a, int& a1, int a2)//÷ела€ часть числа-> числитель
		{
			int tmp = getCountNegative(a, a1, a2);
			a1 = abs(a1);
			a2 = abs(a2);
			a = abs(a);
			a1 += (a * a2);
			if (tmp == 1)
				a1 *= -1;
			a = 0;
		}

		void numeratorToIntPart(int& a, int& a1, int a2)//округление дроби
		{
			a = a1 / a2;
			a1 -= (a * a2);
		}

		int length(System::String^ str)
		{
			int a = str->Length;		
			return a;
		}

		bool numChecker(System::String^ str, int checkId)//checkId = 0 =>положительное число, checkId = 1 => (возможно) отрицательное число
		{
			if ((str[0] >= '0' && str[0] <= '9') || (str[0] == '-'))
			{
				for (int i = checkId; i < length(str); i++)
					if (str[i] < '0' || str[i] > '9')
						return false;
			}
			else return false;

			return true;
		}

		bool numberIn(int n) //можно массивом, но не нужно
		{
			if (n == 0)
				return true;
			if (n == 1)
				return true;
			if (n == 2)
				return true;
			if (n == 3)
				return true;
			return false;
		}



		bool nullChecker(int& a, int& a1, int& a2, int& b, int& b1, int& b2, int ind)//проверка входных значений на null + заполнение
		{
			
			if (textBox2->Text != "" && numChecker(textBox2->Text, 1))
				a1 = System::Convert::ToInt32(textBox2->Text);
			else return false;
			if (textBox3->Text != "" && numChecker(textBox3->Text, 1))
				a2 = System::Convert::ToInt32(textBox3->Text);
			else return false;
			if (numberIn(ind))
			{
				if (textBox5->Text != "" && numChecker(textBox5->Text, 1))
					b1 = System::Convert::ToInt32(textBox5->Text);
				else return false;
				if (textBox6->Text != "" && numChecker(textBox6->Text, 1))
					b2 = System::Convert::ToInt32(textBox6->Text);
				else return false;
			}
			if (textBox1->Text != "")
				if (numChecker(textBox1->Text, 1))
					intPartToNumerator(System::Convert::ToInt32(textBox1->Text), a1, a2);
				else return false;
			if (ind == 4)
			{
				if (textBox4->Text != "")
					if (numChecker(textBox4->Text, 1))
						//intPartToNumerator(System::Convert::ToInt32(textBox4->Text), b1, b2);
						b = System::Convert::ToInt32(textBox4->Text);
					else return false;
				else return false;
			}
			else
			{
				if (numChecker(textBox4->Text, 1))
					intPartToNumerator(System::Convert::ToInt32(textBox4->Text), b1, b2);
				else return false;

			}
			return true;
		}

		//{ L"+", L"-", L"*", L"/", L"^", L"Reduct", L"Swap" });

		void catchAction()
		{
			int a, a1, a2, b, b1, b2, c = 0;
			int ind = comboBox1->SelectedIndex;
			bool rezIsFine = true;
			//MessageBox::Show(System::Convert::ToString(ind));
			if (!nullChecker(a, a1, a2, b, b1, b2, ind)) {
				MessageBox::Show("¬ведены не все значени€, или ввод был некорректен");
				rezIsFine = false;
			}

			if (rezIsFine)
			switch (ind)
			{
			case 0:
				plus(a1, a2, b1, b2);
				break;
			case 1:
				minus(a1, a2, b1, b2);
				break;
			case 2:
				multiply(a1, a2, b1, b2);
				break;
			case 3:
				division(a1, a2, b1, b2);
				break;
			case 4:
				myPow(a1, a2, b);
				break;
			case 5:
				reduction(a1, a2);
				break;
			case 6:
				mySwap(a1, a2);
				break;

			default:
				rezIsFine = false;
				MessageBox::Show("¬ведены не все значени€, или ввод был некорректен");
				break;
			}
			if (rezIsFine)
			{
				numeratorToIntPart(c, a1, a2);
				showRezs(c, a1, a2);
			}
		}

		void showRezs(int c, int c1, int c2)
		{
			textBox7->Text = System::Convert::ToString(c);
			textBox8->Text = System::Convert::ToString(c1);
			textBox9->Text = System::Convert::ToString(c2);
		}

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			catchAction();
			/*int a, a1, a2, b, b1, b2, c = 0;
			if (nullChecker(a, a1, a2, b, b1, b2))
			{
				multiply(a1, a2, b1, b2);
				numeratorToIntPart(c, a1, a2);
				textBox7->Text = System::Convert::ToString(c);
				textBox8->Text = System::Convert::ToString(a1);
				textBox9->Text = System::Convert::ToString(a2);

			};*/

	}

		/*
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		*/



		/*
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		/--------------------------------------------------------------------------------------------------------------------------/
		*/


	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		textBox5->Text = "";
		textBox6->Text = "";
		textBox7->Text = "";
		textBox8->Text = "";
		textBox9->Text = "";
		comboBox1->SelectedIndex = -1;
	}
};



}
