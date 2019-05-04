#include "Director.h"
Director::Director()
{
	cout << "#Director" << endl;
	builder = 0;
}

void Director::setBuilder(Builder * newBuilder)
{
	builder = newBuilder;
}

CAR * Director::getCar()
{
	CAR* car = new CAR;
	car->cOLOR = builder->Get_color();
	car->pRICE = builder->Get_price();
	car->tYPE_ENGINE = builder->Get_type_engine();
	car->pOWER = builder->Get_power();
	car->yEAR = builder->Get_year();
	car->bRAND = builder->Get_brand();
	car->mODEL = builder->Get_model();
	car->dIMENSIONS[0] = builder->Get_dimensions();
	car->dIMENSIONS[1] = builder->Get_dimensions();
	car->dIMENSIONS[2] = builder->Get_dimensions();
	car->fUEL = builder->Get_fuel();
	car->tRANSMISSION = builder->Get_transmission();
	car->cONSUMPTION = builder->Get_consumption();
	car->tRUNK = builder->Get_trunk();
	return car;
}

Director::~Director()
{
	cout << "Director#" << endl;
}