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

ostream& operator<<(ostream& os, const IDgenerator& id)//���������� ���������� ����� � ������ �� ����� ��� ������ IDgenerator|��������������� ������ ostream,fstream...
{//��������� ��� ostream ���������� ���������������� ��� ���� ����� ������ ������ � ������|������ ����������� ���������� ������ ������(���� ����������)(������ cout,cin)
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
	fs.open("data.txt", fstream::in | fstream::out | fstream::app);//������ � ���������� � ����
	try
	{
		do
		{
			cout << "����� �������� ������ ������� 1\n����� ��������� ������ ������� 2\n";
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
				//fs >> inf;//������� ���� �� ����� � ������ ������

				i++;
				fs << id << " ";//��������� ���� � ����, ����� ������������� ��������
				fs << man;

				//fs.write((char*)&id, sizeof(IDgenerator));
				//fs.write((char*)&man, sizeof(MAN));//�������� ��������� ��� �� ������ �� ������ ������ MAN, ������� ��������� � ����, ������ ��������� - ��� ���������� �� ������
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
	catch (const ifstream::failure& ex)//����� ������
	{
		cout << "ERROR";
		return 0;
	}
	
	/*//����� �� ����� � ������
	while (!fs.eof())
	{
		getline(fs, stroka);
		cout << stroka << endl;
	}
	*/

	fs.close();
}