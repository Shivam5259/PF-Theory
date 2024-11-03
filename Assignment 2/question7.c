#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rearrange(char puzzle[6][5]);
void printPuzzle(char puzzle[6][5]);
int findWord(char puzzle[6][5], char str[]);

int main(){
    char puzzle[6][5];
    char str[100];
    int score=0;

    while(1){
        rearrange(puzzle);

        while(1){
            printPuzzle(puzzle);
            printf("\nSearch for Word(Type 'END' to repopulate)= ");
            scanf("%s",str);

            if(strcmp(str, "END")==0){
            break;
            }

            if(findWord(puzzle, str)){
                printf("%s is present. Your Current score is: %d\n", str, ++score);
            }
            else{
                printf("%s is not present. Your Current score is: %d\n", str, --score);
            }
        }
    }
}

void rearrange(char puzzle[6][5]){
    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            puzzle[i][j]= 'A' + (rand()%26);
        }
        if(i==6-1){
                puzzle[i][0]='0';
                puzzle[i][1]='9';
                puzzle[i][2]='5';
                puzzle[i][3]='7';
            }
    }
}

void printPuzzle(char puzzle[6][5]){
    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            printf("| %c ", puzzle[i][j]);
        }
        printf("|\n");
    }

}

int findWord(char puzzle[6][5], char str[]){
    int len= strlen(str);

    for(int i=0; i<6; i++){
        for(int j=0; j<=5-len; j++){
            int found=1;
            if(puzzle[i][j]==str[0]){
                for(int k=0; k<len; k++){
                    if(puzzle[i][k+j]!=str[k]){
                        found=0;
                        break;
                    }
                }  
                if(found){
                    return 1;
                } 
            }
        }
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<=6-len; j++){
            int found=1;
            if(puzzle[j][i]==str[0]){
                for(int k=0; k<len; k++){
                    if(puzzle[k+j][i]!=str[k]){
                        found=0;
                        break;
                    }
                }  
                if(found){
                    return 1;
                } 
            }
        }
    }
    
    return 0;
}