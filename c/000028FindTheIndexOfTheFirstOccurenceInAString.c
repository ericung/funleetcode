#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int strStr(char* haystack, char* needle) {
	char* position = strstr(haystack, needle);

	return position != NULL ? position - haystack : -1;
}

int main() {
	char* needle1 = "sadbutsad";
	char* hay1 = "sad";
	int result = strStr(needle1, hay1);
	printf("%d\n", result);

	return 0;
}
