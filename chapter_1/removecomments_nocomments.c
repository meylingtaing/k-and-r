

#include <stdio.h>

#define OTHER	        0
#define LINE_COMMENT    1
#define BLOCK_COMMENT   2
#define STRING          3
#define CHARACTER       4

int main() {
	int state = OTHER;
	int c1, c2;

	while ( (c1=getchar()) != EOF) {
	    if (state == OTHER) {
            if (c1 == '/') {
                c2 = getchar();

                
                if (c2 == '/')
                    state = LINE_COMMENT;
                
                else if (c2 == '*')
                    state = BLOCK_COMMENT;
                else {
                    putchar(c1);
                    putchar(c2);
                }
            }

            else {
                putchar(c1);
                
                
                if (c1 == '\"')
                    state = STRING;
                
                if (c1 == '\'')
                    state = CHARACTER;
            }
        }

        else if (state == LINE_COMMENT) {
            if (c1 == '\n') {
                putchar('\n');
                state = OTHER;
            }
        }

        else if (state == BLOCK_COMMENT) {
            if (c1 == '*') {
                if ((c2 = getchar()) == '/')
                    state = OTHER;
            }
        }

        else if (state == CHARACTER) {
            putchar(c1);
            
            if (c1 == '\\') {
                c2 = getchar();
                putchar(c2);
            }
            else if (c1 == '\'')
                state = OTHER;
        }

        else { 
            putchar(c1);
            
            if (c1 == '\\') {
                c2 = getchar();
                putchar(c2);
            }

            else if (c1 == '\"')
                state = OTHER;
        }
	}

    return 0;
}
