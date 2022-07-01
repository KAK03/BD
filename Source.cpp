#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class IDgenerator
{
	int id;

public:
	void getID(int& ID)
	{
		cout << id<<endl;
	}

	void setID(int &ID)
	{
		this->id = ID;
	}
};

class MAN
{
	string Name;
	int age, height, weight;

public:
	/*
	MAN()
	{
		this->Name = nullptr;
		this->age = 0;
		this->height = 0;
		this->weight = 0;
	};
	*/
	void SetInfo(string Name, int age, int height, int weight)
	{
		this->Name = Name;
		this->age = age;
		this->height = height;
		this->weight = weight;
	}

	void GetInfo()
	{
		cout<< Name;
		cout << age;
		cout << height;
		cout << weight;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Name;
	int age, height, weight;
	int button = 0;

	
	ofstream fs;
	fs.exceptions(ifstream::badbit | ifstream::failbit);
	fs.open("data.txt", fstream::app);//добавление в файл
	if (fs.is_open())
	{
		do
		{
			cout << "Чтобы добавить данные нажмите 1\nЧтобы завершить работу нажмите 2\n";
			
			cin >> button;
			if (button == 1)
			{
				cout << "Enter your name:";
				cin >> Name;
				cout << "Enter your age:";
				cin >> age;
				cout << "Enter your height:";
				cin >> height;
				cout << "Enter your weight:";
				cin >> weight;

				MAN man;
				man.SetInfo(Name, age, height, weight);//вводим данные

				IDgenerator id;
				int i = 1;
				id.setID(i);
				fs.write((char*)&id, sizeof(IDgenerator));
				fs.write((char*)&man, sizeof(MAN));//передаем указатель чар на ссылку на объект класса MAN, который сохраняем в файл, второй парамметр - это занимаемая им память
			}
			else if (button == 2)
			{
				return 0;
			}
			else
			{
				cout << "ERROR";
				return 0;
			}
		} 
		while (button == 1);
	}

	else
	{
		cout << "ERROR";
		return 0;
	}
	

	/*
	ifstream fin;
	fin.open("data.txt");
	MAN outman;
	if (fin.is_open())
	{
		cout << "SUCCES";
		while (fin.read((char*)&outman, sizeof(MAN)))
		{
			outman.GetInfo();
		}

	}
	else
	{
		cout << "ERROR";
		return 0;
	}
	*/

	
	fs.close();
	//fin.close();
}