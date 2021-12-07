#include "DepthIterator.h"

DepthIterator::DepthIterator(node* root) {
	put_left_branch_to_stack(root);
}

void DepthIterator::put_left_branch_to_stack(node* root) {
	node* temp = root;
	while (temp != nullptr) {
		_stack.push(temp);
		temp = temp->left;
	}
}

void DepthIterator::next() {
	node* popped = _stack.pop();

	put_left_branch_to_stack(popped->right);
}

bool DepthIterator::has_next() const {
	return !_stack.is_empty();
}

int DepthIterator::get_value() const {
	return _stack.top()->value;
}