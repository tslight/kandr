#include <stdio.h>

void inout () {
    int c;
    while ((c = getchar()) != EOF)
	putchar(c);
}

void count_chars () {
    double nc;
    printf("Enter a string: ");
    for (nc = 0; getchar() != '\n'; nc++);
    printf("Number of chars = %.0f\n", nc);
}

void count_lines () {
    int c, nl;
    while ((c = getchar()) != EOF)
	if (c == '\n')
	    ++nl;
    printf("Number of lines = %d\n", nl);
}

void count_words () {
    int c, nc, nw;
    nc = nw = 0;
    while ((c = getchar()))
	if (c == ' ' || c == '\t') {
	    ++nw;
	} else if (c == '\n') {
	    if (nc > 0)
		++nw;
	    break;
	} else {
	    ++nc;
	}
    printf("Number of words = %d\n", nw);
}

int main () {
    /* inout(); */
    /* count_chars(); */
    /* count_lines(); */
    count_words();
}
