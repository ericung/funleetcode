all: longestcommonprefix twosum validparentheses

validparentheses: 000020ValidParentheses.o
	cc -o bin/validparentheses 000020ValidParentheses.o

longestcommonprefix: 000014LongestCommonPrefix.o
	cc -o bin/longestcommonprefix 000014LongestCommonPrefix.o

twosum:	000001TwoSum.o 
	cc -o bin/twosum 000001TwoSum.o

000001TwoSum.o: 000001TwoSum.c
	cc -c 000001TwoSum.c

000014LongestCommonPrefix.o: 000014LongestCommonPrefix.c
	cc -c 000014LongestCommonPrefix.c

000020ValidParentheses.o: 000020ValidParentheses.c
	cc -c 000020ValidParentheses.c

clean:
	rm bin/twosum 000001TwoSum.o \
		bin/longestcommonprefix 000014LongestCommonPrefix.o \
		bin/validparentheses 000020ValidParentheses.o
