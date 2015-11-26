/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<malloc.h>

int power(int base, int exp)
{
	if (exp != 1)
		return (base*power(base, exp - 1));
	else
		return 1;
}

char rev(char *s, int beg, int end)
{
	char p;
	if (beg >= end)
	{
		return 0;
	}
	else
	{
		p = *(s + beg);
		*(s + beg) = *(s + end);
		*(s + end) = p;
		return rev(s, ++beg, --end);
	}
}

void number_to_str(float number, char *str, int afterdecimal){
	int ipart, i = 0,c=0;
	float fpart;
	ipart = (int)number;
	if (ipart < 0){
		ipart *= -1;
		fpart = (-1 * number) - (float)ipart;
	}
	else
		fpart = number - (float)ipart;
	while (ipart){
		str[i++] = (ipart % 10) + '0';
		ipart /= 10;
	}
	if (number < 0)
		str[i++] = '-';
	rev(str, 0, i - 1);
	if (fpart != 0){
		str[i++] = '.';
		ipart = fpart*power(10, afterdecimal + 1);
		char *t = (char *)malloc(sizeof(char));
		while (ipart){
			t[c++] = (ipart % 10) + '0';
			ipart /= 10;
		}
		c--;
		while (c >= 0){
			str[i++] = t[c];
			c--;
		}
		str[i] = '\0';
	}
	else
		str[i] = '\0';
}
