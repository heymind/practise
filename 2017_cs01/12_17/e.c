#include <stdio.h>

int main(){
  int max=0,m=1,n,v,old_v=10001;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&v);
    if(v == old_v) m++; else {
      if(m>max) max = m;
      m = 1;
    }
    old_v = v;
  }
  printf("%d\n",max>m?max:m);
  return 0;
}
