#pragma once
#include "stdafx.h"
#include "ContainerInterface.h"

class PushPopContainerInterface : virtual public ContainerInterface {
public:
	virtual bool push(int value) = 0; // �������� �������
	virtual int pop() = 0; // ������� �������
	virtual int peek() const = 0; // ������ �������
	virtual ~PushPopContainerInterface() {};
};