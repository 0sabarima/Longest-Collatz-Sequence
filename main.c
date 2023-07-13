#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

ulong i = 1;

void collatz_sequence(ulong);

int main() {
    ulong cmp = 0;
    ulong answer = 0;
    for (ulong j = 999999; j > 0; j--) {

        collatz_sequence(j);

        if (i > cmp) {
            cmp = i;
            answer = j;
        }

        i = 1;
    }

    printf("The starting number with the longest chain is %ld, with %ld terms", answer, cmp);

    return 0;

}

void collatz_sequence(ulong x) {
    if(x != 1) {
        if(x % 2 == 0) {
            i++;
            collatz_sequence(x / 2);
        }
        else {
            i++;
            collatz_sequence((3 * x) + 1);
        }
    }
}
