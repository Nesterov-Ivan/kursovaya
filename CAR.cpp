#include "CAR.h"
CAR::CAR()
{
	cout << "#CAR" << endl;
	cOLOR = 0;
	pRICE = 0;
	tYPE_ENGINE = 0;
	pOWER = 0;
	yEAR = 0;
	bRAND = 0;
	mODEL = 0;
	dIMENSIONS[0] = 0;
	dIMENSIONS[1] = 0;
	dIMENSIONS[2] = 0;
	fUEL = 0;
	tRANSMISSION = 0;
	cONSUMPTION = 0;
	tRUNK = 0;

}

CAR* CAR::read_file(const string name_fail, int k)
{
	CAR* car = new CAR;
	try
	{
		ifstream file1(name_fail);
		if (!file1.is_open()) {
			throw 777;
		}

		color* COLOR = new color();
		price* PRICE = new price();
		type_engine* TYPE = new type_engine();
		power* POWER = new power();
		year* YEAR = new year();
		brand* BRAND = new brand();
		model* MODEL = new model();
		dimensions* DIMENSIONS = new dimensions();
		fuel* FUEL = new fuel();
		transmission* TRANSMISSION = new transmission();
		consumption* CONSUMPTION = new consumption();
		trunk* TRUNK = new trunk();


		for (int j = 0; j <= k; j++) {
			file1 >> COLOR->COLOR;
			car->cOLOR = COLOR;
			file1 >> PRICE->cena;
			car->pRICE = PRICE;
			file1 >> TYPE->type;
			car->tYPE_ENGINE = TYPE;
			file1 >> POWER->POWER;
			car->pOWER = POWER;
			file1 >> YEAR->YEAR;
			car->yEAR = YEAR;
			file1 >> BRAND->BRAND;
			car->bRAND = BRAND;
			file1 >> MODEL->MODEL;
			car->mODEL = MODEL;
			file1 >> DIMENSIONS->size;
			car->dIMENSIONS[0] = DIMENSIONS;
			file1 >> DIMENSIONS->size;
			car->dIMENSIONS[1] = DIMENSIONS;
			file1 >> DIMENSIONS->size;
			car->dIMENSIONS[2] = DIMENSIONS;
			file1 >> FUEL->FUEL;
			car->fUEL = FUEL;
			file1 >> TRANSMISSION->TRANSMISSION;
			car->tRANSMISSION = TRANSMISSION;
			file1 >> CONSUMPTION->CONSUMPTION;
			car->cONSUMPTION = CONSUMPTION;
			file1 >> TRUNK->TRUNK;
			car->tRUNK = TRUNK;
		}
		file1.close();
	}
	catch (const int &ex)
	{
		cout << "Oshibka otkritiya faila!" << endl;
	}
	return car;
}

color * CAR::COLOR()
{
	return cOLOR;
}

price * CAR::PRICE()
{
	return pRICE;
}

type_engine * CAR::TYPE_ENGINE()
{
	return tYPE_ENGINE;
}

power * CAR::POWER()
{
	return pOWER;
}

year * CAR::YEAR()
{
	return yEAR;
}

brand * CAR::BRAND()
{
	return bRAND;
}

model * CAR::MODEL()
{
	return mODEL;
}

dimensions * CAR::DIMENSIONS(int i)
{
	return dIMENSIONS[i];
}

fuel * CAR::FUEL()
{
	return fUEL;
}

transmission * CAR::TRANSMISSION()
{
	return tRANSMISSION;
}

consumption * CAR::CONSUMPTION()
{
	return cONSUMPTION;
}

trunk * CAR::TRUNK()
{
	return tRUNK;
}

void CAR::specification()
{
	cout << "color: " << cOLOR->COLOR << endl;
	cout << "price: " << pRICE->cena << endl;
	cout << "type engine: " << tYPE_ENGINE->type << endl;
	cout << "power: " << pOWER->POWER << endl;
	cout << "year: " << yEAR->YEAR << endl;
	cout << "brand: " << bRAND->BRAND << endl;
	cout << "model: " << mODEL->MODEL << endl;
	cout << "length: " << dIMENSIONS[0]->size << endl;
	cout << "width: " << dIMENSIONS[1]->size << endl;
	cout << "height: " << dIMENSIONS[2]->size << endl;
	cout << "type fuel: " << fUEL->FUEL << endl;
	cout << "transmission: " << tRANSMISSION->TRANSMISSION << endl;
	cout << "consumption: " << cONSUMPTION->CONSUMPTION << endl;
	cout << "trunk: " << tRUNK->TRUNK << endl;
}

CAR::~CAR()
{
	cout << "CAR#" << endl;
	delete cOLOR;
	delete pRICE;
	delete tYPE_ENGINE;
	delete pOWER;
	delete yEAR;
	delete bRAND;
	delete mODEL;
	delete[] dIMENSIONS;
	delete fUEL;
	delete tRANSMISSION;
	delete cONSUMPTION;
	delete tRUNK;
}