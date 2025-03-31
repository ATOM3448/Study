#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>
#include "MyTree.h"

using namespace std;
using namespace MyTask;

MyTree* RandomData()
{
	MyTree* tree = new MyTree;
	for (int i = 0; i < 20; i++)
	{
		(*tree).insert_tree(&(*tree).root, (rand() % 100), (*tree).root);
	}
	return tree;
}

MyTree* InputData()
{
	MyTree* tree = new MyTree;
	int in = 0;
	int size = 0;

	cout << "\n\tÂâûåäèòå êîë-âî ýëåìåíòîâ: ";
	cin >> size;
	cout << "\n\tÂâûåäèòå ýëåìåíòû: \n";

	for (int i = 0; i < size; i++)
	{
		cin >> in;
		(*tree).insert_tree(&(*tree).root, in, (*tree).root);
	}
	return tree;
}

MyTree* fileData()
{
	MyTree* tree = new MyTree;
	int integer = 0;

	ifstream in;
	in.open("f.txt");

	while (in >> integer)
	{
		(*tree).insert_tree(&(*tree).root, integer, (*tree).root);
	}
	return tree;
}



int main()
{
	setlocale(0, "");
	srand(time(NULL));

	cout << "Âûáåðèòå ðåæèì:\n\t1: Ðàíäîì\n\t2: Ââîä â êîíñîëè\n\t3: ×òåíèå ñ ôàéëà\nÂàø âûáîð: ";

	__int16 mode = 0;
	cin >> mode;

	MyTree* tree;

	switch (mode)
	{
	case 1:
		tree = RandomData();
		break;
	case 2:
		tree = InputData();
		break;
	case 3:
		tree = fileData();
		break;
	default:
		cout << "Íåêîððåêòíûé ââîä";
		exit(EXIT_FAILURE);
		break;
	}
	
	cout << "\n\nÄåðåâî:\n";

	tree->travel_tree_print_boring(tree->root);

	cout << endl;

	cout << "Ñóììà ëèñòüåâ: " << tree->travel_tree_sum(tree->root) << endl;

	cout << endl;

	system("pause");

	return 0;
}