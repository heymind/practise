#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define BASE (16)

typedef unsigned short _BASE;

typedef struct BigNum {
  size_t n;
  int base;
  void* e;
} BigNum;

void bn_free(BigNum *bn)
{
  free(bn->e);
  free(bn);
}

BigNum *bn_from_int(unsigned long i)
{
  //鬼知道最后是多大个数组。。还是动态调整吧。。。
  size_t capacity = 100,n = 0;
  _BASE *e = (_BASE*) malloc( capacity * sizeof(_BASE));
  while(i>0){
    e[n++] = i % BASE;
    i = i / BASE;
    if(n==capacity){
      //尴尬。。。不够用了
      capacity += capacity/4; //扩大25%
      e = (_BASE*) realloc(e,capacity * sizeof(_BASE));
    }
  }
  //节约起见。。设成n吧
  e = (_BASE*) realloc(e,n*sizeof(_BASE));
  
  BigNum* bn = malloc(sizeof(BigNum));

  bn->n = n;
  bn->e = e;
  
  return bn;
}
//一个大整数除以一个ulong整数，商会存到bn里，返回余数
unsigned long _bn_div_ulong(BigNum *bn,unsigned long den)
{
}


//用的时候会自己拷贝一份。。。
BigNum *bn_from_str(const unsigned char *str,size_t l){
  size_t capacity=100,n=0; //BigNum的预计承载量和实际个数
  _BASE *e = (_BASE*) malloc( capacity * sizeof(_BASE));
  
  unsigned char *a= malloc(l);
  for(size_t i=0;i<l;i++) 
    if('0'<=str[i] && str[i]<='9') 
      a[i] = str[i] - '0';
    else
      return NULL; //不是个数就算了
  
  //需要手工模拟一下除法。。哭哭
  size_t i=0, //遍历被除数的下标
         _l=l; //被除数的长度，l在遍历时为商位数的下表，遍历完成后为商的长度
  _BASE div=0; //模拟除法中被除数...
  l=0; 
  do{
    div = a[i++]; //先拉出来第一个数
    for(;i<_l;i++){//不断的去模拟除法
      a[l++] = div / BASE;
      div = (div % BASE) * 10 + a[i];
    } 
    //最后除一次，记下余数
    a[l++] = div/BASE;
    e[n++]=div % BASE;
    if(n==capacity){
      capacity += capacity/4; //扩大25%
      e = (_BASE*) realloc(e,capacity * sizeof(_BASE));
    }
    //为下一次除法做准备
    _l = l;l = 0;i=0;
    while(i<_l && a[i]==0){i++;} //找到第一个非零的位数
  }while(_l-i>0);
  
  e = (_BASE*) realloc(e,n*sizeof(_BASE));
  BigNum* bn = malloc(sizeof(BigNum));

  bn->n = n;
  bn->e = e;
  
  return bn;
}
void bn_print_raw(const BigNum *bn){
  for(int i=0;i<bn->n;i++) printf("%d,",bn->e[i]);
  printf("\n");
}
unsigned long bn_to_long(const BigNum *bn){
  unsigned long l = 0,factor = 1;
  for(int i=0;i<bn->n;i++) {
    l+=(bn->e[i])*factor;
    factor*=BASE;
  }
  return l;
}
int test_bn_from_str(){
  unsigned long ul = 0;
  size_t s = 0;
  char str[100];
  BigNum *bn;
  for(unsigned long i = 1;i<2147483647;i++){
    sprintf(str, "%ld", i);
    bn = bn_from_str(str,strlen(str));
    if(!(bn_to_long(bn) == i)){
      printf("%ld should be %ld || ",bn_to_long(bn),i);
      bn_print_raw(bn);
      exit(0);
    }
  }
}

int main(){
  BigNum *bn = bn_from_str("65743",5);
  bn_print_raw(bn);
  printf("%ld\n",bn_to_long(bn));
  test_bn_from_str();
  return 0;
}


  
