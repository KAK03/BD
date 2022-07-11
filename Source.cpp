#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class IDgenerator
{
	
public:
	int id;

	IDgenerator()
	{
		this->id = 0;
	}

	IDgenerator(int &id)
	{
		this->id = id;
	}

	/*
	void getID(int& ID)
	{
		cout << id<<endl;
	}

	void setID(int &ID)
	{
		this->id = ID;
	}
	*/
	
};

class MAN
{
public:
	
	string Name;
	int age, height, weight;

	MAN()
	{
		this->Name = nullptr;
		this->age = 0;
		this->height = 0;
		this->weight = 0;
	}

	MAN(string Name, int age, int height, int weight)
	{
		this->Name = Name;
		this->age = age;
		this->height = height;
		this->weight = weight;
	};

	/*
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
	*/
};

class INFO
{
public:
	string Name;
	int age, height, weight, id;

	INFO()
	{
		this->id = 0;
		this->Name = nullptr;
		this->age = 0;
		this->height = 0;
		this->weight = 0;
	}
};

ostream& operator<<(ostream& os, const IDgenerator& id)//перегрузка операторов ввода и вывода из файла для класса IDgenerator|взаимосвязанные классы ostream,fstream...
{//описанная для ostream перегрузка распространяется для всех типов данных работы с файлом|первым парамметром передается объект класса(куда записываем)(аналог cout,cin)
	os << id.id<<" ";
	return os;
}

ostream& operator<<(ostream& os, const MAN & man1)
{
	os << man1.Name<<" "<<man1.age<<" "<<man1.height<<" " << man1.weight<<"\n";
	return os;
}

istream& operator>>(istream& is, INFO& inf)
{
	is >> inf.id >> inf.Name >> inf.age >> inf.height >> inf.weight;
	return is;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Name,stroka;
	int age, height, weight;
	int button = 0;
	int i = 1;
	
	fstream fs;
	fs.exceptions(ifstream::badbit | ifstream::failbit);
	fs.open("data.txt", fstream::in | fstream::out | fstream::app);//чтение и добавление в файл
	try
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

				MAN man(Name, age, height, weight);
				IDgenerator id(i);

				//INFO inf;
				//fs >> inf;//выводим инфу из файла в объект класса

				i++;
				fs << id << " ";//добавляем инфу в файл, через перегруженный оператор
				fs << man;

				//fs.write((char*)&id, sizeof(IDgenerator));
				//fs.write((char*)&man, sizeof(MAN));//передаем указатель чар на ссылку на объект класса MAN, который сохраняем в файл, второй парамметр - это занимаемая им память
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
	catch (const ifstream::failure& ex)//вброс ошибки
	{
		cout << "ERROR";
		return 0;
	}
	
	/*//Вывод из файла в строку
	while (!fs.eof())
	{
		getline(fs, stroka);
		cout << stroka << endl;
	}
	*/

	fs.close();
}