#include<stdio.h>

int main(){ 
    int n;
	printf("Enter the number of matchstiks: ");
	scanf("%d", &n);

    if(n%5==0){
        printf("It's impossible for A to win");
    }
	else{
        printf("A should pick %d matchstick(s).\n", n%5);
    }
}
