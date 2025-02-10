bool lemonadeChange(int* bills, int billsSize) {
    int *till = malloc(sizeof(int)*21);

    memset(till, 0, sizeof(int)*21);

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            till[bills[i]]++;
        }
        else if (bills[i] == 10) {
            if (till[5] > 0) {
                till[5]--;
                till[10]++;
            }
            else {
                return false;
            }
        }
        else if (bills[i] == 20) {
            if ((till[5] > 0)&&(till[10] > 0)) {
                till[5]--;
                till[10]--;
                till[20]++;
            }
            else if (till[5] >= 3) {
                till[5] -= 3;
            }
            else {
                return false;
            }
        }
    }

    return true;
}