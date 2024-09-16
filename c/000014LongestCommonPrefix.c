#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* longestCommonPrefix(char** strs, int strsSize) {
	// initialization of 300, minIndex, minLength, and prefix
	int max = 300;
	int minIndex = 0;
	char* prefix; // don't allocate anything to prefix yet

	// loop invariant is while 1 and strsSize
	for (int i = 1; i < strsSize; i++) {
		int l = strlen(strs[i]);
		int p = max;
		int j = 0;

		// loop invariant is 1 to k is less than p and l
		// and the condition is that
		// strs[i][k] == strs[minimumIndex][k]
		while ((j < p)&&(j < l)) {	
			if (strs[i][j] != strs[minIndex][j]) {
				break;
			}

			j++;
		}

		// j is less than max
		// implies that max is now j
		// and minIndex is i
		if ((j) < max) {
			max = j;
			minIndex = i;
		}
	}

	// given max and minIndex from the algorithm above
	// get the longest common prefix
	prefix = malloc(sizeof(char*)*(max+1));
	strncpy(prefix, strs[minIndex], max);
	prefix[max] = '\0';

	return prefix;
}

int main() {
	char* strs[3] = {"flower","flow","flight"};
	char* result = longestCommonPrefix(strs, 3);
	printf("%s\n", result);

	return 0;
}
