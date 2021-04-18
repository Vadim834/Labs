
#include "Test.h"

int main() {
	testRemove();
	testAdd();
	

	testSort();
	int size = 3;
	struct Message* messages;
	messages = (struct Message*)malloc(size * sizeof(struct Message));
	fread(messages,size);
	write(messages,size);
	sort(messages,size);
	fwrite(messages,size);
	
	
	return 0;
}