#pragma once
#include "stdafx.h"
#include "IndexedContainer.h"
using namespace std;

class StaticArray : public IndexedContainer
{
private:
	int _size;
	int *arr;
public:
	StaticArray(int s);
	virtual int size() const override;
	virtual bool isEmpty() const override; 
	virtual string toString() const override; 
	virtual int get(int index) const override; 
	virtual void set(int index, int value) override; 
	~StaticArray();
};

StaticArray::StaticArray(int s)
{
	_size = s;
	arr =new int[s];
}

int StaticArray::size() const{
	return _size;
}

bool StaticArray::isEmpty() const
{
	return _size==0;
}
string StaticArray::toString() const
{
	string s = "";
	for (int i = 0; i < _size; i++)
	{
		s.append(to_string(arr[i]));
		s.append(" ");
	}
	return s;
}

int StaticArray::get(int index) const
{
	return arr[index];
}

void StaticArray::set(int index, int value)
{
	arr[index] = value;
}
StaticArray::~StaticArray()
{
	delete[] arr;
}
