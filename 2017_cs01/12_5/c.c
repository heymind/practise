#include <stdio.h>
int reverse(int n){
  int result = 0;
  while(n!=0){
    result = result * 10 + n % 10;
    n/=10;
  }
  return result;
}

int main(){
  int n;
  int i=0;
  int ii=0;
  scanf("%d",&n);
  if(reverse(n) != n) goto no;
  while(ii<n){
    i++;
    ii = i*i;
    if(ii ==  n){
      printf("Yes\n");
      return 0;
    }
  }
no:
  printf("No\n");
  return 0;
}

