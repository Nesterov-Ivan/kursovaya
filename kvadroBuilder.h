#pragma once
#include "Builder.h"
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