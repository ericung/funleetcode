int minOperations(char** logs, int logsSize) {
    // The head variable which keeps track of the
    // depth of the traversal. 
    int head = 0;

    for (int i = 0; i < logsSize; i++)
    {
	// A temporary storage for strtemp variable.
        char strtemp[sizeof(char)*10];
	// The strcpy operation from logs[i] to the strtemp 
	// variable.
        strcpy(strtemp, logs[i]);

	// The initial case if the current folder operation is
	// to go back one directory. This has two periods instead
	// of one which is important for the else conditional below.
        if (strcmp(strtemp,"../") == 0)
        {
	    // If the current directory is already at root, the
	    // head variable can't go back anymore.
            if (head > 0)
            {
                head--;
            }
        }
	// Since the beginning of a folder command doesn't start
	// with a period, '.', compare it with the current directory
	// operation, "./", to see if it is NOT equal to it
	// reducing the number of conditionals down to one.
        else if (strcmp(strtemp,"./") == 1)
        {
            head++;
        }
    }

    return head;
}
