#include <stdio.h>

int main(){
  int n,m,v;
  scanf("%d",&n);
  int a[n],flag=0;
  for(int i=0;i<n;i++) scanf("%d",a+i);
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d",&v);
    flag = 0;
    for(int j=0;j<n;j++){
      if(v==a[j]){
        flag = 1;
        if(j == 0 && j == n-1) printf("NULL\n");
        else if(j == 0) printf("%d\n",a[j+1]);
        else if(j == n - 1) printf("%d\n",a[j-1]);
        else printf("%d %d\n",a[j-1],a[j+1]);
      } 
    }
    if(flag == 0)  printf("NULL\n");

  }
  return 0;

}
