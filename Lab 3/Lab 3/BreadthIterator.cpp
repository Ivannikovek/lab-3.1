#include "BreadthIterator.h"

BreadthIterator::BreadthIterator(node* root) {
	if (root != nullptr) 
		_queue.push(root);
}

void BreadthIterator::next() {
	node* popped = _queue.pop();

	put_children_to_queue(popped);
}

void BreadthIterator::put_children_to_queue(node* root) {
	if (root->left != nullptr)
		_queue.push(root->left);

	if (root->right != nullptr)
		_queue.push(root->right);
}

bool BreadthIterator::has_next() const {
	return !_queue.is_empty();
}

int BreadthIterator::get_value() const {
	return _queue.front()->value;
}