#include <stdio.h>

void count_inputs() {
    int c, i, nw, no;
    int nd[10];
    nw = no = 0;

    // initialize array to all zeros
    for (i = 0; i < 10; i++)
	nd[i] = 0;

    while ((c = getchar()) != EOF)
	if (c >= '0' && c <= '9')
	    ++nd[c-'0'];
	else if (c == ' ' || c == '\n' || c == '\t')
	    ++nw;
	else
	    ++no;

    // loop over digits
    printf("Digits: ");
    for (i = 0; i < 10; i++)
	printf("%d", nd[i]);

    // print others
    printf("\nWhite Space: %d", nw);
    printf("\nOther: %d\n", no);
}

void word_histogram() {

}

int main() {
    count_inputs();
}
