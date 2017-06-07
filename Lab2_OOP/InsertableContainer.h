#pragma once
#include "stdafx.h"
#include "IndexedContainer.h"

class InsertableContainer : virtual public IndexedContainer {
public:
	virtual bool insertAt(int index, int value) = 0; // вставить элемент со сдвигом
	virtual int removeAt(int index) = 0; // убрать элемент со сдвигом
	virtual ~InsertableContainer() {};
};