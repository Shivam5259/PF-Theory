#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee{
    int *rating;
    int total_score;
};

void inputEmployees(int **rating, int numEmployees, int numPeriods);
void displayPerformance(int **rating, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int **rating, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int **rating, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(int**rating, int numEmployees, int numPeriods);

int main(){
	struct Employee *ptr;
	int Num_employee,period;
    printf("Enter the Number of Employee: ");
    scanf("%d", &Num_employee);

    printf("Enter the Total Number of Evalution:");
    scanf("%d", &period);

    ptr = (struct Employee*)malloc(sizeof(struct Employee)*Num_employee);

    for(int i=0;i<Num_employee;i++){
        ptr[i].rating=(int *)malloc(sizeof(int)*period);
    }

    int **rating=(int **)malloc(sizeof(int *)*Num_employee);

    for(int i=0; i<Num_employee; i++){
	    *(rating+i)=ptr[i].rating;
    }

	inputEmployees(rating, Num_employee, period);
    printf("Press Enter to display the performances.....");
    getchar();
    getchar();

    displayPerformance(rating, Num_employee, period);	
    printf("\n\n==========================================\n");
    printf("%d Employee has highest average\n",findEmployeeOfTheYear(rating,Num_employee,period)+1);
    printf("%d period has highest average\n",findHighestRatedPeriod(rating,Num_employee,period)+1);	
    printf("%d is the worst performing Employee\n",findWorstPerformingEmployee(rating,Num_employee,period)+1);		          
}

void inputEmployees(int **rating, int numEmployees, int numPeriods){
	for (int i = 0; i < numEmployees; i++){
        printf("\nEnter ratings for employee %d: \n", i+1);
        for (int j = 0; j < numPeriods; j++) {
            printf("Evaluation %d: ", j+1);
            scanf("%d", *(rating+i)+j);
        }
    }  
}

void displayPerformance(int **rating, int numEmployees, int numPeriods){
	for (int i = 0; i < numEmployees; i++){
        printf("\n\nRating of employee %d is:\n",i+1);
        for (int j = 0; j < numPeriods; j++){
            printf("Evaluation %d: %d\n", j+1, *(*(rating+i)+j));
        }
    } 
}

int findEmployeeOfTheYear(int **rating, int numEmployees, int numPeriods){
	int hig_avg=-1,index_high;
	for (int i = 0; i < numEmployees; i++){
        int sum=0;
        for (int j = 0; j < numPeriods; j++){
            sum+=*(*(rating+i)+j);
        }
        if(sum/numPeriods>hig_avg){
    	    hig_avg=sum/numPeriods;
    	    index_high=i;
	    }
    } 
    return index_high;
}

int findHighestRatedPeriod(int **rating, int numEmployees, int numPeriods){
	int hig_avg=-1, index_high;
	for (int i = 0; i < numPeriods; i++){
        int sum=0;
        for (int j = 0; j < numEmployees; j++){
            sum+=*(*(rating+j)+i);
        }
        if(sum/numPeriods>hig_avg){
    	    hig_avg=sum/numEmployees;
    	    index_high=i;
	    }
    } 
    return index_high;
}

int findWorstPerformingEmployee(int **rating,int numEmployees,int numPeriods){
	int low_avg=9999, index_low;
	for (int i = 0; i<numEmployees; i++) {
        int sum=0;
        for (int j = 0; j<numPeriods; j++) {
            sum+=*(*(rating+i)+j);
        }
        if(sum/numPeriods<low_avg){
            low_avg=sum/numPeriods;
	        index_low=i;
	    }
    } 
    return index_low;
}