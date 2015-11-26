/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	if (str=='\0'||K<0)
		return '\0';
	int i=0;
	while (str[i++] != '\0');
	i = i - K - 2;
	if (i >= 0)
		return str[i];
	return '\0';
}