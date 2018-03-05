#include <stdio.h>

int main() {
    int a[40] = {0, 1, 1};
    for (int i = 3; i <= 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    int n, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        printf("%d\n", a[v]);
    }
    return 0;
}