#include "motoBuilder.h"
color * motoBuilder::Get_color()
{
	color* COLOR = new color();
	cout << "write color: ";
	cin >> COLOR->COLOR;
	proverka1(COLOR->COLOR);
	return COLOR;
}

price * motoBuilder::Get_price()
{
	price* PRICE = new price();
	char price2[10];
	cout << "write price: ";
	cin >> price2;
	proverka2(price2);
	PRICE->cena = atoi(price2);
	if (PRICE->cena < 0)
		throw 772;
	return PRICE;
}

type_engine * motoBuilder::Get_type_engine()
{
	type_engine* TYPE = new type_engine();
	cout << "write type_engine: ";
	cin >> TYPE->type;
	proverka1(TYPE->type);
	return TYPE;
}

power * motoBuilder::Get_power()
{
	power* POWER = new power();
	char power2[10];
	cout << "write power: ";
	cin >> power2;
	proverka2(power2);
	POWER->POWER = atoi(power2);
	if (POWER->POWER < 0)
		throw 772;
	return POWER;
}

year * motoBuilder::Get_year()
{
	year* YEAR = new year();
	char year2[10];
	cout << "write year: ";
	cin >> year2;
	proverka2(year2);
	YEAR->YEAR = atoi(year2);
	if (YEAR->YEAR < 0)
		throw 772;
	return YEAR;
}

brand * motoBuilder::Get_brand()
{
	brand* BRAND = new brand();
	cout << "write brand: ";
	cin >> BRAND->BRAND;
	proverka1(BRAND->BRAND);
	return BRAND;
}

model * motoBuilder::Get_model()
{
	model* MODEL = new model();
	cout << "write model: ";
	cin >> MODEL->MODEL;
	proverka1(MODEL->MODEL);
	return MODEL;
}

dimensions * motoBuilder::Get_dimensions()
{
	dimensions* DIMENSIONS = new dimensions();
	char size2[10];
	cin >> size2;
	proverka2(size2);
	DIMENSIONS->size = atoi(size2);
	if (DIMENSIONS->size < 0)
		throw 772;
	return DIMENSIONS;
}

fuel * motoBuilder::Get_fuel()
{
	fuel* FUEL = new fuel();
	char fuel2[10];
	cout << "write fuel: ";
	cin >> fuel2;
	proverka2(fuel2);
	FUEL->FUEL = atoi(fuel2);
	if (FUEL->FUEL < 0)
		throw 772;
	return FUEL;
}

transmission * motoBuilder::Get_transmission()
{
	transmission* TRANSMISSION = new transmission();
	cout << "write transmission: ";
	cin >> TRANSMISSION->TRANSMISSION;
	proverka1(TRANSMISSION->TRANSMISSION);
	return TRANSMISSION;
}

consumption * motoBuilder::Get_consumption()
{
	consumption* CONSUMPTION = new consumption();
	char consumption2[10];
	cout << "write consumption: ";
	cin >> consumption2;
	proverka2(consumption2);
	CONSUMPTION->CONSUMPTION = atoi(consumption2);
	if (CONSUMPTION->CONSUMPTION < 0)
		throw 772;
	return CONSUMPTION;
}

trunk * motoBuilder::Get_trunk()
{
	trunk* TRUNK = new trunk();
	char trunk2[10];
	cout << "write trunk: ";
	cin >> trunk2;
	proverka2(trunk2);
	TRUNK->TRUNK = atoi(trunk2);
	if (TRUNK->TRUNK < 0)
		throw 772;
	return TRUNK;
}