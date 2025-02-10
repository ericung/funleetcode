char* truncateSentence(char* s, int k) {
    int i = 0;
    int pointer = 0;
    char* result = malloc(sizeof(char)*(strlen(s) + 1));

    while ((i < k)&&(pointer < strlen(s))) {
        if (s[pointer++] == ' ') {
            i++;
        }
    }

    strncpy(result, s, pointer);
    
    if (pointer < strlen(s)) {
        result[pointer-1] = '\0';    
    }
    else {
        result[pointer] = '\0';
    }

    return result;
}