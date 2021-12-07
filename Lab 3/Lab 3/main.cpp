#include <iostream>
#include "BinarySearchTree.h"

int main() {
	BinarySearchTree t;

	int arr[] = { 16,40,66,23,12,14,15,5 };

	std::cout << "Order of adding to three: " << std::endl;
	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;

	for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		t.insert(arr[i]);

	std::cout << std::endl << "Depth traversing: " << std::endl;
	DepthIterator di = t.create_dft_iterator();

	for (di; di.has_next(); di.next())
		std::cout << di.get_value() << ' ';
	std::cout << std::endl;


	std::cout << std::endl << "Breadth traversing: " << std::endl;
	BreadthIterator bi = t.create_bft_iterator();

	for (bi; bi.has_next(); bi.next())
		std::cout << bi.get_value() << ' ';

	std::cout << std::endl;

	BinarySearchTree t2(t);

	std::cout << std::endl << "Depth traversing: " << std::endl;

	di = t2.create_dft_iterator();

	for (di; di.has_next(); di.next())
		std::cout << di.get_value() << ' ';
	std::cout << std::endl;

	std::cout << std::endl << "Breadth traversing: " << std::endl;
	bi = t2.create_bft_iterator();

	for (bi; bi.has_next(); bi.next())
		std::cout << bi.get_value() << ' ';

	std::cout << std::endl;

	return 0;
}