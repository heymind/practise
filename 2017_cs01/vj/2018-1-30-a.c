#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0, b = 0, tmp = 0, sqrt_tmp = 0, flag = 0;
    while (scanf("%d%d", &a, &b) && !(a == 0 && b == 0)) {
        flag = 0;
        for (; a <= b; a++) {
            tmp = a * a + a + 41;
            sqrt_tmp = sqrt(tmp);
            for (int i = 2; i <= sqrt_tmp; i++) {
                if (tmp % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            printf("Sorry\n");
        else
            printf("OK\n");
    }
    // system("pause");
    return 0;
}