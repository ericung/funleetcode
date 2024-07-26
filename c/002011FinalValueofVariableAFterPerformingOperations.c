int finalValueAfterOperations(char** operations, int operationsSize) {
	int result = 0;

	// loop invariant is k is between 0 and operationsSize
	for (int i = 0; i < operationsSize; i++) {
		result += findOperation(operations[i]);
	}

	return result;
}

int findOperation(char* operation) {
	// substring operation, 
	// if the current operation contains a - symbol
	// then return -1 because it is subtracting
	// otherwise it is an addition operation by ruling out possibilities
	// thus increase by 1
	if (strstr(operation, "-")) {
		return -1;
	}
	else {
		return 1;
	}
}
