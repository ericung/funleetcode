int minPartitions(char* n) {
	int max = 0;

	for (int i = 0; i < strlen(n); i++) {
		max = max < n[i] ? n[i] : max;
	}

	return max - '0';
}
