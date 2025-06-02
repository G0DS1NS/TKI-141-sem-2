#pragma once

template <typename T>
class Element
{
private:
	T value;
	Element* next;
public:
	Element(const T& value) : value(value), next(nullptr) {}
};
