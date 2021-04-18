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
		printf("Sort was succesful.\n\n");
	}
	else
	{
		printf("Sort was not succesful.\n\n");
	}
}

void testAdd() {

	printf("Here the add test works.\n");

	int size = 2;
	Message* mass = (Message*)malloc(size * sizeof(Message));
	for (int i = 0; i < size; i++)
	{
		mass[i] = create(i);
	}
	size = addMessage(mass, size);

	if (mass[size - 1].encoding > 0 && size == 3)
	{
		printf("Add was succesful.\n\n");
	}
	else
	{
		printf("Add was not succesful.\n\n");
	}

}

void testRemove() {

	printf("Here the remove test works.\n");

	int size = 3;
	Message* mass = (Message*)malloc(size * sizeof(Message));

	for (int i = 0; i < size; i++)
	{
		mass[i] = create(i);
	}

	int tmpWorkExp0 = mass[0].encoding;
	int tmpWorkExp2 = mass[2].encoding;

	size = removeMessage(mass, size, 1);

	if (tmpWorkExp0 == mass[0].encoding && tmpWorkExp2 == mass[1].encoding && size == 2)
	{
		printf("Remove was succesful.\n\n");
	}
	else
	{
		printf("Remove was not succesful.\n\n");
	}

}