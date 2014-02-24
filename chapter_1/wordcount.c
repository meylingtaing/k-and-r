/**
 * Word counting
 * Example from The C Programming Language
 */

 #include <stdio.h>

 #define IN 	1	// Inside a word
 #define OUT	0	// Outside a word

 int main() {

 	int state, c, num_line, num_word, num_char;
 	
 	state = OUT;
 	num_line = num_word = num_char = 0;

 	while ((c = getchar()) != EOF) {
 		num_char++;

 		if (c == '\n')
 			num_line++;
 		if (c == ' ' || c == '\n' || c == '\t' || c == '\r')
 			state = OUT;
 		else if (state == OUT) {
 			state = IN;
 			num_word++;
 		}
 	}

 	printf("Number of lines: %d\n", num_line);
 	printf("Number of words: %d\n", num_word);
 	printf("Number of characters: %d\n", num_char);

 	return 0;
 }