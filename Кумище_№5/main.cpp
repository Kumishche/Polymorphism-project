// Кумище_№5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "SwimmingObject.h"
#include "Boat.h"
#include "Submarine.h"
#include "Yacht.h"
#include "Surfboard.h"
#include "FishingBoat.h"
#include "Tests.h"

using namespace std;

void CheckInput(int& var);
SwimmingObject** resizeArray(SwimmingObject** arr, int& size);
void countObjectsByType(SwimmingObject** objects, int size);
int countObjectsByClass(SwimmingObject** objects, int size, int type);
void setInfo(string& name, int& var);

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	int v = (10 * int('K') + int('R')) % 11;
	cout << "Вариант: " << v << endl;
	cout << setw(40) << setfill('=') << ' ' << endl;
	cout << endl;
	
	int s;
	string name;
	int count;
	int type;
	int speed, depth, luxuryLevel, capacity, length;
	int size = 5;
	int currentSize = 0;
	Surfboard surfboard("null", 0);
	SwimmingObject** objects = new SwimmingObject*[size];

	while (true)
	{
		cout << "Выберите действие: " << endl;
		cout << "1 - задать объект Boat" << endl;
		cout << "2 - задать объект Submarine" << endl;
		cout << "3 - задать объект Yacht" << endl;
		cout << "4 - задать объект Surfboard" << endl;
		cout << "5 - задать объект FishingBoat" << endl;
		cout << setw(20) << setfill('-') << ' ' << endl;
		cout << "6 - количество объектов каждого типа" << endl;
		cout << "7 - количество объектов заданного типа" << endl;
		cout << "8 - информация по всем объектам" << endl;
		cout << "9 - найти объекты по имени" << endl;
		cout << "10 - найти объекты по скорости" << endl;
		cout << setw(20) << setfill('-') << ' ' << endl;
		cout << "11 - вывести статистику по созданным объектам" << endl;
		cout << setw(20) << setfill('-') << ' ' << endl;
		cout << "12 - автоматическое тестирование" << endl;
		cout << "13 - выход" << endl;
		cout << setw(40) << setfill('=') << ' ' << endl;

		cin >> s;
		CheckInput(s);

		switch (s)
		{
		case 1:
			setInfo(name, speed);
			if (currentSize == size)
				objects = resizeArray(objects, size);
			objects[currentSize] = new Boat(name, speed);
			cout << "Вывод объекта: " << endl;
			objects[currentSize]->toString();
			currentSize++;
			break;

		case 2:
			setInfo(name, depth);
			if (currentSize == size)
				objects = resizeArray(objects, size);
			objects[currentSize] = new Submarine(name, depth);
			cout << "Вывод объекта: " << endl;
			objects[currentSize]->toString();
			currentSize++;
			break;

		case 3:
			setInfo(name, luxuryLevel);
			if (currentSize == size)
				objects = resizeArray(objects, size);
			objects[currentSize] = new Yacht(name, luxuryLevel);
			cout << "Вывод объекта: " << endl;
			objects[currentSize]->toString();
			currentSize++;
			break;

		case 4:
			setInfo(name, length);
			surfboard = Surfboard(name, length);
			cout << "Вывод объекта: " << endl;
			surfboard.toString();
			break;

		case 5:
			setInfo(name, speed);
			cin >> capacity;
			CheckInput(capacity);
			while (capacity < 0)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> capacity;
				CheckInput(capacity);
			}
			if (currentSize == size)
				objects = resizeArray(objects, size);
			objects[currentSize] = new FishingBoat(name, speed, capacity);
			cout << "Вывод объекта: " << endl;
			objects[currentSize]->toString();
			currentSize++;
			break;

		case 6:
			countObjectsByType(objects, currentSize);
			if (surfboard.getLength() != 0)
				cout << "Surfboards: 1" << endl;
			break;

		case 7:
			cin >> type;
			CheckInput(type);
			while (type < 0 || type > 5)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> type;
				CheckInput(type);
			}

			if (type == 0)
				count = currentSize;
			else 
				count = countObjectsByClass(objects, currentSize, type);

			if ((type == 0 || type == 4) && surfboard.getLength() != 0)
				count++;

			cout << "Количество: " << count << endl;
			break;

		case 8:
			for (int i = 0; i < currentSize; i++)
			{
				cout << "Объект " << i + 1 << endl;
				objects[i]->toString();
			}
			if (surfboard.getLength() != 0)
			{
				cout << "Объект " << currentSize+1 << endl;
				surfboard.toString();
			}
			break;

		case 9:
			cin >> name;
			for (int i = 0; i < currentSize; i++)
			{
				if (objects[i]->getName() == name)
					objects[i]->toString();
			}
			if (surfboard.getLength() != 0 && surfboard.getName() == name)
				surfboard.toString();
			break;

		case 10:
			cin >> speed;
			CheckInput(speed);
			while (speed < 0)
			{
				cout << "Некорректный ввод" << endl;
				cout << "Повторите ввод: ";
				cin >> speed;
				CheckInput(speed);
			}

			for (int i = 0; i < currentSize; i++)
			{
				if (dynamic_cast<Boat*>(objects[i]) && 
					dynamic_cast<Boat*>(objects[i])->getSpeed() == speed)
					objects[i]->toString();
			}
			break;

		case 11:
			if (currentSize == 0) break;
			cout << "Всего объектов класса Boat: " << Boat::getBoatCount() << endl;
			cout << "Всего объектов класса FishingBoat: " <<
				FishingBoat::getFishingBoatCount() << endl;
			cout << "Максимальная глубина объекта Submarine: " <<
				Submarine::getMaxDepth() << endl;
			break;

		case 12:
			Tests t;
			t.GetTests();
			break;

		case 13:
			return 0;

		default:
			cout << "Некорректный ввод" << endl;
		}

		cout << setw(40) << setfill('=') << ' ' << endl;
		cout << endl;
	}

}

void CheckInput(int& var)
{
	while (cin.fail() || cin.get() != '\n')
	{
		cin.clear(); cin.ignore(256, '\n');
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> var;
	}
}

SwimmingObject** resizeArray(SwimmingObject** arr, int& size)
{
	int newSize = size * 2;
	SwimmingObject** newArr = new SwimmingObject* [newSize];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	size = newSize;

	return newArr;
}

void setInfo(string& name, int& var)
{
	cin >> name;
	cin >> var;
	CheckInput(var);
	while (var < 0)
	{
		cout << "Некорректный ввод" << endl;
		cout << "Повторите ввод: ";
		cin >> var;
		CheckInput(var);
	}
}

void countObjectsByType(SwimmingObject** objects, int size)
{
	int b_count = 0;
	int s_count = 0;
	int y_count = 0;
	int f_count = 0;

	for (int i = 0; i < size; i++)
	{
		if (dynamic_cast<FishingBoat*>(objects[i]))
			f_count++;
		else if (dynamic_cast<Boat*>(objects[i]))
			b_count++;
		else if (dynamic_cast<Submarine*>(objects[i]))
			s_count++;
		else if (dynamic_cast<Yacht*>(objects[i]))
			y_count++;
	}

	cout << "Boats: " << b_count << endl;
	cout << "Fishing boats: " << f_count << endl;
	cout << "Submarines: " << s_count << endl;
	cout << "Yachts: " << y_count << endl;
}

int countObjectsByClass(SwimmingObject** objects, int size, int type)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		switch (type) 
		{
		case 1:
			if (dynamic_cast<Boat*>(objects[i])) 
				count++;
			break;

		case 2:
			if (dynamic_cast<Submarine*>(objects[i])) 
				count++;
			break;

		case 3:
			if (dynamic_cast<Yacht*>(objects[i])) 
				count++;
			break;

		case 4:
			if (dynamic_cast<Surfboard*>(objects[i]))
				count++;
			break;

		default:
			if (dynamic_cast<FishingBoat*>(objects[i]))
				count++;
		}
	}

	return count;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
