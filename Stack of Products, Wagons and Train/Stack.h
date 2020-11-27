#pragma once
#include "Product.h"
class Stack
{
private:
	Product* product;
	unsigned short product_count;

public:

	Stack();

	void Push(const Product*);

	void Pop();

	Product* Get_product() const;

	Product Peek();

	void Clear();

	bool Is_empty();

	void Set_product_count(const unsigned short&);
	unsigned short Get_product_count() const;

	~Stack();

};