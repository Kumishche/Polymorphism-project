#include "Tests.h"

void Tests::GetTests()
{
	int size = 4;
	int currentSize = 0;
	int type = 0;
	int count = 0;
	SwimmingObject** objects = new SwimmingObject * [size];
	Surfboard surf = Surfboard("surf", 5);
	surf.toString();

	objects[currentSize++] = new Boat("b", 12);
	objects[currentSize - 1]->toString();
	objects[currentSize++] = new Submarine("s", 100);
	objects[currentSize - 1]->toString();
	objects[currentSize++] = new Yacht("y", 3);
	objects[currentSize - 1]->toString();
	objects[currentSize++] = new FishingBoat("f", 2, 20);
	objects[currentSize - 1]->toString();

	objects = resizeArray(objects, size);
	objects[currentSize++] = new FishingBoat("f2", 44, 16);
	objects[currentSize - 1]->toString();
	objects[currentSize++] = new Yacht("b", 9);
	objects[currentSize - 1]->toString();


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов каждого типа: " << endl;
	countObjectsByType(objects, currentSize);
	if (surf.getLength() != 0)
		cout << "Surfboards: 1" << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа SwimmingObject: ";
	type = 0;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout << count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа Boat: ";
	type = 1;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout << count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа FishingBoat: ";
	type = 5;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout << count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа Yacht: ";
	type = 3;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout << count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа Submarine: ";
	type = 2;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout <<  count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Количество объектов типа Surfboard: ";
	type = 4;
	if (type == 0)
		count = currentSize;
	else
		count = countObjectsByClass(objects, currentSize, type);
	if ((type == 0 || type == 4) && surf.getLength() != 0)
		count++;
	cout << count << endl;


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Информация по всем объектам: " << endl;
	for (int i = 0; i < currentSize; i++)
	{
		cout << "Объект " << i + 1 << endl;
		objects[i]->toString();
	}
	if (surf.getLength() != 0)
	{
		cout << "Объект " << currentSize + 1 << endl;
		surf.toString();
	}


	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Объекты с именем \"b\": " << endl;
	for (int i = 0; i < currentSize; i++)
	{
		if (objects[i]->getName() == "b")
			objects[i]->toString();
	}
	if (surf.getLength() != 0 && surf.getName() == "b")
		surf.toString();

	cout << setw(20) << setfill('-') << ' ' << endl;
	cout << "Объекты со скорость 12: " << endl;
	for (int i = 0; i < currentSize; i++)
	{
		if (dynamic_cast<Boat*>(objects[i]) && dynamic_cast<Boat*>(objects[i])->getSpeed() == 12)
			objects[i]->toString();
	}
}

void Tests::countObjectsByType(SwimmingObject** objects, int size)
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

int Tests::countObjectsByClass(SwimmingObject** objects, int size, int type)
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

SwimmingObject** Tests::resizeArray(SwimmingObject** arr, int& size)
{
	int newSize = size * 2;
	SwimmingObject** newArr = new SwimmingObject * [newSize];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	size = newSize;

	return newArr;
}