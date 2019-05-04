#pragma once
#include "structures.h"
class CAR
{
private:
	friend class Director;
	color* cOLOR;
	price* pRICE;
	type_engine* tYPE_ENGINE;
	power* pOWER;
	year* yEAR;
	brand* bRAND;
	model* mODEL;
	dimensions* dIMENSIONS[3];
	fuel* fUEL;
	transmission* tRANSMISSION;
	consumption* cONSUMPTION;
	trunk* tRUNK;
public:
	CAR();
	CAR* read_file(const string name_fail, int k);
	color* COLOR();
	price* PRICE();
	type_engine* TYPE_ENGINE();
	power* POWER();
	year* YEAR();
	brand* BRAND();
	model* MODEL();
	dimensions* DIMENSIONS(int i);
	fuel* FUEL();
	transmission* TRANSMISSION();
	consumption* CONSUMPTION();
	trunk* TRUNK();
	void specification();
	~CAR();
};