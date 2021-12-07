#ifndef  _MY_TREE_

#define _MY_TREE_

#include "DepthIterator.h"
#include "BreadthIterator.h"

#include "Queue.hpp"

#include <iostream>

class Tree
{
public:
	Tree();
	Tree(const Tree& other);
	~Tree();
	bool contains(int value) const; // does three contains a value for O(logN)
	void insert(int value); // insert a value for O(logN)
	void remove(int value); // removing a value
	DepthIterator create_dft_iterator() const; // iterator for depth-first traverse
	BreadthIterator create_bft_iterator() const; // iterator for breadth-first traverse
private:
	node* _root;

	static node* _extract_new_child(Queue<node*>& queue_of_children);
	static void _bind_queuing_parent_with_new_childrens(Queue<node*>& created_parents, Queue<node*>& children_to_copy);

	static bool _contains(node* root, int value);
	//static void _insert(node*& reference_to_root, int value);
	static void _insert_in_non_empty(node* root, int value);
	//static node* _insert(node* root, int value);
	static node* _get_parent_of_searching(node* reference_to_root, int value);

	static node* _remove_and_get_replacement(node* element);

	static node* _remove_with_2_children(node* element);
	static node* _remove_with_1_children(node* element);
	static node* _remove_with_0_children(node* element);

	static node* _get_left_leaf(node* root);

	static void _delete(node* root);
};

#endif // ! _MY_TREE_