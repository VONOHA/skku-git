#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int nkmp(char *pat, char *string){
	int failure_arr[10]={0}, l = 0,num;
	failure_arr[0]=-1;
	while(pat[l]!='\0'){
		num = failure_arr[l];
		if(pat[num+1]==pat[l++])failure_arr[l] = num+1;
		else failure_arr[l] = -1;
	}

	int i = 0,  j = 0, count = 0;

	while(string[i]!='\0'){
		if(string[i]==pat[j]) ++i, ++j;
		else if(j == 0) ++i;
		else j = failure_arr[j-1]+1;
		if(j == l) ++count, j = 0;
	}

	return count;
}

int main(void){
	printf("-1");
	int scale, start, end;
	char pat[11], address[20]="testcases/";
	char *string = 0;
	FILE *fp = 0, *text=0;
	text = fopen("nkmp.txt","w+");
	printf("0");
	for(int i = 0; i<1000; ++i){
	sprintf(address+10,"%d",i);
	sprintf(address+strlen(address),".txt");
	fp = fopen(address,"r");
	printf("1");
	fscanf(fp, "%d", &scale);
	fscanf(fp, "%s",pat);
	string = (char*)calloc(scale,sizeof(char));
	fscanf(fp,"%s",string);
	start = clock();
	fprintf(text,"%d ",nkmp(string,pat));
	end = clock();
	fprintf(text,"%d\n",end-start);
	fclose(fp);
	free(string);
	}
	fclose(text);
	return 0;
}
