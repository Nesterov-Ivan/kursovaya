// machineassemblyconveyor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "structures.h"
#include "CAR.h"
#include "Builder.h"
#include "Director.h"
#include "avtoBuilder.h"
#include "motoBuilder.h"
#include "kvadroBuilder.h"

int main()
{
	setlocale(LC_ALL, "rus");
	CAR* Car[20];
	CAR* motorbike[20];
	CAR* kvadrobike[20];
	Director director;
	avtoBuilder AVTOBuilder;
	motoBuilder MOTOBuilder;
	kvadroBuilder KVADROBuilder;
	int a = 1, b = 0, i = 0, i1 = 0, i2 = 0;
	ifstream file1;
	ofstream file;
	
	try
	{
		file1.open("kol.txt", ios::binary | ios::in);
		if (!file1.is_open()) {
			throw 777;
		}
		file1.read(reinterpret_cast<char*>(&i), sizeof(int));
		file1.read(reinterpret_cast<char*>(&i1), sizeof(int));
		file1.read(reinterpret_cast<char*>(&i2), sizeof(int));
		file1.close();
	}
	catch (const int &ex)
	{
		cout << "Oshibka otkritiya faila!" << endl;
	}
	cout << i << " " << i1 << " " << i2 << endl;
	while (a) {
		cout << endl << "select an action: " << endl
			<< "\t1 - add transport" << endl
			<< "\t2- output data from file" << endl
			<< "\t0 - exit" << endl;
		cin >> a;
		switch (a) {
		case 1: 
		{
			cout << endl << "what is the type of transport to add?: " << endl
				<< "\t1 - car" << endl
				<< "\t2- motorbike" << endl
				<< "\t3- quadbike" << endl
				<< "\t0 - exit" << endl;
			cin >> b;
			switch (b) {
			case 1:
			{
				director.setBuilder(&AVTOBuilder);
				Car[i] = director.getCar();
				cout << "\t CAR:" << endl;
				Car[i]->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1)
				{
					try
					{
						file.open("car.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}

						file << Car[i]->COLOR()->COLOR << " ";
						file << Car[i]->PRICE()->cena << " ";
						file << Car[i]->TYPE_ENGINE()->type << " ";
						file << Car[i]->POWER()->POWER << " ";
						file << Car[i]->YEAR()->YEAR << " ";
						file << Car[i]->BRAND()->BRAND << " ";
						file << Car[i]->MODEL()->MODEL << " ";
						file << Car[i]->DIMENSIONS(0)->size << " ";
						file << Car[i]->DIMENSIONS(1)->size << " ";
						file << Car[i]->DIMENSIONS(2)->size << " ";
						file << Car[i]->FUEL()->FUEL << " ";
						file << Car[i]->TRANSMISSION()->TRANSMISSION << " ";
						file << Car[i]->CONSUMPTION()->CONSUMPTION << " ";
						file << Car[i]->TRUNK()->TRUNK << " ";

						file.close();
					}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}

					i++;
					try
					{
						file.open("kol.txt", ios::binary | ios::out);
						if (!file.is_open()) {
							throw 777;
						}

						file.write(reinterpret_cast<char*>(&i), sizeof(int));
						file.write(reinterpret_cast<char*>(&i1), sizeof(int));
						file.write(reinterpret_cast<char*>(&i2), sizeof(int));
						file.close();
					}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
				}
				break;
			}
			case 2:
			{
				director.setBuilder(&MOTOBuilder);
				motorbike[i1] = director.getCar();
				cout << "\t motorbike:" << endl;
				motorbike[i1]->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1)
				{
					try
					{
						file.open("motorbike.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}
					file << motorbike[i1]->COLOR()->COLOR << " ";
					file << motorbike[i1]->PRICE()->cena << " ";
					file << motorbike[i1]->TYPE_ENGINE()->type << " ";
					file << motorbike[i1]->POWER()->POWER << " ";
					file << motorbike[i1]->YEAR()->YEAR << " ";
					file << motorbike[i1]->BRAND()->BRAND << " ";
					file << motorbike[i1]->MODEL()->MODEL << " ";
					file << motorbike[i1]->DIMENSIONS(0)->size << " ";
					file << motorbike[i1]->DIMENSIONS(1)->size << " ";
					file << motorbike[i1]->DIMENSIONS(2)->size << " ";
					file << motorbike[i1]->FUEL()->FUEL << " ";
					file << motorbike[i1]->TRANSMISSION()->TRANSMISSION << " ";
					file << motorbike[i1]->CONSUMPTION()->CONSUMPTION << " ";
					file << motorbike[i1]->TRUNK()->TRUNK << " ";
					file.close();
				}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
					i1++;
					try
					{
						file.open("kol.txt", ios::binary | ios::out);
						if (!file.is_open()) {
							throw 777;
						}

						file.write(reinterpret_cast<char*>(&i), sizeof(int));
						file.write(reinterpret_cast<char*>(&i1), sizeof(int));
						file.write(reinterpret_cast<char*>(&i2), sizeof(int));
						file.close();
					}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
				}
				break;
			}
			case 3:
			{
				director.setBuilder(&KVADROBuilder);
				kvadrobike[i2] = director.getCar();
				cout << "\t quadbike:" << endl;
				kvadrobike[i2]->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1)
				{
					try
					{
						file.open("quadbike.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}
					file <<  kvadrobike[i2]->COLOR()->COLOR << " ";
					file << kvadrobike[i2]->PRICE()->cena << " ";
					file << kvadrobike[i2]->TYPE_ENGINE()->type << " ";
					file << kvadrobike[i2]->POWER()->POWER << " ";
					file << kvadrobike[i2]->YEAR()->YEAR << " ";
					file << kvadrobike[i2]->BRAND()->BRAND << " ";
					file << kvadrobike[i2]->MODEL()->MODEL << " ";
					file << kvadrobike[i2]->DIMENSIONS(0)->size << " ";
					file << kvadrobike[i2]->DIMENSIONS(1)->size << " ";
					file << kvadrobike[i2]->DIMENSIONS(2)->size << " ";
					file << kvadrobike[i2]->FUEL()->FUEL << " ";
					file << kvadrobike[i2]->TRANSMISSION()->TRANSMISSION << " ";
					file << kvadrobike[i2]->CONSUMPTION()->CONSUMPTION << " ";
					file << kvadrobike[i2]->TRUNK()->TRUNK << " ";
					file.close();
				}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
				i2++;
				try
				{
					file.open("kol.txt", ios::binary | ios::out);
					if (!file.is_open()) {
						throw 777;
					}

					file.write(reinterpret_cast<char*>(&i), sizeof(int));
					file.write(reinterpret_cast<char*>(&i1), sizeof(int));
					file.write(reinterpret_cast<char*>(&i2), sizeof(int));
					file.close();
				}
				catch (const int &ex)
				{
					cout << "Oshibka otkritiya faila!" << endl;
				}
			}
				break;
			}
			case 0:
				break;
			}
			break;
		}
		case 2:
		{
			cout << endl << "what is the type of transport to output?: " << endl
				<< "\t1 - car" << endl
				<< "\t2- motorbike" << endl
				<< "\t3- quadbike" << endl
				<< "\t0 - exit" << endl;
			cin >> b;
			switch (b) {
			case 1:
			{
				for (int k = 0; k < i; k++) {
					Car[k] = Car[k]->read_file("car.txt",k);
					cout << endl << "CAR " << k + 1 << endl;
					Car[k]->specification();
					cout << endl;
				}
				break;
			}
			case 2:
			{
				for (int k = 0; k < i1; k++) {
					motorbike[k] = motorbike[k]->read_file("motorbike.txt", k);
					cout << endl << "Motorbike " << k + 1 << endl;
					motorbike[k]->specification();
					cout << endl;
				}
				break;
			}
			case 3:
			{
				for (int k = 0; k < i2; k++) {
					kvadrobike[k] = kvadrobike[k]->read_file("quadbike.txt", k);
					cout << endl << "Quadbike " << k + 1 << endl;
					kvadrobike[k]->specification();
					cout << endl;
				}
				break;
			}
			case 0:
				break;
			}
			break;
		}
		case 0:
			break;
		}
	}
    return 0;
	system("PAUSE");
}