#include <stdio.h>

int main(){
  int n,m,max=0,min=101,sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&m);
    if(m > max ) max = m;
    if(m < min) min = m;
    sum+=m;
  }
  printf("%.2f %d %d\n",(double)sum/n,max,min);
}
