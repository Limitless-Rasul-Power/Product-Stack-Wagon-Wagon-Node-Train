#pragma once
#include "Wagon_Node.h"
struct Train
{

private:

	std::string name;

	WagonNode* first;
	WagonNode* last;

	void Delete_first();	
	void Delete_last();

public:


	Train();

	Train(const std::string&, WagonNode* first, WagonNode* last);

	WagonNode* Get_wagon_by_number(const std::string&);

	void Show_product_by_number(const std::string&);

	void Update_speed_by_number(const std::string&, const double&);

	void Update_country_by_number(const std::string&, const std::string&);

	void Delete_wagon_by_number(const std::string&);

	void Forward_traverse();

	void Backward_traverse();

	~Train();

};
