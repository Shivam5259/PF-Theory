#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validEmail(char*);

int main(){
	char *ptr;

	ptr = (char *)malloc(100*sizeof(char));
	scanf("%s",ptr);

	ptr = (char *)realloc(ptr,strlen(ptr)*sizeof(char));
	ptr[strlen(ptr)] = '\0';

	if(validEmail(ptr)) printf("\nValid Email");
	else printf("\nUnvalid Email");
	
	free(ptr);
}

int validEmail(char *email){

	int v1=0,v2=0;
	if(strlen(email)==1) return 0;

	for(int i=0; i< *(email+i) != '\0'; i++){
		if(*(email+i)=='@') v1++;
		if(*(email+i)=='.' && v1!=0) v2=1;
	}

    if(v1==1 && v2) return 1;
	else return 0;
}