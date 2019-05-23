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
	Director director;
	avtoBuilder AVTOBuilder;
	motoBuilder MOTOBuilder;
	kvadroBuilder KVADROBuilder;
	int a = 1, b = 0, i = 0, i1 = 0, i2 = 0, flag = 0;
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

	CAR* Car = new CAR[i];
	CAR* motorbike = new CAR[i1];
	CAR* kvadrobike = new CAR[i2];

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
				int ii = i;
				while (true) {
					CAR* tmp = new CAR[ii + 1];
					for (int j = 0; j < ii; j++)
					{
						tmp[j] = Car[j];
					}
					delete[] Car;
					Car = tmp;

					director.setBuilder(&AVTOBuilder);
					try {
						Car[ii] = director.getCar();
					}
					catch (const int &ex)
					{
						cout << "Oshibka vvoda dannyix!" << endl;
						flag = 1;
						break;
					}
					cout << "\t CAR:" << endl;
					ii++;
					cout << "write again?" << endl << "1 - yes" << endl;
					cin >> b;
					if (b != 1)
						break;
				}
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1 && flag != 1)
				{
					try
					{
						file.open("car.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}
						while (i < ii) {
							file << Car[i].COLOR()->COLOR << " ";
							file << Car[i].PRICE()->cena << " ";
							file << Car[i].TYPE_ENGINE()->type << " ";
							file << Car[i].POWER()->POWER << " ";
							file << Car[i].YEAR()->YEAR << " ";
							file << Car[i].BRAND()->BRAND << " ";
							file << Car[i].MODEL()->MODEL << " ";
							file << Car[i].DIMENSIONS(0)->size << " ";
							file << Car[i].DIMENSIONS(1)->size << " ";
							file << Car[i].DIMENSIONS(2)->size << " ";
							file << Car[i].FUEL()->FUEL << " ";
							file << Car[i].TRANSMISSION()->TRANSMISSION << " ";
							file << Car[i].CONSUMPTION()->CONSUMPTION << " ";
							file << Car[i].TRUNK()->TRUNK << " ";
							i++;
						}
						file.close();
					}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
				}
				else {
					CAR* tmp = new CAR[i];
					for (int j = 0; j < i; j++)
					{
						tmp[j] = Car[j];
					}
					delete[] Car;
					Car = tmp;
				}
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
				flag = 0;
				break;
			}
			case 2:
			{
					int ii1 = i1;
					while (true) {
						CAR* tmp = new CAR[ii1 + 1];
						for (int j = 0; j < ii1; j++)
						{
							tmp[j] = motorbike[j];
						}
						delete[] motorbike;
						motorbike = tmp;

						director.setBuilder(&MOTOBuilder);
						try {
							motorbike[ii1] = director.getCar();
						}
						catch (const int &ex)
						{
							cout << "Oshibka vvoda dannyix!" << endl;
							flag = 1;
							break;
						}
						cout << "\t motorbike:" << endl;
						motorbike[ii1].specification();
						ii1++;
						cout << "write again?" << endl << "1 - yes" << endl;
						cin >> b;
						if (b != 1)
							break;
					}
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1 && flag != 1)
				{
					try
					{
						file.open("motorbike.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}
						while (i1 < ii1) {
							file << motorbike[i1].COLOR()->COLOR << " ";
							file << motorbike[i1].PRICE()->cena << " ";
							file << motorbike[i1].TYPE_ENGINE()->type << " ";
							file << motorbike[i1].POWER()->POWER << " ";
							file << motorbike[i1].YEAR()->YEAR << " ";
							file << motorbike[i1].BRAND()->BRAND << " ";
							file << motorbike[i1].MODEL()->MODEL << " ";
							file << motorbike[i1].DIMENSIONS(0)->size << " ";
							file << motorbike[i1].DIMENSIONS(1)->size << " ";
							file << motorbike[i1].DIMENSIONS(2)->size << " ";
							file << motorbike[i1].FUEL()->FUEL << " ";
							file << motorbike[i1].TRANSMISSION()->TRANSMISSION << " ";
							file << motorbike[i1].CONSUMPTION()->CONSUMPTION << " ";
							file << motorbike[i1].TRUNK()->TRUNK << " ";
							i1++;
						}
						file.close();
				}
				catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}		
				}
				else {
					CAR* tmp = new CAR[i];
					for (int j = 0; j < i; j++)
					{
						tmp[j] = motorbike[j];
					}
					delete[] motorbike;
					motorbike = tmp;
				}
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
				flag = 0;
				break;
			}
			case 3:
			{
				int ii2 = i2;
				while (true) {
					CAR* tmp = new CAR[ii2 + 1];
					for (int j = 0; j < ii2; j++)
					{
						tmp[j] = kvadrobike[j];
					}
					delete[] kvadrobike;
					kvadrobike = tmp;

					director.setBuilder(&KVADROBuilder);
					try {
						kvadrobike[ii2] = director.getCar();
					}
					catch (const int &ex)
					{
						cout << "Oshibka vvoda dannyix!" << endl;
						flag = 1;
						break;
					}
					cout << "\t quadbike:" << endl;
					kvadrobike[ii2].specification();
					ii2++;
					cout << "write again?" << endl << "1 - yes" << endl;
					cin >> b;
					if (b != 1)
						break;
				}
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> b;
				if (b == 1 && flag != 1)
				{
					try
					{
						file.open("quadbike.txt", ios::binary | ios::app);
						if (!file.is_open()) {
							throw 777;
						}
						while (i2 < ii2) {
							file << kvadrobike[i2].COLOR()->COLOR << " ";
							file << kvadrobike[i2].PRICE()->cena << " ";
							file << kvadrobike[i2].TYPE_ENGINE()->type << " ";
							file << kvadrobike[i2].POWER()->POWER << " ";
							file << kvadrobike[i2].YEAR()->YEAR << " ";
							file << kvadrobike[i2].BRAND()->BRAND << " ";
							file << kvadrobike[i2].MODEL()->MODEL << " ";
							file << kvadrobike[i2].DIMENSIONS(0)->size << " ";
							file << kvadrobike[i2].DIMENSIONS(1)->size << " ";
							file << kvadrobike[i2].DIMENSIONS(2)->size << " ";
							file << kvadrobike[i2].FUEL()->FUEL << " ";
							file << kvadrobike[i2].TRANSMISSION()->TRANSMISSION << " ";
							file << kvadrobike[i2].CONSUMPTION()->CONSUMPTION << " ";
							file << kvadrobike[i2].TRUNK()->TRUNK << " ";
							i2++;
						}
						file.close();
					}
					catch (const int &ex)
					{
						cout << "Oshibka otkritiya faila!" << endl;
					}
				}
				else {
					CAR* tmp = new CAR[i];
					for (int j = 0; j < i; j++)
					{
						tmp[j] = kvadrobike[j];
					}
					delete[] kvadrobike;
					kvadrobike = tmp;
				}
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
				flag = 0;
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
					Car[k].read_file("car.txt",k);
					cout << endl << "CAR " << k + 1 << endl;
					Car[k].specification();
					cout << endl;
				}
				break;
			}
			case 2:
			{
				for (int k = 0; k < i1; k++) {
					motorbike[k].read_file("motorbike.txt", k);
					cout << endl << "Motorbike " << k + 1 << endl;
					motorbike[k].specification();
					cout << endl;
				}
				break;
			}
			case 3:
			{
				for (int k = 0; k < i2; k++) {
					kvadrobike[k].read_file("quadbike.txt", k);
					cout << endl << "Quadbike " << k + 1 << endl;
					kvadrobike[k].specification();
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
	delete[] Car;
	delete[] motorbike;
	delete[] kvadrobike;
	system("PAUSE");
}