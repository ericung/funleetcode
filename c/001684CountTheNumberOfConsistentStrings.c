int countConsistentStrings(char * allowed, char ** words, int wordsSize){
	int *hash = malloc(sizeof(int*)*27);
	int count = 0;

	memset(hash, 0, sizeof(int*)*27);

	for (int i = 0; i < strlen(allowed); i++) {
		hash[allowed[i] - 'a']++;
	}

	for (int i = 0; i < wordsSize; i++) {
		// loop invariant while hash[words[i][j] - 'a'] is not equal 0
		// otherwise break
		for (int j = 0; j < strlen(words[i]); j++) {
			if (hash[words[i][j] - 'a'] == 0) {
				break;
			}

			if (j == strlen(words[i]) - 1) {
					count++;
			}
		}
	}

	return count;
}

// (S,w) = lambda * mu * w * gamma = lambda * mu is an element of a A^27x27 * w * gamma
// linear representations of morphisms, 
//
// what is 
// lambda - [1 0 0 0 ...] index j
// mu [ 1 0 0
//	0 1 0 
// 	0 0 1 ] is a 27x27 matrix that morphs the allowed word count to the hash
// w ababba is the elements in the words matrix being tested
// gamma index j
// 	[	1
// 		0
// 		0
// 		... ]
// mu = {x - 'a'}
