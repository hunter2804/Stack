#include "stack.h"

Stack buffer(4);
const uint8_t data[5]={"abc0"};

int main(void){

	buffer.write(data,4);

	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());
	printf("%c\r\n",buffer.read());

	return 0;
}
