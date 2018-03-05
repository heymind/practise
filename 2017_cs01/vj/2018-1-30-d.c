#include <stdio.h>

void printTheFuckingThings(int n, char c) {
    if (n == 1) {
        printf("%c\n", c);
        return;
    }
    int tmp;
    tmp = n - 1;
    while (tmp--)
        printf(" ");
    printf("%c", c);

    printf("\n");
    for (int i = 1; i < n - 1; i++) {
        tmp = n - 1 - i;
        while (tmp--)
            printf(" ");
        printf("%c", c);
        tmp = 2 * i - 1;
        while (tmp--)
            printf(" ");
        printf("%c", c);
        printf("\n");
    }
    tmp = 2 * n - 1;
    while (tmp--)
        printf("%c", c);
    printf("\n");
}

int main() {
    char a;
    int b;
    int not_first = 0;
    while (scanf("%s", &a) && a != '@') {
        if (not_first)
            printf("\n");
        else {
            not_first = 1;
        }
        scanf("%d", &b);
        printTheFuckingThings(b, a);
    }
    return 0;
}