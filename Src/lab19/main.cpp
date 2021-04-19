#include "List.h"
void menu(node_t* head);

int main() {


	node_t* head = NULL;
	head = (node_t*)malloc(sizeof(node_t));
	head->message = create(0);
	head->next = NULL;
	menu(head);
	head = free_list(head);

	return 0;
}

void menu(node_t* head) {
	printf("\n\n        A list of Messages.Select an action from the following.\n\n");
	printf("1.Write list to screen.\n");
	printf("2.Generate and add message.\n");
	printf("3.Remove message by index.\n");
	printf("4.Search draft messages.\n");
	printf("5.Sort by encoding.\n");
	printf("6.Reading messages from a file.\n");
	printf("7.Writing messages in file.\n");
	printf("0.Exit.\n\n");
	printf("Your choice: ");

	int choice = -1;
	int size_list;


	while (choice < 0 || choice>7) {
		scanf("%d", &choice);
		if (choice < 0 || choice>7)
			printf("You entered an invalid value, please retry\n\nYour choice: ");
	}
	printf("\n\n");


	switch (choice) {
	case 0: return;
	case 1: print_list(head);
		break;
	case 2: add(head, create(size(head)));
		break;
	case 3:
		size_list = size(head);
		choice = -1;
		printf("Choose index(0-%d):", size_list);
		while (choice < 0 || choice > size_list) {
			scanf("%d", &choice);
			if (choice < 0 || choice > size_list)
				printf("You entered an index that is larger than the size of the list, please retry\n\nYour choice: ");
		}
		remove_by_index(&head, choice);
		break;
	case 4:	 search_draft(head);
		break;
	case 5: head = sort_by_encoding(head);
		break;
	case 6: head=read_from_file();
		break;
	case 7: write_to_file(head);
		break;
	}
	printf("Successful.");
	menu(head);
}