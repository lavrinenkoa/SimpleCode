#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort(char *data, int n)
{
	char table[sizeof(char)] = { 0 };
	int i, j, p = 0;

	printf("in:  %s\n", data);

	for (i = 0; i < n; i++) {
//		printf("%c\t%d\n", data[i] , data[i]);
		table[data[i]]++;
	}

	for (i = 0; i < sizeof(char); i++) {
//		printf("%d\t%d\n", m[i], i);
		for (j = 0; j < table[i]; j++) {
			data[p++] = i;
		}
	}

	printf("out: %s\n", data);
}

int main(int argc, char *argv[]) {
	char data[] = "eeaaaaabbbaccccccdddddddaaaaaddddbbbbaaaa";

	sort(data, strlen(data));

	exit(EXIT_SUCCESS);
}
