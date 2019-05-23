#pragma once
#include "structures.h"
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
	void proverka1(char pr[20]);
	void proverka2(char pr[10]);
};