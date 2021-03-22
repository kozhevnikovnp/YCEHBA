#pragma once
#include <windows.h> 
#include <string>
#include <cmath>
#include <iostream>

namespace Kozhevnikov {

	using namespace System;
	//��� ������� �������
	class Book
	{
	public:
		int udc; //������������� ���������� �������������
		std::string authorFio;//������� �������� ������
		std::string bookName;//�������� �����
		int publishYear;//��� �������
		int count;//���-�� � ����������


		Book(int udc, std::string authorFio, std::string bookName, int publishYear, int count)
		{
			this->udc = udc;
			this->authorFio = authorFio;
			this->bookName = bookName;
			this->publishYear = publishYear;
			this->count = count;
		}

		std::string GetStr()
		{
			return std::to_string(udc) + "|" + authorFio + "|" + bookName;
		}

		System::String ^ GetStr1()
		{
			return gcnew System::String((std::to_string(udc) + "|" + authorFio + "|" + bookName).c_str());
		}

	};

	struct bookBTree
	{
	public:
		int key;
		int level;
		Book* b;
		struct bookBTree* left;
		struct bookBTree* right;

	};
}