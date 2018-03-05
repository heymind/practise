#include <stdio.h>
int main(){
  int n=0;
  scanf("%d",&n);
  int a[n*n];
  int b[n];
  int v,sum;
  for(int i=0;i<n;i++){
    sum=0;
    for(int j=0;j<n;j++){
      scanf("%d",&v);
      sum+=v;
      a[i*n+j] = v;
    }
    b[i] = sum;
  }
  int min=0,idx=0;
  for(int i=0;i<n;i++){
    min = -1;
    idx = 0;
    for(int j=0;j<n;j++) 
      if(b[j] != -1 && (min == -1 || b[j] < min)) {
          min = b[j];
          idx = j;
      }
    printf("%d",a[idx*n]);
    for(int j=1;j<n;j++) printf(" %d",a[idx*n+j]);
    printf("\n");
    b[idx] = -1;
  }
    
  return 0;
}

