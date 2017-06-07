#pragma once
#include "stdafx.h"
#include "ContainerInterface.h"

class PushPopContainerInterface : virtual public ContainerInterface {
public:
	virtual bool push(int value) = 0; // добавить элемент
	virtual int pop() = 0; // забрать элемент
	virtual int peek() const = 0; // узнать элемент
	virtual ~PushPopContainerInterface() {};
};