all: longestcommonprefix twosum

longestcommonprefix: 000014LongestCommonPrefix.o
	cc -o bin/longestcommonprefix 000014LongestCommonPrefix.o

twosum:	000001TwoSum.o 
	cc -o bin/twosum 000001TwoSum.o

000001TwoSum.o: 000001TwoSum.c
	cc -c 000001TwoSum.c

000014LongestCommonPrefix.o: 000014LongestCommonPrefix.c
	cc -c 000014LongestCommonPrefix.c

clean:
	rm bin/twosum 000001TwoSum.o bin/longestcommonprefix 000014LongestCommonPrefix.o
