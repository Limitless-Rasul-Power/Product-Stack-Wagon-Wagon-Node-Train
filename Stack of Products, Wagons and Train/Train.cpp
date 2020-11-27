#include <iostream>
#include <assert.h>
#include "Train.h"

Train::Train() :name(""), first(nullptr), last(nullptr)
{}

Train::Train(const std::string& name, WagonNode* first, WagonNode* last)
{
	assert(!name.empty() && "Name is Empty!");
	this->name = name;

	assert(first && "First Wagon didn't exist!");
	this->first = first;

	assert(last && "Last Wagon didn't exist!");
	this->last = last;
}

WagonNode* Train::Get_wagon_by_number(const std::string& number)
{

	WagonNode* temp = first;

	while (temp != nullptr && temp->wagon->Get_number() != number)
		temp = temp->next;

	return temp;
}

void Train::Show_product_by_number(const std::string& number)
{
	WagonNode* temp = first;
	while (temp != nullptr)
	{
		if (temp->wagon->Get_number() == number)
		{
			temp->wagon->Show();
			return;
		}
		temp = temp->next;
	}

	std::cout << "No_" << number << " Wagon didnt't Exist!\n";
}

void Train::Update_speed_by_number(const std::string& number, const double& speed)
{
	WagonNode* temp = last;

	while (temp != nullptr)
	{
		if (temp->wagon->Get_number() == number)
		{
			temp->wagon->Set_speed(speed);
			return;
		}
		temp = temp->prev;
	}
	std::cout << "No_" << number << " Wagon didnt't Exist!\n";
}

void Train::Update_country_by_number(const std::string& number, const std::string& country)
{
	WagonNode* temp = last;

	while (temp != nullptr)
	{
		if (temp->wagon->Get_number() == number)
		{
			temp->wagon->Set_country(country);
			return;
		}
		temp = temp->prev;
	}
	std::cout << "No_" << number << " Wagon didnt't Exist!\n";
}

void Train::Delete_first()
{
	if (first != nullptr)
	{
		WagonNode* temp = first;
		first->next->prev = first->prev;
		first = first->next;
		delete temp;
	}
}

void Train::Delete_last()
{
	if (last != nullptr)
	{
		WagonNode* temp = last;
		last->prev->next = last->next;
		last = last->prev;
		delete temp;
	}
}

void Train::Delete_wagon_by_number(const std::string& number)
{
	if (first->wagon->Get_number() == number)
		Delete_first();
	else if (last->wagon->Get_number() == number)
		Delete_last();
	else
	{
		WagonNode* temp = first;

		while (temp != nullptr)
		{
			if (temp->wagon->Get_number() == number)
				break;

			temp = temp->next;
		}


		WagonNode* deleted_wagon = temp;

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp = temp->next;

		delete deleted_wagon;
	}
}

void Train::Forward_traverse()
{
	std::cout << "Train Name: " << name << "\n\n";
	WagonNode* temp = first;

	while (temp != nullptr)
	{
		temp->wagon->Show();
		temp = temp->next;
	}
}

void Train::Backward_traverse()
{
	std::cout << "Train Name: " << name << "\n\n";
	WagonNode* temp = last;

	while (temp != nullptr)
	{
		temp->wagon->Show();
		temp = temp->prev;
	}
}

Train::~Train()
{
	while (first != nullptr)
	{
		WagonNode* temp = first;
		first = first->next;
		delete temp;
	}
}
