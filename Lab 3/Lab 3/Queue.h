#ifndef _MY_QUEUE_

#define _MY_QUEUE_

#include <stdexcept>

template <typename T>
class Queue
{
private:
	struct element;
public:
	Queue();
	Queue(const Queue& other);
	~Queue();

	Queue& operator=(const Queue& other);

	T pop();
	T front() const;
	void push(T value);
	bool is_empty() const;
private:
	element* _front;
	element* _back;

	void _copy(const Queue& other);
	void _clear();
};

template <typename T>
struct Queue<T>::element {
	T value;
	element* next;
};

#endif //! _MY_QUEUE_
