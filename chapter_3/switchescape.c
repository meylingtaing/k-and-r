/* Write function escape(s,t) that converts certain chars to visible escape
   sequences. Also write function for the other way */

// TODO: Add the other escape sequences...

#include <stdio.h>

#define OTHER 0
#define SLASH 1
#define BUFF 1000

void escape(char* s, char* t);
void unescape(char* s, char* t);

// This is a terrible driver because I don't even know how to insert a tab
// into one of the command line arguments...
int main(int argc, char** argv) {
	char str1[BUFF];
	char str2[BUFF];

	if (argc < 2) {
		printf("Usage: %s string_to_escape\n", argv[0]);
		return -1;
	}

	escape(str1, argv[1]);
	unescape(str2, str1);

	printf("Escaped:\n%s\n", str1);
	printf("Unescaped:\n%s\n", str2);

	return 0;
}

// So this assumes that s has enough spaces
// Only doing common ones
void escape(char* s, char* t) {
	int i = 0;
	int j = 0;

	while (t[i] != 0) {
		switch (t[i]) {
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\\':
				s[j++] = '\\';
				s[j++] = '\\';
				break;
			case '\'':
				s[j++] = '\\';
				s[j++] = '\'';
				break;
			case '\"':
				s[j++] = '\\';
				s[j++] = '\"';
				break;
			default:
				s[j++] = t[i];
				break;
		}
		i++;
	}
}

void unescape(char* s, char* t) {
	int state = OTHER;
	int i, j;
	i = j = 0;

	while (t[i] != 0) {
		if (state == OTHER) {
			if (t[i] == '\\')
				state = SLASH;
			else
				s[j++] = t[i];
		}
		else {
			switch (t[i]) {
				case 't':
					s[j++] = '\t';
					break;
				case 'n':
					s[j++] = '\n';
					break;
				case '\\':
					s[j++] = '\\';
					break;
				case '\'':
					s[j++] = '\'';
					break;
				case '\"':
					s[j++] = '\"';
					break;
				default:
					// Just going to print out the escape sequence if we
					// don't recognize it
					s[j++] = '\\';
					s[j++] = t[i];
					break;
			}
			state = OTHER;
		}
		i++;
	}

	s[j++] = 0;
}