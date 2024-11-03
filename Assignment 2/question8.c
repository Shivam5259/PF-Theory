#include <stdio.h>
#include <math.h>

int bin2dec(int);
int dec2bin(int);
void dec2hex(int);
void hex2dec(char str[]);
void bin2hex(int);
void hex2bin(char str[]);

int main(){
    printf("Enter Appropriate number according to your requirment: \n");
    printf("1- Binary to Decimal\n");
    printf("2- Decimal to Binary\n");
    printf("3- Decimal to Hexadecimal\n");
    printf("4- Hexadecimal to Decimal\n");
    printf("5- Binary to Hexadecimal\n");
    printf("6- Hexadecimal to Binary Number\n");
    printf("_____________________________________________________\n");
    int n, num;
    char str[20];
    printf("Enter: ");
    scanf("%d", &n);

    switch(n){
        case 1:
        printf("Enter binary number: ");
        scanf("%d", &num);
        int a=bin2dec(num);
        if(a==0) return 0;
        else printf("The corresponding decimal number is: %d", a);
        break;

        case 2:
        printf("Enter Decimal Number: ");
        scanf("%d", &num);
        int b=dec2bin(num);
        if(b==0) return 0;
        else printf("The correponding Binary number is: %d", b);
        break;
        
        case 3:
        printf("Enter Decimal Number: ");
        scanf("%d", &num);
        dec2hex(num);
        break;

        case 4:
        printf("Enter Hexadecimal Number: ");
        scanf("%s", str);
        hex2dec(str);
        break;

        case 5:
        printf("Enter binary number: ");
        scanf("%d", &num);
        bin2hex(num);
        break;

        case 6:
        printf("Enter Hexadecimal Number: ");
        scanf("%s", str);
        hex2bin(str);
        break;

        default:
        printf("Invalid Input");
    }
}

int bin2dec(int n){
    int num=n;
    while(n>0){
        if(n%10!=1 && n%10!=0){
            printf("Invalid Number.\n");
            return 0;
        }
        n/=10;
    }
    int sum=0;
    for(int i=0; num!=0; i++){
        sum+=((num%10)*pow(2,i));
        num/=10;
    }
    return sum;
}

int dec2bin(int n){
    int number=n;
    while(n!=0){
        if(n%10<0 && n%10>9){
            printf("Invalid Number.");
            return 0;
        }
        n/=10;
    }
    int num=0, a=0, arr[32];
    while(number>=1){
        arr[a++]=number%2;
        number/=2;
    }
    for(int i=a-1; i>=0; i--){
        num=10*num+arr[i];
    }
    return num;
}

void dec2hex(int n){
    int num=n;
    while(n!=0){
        if(n%10<0 && n%10>9){
            printf("Invalid Number.");
            return;
        }
        n/=10;
    }
    int sum=0, a=0, arr[20];
    while(num>0){
        arr[a++]=num%16;
        num/=16;
    }

    for(int i=a-1; i>=0; i--){
        if(arr[i]>=10 && arr[i]<=15){
            arr[i]+=55;
        }
        else{
            arr[i]+=48;
        }
        printf("%c", arr[i]);
    }
    return;
}

void hex2dec(char str[]){
    int num=0, a, i;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]<'0' && str[i]>'9' || str[i]<'A' && str[i]>'F'){
            printf("Invalid Number.");
            return;
        }
    }

    for(int j=i-1, k=0; j>=0; j--, k++){
        if(str[j]>='0' && str[j]<='9') a=str[j]-48;
        if(str[j]>='A' && str[j]<='F') a=str[j]-55;
        num+=(a*pow(16,k));
    }
    printf("%d", num);
    return;
}

void bin2hex(int n){
    int dec=bin2dec(n);
    dec2hex(dec);
    return;
}

void hex2bin(char str[]){
    int i, num, a;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]<'0' && str[i]>'9' || str[i]<'A' && str[i]>'F'){
            printf("Invalid Number.");
            return;
        }
    }
    for(int j=i-1; j>=0; j--){
        if(str[j]=='0') printf("0000");
        else if(str[j]=='1') printf("0001");
        else if(str[j]=='2') printf("0010");
        else if(str[j]=='3') printf("0011");
        else if(str[j]=='4') printf("0100");
        else if(str[j]=='5') printf("0101");
        else if(str[j]=='6') printf("0110");
        else if(str[j]=='7') printf("0111");
        else if(str[j]=='8') printf("1000");
        else if(str[j]=='9') printf("1001");
        else if(str[j]=='A') printf("1010");
        else if(str[j]=='B') printf("1011");
        else if(str[j]=='C') printf("1100");
        else if(str[j]=='D') printf("1101");
        else if(str[j]=='E') printf("1110");
        else if(str[j]=='F') printf("1111");
    }
    return;
}