#include <stdio.h>
#include <string.h>

char* compressor(char str[][50], int);

int main(){
    int n;
    printf("Enter number of words you want to compress: ");
    scanf("%d", &n);
    char str[n][50];
    getchar();
    for(int i=0; i<n; i++){
        printf("Enter word %d: ", i+1);
        fgets(str[i], sizeof(str[i]), stdin);
    }
    for(int i=0; i<n; i++){
        int count=0;
        compressor(str, i);
        printf("%d compressed word is: ", i+1);
        for(int j=0; str[i][j]!='\0'; j++){
            if(str[i][j]=='1') count++;
            else{
                printf("%c", str[i][j]);
            }
        }
        printf("The number of removed characters is: %d\n", count);
    }
}

char* compressor(char str[][50], int n){
    for(int i=0; str[n][i]!='\0'; i++){
        for(int j=i+1; str[n][j]!='\0'; j++){
            if(str[n][i]==str[n][j]){
                str[n][j]='1';
            }
            else{
                break;
            }
        }
    }
    return str;
}