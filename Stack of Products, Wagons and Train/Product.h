#pragma once
#include <string>
class Product
{

private:
	unsigned int id;
	std::string name;
	double price;
	double discount;
	std::string company;

public:

	Product();

	explicit inline Product(const std::string&);

	Product(const std::string&, const double&);

	Product(const std::string&, const double&, const double&);

	Product(const std::string& name, const double&, const double&, const std::string&);

	void Set_name(const std::string&);

	std::string Get_name() const;

	void Set_price(const double&);

	double Get_price() const;

	void Set_discount(const double&);

	double Get_discount() const;

	double Get_price_with_discount() const;

	void Set_id();

	void Equal_id(const unsigned int&);

	unsigned int Get_id() const;

	void Set_company(const std::string&);

	std::string Get_company() const;

};