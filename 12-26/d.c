#include <stdio.h>
#include <string.h>

int main(){
  char a[1000],b;
  fgets(a,1000,stdin);
  b=getchar();
  int l = strlen(a);
  for(int i=0;i<l;i++) if(a[i] != b) putchar(a[i]);
  
  return 0;
}

