#include "Message.h"

void fread(struct Message* message, int size) {
	FILE* file;
	file = fopen(filename, "r");

	for (int i = 0; i < size; i++) {
		fgets(message[i].topic, 64, file);
		fgets(message[i].text, 256, file);
		fgets(message[i].sender.name, SIZE, file);
		fgets(message[i].sender.mail, SIZE, file);
		fgets(message[i].recipient.name, SIZE, file);
		fgets(message[i].recipient.mail, SIZE, file);
		fscanf(file, "%d\n", &message[i].encoding);
		fscanf(file, "%d\n", &message[i].draft);
	}
	fclose(file);
}
void fwrite(struct Message* messages, int size) {
	FILE* file;
	file = fopen(filename, "w");

	for (int i = 0; i < size; i++) {
		fprintf(file, messages[i].topic);
		fprintf(file, messages[i].text);
		fprintf(file, messages[i].sender.name);
		fprintf(file, messages[i].sender.mail);
		fprintf(file, messages[i].recipient.name);
		fprintf(file, messages[i].recipient.mail);
		fprintf(file, "%d\n", messages[i].encoding);
		fprintf(file, "%d\n", messages[i].draft);
	}

	fclose(file);
}
void write(struct Message* messages, int size) {
	for (int i = 0; i < size; i++) {
		printf("From:%s %s", messages[i].sender.name, messages[i].sender.mail);
		printf("To:%s %s", messages[i].recipient.name, messages[i].sender.mail);
		printf("Topic:%s", messages[i].topic);
		printf("Text:\n%s", messages[i].text);
		printf("Encoding:");

		switch (messages[i].encoding)
		{
		case 0:
			printf("UTF-8\n");
			break;
		case 1:
			printf("UTF-16\n");
			break;
		case 2:
			printf("CP-1251\n");
			break;
		default:
			break;
		}

		printf("%s\n\n", messages[i].draft ? "[Draft]" : "");
	}
}
void sort(struct Message* employee, int size) {
	struct Message tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (employee[j].encoding > employee[j + 1].encoding) {
				tmp = employee[j];
				employee[j] = employee[j + 1];
				employee[j + 1] = tmp;
			}
		}
	}
}
Message create(int index) {
	Message employee;
	strcpy(employee.topic, "exampleTopic\n");
	strcpy(employee.text, "exampleText\n");
	strcpy(employee.sender.name, "exampleSender\n");
	strcpy(employee.sender.mail, "exampleMail");
	strcpy(employee.recipient.name, "exampleRecipient\n");
	strcpy(employee.recipient.mail, "exampleMail");

	char digit[3];
	sprintf(digit, "%d", index);
	strcat(employee.sender.mail, digit);
	strcat(employee.recipient.mail, digit);
	strcat(employee.sender.mail, "@gmail.com\n");
	strcat(employee.recipient.mail, "@gmail.com\n");

	employee.encoding = rand() % 3;
	employee.draft = rand() % 2;

	return employee;
}

void fwriteB(struct Message* employee, int size) {
	FILE* file;
	file = fopen(filenameB, "wb");
	for (int i = 0; i < size; i++)
		fwrite(&employee, sizeof(Message), 1, file);

	fclose(file);
}
Message freadB()
{
	struct Message message;
	FILE* file;
	file = fopen(filenameB, "rb");
	fread(&message, sizeof(Message), 1, file);

	fclose(file);
	return message;
}
int addMessage(struct Message* messages, int size) {

	size++;
	Message* mass = (Message*)malloc(size * sizeof(Message));
	memcpy(mass, messages, sizeof(Message) * (size - 1));
	mass[size - 1] = create(size-1);
	memcpy(messages, mass, sizeof(Message) * size);

	return size;
}
int removeMessage(struct Message* messages, int size, int index) {

	size--;
	Message* mass = (Message*)malloc(size * sizeof(Message));
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			mass[i] = messages[i];
		}
		else
		{
			mass[i] = messages[i + 1];
		}
	}
	memcpy(messages, mass, sizeof(Message) * size);

	return size;
}