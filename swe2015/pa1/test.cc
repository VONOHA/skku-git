#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(void){
	int pat_leng = 0, title = 0, scale = 1000000;
	FILE *fp = NULL;
	for(; title<1000; ++title){
		scale += 10000;
		fp = fopen(("testcases1/"+to_string(title)+".txt").c_str(),"w+");
		fprintf(fp,"%d\n",scale);
		pat_leng = rand()%3 + 1;
		for(int i = 0; i<pat_leng; ++i){
			fprintf(fp,"%c", rand()%26+97);
		}
		fprintf(fp,"\n");
		for(int i = 0; i< scale; ++i) fprintf(fp, "%c", rand()%26+97);
		fclose(fp);
	}
	return 0;
}
