#include <stdio.h>
#define MAXLINE 5    // maximum input line size

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */

int getArbitraryLines()
{
	int len;            //current line lenght
	int max;            //maximum length seen so far
	int acc;
	int isNonTerminated;
	int result;
	char line[MAXLINE]; //current input line
	char longest[MAXLINE];//longest line saved here

	max = 0; acc = 0; isNonTerminated = 0; result = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		isNonTerminated = nonTerminated(line);

		if (len < max) {
			if (acc > 0) {
				result = len + acc; //sum up total
				acc = 0;
			}
		}
		else if (len >= max) {
			if (len > max) { // can't be an acc then
				max = len;
				copy(longest, line);
				if (len + 1 == MAXLINE && nonTerminated(line)) //check non-terminated
					acc = acc + len;
			}
			if (len == max) { // don't copy
				if (acc > 0) { // we know we are at max length and there is more to read
					if (nonTerminated(line)) {
						acc = acc + len;
					}
					else {
						result = len + acc;
						acc = 0;
					}
				}
			}
		}
	}
		
	if (max > 0) {
		printf("%s\n", longest);
		printf("len including \\n: %i\n", len);
	}
		
	return 0;
}

int nonTerminated(char line[]) 
{
	char last = line[MAXLINE - 2];
	if (last != EOF && last != '\n')
		return 1;
	return 0;
}

/*  getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}