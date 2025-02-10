int countSeniors(char ** details, int detailsSize){
	int result = 0;

	// k is between 0 and detailsSize
	for (int i = 0; i < detailsSize; i++) {
		int age = 0;

		age = (details[i][11] - '0') * 10;
		age += (details[i][12] - '0');

		if (age > 60) {
			result++;
		}
	}

	return result;
}
