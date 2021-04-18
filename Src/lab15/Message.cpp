#include "Message.h"

void fread(struct Message* message, int size) {
	std::ifstream in(filename); // окрываем файл для чтения
	if (in.is_open()) {
		string tmp;

		for (int i = 0; i < size; i++) {
			getline(in, message[i].topic);
			getline(in, message[i].text);
			getline(in, message[i].sender.name);
			getline(in, message[i].sender.mail);
			getline(in, message[i].recipient.name);
			getline(in, message[i].recipient.mail);
			getline(in, tmp);
			message[i].encoding = atoi(tmp.c_str());
			getline(in, tmp); 
			message[i].draft = atoi(tmp.c_str());
		}in.close();
	}
}
void fwrite(struct Message* messages, int size) {
	std::ofstream out(filename);
	if (out.is_open()) {
		for (int i = 0; i < size; i++) {
			out << messages[i].topic << endl << messages[i].text << endl << messages[i].sender.name << endl << messages[i].sender.mail <<endl
				<< messages[i].recipient.name <<endl<< messages[i].recipient.mail <<endl<< messages[i].encoding << endl << messages[i].draft << endl;
		}
	}out.close();
}
void write(struct Message* messages, int size) {
	for (int i = 0; i < size; i++) {
		cout << "From:" << messages[i].sender.name << " " << messages[i].sender.mail;
		cout << "\nTo:" << messages[i].recipient.name << " " << messages[i].sender.mail;
		cout << "\nTopic:" << messages[i].topic;
		cout << "\nText:\n" << messages[i].text;
		cout << "\nEncoding:";

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
	Message message;
	stringstream ss;
	ss << "exampleMail" << index << "@gmail.com";

	message.topic = "exampleTopic";
	message.text = "exampleText";
	message.sender.name = "exampleSender";
	message.sender.mail = ss.str();

	ss.str("");
	ss << "exampleRecipient" << index << "@gmail.com";
	message.recipient.mail = ss.str();
	message.recipient.name = "exampleRecipient";

	message.encoding = rand() % 3;
	message.draft = rand() % 2;

	return message;
}

void fwriteB(struct Message* messages, int size) {
	FILE* file;
	file = fopen(filenameB, "wb");
	for (int i = 0; i < size; i++)
		fwrite(&messages, sizeof(Message), 1, file);

	fclose(file);
}
Message freadB()
{
	Message messages = create(0);
	FILE* file;
	file = fopen(filenameB, "rb");
	fread(&messages, sizeof(Message), 1, file);

	fclose(file);
	return messages;
}