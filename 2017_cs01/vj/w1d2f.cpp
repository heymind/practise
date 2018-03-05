
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    long long a, b;
    while (cin >> hex >> a >> b) {
        if (a + b >= 0)
            printf("%llX\n", a + b);
        else
            printf("-%llX\n", -a - b);
    }
}