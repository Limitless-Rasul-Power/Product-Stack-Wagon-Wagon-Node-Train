#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

int main()
{
	Product* p1 = new Product("Cake", 12.2, 10, "A");
	Product* p2 = new Product("Lazanya", 23.2, 20, "B");
	Product* p3 = new Product("Immune booster", 70, 13.4, "C");

	Product* p4 = new Product("Pizza", 20, 10, "D");
	Product* p5 = new Product("Green Papaya Salad", 50, 20, "D");
	Product* p6 = new Product("Ultimate Energy Drop", 1000, 13.4, "E");

	Product* p7 = new Product("Caesar Salad", 23, 5, "F");
	Product* p8 = new Product("Unleash the Power within", 1400, 10, "G");
	Product* p9 = new Product("Tongue Fu", 1000, 13.4, "Sam Horn");


	Product* p10 = new Product("Lays", 230, 40, "S");
	Product* p11 = new Product("Nike Sneakers", 900, 10, "W");
	Product* p12 = new Product("Giant Lion", 9000, 3.4, "Q");

	Product* p13 = new Product("OOOOO", 230, 40, "P");
	Product* p14 = new Product("Nike Sneakers", 900, 10, "Z");
	Product* p15 = new Product("Giant Lion", 9000, 3.4, "V");

	Stack** st1 = new Stack * [2];
	st1[0] = new Stack;
	st1[1] = new Stack;

	st1[0]->Push(p1);
	st1[0]->Push(p2);
	st1[0]->Push(p3);

	st1[1]->Push(p13);
	st1[1]->Push(p14);
	st1[1]->Push(p15);

	Stack** st2 = new Stack*;
	*st2 = new Stack;

	st2[0]->Push(p4);
	st2[0]->Push(p5);
	st2[0]->Push(p6);

	Stack** st3 = new Stack*;
	*st3 = new Stack;

	st3[0]->Push(p7);
	st3[0]->Push(p8);
	st3[0]->Push(p9);

	Stack** st4 = new Stack*;
	*st4 = new Stack;

	st4[0]->Push(p10);
	st4[0]->Push(p11);
	st4[0]->Push(p12);

	Wagon* w1 = new Wagon("TPOD_129", "New Jersie", 250.4, st1, 2);
	Wagon* w2 = new Wagon("Nupole_45", "San_Fransisco", 350.4, st2, 1);
	Wagon* w3 = new Wagon("Itno_3", "Ohaya", 333.3, st3, 1);
	Wagon* w4 = new Wagon("_Box_", "America", 450.4, st4, 1);

	WagonNode* wn1 = new WagonNode;
	WagonNode* wn2 = new WagonNode;
	WagonNode* wn3 = new WagonNode;
	WagonNode* wn4 = new WagonNode;

	wn1->wagon = w1;
	wn2->wagon = w2;
	wn3->wagon = w3;
	wn4->wagon = w4;


	wn1->prev = nullptr;
	wn1->next = wn2;

	wn2->prev = wn1;
	wn2->next = wn3;

	wn3->prev = wn2;
	wn3->next = wn4;

	wn4->prev = wn3;
	wn4->next = nullptr;


	Train t("Kosmos", wn1, wn4);

	//cout << "Backward Traverse\n\n\n";
	//t.Backward_traverse();
	//cout << "Forward Traverse\n\n\n";
	//t.Forward_traverse();
	//
	//t.Delete_wagon_by_number("_Box_");
	//cout << "\n======= After Deleting ==========\n\n";
	//
	//cout << "Backward Traverse\n\n\n";
	//t.Backward_traverse();
	//cout << "Forward Traverse\n\n\n";
	//t.Forward_traverse();


	//WagonNode* node = t.Get_wagon_by_number("Nupole_45");
	//if (node != nullptr)
	//	node->wagon->Show();
	//else
	//	cout << "Wagon didn't Exist!\n";


	//t.Show_product_by_number("_Box_");
	//t.Show_product_by_number("DADW");


	/*t.Show_product_by_number("Itno_3");

	t.Update_speed_by_number("Itno_3", 1000);
	t.Update_country_by_number("Itno_3", "China");

	cout << "\n\n====== After Change ======\n\n";
	t.Show_product_by_number("Itno_3");*/


	system("pause");
	return 0;
}