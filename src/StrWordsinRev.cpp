/*
OVERVIEW: Given a string, reverse all the w not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
#include<malloc.h>

void reverse(char *x, int begin, int end)
{
	if (begin >= end)
		return;
	char c = *(x + begin);
	*(x + begin) = *(x + end);
	*(x + end) = c;
	reverse(x, ++begin, --end);
}

void str_words_in_rev(char *input, int len){
	strrev(input);
	int s = 0, e = 0, i = 1;
	while (input[i] != '\0'){
		if (input[i] == ' '&&s != -1){
			reverse(input, s, i - 1);
			s = -1;
		}
		else if (input[i - 1] == ' ')
			s = i;
		i++;
	}
	reverse(input, s, i - 1);
}
