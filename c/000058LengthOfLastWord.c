int lengthOfLastWord(char* s) {
    int last = 0; // length of last word
    int c = 0; // current length of the word between spaces
    int n = strlen(s); // length of the input string s

    for (int i = 0; i < n; i++)
    {
        // isspace function from ctype.h libraray for s[i]
        if (!isspace(s[i]))
        {   
            c++;
            last = c;
            
        }
        else
        {
            // reset the current length of the word between spaces
            c = 0;
        }
    }

    // return length of the last variable
    return last;
}
