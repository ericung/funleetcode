bool isIsomorphic(char* s, char* t) {
	int *hashs = malloc(sizeof(int)*200);
	int *hasht = malloc(sizeof(int)*200);
	int iter = 0;

	// set hashs and hasht to -1
	for (int i = 0; i < 200; i++)
	{
		hashs[i] = -1;
		hasht[i] = -1;
	}

	// loop invariant: while the pointer for s on iter
	// isn't null, continue looping
	while (s[iter] != NULL)
	{
		// If the values for hashs and hasht aren't set yet
		// create a bijective map between them
		if (hashs[s[iter]] == -1 && hasht[t[iter]] == -1)
		{
			hashs[s[iter]] = t[iter];
			hasht[t[iter]] = s[iter];
		}
		else
		{
			// if the loop invariant meets the condition that
			// hashs or hasht isn't set or hashs isn't equal to
			// t on iter or hasht isn't equal to s on iter
			// break the loop invariant
			if (hashs[s[iter]] == -1 || hasht[t[iter]] == -1 ||
			hashs[s[iter]] != t[iter] || hasht[t[iter]] != s[iter])
			{
				return false;
			}
		}
		iter++;
	}

	// since hashs and hasht form an isomorphic map between t and s, respectively
	// return true
	return true;
}

// loop invariant: while the pointer s on iter isn't null, while the condition
// hashs on s on iter and hasht on t on iter is both -1 and
// hashs isn't -1 and hasht isn't -1 and hashs on s on iter is equal to t on iter
// and hasht on t on iter is equal to t on iter
// update the iter variable
