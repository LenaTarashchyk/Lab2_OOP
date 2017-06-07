#pragma once
#include "stdafx.h"
#include "PushPopContainerInterface.h"
using namespace std;

class Queue : public PushPopContainerInterface
{
private:
	struct Node;
	Node *head;
	int _size;
public:
	Queue();
	int size() const override;
	bool isEmpty() const override;
	std::string toString() const override;
	bool push(int value) override;
	int pop() override;
	int peek() const override;
	~Queue();
};

struct Queue::Node{
	int value;
	Node* next;
	Node(int value):value(value), next(nullptr){
	}
};
Queue::Queue()
{
	_size=0;
	head = nullptr;
}

int Queue::size() const
{
	return _size;
}

bool Queue::isEmpty() const
{
return _size==0;
}
std::string Queue::toString() const
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
bool Queue::push(int value)
{
	if(isEmpty()){
		head = new Node(value);
	}else
	{
		Node* tmp = head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next  = new Node(value);
	}
	_size++;
	return 1;
}

int Queue::pop()
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
int Queue::peek() const
{
	return head->value;
}
Queue::~Queue()
{
	while(!isEmpty())
	{
		pop();
	}
}