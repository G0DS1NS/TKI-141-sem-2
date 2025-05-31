#include "list.h"

int main(void)
{
	CircularList<int> list;
	list.PushBack(10);
	list.PushFront(5);
	list.insert(3, 3);
	list.print();

	return 0;
}
