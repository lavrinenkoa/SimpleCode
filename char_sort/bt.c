#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR (256)

void sort(char *data, int n)
{
	int table[MAX_CHAR] = { 0 };
	int i, j, p = 0;

	printf("in:  %s\n", data);

	for (i = 0; i < n; i++) {
//		printf("%c\t%d\n", data[i] , data[i]);
		table[data[i]]++;
	}

	for (i = 0; i < MAX_CHAR; i++) {
//		printf("%d\t%d\n", table[i], i);
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
