#include <stdio.h>
int count = 1;
void f(long a){
  if(a/2==0) return;
  count++;
  f(a/2);
}
int main(){
  long num;
  scanf("%ld",&num);
  f(num);
  printf("%d\n",count);
  return 0;
}

