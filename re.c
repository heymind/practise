#include <stdio.h>

void reverse(int in,int *out){
  *out*=10;
  *out+=in % 10;
  if(in < 10) return; else reverse(in / 10,out);
}
int main(){
  int d=0;
  reverse(1234567,&d);
  printf("%d",d);
}

