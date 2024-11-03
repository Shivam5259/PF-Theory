#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Enter number of encoded strings you want to enter: ");
    scanf("%d", &n);
    int len[n];
    char str[n][50];
    char result[n][n][50];
    for(int i=0; i<n; i++){
        printf("Enter string %d: ",i+1);
        scanf("%s", str[i]);
        len[i]=strlen(str[i]);
    }

    for(int i=n-1; i>=0; i--){
        if(str[i][0]!='#'){
            printf("[%s",str[i]);
            for(int j=i-1; j>=0; j--){
                if(len[i]==len[j]){
                    int count=0;
                    for(int k=0; str[i][k]!='\0'; k++){
                        for(int l=0; str[j][l]!='\0'; l++){
                            if(str[i][k]==str[j][l]){
                                count++;
                            }
                        }
                    }
                    if(count==len[j]){
                        printf(",%s",str[j]);
                        str[j][0]='#';
                    }
                }
            }
            printf("],");
        }
    }
}