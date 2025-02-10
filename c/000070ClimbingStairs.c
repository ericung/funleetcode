#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int climbStairs(int n) {
	// trivial cases
	if (n < 3)
	{
		return n;
	}

	// prev and prevprev pointer variables
	int prev = 1;
	int prevprev = 2;

	// loop invariant such that it starts at 3 and ends at n
	for (int i = 3; i <= n; i++)
	{
		// temp variable such that it is the aggregate of the pointer variables
		int temp = prev + prevprev;
		prev = prevprev;
		prevprev = temp;
	}

	// result variable
	return prevprev;
}

/* On the analysis of the fibonacci sequence
 * loop invariant such that i is in 3 to n
 * 	prev = t_{n-2}
 * 	prevprev = t_{n-1}
 * 	while looping, temp = prevprev + prev
 * 	or t_{n} = t_{n-1} + t_{n-2}
 *
 */

int main() {
	int result = climbStairs(5);
	printf("%d\n", result);

	return 0;
}
