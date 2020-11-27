#include <iostream>
#include <assert.h>
#include "Stack.h"

Stack::Stack():product(nullptr), product_count(0)
{}

void Stack::Push(const Product* product)
{
	auto temp = new Product[Get_product_count() + 1];

	for (unsigned short i = 0; i < Get_product_count(); i++)
		temp[i] = this->product[i];

	temp[Get_product_count()] = *product;
	delete[] this->product;

	this->product = temp;
	temp = nullptr;
	Set_product_count(Get_product_count() + 1);
}

void Stack::Pop()
{

	if (!Is_empty())
	{
		auto temp = new Product[Get_product_count() - 1];

		for (unsigned short i = 0; i < Get_product_count() - 1; i++)
			temp[i] = this->product[i];

		delete[] this->product;
		this->product = temp;
		temp = nullptr;
		Set_product_count(Get_product_count() - 1);
	}
}

Product* Stack::Get_product() const
{
	return this->product;
}

Product Stack::Peek()
{
	assert(!Is_empty() && "No Product!");
	return this->product[Get_product_count() - 1];
}

void Stack::Clear()
{
	if (this->product != nullptr)
	{
		delete[] product;
		product = nullptr;
	}
}

bool Stack::Is_empty()
{
	if (this->product_count > 0)
		return false;

	return true;
}

void Stack::Set_product_count(const unsigned short& product_count)
{
	this->product_count = product_count;
}

unsigned short Stack::Get_product_count() const
{
	return product_count;
}

Stack::~Stack()
{
	std::cout << "Name: " << product->Get_name() << std::endl;
	delete product;
}