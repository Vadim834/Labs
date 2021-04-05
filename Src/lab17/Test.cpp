#include "Test.h"

void testSort() {
	printf("Here the sort test works.\n");
	int size = 3;
	struct Message* Messages = (struct Message*)malloc(size * sizeof(struct Message));

	for (int i = 0; i < size; i++)
	{
		Messages[i] = create(i);
	}
	sort(Messages, size);
	if (Messages[0].encoding <= Messages[1].encoding &&
		Messages[1].encoding <= Messages[2].encoding)
	{
		printf("Sort was succesful.\n");
	}
	else
	{
		printf("Sort was not succesful.\n");
	}
}