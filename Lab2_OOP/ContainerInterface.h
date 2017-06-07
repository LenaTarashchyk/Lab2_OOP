#pragma once
#include "stdafx.h"
class ContainerInterface {
public:
	virtual int size() const = 0; // ���������� ������ ����������
	virtual bool isEmpty() const = 0; // ��������� ������ �� ���������
	virtual std::string toString() const = 0; // ������ �� ����� ����������
	virtual ~ContainerInterface() {};
};