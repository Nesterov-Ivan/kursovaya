#include "kvadroBuilder.h"
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