char* trim(char* s);

bool isPalindrome(char* s) {
	char* t = trim(s);
	int n = strlen(t);
	int half = n/2;
	int i = 0;

	// loop invariant is while k is between 0 and n/2
	// and the condition t[k] == t[n-k-1]
	while (i < half) {
		if (t[i] != t[n-i-1]) {
			return false;
		}

		i++;

	}

	return true;
}

char* trim(char* s) {
	int n = strlen(s) + 1;
	char* t = malloc(sizeof(char*)*n);
	int p = 0;

	// loop invariant is while k is between 0 and n - 1
	for (int i = 0; i < n; i++) {
		if (!isspace(s[i])&&(isalnum(s[i]))) {
			t[p++] = tolower(s[i]);
		}
	}

	t[p] = '\0';

	return t;
}
