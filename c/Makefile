all: longestcommonprefix twosum validparentheses removeelement findindexfirstoccurence climbingstairs defusethebomb

defusethebomb: 001652DefuseTheBomb.o
	cc -o bin/defusethebomb 001652DefuseTheBomb.c

climbingstairs: 000070ClimbingStairs.o
	cc -o bin/climbingstairs 000070ClimbingStairs.c

findindexfirstoccurence: 000028FindTheIndexOfTheFirstOccurenceInAString.o
	cc -o bin/findindexfirstoccurence 000028FindTheIndexOfTheFirstOccurenceInAString.c

removeelement: 000027RemoveElement.o
	cc -o bin/removeelement 000027RemoveElement.o

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

000027RemoveElement.o: 000027RemoveElement.c
	cc -c 000027RemoveElement.c

000028FindTheIndexOfTheFirstOccurenceInAString.o: 000028FindTheIndexOfTheFirstOccurenceInAString.c
	cc -c 000028FindTheIndexOfTheFirstOccurenceInAString.c

000070ClimbingStairs.o: 000070ClimbingStairs.c
	cc -c 000070ClimbingStairs.c

001652DefuseTheBomb.o: 001652DefuseTheBomb.c
	cc -c 001652DefuseTheBomb.c

clean:
	rm bin/twosum 000001TwoSum.o \
		bin/longestcommonprefix 000014LongestCommonPrefix.o \
		bin/validparentheses 000020ValidParentheses.o \
		bin/removeelement 000027RemoveElement.o	\
		bin/findindexfirstoccurence 000028FindTheIndexOfTheFirstOccurenceInAString.o \
		bin/climbingstairs 000070ClimbingStairs.o \
		bin/defusethebomb 001652DefuseTheBomb.o
