#include <assert.h>
#include "Product.h"

Product::Product() :id(0), name(""), price(0.0), discount(0.0)
{}

inline Product::Product(const std::string& name)
{
	Set_name(name);
}

Product::Product(const std::string& name, const double& price)
	:Product(name)
{
	Set_price(price);
}

Product::Product(const std::string& name, const double& price, const double& discount)
	:Product(name, price)
{
	Set_discount(discount);
}

Product::Product(const std::string& name, const double& price, const double& discount, const std::string& company)
	:Product(name, price, discount)
{
	Set_company(company);
	Set_id();
}

void Product::Set_name(const std::string& name)
{
	assert(!name.empty() && "Name is empty!");
	this->name = name;
}

std::string Product::Get_name() const
{
	return name;
}

void Product::Set_price(const double& price)
{
	assert(price > 0 && "Price must be positive integer and more than 0!");
	this->price = price;
}

double Product::Get_price() const
{
	return price;
}

void Product::Set_discount(const double& discount)
{
	assert(discount > 0 && discount < 100 && "Discount min is 1 and max is 99!");
	this->discount = discount;
}

double Product::Get_discount() const
{
	return discount;
}

double Product::Get_price_with_discount() const
{
	return price - ((price * discount) / (double)100);
}

void Product::Set_id()
{
	this->id = rand() % (unsigned int)4294967294 + 1;
}

void Product::Equal_id(const unsigned int& id)
{
	this->id = id;
}

unsigned int Product::Get_id() const
{
	return id;
}

void Product::Set_company(const std::string& company)
{
	assert(!company.empty() && "Company is Empty!");
	this->company = company;
}

std::string Product::Get_company() const
{
	return company;
}