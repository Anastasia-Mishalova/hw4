// hw4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <typeinfo>
#include <fstream>
#include <malloc.h>
#include <cstring>.
using namespace std;

// Создайте программу, имитирующую многоквартирный дом.Необходимо иметь классы “Человек”, “Квартира”, “Дом”.
// Класс “Квартира” содержит динамический массив объектов класса “Человек”.Класс “Дом” содержит массив объектов класса “Квартира”.
// Каждый из классов содержит переменные - члены и функции - члены, которые необходимы для предметной области класса.
// Обращаем ваше внимание, что память под строковые значения выделяется динамически.Например, для ФИО в классе “Человек”.
// Не забывайте обеспечить классы различными конструкторами(конструктор копирования обязателен), деструкторами.
// В main протестировать работу полученного набора классов.

class Person
{
public:

	char* firstname, * lastname;              //имяфамилия
	int l;
	Person()
	{
		firstname = new char[l + 1];
		lastname = new char[l + 1];
	}

	Person(const Person& p)
	{
		char* firstname = new char;
		firstname = p.firstname;

		char* lastname = new char;
		lastname = p.lastname;
	}
	~Person()
	{
		delete firstname;
		delete lastname;
	}

	void inputPerson()
	{
		cout << "Имя: ";
		cin >> firstname;
		cout << "Фамилия: ";
		cin >> lastname;
	}

	void showPerson()
	{
		cout << "Фамилия: " << lastname << endl;
		cout << "Имя: " << firstname << endl;
	}

};

class Apartment : public Person
{
protected:
	int num_this_apart, num_tenants, num_rooms;              // номер текущей квартиры, кол-во жильцов и кол-во комнат
public:
	Person* person;

	void inputApartment()
	{
		cout << "Номер квартиры: ";
		cin >> num_this_apart;
		cout << "Количество жильцов: ";
		cin >> num_tenants;
		cout << "Количество комнат: ";
		cin >> num_rooms;

		person = new Person[num_tenants];         // массив Person
		for (int i = 0; i < num_tenants; i++)
		{
			person->inputPerson();                     // инициализация фио
		}
	}

	void showApartment()
	{
		cout << "Номер квартиры: " << num_this_apart << endl;
		cout << "Количество жильцов: " << num_tenants << endl;
		cout << "Количество комнат: " << num_rooms << endl;
		cout << "Жильцы" << endl;

		for (int i = 0; i < num_tenants; i++)
		{
			cout << "Проживающий " << i + 1 << ": " << person[i].lastname << " " << person[i].firstname << endl;
		}
	}

	Apartment(){}

	Apartment(const Apartment& ap) 
	{
		num_this_apart = ap.num_this_apart;
		num_tenants = ap.num_tenants;
		num_rooms = ap.num_rooms;
	}   

	
};

class House : public Apartment
{
protected:
	int num_apartment, num_floors;                // кол-во квартир и кол-во этажей
public:
	Apartment* apartment;

	void inputHouse()
	{
		cout << "Количество квартир: ";
		cin >> num_apartment;
		cout << "Количество этажей: ";
		cin >> num_floors;

		apartment = new Apartment[num_apartment];         // массив Apartment
		for (int i = 0; i < num_apartment; i++)
		{
			apartment->inputApartment();                     // инициализация квартир
		}
	}

	void showHouse()
	{
		cout << "Количество квартир: " << num_apartment << endl;
		cout << "Количество этажей: " << num_floors << endl;
		showApartment();
	}

	House() {}

	House(const House& h)
	{
		num_apartment = h.num_apartment;
		num_floors = h.num_floors;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	House house;
	house.inputHouse();
	house.showHouse();

}


