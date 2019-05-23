#include "stdafx.h"
#include "Builder.h"

void Builder::proverka1(char pr[20])
{
	for (int i = 0; i < strlen(pr); i++)
	{
		if (!isalpha(pr[i])) {
			throw 777;
		}
	}
}

void Builder::proverka2(char pr[10])
{
	for (int i = 0; i < strlen(pr); i++)
	{
		if (!isdigit(pr[i])) {
			throw 777;
		}
	}
}