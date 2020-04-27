#include <stdio.h>

void entry(void) {
	char buffer[512];

	gets(buffer);
	return;
}

int main(void) {
	entry();
}
