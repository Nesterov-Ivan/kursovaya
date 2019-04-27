// machineassemblyconveyor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct color
{
	char* COLOR;
	color() {
		COLOR = new char[10];
	}
	~color() {
		delete[] COLOR;
	}
};

struct price
{
	int cena;
};

struct type_engine
{
	char* type;
	type_engine() {
		type = new char[10];
	}
	~type_engine() {
		delete[] type;
	}
};

struct power
{
	int POWER;
};

struct year
{
	int YEAR;
};

struct brand
{
	char* BRAND;
	brand() {
		BRAND = new char[20];
	}
	~brand() {
		delete[] BRAND;
	}
};

struct model
{
	char* MODEL;
	model() {
		MODEL = new char[20];
	}
	~model() {
		delete[] MODEL;
	}
};

struct dimensions
{
	int size;
};

struct fuel
{
	int FUEL;
};

struct transmission
{
	char* TRANSMISSION;
	transmission() {
		 TRANSMISSION = new char[10];
	}
	~transmission() {
		delete[] TRANSMISSION;
	}
};

struct consumption
{
	int CONSUMPTION;
};

struct trunk
{
	int TRUNK;
};

class CAR
{
public:
	color* COLOR;
	price* PRICE;
	type_engine* TYPE_ENGINE;
	power* POWER;
	year* YEAR;
	brand* BRAND;
	model* MODEL;
	dimensions* DIMENSIONS[3];
	fuel* FUEL;
	transmission* TRANSMISSION;
	consumption* CONSUMPTION;
	trunk* TRUNK;
	void specification();
};

void CAR::specification()
{
	cout << "color: " << COLOR->COLOR << endl;
	cout << "price: " << PRICE->cena << endl;
	cout << "type engine: " << TYPE_ENGINE->type << endl;
	cout << "power: " << POWER->POWER << endl;
	cout << "year: " << YEAR->YEAR << endl;
	cout << "brand: " << BRAND->BRAND << endl;
	cout << "model: " << MODEL->MODEL << endl;
	cout << "length: " << DIMENSIONS[0]->size << endl;
	cout << "width: " << DIMENSIONS[1]->size << endl;
	cout << "height: " << DIMENSIONS[2]->size << endl;
	cout << "type fuel: " << FUEL->FUEL << endl;
	cout << "transmission: " << TRANSMISSION->TRANSMISSION << endl;
	cout << "consumption: " << CONSUMPTION->CONSUMPTION << endl;
	cout << "trunk: " << TRUNK->TRUNK << endl;
}

class Builder {
public:
	virtual color* Get_color() = 0;
	virtual price* Get_price() = 0;
	virtual type_engine* Get_type_engine() = 0;
	virtual power* Get_power() = 0;
	virtual year* Get_year() = 0;
	virtual brand* Get_brand() = 0;
	virtual model* Get_model() = 0;
	virtual dimensions* Get_dimensions() = 0;
	virtual fuel* Get_fuel() = 0;
	virtual transmission* Get_transmission() = 0;
	virtual consumption* Get_consumption() = 0;
	virtual trunk* Get_trunk() = 0;
};

class Director
{
private:
	Builder* builder;
public:
	void setBuilder(Builder* newBuilder);
	CAR* getCar();
};

void Director::setBuilder(Builder * newBuilder)
{
	builder = newBuilder;
}

CAR * Director::getCar()
{
	CAR* car = new CAR;
	car->COLOR = builder->Get_color();
	car->PRICE = builder->Get_price();
	car->TYPE_ENGINE = builder->Get_type_engine();
	car->POWER = builder->Get_power();
	car->YEAR = builder->Get_year();
	car->BRAND = builder->Get_brand();
	car->MODEL = builder->Get_model();
	car->DIMENSIONS[0] = builder->Get_dimensions();
	car->DIMENSIONS[1] = builder->Get_dimensions();
	car->DIMENSIONS[2] = builder->Get_dimensions();
	car->FUEL = builder->Get_fuel();
	car->TRANSMISSION = builder->Get_transmission();
	car->CONSUMPTION = builder->Get_consumption();
	car->TRUNK = builder->Get_trunk();
	return car;
}

class avtoBuilder : public Builder {
public:
	color* Get_color();
	price* Get_price();
	type_engine* Get_type_engine();
	power* Get_power();
	year* Get_year();
	brand* Get_brand();
	model* Get_model();
	dimensions* Get_dimensions();
	fuel* Get_fuel();
	transmission* Get_transmission();
	consumption* Get_consumption();
	trunk* Get_trunk();
};

class motoBuilder : public Builder {
public:
	color* Get_color();
	price* Get_price();
	type_engine* Get_type_engine();
	power* Get_power();
	year* Get_year();
	brand* Get_brand();
	model* Get_model();
	dimensions* Get_dimensions();
	fuel* Get_fuel();
	transmission* Get_transmission();
	consumption* Get_consumption();
	trunk* Get_trunk();
};

class kvadroBuilder : public Builder {
public:
	color* Get_color();
	price* Get_price();
	type_engine* Get_type_engine();
	power* Get_power();
	year* Get_year();
	brand* Get_brand();
	model* Get_model();
	dimensions* Get_dimensions();
	fuel* Get_fuel();
	transmission* Get_transmission();
	consumption* Get_consumption();
	trunk* Get_trunk();
};

int main()
{
	setlocale(LC_ALL, "rus");
	CAR* Car;
	Director director;
	avtoBuilder AVTOBuilder;
	motoBuilder MOTOBuilder;
	kvadroBuilder KVADROBuilder;
	int a = 1, b = 0;
	ifstream file1;

	while (a) {
		cout << endl << "select an action: " << endl
			<< "\t1 - add transport" << endl
			<< "\t2- output data from file" << endl
			<< "\t0 - exit" << endl;
		cin >> a;
		switch (a) {
		case 1: 
		{
			cout << endl << "what type of transport to add?: " << endl
				<< "\t1 - car" << endl
				<< "\t2- motorbike" << endl
				<< "\t3- quadbike" << endl
				<< "\t0 - exit" << endl;
			cin >> b;
			switch (b) {
			case 1:
			{
				director.setBuilder(&AVTOBuilder);
				Car = director.getCar();
				cout << "\t CAR:" << endl;
				Car->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> a;
				if (a == 1)
				{
					ofstream file("car.txt", ios::app);
					file << "color: " << Car->COLOR->COLOR << endl;
					file << "price: " << Car->PRICE->cena << endl;
					file << "type engine: " << Car->TYPE_ENGINE->type << endl;
					file << "power: " << Car->POWER->POWER << endl;
					file << "year: " << Car->YEAR->YEAR << endl;
					file << "brand: " << Car->BRAND->BRAND << endl;
					file << "model: " << Car->MODEL->MODEL << endl;
					file << "length: " << Car->DIMENSIONS[0]->size << endl;
					file << "width: " << Car->DIMENSIONS[1]->size << endl;
					file << "height: " << Car->DIMENSIONS[2]->size << endl;
					file << "type fuel: " << Car->FUEL->FUEL << endl;
					file << "transmission: " << Car->TRANSMISSION->TRANSMISSION << endl;
					file << "consumption: " << Car->CONSUMPTION->CONSUMPTION << endl;
					file << "trunk: " << Car->TRUNK->TRUNK << endl;
					file.close();
				}
				break;
			}
			case 2:
			{
				director.setBuilder(&MOTOBuilder);
				Car = director.getCar();
				cout << "\t motorbike:" << endl;
				Car->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> a;
				if (a == 1)
				{
					ofstream file("motorbike.txt", ios::app);
					file << "color: " << Car->COLOR->COLOR << endl;
					file << "price: " << Car->PRICE->cena << endl;
					file << "type engine: " << Car->TYPE_ENGINE->type << endl;
					file << "power: " << Car->POWER->POWER << endl;
					file << "year: " << Car->YEAR->YEAR << endl;
					file << "brand: " << Car->BRAND->BRAND << endl;
					file << "model: " << Car->MODEL->MODEL << endl;
					file << "length: " << Car->DIMENSIONS[0]->size << endl;
					file << "width: " << Car->DIMENSIONS[1]->size << endl;
					file << "height: " << Car->DIMENSIONS[2]->size << endl;
					file << "type fuel: " << Car->FUEL->FUEL << endl;
					file << "transmission: " << Car->TRANSMISSION->TRANSMISSION << endl;
					file << "consumption: " << Car->CONSUMPTION->CONSUMPTION << endl;
					file << "trunk: " << Car->TRUNK->TRUNK << endl;
					file.close();
				}
				break;
			}
			case 3:
			{
				director.setBuilder(&KVADROBuilder);
				Car = director.getCar();
				cout << "\t quadbike:" << endl;
				Car->specification();
				cout << "write to file?" << endl << "1 - yes" << endl;
				cin >> a;
				if (a == 1)
				{
					ofstream file("quadbike.txt", ios::app);
					file << "color: " << Car->COLOR->COLOR << endl;
					file << "price: " << Car->PRICE->cena << endl;
					file << "type engine: " << Car->TYPE_ENGINE->type << endl;
					file << "power: " << Car->POWER->POWER << endl;
					file << "year: " << Car->YEAR->YEAR << endl;
					file << "brand: " << Car->BRAND->BRAND << endl;
					file << "model: " << Car->MODEL->MODEL << endl;
					file << "length: " << Car->DIMENSIONS[0]->size << endl;
					file << "width: " << Car->DIMENSIONS[1]->size << endl;
					file << "height: " << Car->DIMENSIONS[2]->size << endl;
					file << "type fuel: " << Car->FUEL->FUEL << endl;
					file << "transmission: " << Car->TRANSMISSION->TRANSMISSION << endl;
					file << "consumption: " << Car->CONSUMPTION->CONSUMPTION << endl;
					file << "trunk: " << Car->TRUNK->TRUNK << endl;
					file.close();
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
			cout << endl << "what type of transport to output?: " << endl
				<< "\t1 - car" << endl
				<< "\t2- motorbike" << endl
				<< "\t3- quadbike" << endl
				<< "\t0 - exit" << endl;
			cin >> b;
			switch (b) {
			case 1:
			{
				file1.open("car.txt");
				char *str = new char[1000];
				int i = 0;
				while (file1.get(str[i]))
				{
					cout << str[i];
					i++;
				}
				delete[] str;
				file1.close();
				break;
			}
			case 2:
			{
				file1.open("motorbike.txt");
				char *str = new char[1000];
				int i = 0;
				while (file1.get(str[i]))
				{
					cout << str[i];
					i++;
				}
				delete[] str;
				file1.close();
				break;
			}
			case 3:
			{
				file1.open("quadbike.txt");
				char *str = new char[1000];
				int i = 0;
				while (file1.get(str[i]))
				{
					cout << str[i];
					i++;
				}
				delete[] str;
				file1.close();
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
}

color * avtoBuilder::Get_color()
{
	color* COLOR = new color();
	cout << "write color: ";
	cin >> COLOR->COLOR;
	return COLOR;
}

price * avtoBuilder::Get_price()
{
	price* PRICE = new price();
	cout << "write price: ";
	cin >> PRICE->cena;
	return PRICE;
}

type_engine * avtoBuilder::Get_type_engine()
{
	type_engine* TYPE = new type_engine();
	cout << "write type_engine: ";
	cin >> TYPE->type;
	return TYPE;
}

power * avtoBuilder::Get_power()
{
	power* POWER = new power();
	cout << "write power: ";
	cin >> POWER->POWER;
	return POWER;
}

year * avtoBuilder::Get_year()
{
	year* YEAR = new year();
	cout << "write year: ";
	cin >> YEAR->YEAR;
	return YEAR;
}

brand * avtoBuilder::Get_brand()
{
	brand* BRAND = new brand();
	cout << "write brand: ";
	cin >> BRAND->BRAND;
	return BRAND;
}

model * avtoBuilder::Get_model()
{
	model* MODEL = new model();
	cout << "write model: ";
	cin >> MODEL->MODEL;
	return MODEL;
}

dimensions * avtoBuilder::Get_dimensions()
{
	dimensions* DIMENSIONS = new dimensions();
	cout << "write dimensions: ";
	cin >> DIMENSIONS->size;
	return DIMENSIONS;
}

fuel * avtoBuilder::Get_fuel()
{
	fuel* FUEL = new fuel();
	cout << "write fuel: ";
	cin >> FUEL->FUEL;
	return FUEL;
}

transmission * avtoBuilder::Get_transmission()
{
	transmission* TRANSMISSION = new transmission();
	cout << "write transmission: ";
	cin >> TRANSMISSION->TRANSMISSION;
	return TRANSMISSION;
}

consumption * avtoBuilder::Get_consumption()
{
	consumption* CONSUMPTION = new consumption();
	cout << "write consumption: ";
	cin >> CONSUMPTION->CONSUMPTION;
	return CONSUMPTION;
}

trunk * avtoBuilder::Get_trunk()
{
	trunk* TRUNK = new trunk();
	cout << "write trunk: ";
	cin >> TRUNK->TRUNK;
	return TRUNK;
}

color * motoBuilder::Get_color()
{
	color* COLOR = new color();
	cout << "write color: ";
	cin >> COLOR->COLOR;
	return COLOR;
}

price * motoBuilder::Get_price()
{
	price* PRICE = new price();
	cout << "write price: ";
	cin >> PRICE->cena;
	return PRICE;
}

type_engine * motoBuilder::Get_type_engine()
{
	type_engine* TYPE = new type_engine();
	cout << "write type_engine: ";
	cin >> TYPE->type;
	return TYPE;
}

power * motoBuilder::Get_power()
{
	power* POWER = new power();
	cout << "write power: ";
	cin >> POWER->POWER;
	return POWER;
}

year * motoBuilder::Get_year()
{
	year* YEAR = new year();
	cout << "write year: ";
	cin >> YEAR->YEAR;
	return YEAR;
}

brand * motoBuilder::Get_brand()
{
	brand* BRAND = new brand();
	cout << "write brand: ";
	cin >> BRAND->BRAND;
	return BRAND;
}

model * motoBuilder::Get_model()
{
	model* MODEL = new model();
	cout << "write model: ";
	cin >> MODEL->MODEL;
	return MODEL;
}

dimensions * motoBuilder::Get_dimensions()
{
	dimensions* DIMENSIONS = new dimensions();
	cout << "write dimensions: ";
	cin >> DIMENSIONS->size;
	return DIMENSIONS;
}

fuel * motoBuilder::Get_fuel()
{
	fuel* FUEL = new fuel();
	cout << "write fuel: ";
	cin >> FUEL->FUEL;
	return FUEL;
}

transmission * motoBuilder::Get_transmission()
{
	transmission* TRANSMISSION = new transmission();
	cout << "write transmission: ";
	cin >> TRANSMISSION->TRANSMISSION;
	return TRANSMISSION;
}

consumption * motoBuilder::Get_consumption()
{
	consumption* CONSUMPTION = new consumption();
	cout << "write consumption: ";
	cin >> CONSUMPTION->CONSUMPTION;
	return CONSUMPTION;
}

trunk * motoBuilder::Get_trunk()
{
	trunk* TRUNK = new trunk();
	cout << "write trunk: ";
	cin >> TRUNK->TRUNK;
	return TRUNK;
}

color * kvadroBuilder::Get_color()
{
	color* COLOR = new color();
	cout << "write color: ";
	cin >> COLOR->COLOR;
	return COLOR;
}

price * kvadroBuilder::Get_price()
{
	price* PRICE = new price();
	cout << "write price: ";
	cin >> PRICE->cena;
	return PRICE;
}

type_engine * kvadroBuilder::Get_type_engine()
{
	type_engine* TYPE = new type_engine();
	cout << "write type_engine: ";
	cin >> TYPE->type;
	return TYPE;
}

power * kvadroBuilder::Get_power()
{
	power* POWER = new power();
	cout << "write power: ";
	cin >> POWER->POWER;
	return POWER;
}

year * kvadroBuilder::Get_year()
{
	year* YEAR = new year();
	cout << "write year: ";
	cin >> YEAR->YEAR;
	return YEAR;
}

brand * kvadroBuilder::Get_brand()
{
	brand* BRAND = new brand();
	cout << "write brand: ";
	cin >> BRAND->BRAND;
	return BRAND;
}

model * kvadroBuilder::Get_model()
{
	model* MODEL = new model();
	cout << "write model: ";
	cin >> MODEL->MODEL;
	return MODEL;
}

dimensions * kvadroBuilder::Get_dimensions()
{
	dimensions* DIMENSIONS = new dimensions();
	cout << "write dimensions: ";
	cin >> DIMENSIONS->size;
	return DIMENSIONS;
}

fuel * kvadroBuilder::Get_fuel()
{
	fuel* FUEL = new fuel();
	cout << "write fuel: ";
	cin >> FUEL->FUEL;
	return FUEL;
}

transmission * kvadroBuilder::Get_transmission()
{
	transmission* TRANSMISSION = new transmission();
	cout << "write transmission: ";
	cin >> TRANSMISSION->TRANSMISSION;
	return TRANSMISSION;
}

consumption * kvadroBuilder::Get_consumption()
{
	consumption* CONSUMPTION = new consumption();
	cout << "write consumption: ";
	cin >> CONSUMPTION->CONSUMPTION;
	return CONSUMPTION;
}

trunk * kvadroBuilder::Get_trunk()
{
	trunk* TRUNK = new trunk();
	cout << "write trunk: ";
	cin >> TRUNK->TRUNK;
	return TRUNK;
}