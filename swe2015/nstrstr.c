#include <string.h>
#include <stdio.h>

int nstrstr(char *string, char *pat){
	int count = 0,pat_length=-1;
	char *start = string, *value = 0;
	while(pat[++pat_length]!='\0');
	while((value = strstr(start,pat))!=NULL){
		++count,start = value + pat_length - 1;
	}
	return count;
}

int main(void){
	char pat[11], string[21];
	scanf("%s %s",pat,string);
	printf("%d",nstrstr(string,pat));
	return 0;
}
