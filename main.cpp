#include "list.h"

int main(void)
{
	CircularList<int> list;
	list.PushBack(10);
	list.print();

	return 0;
}