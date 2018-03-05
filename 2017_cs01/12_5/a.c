#include <stdio.h>
int result = 0;
int to_add = 1;
void f(int a){
  if(a==0) return;
  if(a % 10 == 1) result+=to_add;
  to_add*=2;
  f(a/10);
}

int main(){
  int num;
  scanf("%d",&num);
  f(num);
  printf("%d",result); 
  return 0;
}
