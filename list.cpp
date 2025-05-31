#include <string>
#include <iostream>
#include "list.h"

using namespace std;

template<typename T>
CircularList<T>::CircularList(const CircularList& list)
{
    CircularList* old_lis = &this;
    old_list = list;
}

template<typename T>
bool operator==(CircularList<T>* first_list, CircularList<T> second_list)
{
    CircularList<T>* temp = new CircularList<T>;
    temp = first_list;
    first_list = second_list;
    second_list = temp;
    delete temp;
}

template<typename T>
CircularList<T>* CircularList<T>::operator=(CircularList<T>* second_list)
{
    &this = second_list;
}

template<typename T>
inline CircularList<T>::~CircularList()
{
	clear();
}

template<typename T>
bool CircularList<T>::IsEmpty()
{
	return size == 0;
}

template<typename T>
size_t CircularList<T>::GetSize()
{
	return size;
}

template<typename T>
void CircularList<T>::PushBack(const T& data)
{
    Element<T>* newNode = new Element<T>(data);

    if (IsEmpty()) {
        head = newNode;
        head->next = head;
    }
    else {
        Element<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
    }

    size++;
}

template<typename T>
void CircularList<T>::PushFront(const T& data)
{
    Element<T>* newNode = new Element<T>(data);

    if (IsEmpty()) {
        head = newNode;
        head->next = head; 
    }
    else {
        Element<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        head = newNode;
        last->next = head;
    }

    size++;
}

template<typename T>
void CircularList<T>::PopFront()
{
    if (IsEmpty()) {
        throw out_of_range("List is empty");
    }

    if (head->next == head) { 
        delete head;
        head = nullptr;
    }
    else {
        Element<T>* last = head;
        while (last->next != head) {
            last = last->next;
        }

        Element<T>* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }

    size--;
}

template<typename T>
void CircularList<T>::PopBack()
{
    if (IsEmpty()) {
        throw out_of_range("List is empty");
    }

    if (head->next == head) {  
        delete head;
        head = nullptr;
    }
    else {
        Element<T>* prev = nullptr;
        Element<T>* current = head;

        while (current->next != head) {
            prev = current;
            current = current->next;
        }

        prev->next = head;
        delete current;
    }

    size--;
}

template<typename T>
void CircularList<T>::clear()
{
    while (!IsEmpty()) {
        PopFront();
    }
}

template<typename T>
void CircularList<T>::print()
{
    if (IsEmpty())
    {
        cout << "()";
        return;
    }
    stringstream ss;
    ss << "(";
    Element<T>* last = head;
    while (last.next != head)
    {
        ss << " " + last + " ";
        last = last.next;
    }
    ss << ")";
    cout << ss;
}

template<typename T>
void CircularList<T>::insert(size_t index, const T& data)
{
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }

    if (index == 0) {
        PushFront(data);
    }
    else if (index == size) {
        PushBack(data);
    }
    else {
        Element<T>* newNode = new Element<T>(data);
        Element<T>* prev = head;

        for (int i = 0; i < index - 1 ; i++) {
            prev = prev->next;
        }

        newNode->next = prev->next;
        prev->next = newNode;
        size++;
    }
}

template<typename T>
void CircularList<T>::remove(size_t index)
{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }

    if (index == 0) {
        PopFront();
    }
    else if (index == size - 1) {
        PopBack();
    }
    else {
        Element<T>* prev = head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }

        Element<T>* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        size--;
    }
}

template<typename T>
T& CircularList<T>::get(size_t index)
{
    if(index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }

    Element<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}
