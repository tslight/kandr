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

// https://codereview.stackexchange.com/q/106542
void word_histogram() {
    int c, i, j, len, ne, max;
    i = j = ne = len = 0;
    max = 25;
    int h[max];

    for (int i = 0; i < max; i++) {
	h[i] = 0;
    }

    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (len < max)
		ne = len;
	    else
		ne = max;
	    h[ne-1]++;
	    len = 0;
	} else {
	    len++;
	}
    }

    for (i = max; i > 0; i--) {
	printf("%3d|", i);
	for (j = 0; j < max; j++) {
	    if (h[j] < i)
		printf("  ");
	    else
		printf(" #");
	}
	printf("\n");
    }

    printf("   ");
    for (i = 0; i < max; i++) {
	printf("--");
    }
    printf("\n");
}

int main() {
    /* count_inputs(); */
    word_histogram();
}
