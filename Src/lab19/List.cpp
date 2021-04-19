#include "List.h"

void print_list(node_t* head) {

	node_t* current = head;

	while (current != NULL) {
		print(current->message);
		current = current->next;
	}
}

void add(node_t* head, Message message) {

	node_t* current = head;

	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (node_t*)malloc(sizeof(node_t));
	current->next->message = message;
	current->next->next = NULL;
}

void add_to_beginning(node_t** head, Message employer) {

	node_t* new_node;
	new_node = (node_t*)malloc(sizeof(node_t));

	new_node->message = employer;
	new_node->next = *head;
	*head = new_node;
}

void remove_first(node_t** head) {

	node_t* next_node = NULL;

	if (*head == NULL) {
		return;
	}

	next_node = (*head)->next;
	free(*head);
	*head = next_node;

	return;
}

void remove_last(node_t* head) {

	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		free(head);
		return;
	}

	/* get to the last node in the list */
	node_t* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the last item of the list, so let's remove current->next */
	free(current->next);
	current->next = NULL;
	return;
}

void remove_by_index(node_t** head, int index) {

	int i = 0;

	node_t* current = *head;
	node_t* temp_node = NULL;

	if (index == 0) {
		remove_first(head);
		return;
	}

	for (int i = 0; i < index - 1; i++) {
		if (current->next == NULL) {
			return;
		}
		current = current->next;
	}

	temp_node = current->next;
	current->next = temp_node->next;
	free(temp_node);

	return;
}

node_t* read_from_file() {
	FILE* f = fopen(filename, "r");

	struct Message message;
	node_t* head = NULL;

	head = (node_t*)malloc(sizeof(node_t));
	head->message = create(0);
	head->next = NULL;

	for(int i=0;i<3;i++){	 //to do(how make while??)
		fgets(message.topic,64,f);
		fgets(message.text, 256, f);
		fscanf(f, "%s%s%s%s%d%d\n",  message.sender.name, message.sender.mail,
			message.recipient.name, message.recipient.mail, &message.encoding, &message.draft);
		print(message);
		add(head, message);
	}
	remove_first(&head);
	fclose(f);
	return head;
}

void write_to_file(node_t* head) {

	node_t* current = head;
	FILE* file;
	file = fopen(filename, "w");
	fprintf(file, "");
	fclose(file);
	while (current != NULL) {
		fwrite(current->message);		
		current = current->next;
	}
}

int size(node_t* head) {
	node_t* current = head;
	int count = 0;

	while (current->next != NULL) {
		current = current->next;
		count++;
	}

	return count;
}

void search_draft(node_t* head) {
	node_t* current = head;

	while (current->next != NULL) {
		if (current->message.draft == true)
			print(current->message);
		current = current->next;
	}
}

node_t* sort_by_encoding(node_t* head) {
	node_t* tmp = NULL;

	while (head != NULL) {
		node_t* node = head;
		head = head->next;

		if (tmp == NULL || node->message.encoding < tmp->message.encoding)
		{
			node->next = tmp;
			tmp = node;
		}
		else
		{
			node_t* current = tmp;
			while (current->next != NULL && !(node->message.encoding < current->next->message.encoding))
			{
				current = current->next;
			}

			node->next = current->next;
			current->next = node;
		}
	}
	return tmp;
}

node_t* free_list(node_t* dlist)
{
	node_t* current = dlist->next;

	while (current != NULL)
	{
		node_t* tmp = current;
		current = current->next;

		free(tmp);
	}

	dlist->next = nullptr;

	return dlist;
}