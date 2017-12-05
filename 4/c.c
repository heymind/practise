#include <stdio.h>
int main(){
    int n,a=2,b=1,t;
    scanf("%d",&n);
    double sum = 0.0;
    while(n--){
        sum+=(double)a/b;
        t=a;
        a+=b;
        b=t;
    }
    printf("%.2f",sum);
    return 0;
}

