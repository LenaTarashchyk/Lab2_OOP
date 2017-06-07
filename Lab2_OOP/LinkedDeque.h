#pragma once
#include "stdafx.h"
#include "Deque.h"
using namespace std;
class LinkedDeque : public Deque
{
private:
	struct Node;
	Node* head;
	Node* tail;
	int _size;
public:
	LinkedDeque();
	virtual int size() const override; // ���������� ������ ����������
	virtual bool isEmpty() const override; // ��������� ������ �� ���������
	virtual string toString() const override; // ������ �� ����� ����������
	virtual bool pushFront(int value) override; // �������� � ������
	virtual bool pushBack(int value) override; // �������� � �����
	virtual int popFront() override; // ������� �� ������
	virtual int popBack() override; // ������� � �����
	virtual int peekFront() const override; // ������ ������� � ������
	virtual int peekBack() const override; // ������ ������� � �����
	~LinkedDeque();
};

struct LinkedDeque::Node{
	int value;
	Node* next;
	Node* prev;
	Node(int value):value(value), next(nullptr), prev(nullptr){
	}
};
LinkedDeque::LinkedDeque()
{
_size=0;
head=tail=nullptr;
}
int LinkedDeque::size() const
{
	return _size;
}
bool LinkedDeque::isEmpty() const
{
	return head == nullptr;
}
string LinkedDeque::toString() const
{
	string str = "";
	Node*tmp = head;
	while(tmp!=nullptr){
		str.append(to_string(tmp->value));
		str.append(" ");
		tmp = tmp->next;
	}
	return str;
}
bool LinkedDeque::pushFront(int value)
{
	if(isEmpty())
		head = tail = new Node(value);
	else
	{
		head->prev = new Node(value);
		head->prev->next = head;
		head=head->prev;
	}
	_size++;
	return true;
}

bool LinkedDeque::pushBack(int value)
{
	if(isEmpty())
		head = tail = new Node(value);
	else
	{
		tail->next = new Node(value);
		tail->next->prev = tail;
		tail=tail->next;
	}
	_size++;
	return true;
}
int LinkedDeque::popFront()
{
	if(isEmpty()) return 0;
	if(tail==head)
	{
		int tmp = head->value;
		delete head;
		head=tail=nullptr;
		return tmp;
	}
	int val = head->value;
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
	_size--;
	return val;
}
int LinkedDeque::popBack()
{
	if(isEmpty()) return 0;
	if(tail==head)
	{
		int tmp = head->value;
		delete head;
		head=tail=nullptr;
		return tmp;
	}
	
	int val = tail->value;
	tail=tail->prev;
	delete tail->next;
	tail->next = nullptr;
	_size--;
	return val;

}
int LinkedDeque::peekFront() const
{
	if(!isEmpty())
	return head->value;
}
int LinkedDeque::peekBack() const
{
	if(!isEmpty())
	return tail->value;
}
LinkedDeque::~LinkedDeque()
{
	while(!isEmpty())
	{
		popBack();
	}
}