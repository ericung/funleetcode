int finalValueAfterOperations(char** operations, int operationsSize) {
	int result = 0;

	// loop invariant is k is between 0 and operationsSize
	for (int i = 0; i < operationsSize; i++) {
		result += findOperation(operations[i]);
	}

	return result;
}

int findOperation(char* operation) {
	// substring operation
	if (strstr(operation, "-")) {
		return -1;
	}
	else {
		return 1;
	}
}
