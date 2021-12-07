#ifndef  _MY_NODE_

#define _MY_NODE_

struct node {
	node(int value);
	int value;
	node* left;
	node* right;
};

#endif // !_MY_NODE_