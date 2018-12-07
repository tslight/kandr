#include <stdio.h>

void echo_input() {
    int c;
    while ((c = getchar()) != EOF)
	putchar(c);
}

void count_chars() {
    double nc;
    printf("Enter a string: ");
    for (nc = 0; getchar() != '\n'; nc++);
    printf("Number of chars = %.0f\n", nc);
}

void count_lines() {
    int c, nl;
    while ((c = getchar()) != EOF)
	if (c == '\n')
	    ++nl;
    printf("Number of lines = %d\n", nl);
}

void count_words() {
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

void truncate_whitespace() {
    int c, s;
    s = 0;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\t')
	    ++s;
	else
	    s = 0;
	if (s <= 1)
	    putchar(c);
    }
}

void count_btl() {
    int c, b, t, l;
    b = t = 0;
    l = 1;
    while ((c = getchar()) != EOF) {
	if (c == ' ')
	    ++b;
	else if (c == '\t')
	    ++t;
	else if (c == '\n')
	    ++l;
    }
    printf("\n"
	   "Number of blanks: %d\n"
	   "Number of tabs:   %d\n"
	   "Number of lines:  %d\n",
	   b, t, l);
}

void replace_specials() {
    int c;
    while ((c = getchar()) != '\n') {
	if (c == '\\') {
	    putchar('\\');
	    putchar('\\');
	} else if (c == '\t') {
	    putchar('\\');
	    putchar('t');
	} else if (c == '\b'){
	    putchar('\\');
	    putchar('b');
	} else {
	    putchar(c);
	}
    }
}

#define IN  1
#define OUT 0

void wc() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
	++nc;
	if (c == '\n')
	    ++nl;
	if (c == ' ' || c == '\t' || c == '\n') {
	    state = OUT;
	} else if (state == OUT) {
	    state = IN;
	    ++nw;
	}
    }
    printf("\n"
	   "Number of lines: %d\n"
	   "Number of words: %d\n"
	   "Number of chars: %d\n",
	   nl, nw, nc);
}

void one_word_line() {
    int c;
    int lc;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\t') {
	    if (lc != '\n') {
		putchar('\n');
		lc = '\n';
	    }
	} else{
	    putchar(c);
	    lc = c;
	}
    }
}

int main() {
    /* echo_input (); */
    /* count_chars(); */
    /* count_lines(); */
    /* count_words(); */
    /* truncate_whitespace(); */
    /* count_btl(); */
    /* replace_specials(); */
    /* wc(); */
    one_word_line();
}
