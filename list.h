#pragma once
#include "element.h"

template <typename T>
class CircularList
{
private:
	Element<T>* head;
	size_t size;
public:
	CircularList(const CircularList& list);
	CircularList(CircularList&& other) noexcept;
	CircularList() : head(nullptr), size(0) {}
	CircularList& operator=(const CircularList& other);
	CircularList& operator=(CircularList&& other) noexcept;
	~CircularList();
	bool IsEmpty();
	size_t GetSize();
	void PushBack(const T& data);
	void PushFront(const T& data);
	void PopFront();
	void PopBack();
	void clear();
	void print();
	void insert(size_t index, const T& data);
	void remove(size_t index);
	T& get(size_t index);
};

template <typename T>
bool operator==(CircularList<T>*first_list, CircularList<T> second_list);


