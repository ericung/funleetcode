char * interpret(char * command){
    char* result = malloc(sizeof(char*)*100);
    int pointer = 0;

    for (int i = 0; i < strlen(command); i++) {
        if (command[i] == '(') {
            if (command[i+1] == ')') {
                result[pointer] = 'o';
                i++;
            }
            else {
                result[pointer] = 'a';
                pointer++;
                result[pointer] = 'l';
                i+= 3;
            }
        }
        else {
            result[pointer] = 'G';
        }
        pointer++;
    }

    result[pointer] = '\0';

    return result;
}