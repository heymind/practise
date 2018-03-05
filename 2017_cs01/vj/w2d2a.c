#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int main() {
    int _n;
    scanf("%d", &_n);
    while (_n--) {
        int n;
        scanf("%d", &n);
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i < n; i++) {
            a[i][0] += a[i - 1][0];
            for (int j = 1; j < i; j++) {
                a[i][j] += MAX(a[i - 1][j - 1], a[i - 1][j]);
            }
            a[i][i] += a[i - 1][i - 1];
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (a[n - 1][i] > max)
                max = a[n - 1][i];
        }
        printf("%d\n", max);
    }
    return 0;
}