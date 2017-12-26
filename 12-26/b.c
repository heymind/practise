#include <stdio.h>
int bsearch(const int a[],int v,int lo,int hi){ //[lo,hi),,length = hi - lo
  if(hi-lo == 1) return a[lo] == v ? lo : -1; 
  int mid = (lo+hi)/2;
  if(a[mid] == v) return mid;
  if(a[mid] > v) return bsearch(a,v,lo,mid); else return bsearch(a,v,mid+1,hi);
}
int main(){
  int n=0;
  scanf("%d",&n);
  int a[n];
  int v,j;
  for(int i=0;i<n;i++) scanf("%d",a+i);
  scanf("%d",&v);
  printf("%d\n",bsearch(a,v,0,n));
  return 0;
}

