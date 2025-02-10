bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0, j = 0, k = 0, l = 0;
    int len1 = 0, len2 = 0;
    int m = strlen(word1[0]), n = strlen(word2[0]);

    while ((i < word1Size)&&(k < word2Size)) {
        if (word1[i][j] != word2[k][l]) {
            return false;
        }

        j++;
        if (j >= m) {
            j = 0;
            i++;
            if (i < word1Size) {
                m = strlen(word1[i]);
            }
        }
        len1++;

        l++;
        if (l >= n) {
            l = 0;
            k++;
            if (k < word2Size) {
                n = strlen(word2[k]);
            }
        }
        len2++;
    }

    while (i < word1Size) {
        j++;
        if (j >= m) {
            j = 0;
            i++;
            if (i < word1Size) {
                m = strlen(word1[i]);
            }
        }
        len1++;
    }

    while (k < word2Size) {
        l++;
        if (l >= n) {
            l = 0;
            k++;
            if (k < word2Size) {
                n = strlen(word2[k]);
            }
        }
        len2++;
    }

    return len1 == len2;
}