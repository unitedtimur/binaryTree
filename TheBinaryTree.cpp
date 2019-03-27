#include <iostream>
#include "tree.h"
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(0));

	tree<int> tamerlan;

	tamerlan.add_node("tam.tamerlan"); //from file
	
	tamerlan.print_tree_BRD();

	cout << endl;

	for (auto i = 0; i < 2; ++i)
	{
		tamerlan.add_node(rand() % 10 + 1);
	}

	tamerlan.print_tree_LRD();

	cout << endl;

	if (tamerlan.find_data(2))
	{
		cout << "//find" << endl;
	}
	else
	{
		cout << "//not find" << endl;
	}

	tamerlan.find_max();
	tamerlan.find_min();

	cout << "//height " << tamerlan.height() << endl;

	system("pause");
	return 0;
}