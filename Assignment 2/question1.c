#include <stdio.h>

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter Number %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    int max=0;
    for(int i=0; i<n; i++){
        if(arr[i]>max) max=arr[i];
    }

    for(int i=0; i<n-1; i++){
        if(arr[i]<arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            i=-1;
        }
    }

    int min=max, second_min=max;

    for(int i=0; i<n; i++){ 
        if(arr[i]<min){
            second_min=min;
            min=arr[i];
        }
    }
    if(min<second_min)
        printf("The Second Smallest Number is : %d", second_min);
    else printf("Second minimum not found.");
}