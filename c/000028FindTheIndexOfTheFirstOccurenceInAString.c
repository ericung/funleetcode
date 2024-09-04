int strStr(char* haystack, char* needle) {
    char* position = strstr(haystack, needle);

    return position != NULL ? position - haystack : -1;
}