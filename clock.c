#include <stdio.h>
#include <math.h>
#define SIZE (30)
#define PI (3.1415926)

int d[SIZE][SIZE];
void clear(){
  for(int i=0;i<SIZE;i++) for(int j = 0;j<SIZE;j++) d[i][j] = 0;
}
void output(){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++) printf(d[i][j] ? "**" : "  ");
    putchar('\n');
  }
}
void drawLineWithDegree(double degree,double length){
  double x = length * sin(degree);
  double y = length * cos(degree);
  x+=SIZE/2;
  y+=SIZE/2;
  int x0 = SIZE/2;
  int y0 = SIZE/2;
  int x1 = x;
  int y1 = y;
  printf("%d|%d|%d|%d",x0,y0,x1,y1);
  for(int i = x0;i<x1;i++) d[i][y0+(int)(((double)(i-x0)/(x-x0))*(y-y0))]=1;
  for(int i = y0;i<y1;i++) d[x0+(int)(((double)(i-y0)/(y-y0))*(x-x0))][i]=1;
}
int main(){
  clear();
  for(int i=0;i<SIZE;i++) for(int j = 0;j<SIZE;j++) d[i][j] = pow(i-((double)SIZE/2),2) + pow(j-((double)SIZE/2),2) > pow((SIZE-1)/2,2) ? 1: 0;
  drawLineWithDegree(PI,15); 
  output();

}
