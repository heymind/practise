#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define BASE (16)

typedef unsigned short _BASE;

typedef struct BigNum {
  int n;
  _BASE* e;
} BigNum;

void bn_free(BigNum *bn)
{
  free(bn->e);
  free(bn);
}

BigNum *bn_from_int(unsigned long i)
{
  //鬼知道最后是多大个数组。。还是动态调整吧。。。
  int capable = 100; 
  int n = 0;
  _BASE *e = (_BASE*) malloc( capable * sizeof(_BASE));
  while(i>0){
    e[n++] = i % BASE;
    i = i / BASE;
    if(n==capable){
      //尴尬。。。不够用了
      capable += capable/4; //扩大25%
      e = (_BASE*) realloc(e,capable * sizeof(_BASE));
    }
  }
  //节约起见。。设成n吧
  e = (_BASE*) realloc(e,n*sizeof(_BASE));
  
  BigNum* bn = malloc(sizeof(BigNum));

  bn->n = n;
  bn->e = e;
  
  return bn;
}
//用的时候会自己拷贝一份。。。
BigNum *bn_from_str(const char *str,size_t l){
  char *a= malloc(l);
  for(size_t i=0;i<l;i++) 
    if('0'<=str[i] && str[i]<='9') 
      a[i] = str[i] - '0';
    else
      return NULL; //不是个数就算了
  //需要手工模拟一下除法。。哭哭
  int capable = 100; 
  int n = 0;
  _BASE *e = (_BASE*) malloc( capable * sizeof(_BASE));
  int div = a[0],i=1;
  int _l = l;
  int ll=0;
  l = 0; // l 是新的被除数的长度
  do{
    while(i<_l){
      if(div < BASE){
        //被除数太小。。商0
        a[l++] = 0;
        div = div * 10 + a[i++];
      }else{
        a[l++] = div / BASE;
        div = (div % BASE) * 10 + a[i++];
      }
    }
    if(div>=BASE) {
      a[l++] = div/BASE;
      div = div % BASE;
    }else a[l++]=0;
    e[n++]=div;
    _l = l;
    l = 0;i=0;
    while(i<_l && a[i]==0){i++;}
    ll = _l-i; 
    //printf("%d->%d(%d,%d,%d)_%d_%d\n",_l,l,a[0],a[1],a[2],div,_l-i);
    div = a[i];i++;
  }while(ll>0);
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
    }
  }
}

int main(){
  //BigNum *bn = bn_from_str("65743",5);
  //bn_print_raw(bn);
  //printf("%ld\n",bn_to_long(bn));
  test_bn_from_str();
  return 0;
}


  
