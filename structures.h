#pragma once
#include "stdafx.h"
struct color
{
	char* COLOR;
	color() {
		cout << "#color" << endl;
		COLOR = new char[10];
	}
	~color() {
		cout << "color#" << endl;
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
		cout << "#type_engine" << endl;
		type = new char[10];
	}
	~type_engine() {
		cout << "type_engine#" << endl;
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
		cout << "#brand" << endl;
		BRAND = new char[20];
	}
	~brand() {
		cout << "brand#" << endl;
		delete[] BRAND;
	}
};

struct model
{
	char* MODEL;
	model() {
		cout << "#model" << endl;
		MODEL = new char[20];
	}
	~model() {
		cout << "model#" << endl;
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
		cout << "#transmission" << endl;
		TRANSMISSION = new char[10];
	}
	~transmission() {
		cout << "transmission#" << endl;
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