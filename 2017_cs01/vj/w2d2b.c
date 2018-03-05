#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n], v[m][n], max = 0, c = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            v[i][j] = -1;
        }
    while (c) {
        c = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j] == -1) {
                    c = 1;
                    int max_v = 0;
                    if (i - 1 >= 0 && a[i - 1][j] < a[i][j])
                        if (v[i - 1][j] == -1)
                            continue;
                        else if (v[i - 1][j] > max_v)
                            max_v = v[i - 1][j];

                    if (i + 1 < m && a[i + 1][j] < a[i][j])
                        if (v[i + 1][j] == -1)
                            continue;
                        else if (v[i + 1][j] > max_v)
                            max_v = v[i + 1][j];
                    if (j - 1 >= 0 && a[i][j - 1] < a[i][j])
                        if (v[i][j - 1] == -1)
                            continue;
                        else if (v[i][j - 1] > max_v)
                            max_v = v[i][j - 1];

                    if (j + 1 < n && a[i][j + 1] < a[i][j])
                        if (v[i][j + 1] == -1)
                            continue;
                        else if (v[i][j + 1] > max_v)
                            max_v = v[i][j + 1];
                    v[i][j] = max_v + 1;
                    if (v[i][j] > max)
                        max = v[i][j];
                }
    }
    printf("%d\n", max);
    system("pause");
    return 0;
}