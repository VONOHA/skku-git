#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


void fil(int start, int end, char* arr)


int main(void){
	
	char inorder[256] = "", postorder[256] = "", letter;
	int length = 0, depth = 0, top,index,row, column,sequence[6] = {1,2,5,11,23,47};

	while((letter = getchar()) !='\n'){

		if(isalpha(letter)) inorder[length++]=letter;
	}
	
	length = 0;

	while((letter = getchar()) !='\n'){

		if(isalpha(letter)) postorder[length++]=letter;
	}

	char *depth_arr = (char*)calloc(length,sizeof(char));
	
	for(int i = length - 1; i>=0; --i){
		
		letter = postorder[i];
		
		for(int l = 0; l<length; ++l){
			if(inorder[l] == letter){
				index = l;
				break;
			}
		}

		depth = depth_arr[index];
		if(!depth) top = index;

		for(int l = index-1; l>=0 && depth_arr[l]==depth; --l) ++depth_arr[l];
		for(int l = index+1; l<length && depth_arr[l]==depth; ++l) ++depth_arr[l];
	}
	//printf("%d\n",depth);	
	row = sequence[depth]+1;
	column = sequence[depth+1];

	char **result = (char**)calloc(row, sizeof(char*));
	
	for(int i = 0; i<row; ++i) {
		result[i] = (char*)calloc(column, sizeof(char));
		for(int l = 0; l<column; ++l) result[i][l] = i+l;
	}

	//printf("%d",str_len);
	
	for(int i = 0; i<row; ++i) {
		for(int l = 0; l<column; ++l)printf("%d ",result[i][l]);
		printf("\n");	
	}

	return 0;
}
