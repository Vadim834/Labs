#include "Message.h"

void fread(struct Message* message, int size) {
	FILE* file;
	file = fopen(fileName, "r");

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
void fwrite(struct Message message) {
	FILE* file;
	file = fopen(fileName, "a");


	fprintf(file, message.topic);
	fprintf(file, "\n");
	fprintf(file, message.text);
	fprintf(file, "\n");
	fprintf(file, message.sender.name);
	fprintf(file, "\n");
	fprintf(file, message.sender.mail);
	fprintf(file, "\n");
	fprintf(file, message.recipient.name);
	fprintf(file, "\n");
	fprintf(file, message.recipient.mail);
	fprintf(file, "\n");
	fprintf(file, "%d\n", message.encoding);
	fprintf(file, "%d\n", message.draft);


	fclose(file);
}
void print(struct Message message) {

	printf("From:%s (%s)\n", message.sender.name, message.sender.mail);
	printf("To:%s (%s)\n", message.recipient.name, message.recipient.mail);
	printf("Topic: %s\n", message.topic);
	printf("Text:\n%s\n", message.text);
	printf("Encoding:");

	switch (message.encoding)
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

	printf("%s\n\n", message.draft ? "[Draft]" : "");

}
void sort(struct Message* messages, int size) {
	struct Message tmp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (messages[j].encoding > messages[j + 1].encoding) {
				tmp = messages[j];
				messages[j] = messages[j + 1];
				messages[j + 1] = tmp;
			}
		}
	}
}
Message create(int index) {
	Message employee;
	strcpy(employee.topic, "exampleTopic");
	strcpy(employee.text, "exampleText");
	strcpy(employee.sender.name, "exampleSender");
	strcpy(employee.sender.mail, "exampleMail");
	strcpy(employee.recipient.name, "exampleRecipient");
	strcpy(employee.recipient.mail, "exampleMail");

	char digit[3];
	sprintf(digit, "%d", index);
	strcat(employee.sender.mail, digit);
	strcat(employee.recipient.mail, digit);
	strcat(employee.sender.mail, "@gmail.com");
	strcat(employee.recipient.mail, "@gmail.com");

	employee.encoding = rand() % 3;
	employee.draft = rand() % 2;

	return employee;
}
Message create(char* topic, char* text, char* recip_mail, char* recip_name,
	char* sender_mail, char* sender_name, int encoding, bool insurance) {
	Message message;
	strcpy(message.topic, topic);
	strcpy(message.text, text);
	strcpy(message.recipient.mail, recip_mail);
	strcpy(message.recipient.name, recip_name);
	strcpy(message.sender.mail, sender_mail);
	strcpy(message.sender.name, sender_name);

	message.encoding = encoding;
	message.draft = insurance;

	return message;
}