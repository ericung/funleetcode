char* reversePrefix(char* word, char ch) {
    char* result = malloc(sizeof(char*)*strlen(word) + 1);
    int index = 0;
    
    memcpy(result, word, strlen(word));
    result[strlen(word)] = '\0';
    index = strchr(word, ch) - word;

    if (index != NULL) {
        for (int i = 0; i <= index; i++) {
            result[i] = word[index - i];
        }
    }

    return result;
}