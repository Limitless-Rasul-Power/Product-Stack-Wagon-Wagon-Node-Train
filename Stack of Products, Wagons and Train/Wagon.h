#pragma once
#include "Stack.h"
class Wagon
{
private:
	Stack** products;
	unsigned short stack_count;
	std::string number;
	std::string country;
	double speed;

public:

	/*Wagon* next;
	Wagon* prev;*/

	Wagon();

	Wagon(const std::string&, const std::string&, const double&, Stack**, const short&);

	void Set_number(const std::string&);

	std::string Get_number() const;


	void Set_country(const std::string&);

	std::string Get_country() const;

	void Set_speed(const double&);

	double Get_speed() const;

	void Set_stack_count(const short&);

	unsigned short Get_stack_count() const;

	void Set_products(Stack**);

	Stack** Get_products() const;

	void Show();

	~Wagon();
};