#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int scale, start, end;
	char pat[11],adress[20]="testcases/";
	char* string = 0;
	FILE *fp = 0, *text = fopen("nfind.txt","w+");
	for(int i = 0; i<1000; ++i){
		sprintf(adress+10,"%d",i);
		sprintf(adress+strlen(adress),".txt");
		fp = fopen(adress,"r");
		fscanf(fp,"%d", &scale);
		fscanf(fp,"%s",pat);
		string = (char*)calloc(scale,sizeof(char));
		fscanf(fp,"%s",string);
		start = clock();
		nfind(string,pat);
		end = clock();
		fprintf(text,"%d\n",end-start);
		fclose(fp);

		free(string);}
	return 0;
}
