#include <stdio.h>

int nfind(char *string, char *pat){
	int i=0, j=0, count=0, pat_length=-1;
	//while(pat[++pat_length]!="\0");
	while(string[i]!='\0'){
		if(pat[j]==string[i]) ++i, ++j;
		else {
			j=0;
			if(pat[j]!=string[i]) ++i;
		}
		if(pat[j]=='\0') ++count, j=0;
	}
	return count;
}

int main(void){
	char pat[11];
	scanf("%s",pat);
	char string[21];
	scanf("%s",string);
	printf("%d",nfind(string,pat));
	return 0;
}
