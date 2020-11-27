#pragma once
#include "Wagon.h"
struct WagonNode
{
	Wagon* wagon;

	WagonNode* next;
	WagonNode* prev;

	WagonNode();

	~WagonNode();
};