#include "Message.h"

int main() {
	int size = 3;
	Message *messages = new Message[3];
	fread(messages, 3);
	
	write(messages,size);
	sort(messages,size);
	fwrite(messages,size);

	return 0;
}