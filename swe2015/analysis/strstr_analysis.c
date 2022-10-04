#include <string.h>
#include <stdio.h>


char*  _strstr(char *string, char *pat){
	char* k = strstr(string,pat);
	return k;
}

int main(void){
	char string[]="123456789123";
	char pat[]="34";
	printf("%s",strstr(string,pat));
	return 0;
}
