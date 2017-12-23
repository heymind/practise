#include <stdio.h>
int calcCode(const int *a,int nth){
  int count=0;
  for(int i=0;i<nth;i++) if(a[i]<a[nth]) count++;
  return count;
}

void encode(const int *in,int *out,int length){
  for(int i=0;i<length;i++) out[i] = calcCode(in,i);
}

int decode(const int *in,int *out,int length,int nth){
  if(nth == length) return 1;

  int flag_next = 0;
  for(int i=0;i<length;i++){ //挨个数看看。。感觉没比暴力枚举好到哪去，
    //整个过程就是一个forward的过程，当forward到某位尝试所有的可能性都没戏的时候
    //就backward到上一层接着试下一个数
    flag_next = 0; 
    for(int j=0;j<nth;j++)
      if(i==out[j]) {flag_next = 1;break;} //这个数之前用过了，直接下一个数
    if(flag_next) continue; 
    
    out[nth] = i;
    if(calcCode(out,nth) == in[nth] 
        && decode(in,out,length,nth+1)) return 1;
  }
  return 0;
    
}
void output(const int *array,int length){
  for(int i=0;i<length;i++) printf("%d,",array[i]);
}

int main(){
  int a[]={0,1,2,0,1,1,4,5};
  int b[100];
  decode(a,b,8,0);
  output(b,8);
  printf("\n");
  int c[]={2,1,3,0,4};
  encode(c,b,5);
  output(b,5);
  

  return 0;
}
