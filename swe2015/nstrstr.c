#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int nstrstr(char *string, char *pat){
	int count = 0,pat_length=-1;
	char *start = string, *value = 0;
	while(pat[++pat_length]!='\0');
	while((value = strstr(start,pat))!=NULL){
		++count,start = value + pat_length ;
	}
	return count;
}

int main(void){
	int scale, start, end;
	char pat[11], address[20] = "testcases/";
	char *string = 0;
	FILE *fp = 0, *text = fopen("nstrstr.txt","w+");
	for(int i = 0; i<1000; ++i){
		sprintf(address+10, "%d",i);
		sprintf(address+strlen(address),".txt");
		fp = fopen(address,"r");
		fscanf(fp,"%d",&scale);
		fscanf(fp,"%s",pat);
		string = (char*)calloc(scale,sizeof(char));
		fscanf(fp,"%s",string);
		start = clock();
		nstrstr(string,pat);
		end = clock();
		fprintf(text, "%d\n", end-start);
		fclose(fp);
		free(string);
	}
	fclose(text);
	return 0;
}
