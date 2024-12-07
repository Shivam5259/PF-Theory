#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee{
	int employeeCode;
	char employeeName[100];
    char dateOfJoining[11];
};

void value_definer(struct  Employee *ptr,int n);
void tenure_cal(struct Employee arr[],int n);

int main(){
	int N=4;
	struct Employee arr[N];
	value_definer(arr,N);
	tenure_cal(arr,N);
}

void value_definer(struct Employee *ptr,int n){

	for(int i=0;i<n;i++){

		printf("\nEnter the Employee Code of %d employee: ", i+1);
		scanf("%d", &(ptr+i)->employeeCode);

		printf("Enter the Employee Name of %d employee: ", i+1);
		scanf(" %[^\n]", (ptr+i)->employeeName);

		printf("Enter the Date Of Joining of %d employee: ", i+1);
		scanf(" %[^\n]", (ptr+i)->dateOfJoining);
	}
	return ;
}
void tenure_cal(struct Employee arr[],int n){
	int count=0;
	char curr_year[5];
    printf("\nEnter the current year: ");
	scanf("%s", curr_year);

	printf("Employee whose tenure is more than 3\n===========================================\n");

	for(int i=0;i<n;i++){

		char year[5];
		int len = strlen(arr[i].dateOfJoining);
		strncpy(year, arr[i].dateOfJoining, 4);
		year[4]='\0';

		long int Current_Year = strtol(curr_year, NULL, 10);
		long int Joining_Year = strtol(year, NULL, 10);

		if(Current_Year - Joining_Year> 3){
			printf("Employee Code: %d\tName: %s\tDate Of Joining: %s\n", arr[i].employeeCode, arr[i]. employeeName, arr[i].dateOfJoining);
			count++;
		}
    }
    
	printf("\nThere are %d employee whose tensure is more than 3",count);
}