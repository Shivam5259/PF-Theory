#include<stdio.h>

int main(){
    int n, i ,j;
    printf("Enter length of the pattern(Odd Number): ");
    scanf("%d", &n);

    int spc1 = (n*2)-2;
    int spc2 = 0;


    for(i = 0; i<(n-1); i++){
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<spc2; j++){
            printf(" ");
        }
        if(j!=0) printf("*");
        printf("\n");
        
        spc1--;
        if(i == 0) spc2++;
        else spc2+=2;
    }

    for(i=0; i<n; i++){
        printf("*");
    }
    for(i=0; i<spc2; i++){
        printf(" ");
    }
    for(i=0; i<n; i++){
        printf("*");
    }
    printf("\n");
    
    spc2 = (spc2*2)-1;
    spc1 = 1;

    for(i=0; i<n-1; i++){
        for(j=0; j<spc1; j++){
            printf(" ");
        }
        printf("*");
        for(j=0; j<spc2; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spc2-=2;
        spc1++;

    }
    
    spc1 = n-2;
    spc2 = 1;
    for(i=0; i<n-2; i++){
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
        spc1 --;
        spc2+=4;
    }

    spc2+=2;
    printf("*");
    for(j=0; j<spc2; j++){
        printf(" ");
    }
    printf("*");
    return 0;
}