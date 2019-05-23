#pragma once
#include "Builder.h"
#include "CAR.h"
class Director
{
private:
	Builder* builder;
public:

	Director();
	void setBuilder(Builder* newBuilder);
	CAR getCar();
	~Director();
};