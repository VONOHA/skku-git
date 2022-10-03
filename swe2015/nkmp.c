#include <stdio.h>

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
	char pat[11], string[21];
	scanf("%s %s",pat,string);
	printf("%d",nkmp(pat,string));
	return 0;
}
