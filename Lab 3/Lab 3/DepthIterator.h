#ifndef _MY_DEPTH_ITERATOR_ 

#define _MY_DEPTH_ITERATOR_

#include "Iterator.h"
#include "node.h"
#include "Stack.hpp"

class DepthIterator : public Iterator {
public:
	DepthIterator(node* root);

	virtual void next() override;
	virtual bool has_next() const override;
	virtual int get_value() const override;

private:
	Stack<node*> _stack;

	void put_left_branch_to_stack(node* root);
};

#endif	//! _MY_DEPTH_ITERATOR_
