#include <stdio.h>

int main(){
  int l=0;
  char c;
  while((c=getchar())>0 && c != '#'){
    if(c == '(') l++;
    if(c == ')') l--;
    if(l<0) goto no;
  }
  if(l==0) goto yes; else goto no; 
yes:
  printf("YES");
  return 0;
no:
  printf("NO");
  return 0;
}

