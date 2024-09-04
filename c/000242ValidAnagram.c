bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    int *count = malloc(sizeof(int*)*26);
    int n = strlen(s);

    memset(count, 0, sizeof(int*)*26);

    for (int i = 0; i < n; i++) {
        count[s[i]- 'a']++;
    }

    for (int j = 0; j < n; j++) {
        count[t[j] - 'a']--;

        if (count[t[j]-'a'] < 0) {
            return false;
        }
    }

    for (int k = 0; k < 26; k++) {
        if (count[k] != 0) {
            return false;
        }
    }

    return true;
}