#include <stdio.h>

int main(){
  int n=0;
  scanf("%d",&n);
  int a[n];
  int v,j;
  for(int i=0;i<n;i++) scanf("%d",a+i);
  for(int i=1;i<n;i++){
    v = a[i];j=0;
    //找位置
    while(a[j]<v && j<n){j++;};
    //[i-1] -> [i] | i>j 挪地方
    for(int ii=i;ii>j;ii--) a[ii]=a[ii-1];
    //放进去
    a[j] = v;
  }
  printf("%d",a[0]);
  for(int i=1;i<n;i++) printf(" %d",a[i]);
  printf("\n");
  return 0;
}

