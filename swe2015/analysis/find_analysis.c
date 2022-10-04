#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* find(char *string, char *pat){
	int i=0, j=0, count=0, pat_length=-1;
	//while(pat[++pat_length]!="\0");
	while(string[i]!='\0'){
		if(pat[j]==string[i]) ++i, ++j;
		else {
			j=0;
			if(pat[j]!=string[i]) ++i;
		}
		if(pat[j]=='\0') return string + i - j;
	}
	return NULL;
}

int main(void){
	char string[] = "123456789", pat[]="56";
	printf("%s",find(string,pat));
	return 0;
}
