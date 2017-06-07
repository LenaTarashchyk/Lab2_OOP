#pragma once
#include "stdafx.h"
#include "ContainerInterface.h"

class IndexedContainer : virtual public ContainerInterface {
public:
	virtual int get(int index) const = 0; // узнать элемент по индексу index
	virtual void set(int index, int value) = 0; // задать значение элементу
	virtual ~IndexedContainer() {};
};