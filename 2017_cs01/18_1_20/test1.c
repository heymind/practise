#include <stdio.h>
#include <string.h>
struct student
{
	char name[21];
	int total;
};
int main()
{
	int n;
	scanf("%d",&n);
	
	struct student stu[n];
	for(int i = 0;i < n;i++){
		int j = 0;
		while((stu[i].name[j] = getchar()) > '9'||stu[i].name[j] == ' '){
			j++;
		}
		stu[i].name[j+1] = '\0';
		scanf("%d",&stu[i].total);
		//scanf("%d",&stu[i].total);
	}
	struct student temp;
	for(int i = n-1;i >= 0;i--){
		for(int j = n-i-1;j > 0;j--){
			if(stu[j].total > stu[j-1].total){
				temp = stu[j];
				stu[j] = stu[j-1];
				stu[j-1] = temp;	
			}
			else if(stu[j].total == stu[j-1].total){
				if(strcmp(stu[j].name,stu[j-1].name) < 0){
					temp = stu[j];
					stu[j] = stu[j-1];
					stu[j-1] = temp;	
				}
			}		 
		}
	}
	for(int q = 0;q < n;q++){
		printf("%s\n",stu[q].name);
		printf("%d\n",stu[q].total);
		printf("\n");
	}
	return 0;
}
