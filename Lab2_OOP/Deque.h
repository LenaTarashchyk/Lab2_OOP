#pragma once
#include "ContainerInterface.h"

class Deque :  public ContainerInterface {
public:
	virtual bool pushFront(int value) = 0; // �������� � ������
	virtual bool pushBack(int value) = 0; // �������� � �����
	virtual int popFront() = 0; // ������� �� ������
	virtual int popBack() = 0; // ������� � �����
	virtual int peekFront() const = 0; // ������ ������� � ������
	virtual int peekBack() const = 0; // ������ ������� � �����
	virtual ~Deque() {};
};