#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* replace(char *baseString, char *from, char *to) {
	char *endString = malloc(sizeof(char) * 1024);
	int endIndex = 0;
	int matched = 0;
	for(int index = 0; index < strlen(baseString); index++) {
		if (baseString[index] == from[0]) {
			matched = 1;
			for (int fromIndex = 0; fromIndex < strlen(from); fromIndex++) {
				if (baseString[index + fromIndex] != from[fromIndex]) {
					matched = 0;
				}
			}
			if (matched) {
				for (int toIndex = 0; toIndex < strlen(to); toIndex++) {
					endString[endIndex] = to[toIndex];
					endIndex++;
				}
				index += strlen(from) - 1;
			} else {
				endString[endIndex] = baseString[index];
				endIndex++;
			}
		} else {
			endString[endIndex] = baseString[index];
			endIndex++;
		}
	}
	endString[endIndex] = 0;
	 free(baseString);
	// baseString = endString;
	return endString;
}

int getLine(char *prompt, char *buffer, int size) {
	printf("%s", prompt);
	fflush(stdin);
	fgets(buffer, size, stdin);
	buffer[strlen(buffer)-1] = 0;
}

int main() {
	int size = 1024;
	char *base = malloc(size * sizeof(char)),
			 *from = malloc(size * sizeof(char)),
			 *to = malloc(size * sizeof(char));
	getLine("base> ", base, size);
	for (int i = 0; i < strlen(base); i++) {
		if (base[i] == '@') {
			base[i] = 0;
		}
	}
	int goodInput = 1;
	while(goodInput) {
		getLine("from> ", from, size);
		getLine("to> ", to, size);
		if (from[0] != '@' && to[0] != '@') {
			base = replace(base, from, to);
		} else {
			goodInput = 0;
		}
	}
    printf("%s\n\n", base);
	 free(base);
	 free(from);
	 free(to);

}
