#include <iostream>
#include <assert.h>
#include "Wagon.h"

Wagon::Wagon() :products(nullptr), stack_count(0), number(""), country(""), speed(0.0)/*, next(nullptr), prev(nullptr)*/
{}

Wagon::Wagon(const std::string& number, const std::string& country, const double& speed, Stack** products, const short& stack_count)
{
	Set_number(number);
	Set_country(country);
	Set_speed(speed);
	Set_stack_count(stack_count);
	Set_products(products);
}

void Wagon::Set_number(const std::string& number)
{
	assert(!number.empty() && "Number is empty!");
	this->number = number;
}

std::string Wagon::Get_number() const
{
	return number;
}


void Wagon::Set_country(const std::string& country)
{
	assert(!country.empty() && "Country is empty!");
	this->country = country;
}

std::string Wagon::Get_country() const
{
	return country;
}

void Wagon::Set_speed(const double& speed)
{
	assert(speed > 0 && "Speed must be postive number!");
	this->speed = speed;
}

double Wagon::Get_speed() const
{
	return speed;
}

void Wagon::Set_stack_count(const short& stack_count)
{
	assert(stack_count > 0 && "Stack count is 0!");
	this->stack_count = stack_count;
}

unsigned short Wagon::Get_stack_count() const
{
	return stack_count;
}

void Wagon::Set_products(Stack** products)
{
	assert(products && "Product is nullptr!");
	this->products = new Stack * [Get_stack_count()];

	for (unsigned short i = 0; i < Get_stack_count(); i++)
	{
		this->products[i] = new Stack;
		this->products[i] = products[i];
	}
}

Stack** Wagon::Get_products() const
{
	return products;
}

void Wagon::Show()
{
	std::cout << "Wagon No_" << Get_number() << '\n';
	std::cout << "Wagon Country: " << Get_country() << '\n';
	std::cout << "Wagon Speed: " << Get_speed() << "\n\n";

	for (unsigned short i = 0; i < Get_stack_count(); i++)
	{
		std::cout << "#" << i + 1 << ", Stack Products" << "\n\n";
		for (unsigned short j = 0; j < products[i]->Get_product_count(); j++)
		{
			std::cout << "#" << j + 1 << ", Product Company: " << products[i]->Get_product()[j].Get_company() << '\n';
			std::cout << "#" << j + 1 << ", Product Name: " << products[i]->Get_product()[j].Get_name() << '\n';
			std::cout << "#" << j + 1 << ", Product Price Before Discount: " << products[i]->Get_product()[j].Get_price() << '\n';
			std::cout << "#" << j + 1 << ", Product Price After Discount: " << products[i]->Get_product()[j].Get_price_with_discount() << "\n\n";
		}
	}
}

Wagon::~Wagon()
{
	for (unsigned short i = 0; i < Get_stack_count(); i++)
		for (unsigned short j = 0; j < products[i]->Get_product_count(); j++)
				products[i]->Pop();

	delete[] products;
}