#ifndef _STACK_LIST_TPT_H_
#define _STACK_LIST_TPT_H_
#include <stdexcept>

// Lab 5 
// Abdul Wahab

using namespace std;

// abstract stack class implemented using single-linked list
template<class T>
class abs_stack_list {
public:
	// pushes an element onto the top of the stack. 
	// grows the vector if needed.
	virtual void push(const T& elem)=0;
	
	// pops an element from the top of the stack.
	// does nothing if the stack is empty.
	virtual void pop()=0;
	
	// returns the value of the top element on the stack.
	// throws domain_error if the stack is empty.
	virtual const T& top() const=0;
	
	// returns the number of elements currently on the stack.
	virtual unsigned size() const=0;
};

// the following class inherits from the abstract stack class
// using its own implementation of a single-linked list
// you must implement the abstract methods push, pop, and top.
template<class T>
class mystack_list: public abs_stack_list<T> {
public:
	unsigned size() const {return _size;}
	
	// default constructor
	mystack_list() {
		_size = 0;
		head = nullptr;
	}
	
	//destructor
	~mystack_list() {
		Node* tmp;
		for(Node* current = head; 
				current != nullptr; 
				current = tmp) {
			tmp = current->next;
			delete current;
		}
	}
	
	// TO-DO: YOU MUST IMPLEMENT THE FOLLOWING METHODS:
	// PUSH, POP, TOP

	void push(const T& item)
	{
	head = new Node(item, head);
	_size++;
	}

	void pop() {
		if (head)
		{
		Node* temp = head;
		head = head -> next;
		temp = nullptr;
		--_size;

		
		}
	}


	
	const T& top() const
	{
		if (!size())
		{
			throw domain_error("Stack is empty");
		}
		return head -> data; 
	}

	
 // END OF TO-DO
private:
	// single-linked list node structure
	struct Node {
		T data;
		Node* next;
		Node(T d, Node* n): data(d), next(n) {}
	};

	Node* head;
	unsigned _size;
};
#endif
