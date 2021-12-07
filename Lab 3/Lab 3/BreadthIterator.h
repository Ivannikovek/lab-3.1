#ifndef _MY_BREADTH_ITERATOR_ 

#define _MY_BREADTH_ITERATOR_

#include "Iterator.h"
#include "node.h"
#include "Queue.hpp"

class BreadthIterator : public Iterator {
public:
	BreadthIterator(node* root);

	virtual void next() override;
	virtual bool has_next() const override;
	virtual int get_value() const override;
private:
	Queue<node*> _queue;

	void put_children_to_queue(node* root);
};

#endif	//! _MY_BREADTH_ITERATOR_