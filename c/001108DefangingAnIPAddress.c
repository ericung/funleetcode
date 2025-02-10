char * defangIPaddr(char * address){
	// initialization of variables
	int n = strlen(address);
	char* result = (char*)malloc(sizeof(char*)*(strlen(address)+8));
	int p = 0;

	// loop invariant is while k is between 0 and n
	for (int i = 0; i < n; i++) {
			if (address[i] == '.') {
			result[p++] = '[';
			result[p++] = '.';
			result[p++] = ']';
		}
		else {
			result[p++] = address[i];
		}
	}

	result[p] = '\0';
	return result;
}
