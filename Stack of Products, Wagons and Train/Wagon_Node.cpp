#include "Wagon_Node.h"
WagonNode::WagonNode()
{
	wagon = nullptr;
	next = nullptr;
	prev = nullptr;
}
WagonNode::~WagonNode()
{
	delete wagon;
}