int scoreOfString(char* s) {
	int score = 0;

	// loop invariant is while k is in
	// between 0 and n - 1
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		score += abs(s[i] - s[i+1]);
		i++;
	}

	return score;
}

// loop invariant is score += abs(s[i] - s[i+1])
