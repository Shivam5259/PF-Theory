#include<stdio.h>

int main(){
    int n, i ,j;
    printf("Enter length of the pattern(Odd Number): ");
    scanf("%d", &n);

    int spc1 = (n*2)-2;//initializing outer space in start of patter for exmaple if n=5 so the space in starting are 8
    int spc2 = 0;//intializing inner space


    for(i = 0; i<(n-1); i++){//dividing the pattern in 4 parts
        for(j=0; j<spc1; j++){// loop for spaces
            printf(" ");
        }
        printf("*");//one star in first line
        for(j=0; j<spc2; j++){
            printf(" ");
        }
        if(j!=0) printf("*");//a star after inner spaces
        printf("\n");
        
        spc1--;//decreasing outer spaces by 1
        if(i == 0) spc2++;//in second line there is only one inner space
        else spc2+=2;//inner space is increasing by 2
    }//end for loop

    for(i=0; i<n; i++){//stars in nth line
        printf("*");
    }
    for(i=0; i<spc2; i++){middle spaces in nth line
        printf(" ");
    }
    for(i=0; i<n; i++){
        printf("*");
    }
    printf("\n");
    
    spc2 = (spc2*2)-1;//increment in inner spaces
    spc1 = 1;//outer space is 1

    for(i=0; i<n-1; i++){//3rd part of pattern
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<spc2; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spc2-=2;//decrement in inner space by 2
        spc1++;//increment in outer space by 1

    }
    
    spc1 = n-2;//outer space
    spc2 = 1;//inner space
    for(i=0; i<n-2; i++){//last part pattern
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        for(j=0;  j<spc2; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spc1 --;//decrement in outer space by 1
        spc2+=4;//increment in inner space by 4
    }

    spc2+=2;//inner space = previos inner space +2
    printf("*");//the last line
    for(j=0; j<spc2; j++){//loop for spaces
        printf(" ");
    }
    printf("*");
    return 0;
}//end main
