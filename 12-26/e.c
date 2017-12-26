#include <stdio.h>

int main(){
  int n,m;
  scanf("%d%d",&n,&m);

  int r = 0;
  for(int i = 2;i<=n;i++) r = (r + m ) % i;
  printf("%d\n",r+1);
  return 0;
}

