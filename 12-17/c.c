#include <stdio.h>

int main(){
  int n,m;
  scanf("%d",&n);
  int _a[n],_b[n],a_count=0,b_count=0,*a=_a,*b=_b;
  for(int i=0;i<n;i++){
    scanf("%d",&m);
    if( m % 2 ==0) a[a_count++] = m; else b[b_count++]=m;
  }
  if(!a_count) goto ugly_method;
  while(a_count && --a_count) printf("%d ",*(a++));
  if(!b_count) {printf("%d\n",*a);return 0;} else printf("%d ",*a);
ugly_method:
  while(b_count && --b_count) printf("%d ",*(b++));
  printf("%d\n",*b);
  return 0;
}
