#pragma once
#include "stdafx.h"
#include "PushPopContainerInterface.h"
using namespace std;

class Stack : public PushPopContainerInterface
{
private:
	struct Node;
	Node *head;
	int _size;
public:
	Stack();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool push(int value) override;
	int pop() override;
	int peek() const override;
	~Stack();
};

struct Stack::Node{
	int value;
	Node* next;
	Node(int value):value(value), next(nullptr){
	}
};
Stack::Stack()
{
	_size=0;
	head = nullptr;
}

int Stack::size() const
{
	return _size;
}

bool Stack::isEmpty() const
{
return _size==0;
}
std::string Stack::toString() const
{
	string str = "";
	Node* tmp = head;
	while(tmp!=nullptr){
		str.append(to_string(tmp->value));
		str.append(" ");
		tmp = tmp->next;
	}
	return str;
}
bool Stack::push(int value)
{
	if(isEmpty()){
		head = new Node(value);
	}else
	{
		/*Node* tmp = head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next  = new Node(value);*/

		Node* tmp = new Node(value);
		tmp-> next = head;
		head = tmp;
	}
	_size++;
	return 1;
}

int Stack::pop()
{
	if(isEmpty())
		return 0;
	Node *tmp = head->next;
	int val = head->value;
	delete head;
	head = tmp;
	_size--;
	return val;
}
int Stack::peek() const
{
	return head->value;
}
Stack::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
}


