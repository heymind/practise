#include <stdio.h>
#define MIN(a,b) ((a) > (b) ? (b) : (a))
int gen_numbers(int n){
    unsigned short _s2[1000],_s3[1000],_s5[1000];
    unsigned short *s2 = _s2 , *s3 = _s3 , *s5 = _s5;
    *s2 = 2;
    *s3 = 3;
    *s5 = 5;
    unsigned short x;
    while(1){
        x = MIN(*s2,*s3);
        x = MIN(x,*s5);
        printf("%d|%d|%d\n",*s2,*s3,*s5);
        if(x==n) return 0; else if (x>n) return 1;
        if(*s2 < *s3 && *s2 < *s5){
            *(++s3) = *s2*3;
            *(++s5) = *s2*5;
            *s2*=2;
        }else if(*s3 < *s2 && *s3 < *s5){
            *(++s5) = *s3*5;
            *s3*=3;
        }else{
            *s5*=5;
        }
    
    }

}
void main(){
    int n;
    scanf("%d",&n);
    printf("%d",gen_numbers(n));

}
