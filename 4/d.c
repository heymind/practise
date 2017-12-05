#include <stdio.h>
int main(){
    char s[1000],*str=s;
    scanf("%s",str);
    int len = 0,per;
    while(*(str++) != '\0')  len++;
    str-= len + 1;
    per = len % 3;
    if(per==0) per = 3;
    do{
       printf("%c",*str);
        if(!(--per) && *(str+1) != '\0'){printf(",");per=3;}
    }while(*(++str) != '\0');
    return 0;
}
