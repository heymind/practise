#include <stdio.h>

void f(char* s){
   printf("%p\n",s);

  s="abcded";
 printf("%p\n",s);

}

void main(){
  char ss[100]= "aeeeee";
  printf("%p\n",ss);
  f(ss); 
  printf("%s|%p",ss,ss);
}

