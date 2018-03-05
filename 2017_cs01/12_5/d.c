#include <stdio.h>
//使用位运算统计重复否。。。
//一个二进制数0b000000000 有10位分别代表数字0~9有没有出现过
int f(int n,int flag){
  int c;
  do {
    c = n % 10;
    if(flag >> c & 1) return 0; else flag |= 1 << c;
  }while((n=n/10));
  return 1;
}
int main(){
  int a,b,n,j=0,flag=0,no=1,should_a_tab=0;
  scanf("%d%d%d",&a,&b,&n);
  for(int i = n+1;i<=9;i++) flag|=1<<i;
  flag|=1;
  for(int i=a;i<=b;i++){
    if(f(i,flag)){
      no = 0;
      if(should_a_tab) {printf("\t");should_a_tab=0;}
      printf("%d",i);j++;
      if(j % 5 == 0 ) printf("\n"); else should_a_tab=1;
    }
  }
  if(no) printf("There is no proper number in the interval.\n"); else printf("\n");
  return 0;

}

