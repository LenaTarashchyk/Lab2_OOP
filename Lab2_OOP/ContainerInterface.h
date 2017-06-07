#pragma once
#include "stdafx.h"
class ContainerInterface {
public:
	virtual int size() const = 0; // возвращает размер контейнера
	virtual bool isEmpty() const = 0; // проверяет пустой ли контейнер
	virtual std::string toString() const = 0; // строка со всеми элементами
	virtual ~ContainerInterface() {};
};