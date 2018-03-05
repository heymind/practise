#include <stdio.h>

int is_leap(int year){
  return year % 4 == 0 &&  year % 100 != 0 || year % 400 == 0;
}

int get_month_days(int year,int month){
  int days[12] = {31,is_leap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
  return days[month-1];
}

int get_week_day(int year,int month,int day){
  year--;
  day+= year * 365 + year / 400 + year / 4 - year / 100 ;
  for(int i=1;i<month;i++) day+=get_month_days(year+1,i);
  return day % 7;
}

void print_month_cal(int start_day,int days){
  for(int i=0;i<start_day;i++) putchar('\t');
  for(int i=1;i<=days;i++){
    if((++start_day) % 7 == 0) printf("%d\n",i); else printf("%t\t",i);
  }
}
int main(){
  printf("Please input year and month:");
  int year,month;
  scanf("%d%d",&year,&month);
  printf("The result is:\n\t\t\t%d-%d\nSun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n",year,month);
  print_month_cal(get_week_day(year,month,1),get_month_days(year,month));
  return 0;
}
