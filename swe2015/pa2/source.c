#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char inorder[256] = "", postorder[256] = "",**result=0;
int sequence[6] = {1,2,5,11,23,47}, length = 0,row,column, arr[6]={0}, id = 0;

void fill_template(int r, int c, int index){
	
	if(arr[id]<r) arr[++id] = r;

	//printf("haey");

	if(index >= 0) result[r][c] = 0;
	else if(index < 0){ 
		result[r][c] = 0;
		return;}
	else return;
	
	//printf("%d\n",index);

	int num = sequence[index];
	
	//printf("%d\n", num);
/*
	for(int i = 0; i<row; ++i) {
		for(int l = 0; l<column; ++l) printf("%c", result[i][l]);
		printf("\n");
	}printf("\n");
*/	

	for(int i=r+1, l = c-1; l>c-num-1; --l,++i) result[i][l] = '/';
	for(int i=r+1, l = c+1; l<c+num+1; ++l,++i) result[i][l] = '\\';

	fill_template( r+num+1, c-num-1, index-1);
	
	fill_template( r+num+1, c+num+1, index-1);
	
}

int main(void){
	//printf("\n");
	char letter;
	int depth = 0, index, top;

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
	} // get depth of elements in inorder
	
	for(int i = 0; i<length; ++i) if(depth< depth_arr[i]) depth = depth_arr[i];

	row = sequence[depth] + 1, column = sequence[depth+1]; // size of result array
	
//	printf("length %d depth %d row %d column %d\n", length, depth, row, column);

	result = (char**)calloc(row,sizeof(char*));
	for(int i = 0; i<row; ++i) result[i] = (char*)calloc(column,sizeof(char)); // result array
	
	for(int i = 0; i<row; ++i) for( int l = 0; l<column; ++l) result[i][l] = ' ';

	fill_template(0,(column-1)/2,depth-1);
	/*
	for(int i = 0; i<row; ++i) {
		for(int l = 0; l<column; ++l) printf("%c", result[i][l]);
		printf("\n");
	}*/
	int n = 0,previous_r,previous_c;
	char d,r,c,dr,dc;

	for(int i = 0; i<length; ++i){
		d = depth_arr[i];
		r = arr[d];
		for(; n < column; ++n){
			if(!result[r][n]){
				result[r][n] = inorder[i];
				//previous_r = r, previous_c = n;
				break;
			}
		}
	}
	


	for(int i = 0; i<row; ++i) for(int l = 0; l<column; ++l) if(!result[i][l]) {
		result[i][l] = ' ';
		for(int a = i+1, b =l+1; a < row && b < column && result[a][b] == '\\'; a++, b++) result[a][b] = ' ';

		for(int a = i+1, b =l-1; a<row && b > -1 && result[a][b] == '/'; a++, b--) result[a][b] = ' ';
	
		for(int a = i-1, b =l-1; a>=-1 && b >= -1 && result[a][b] == '\\'; a--, b--) result[a][b] = ' ';

		for(int a = i-1, b =l+1; a>= -1 && b < column&& result[a][b] == '/'; a--, b++) result[a][b] = ' ';

	}
		
	for(int i = 0; i<row; ++i){
		for(int l = 0 ; l<column; ++l) printf("%c",result[i][l]);
		printf("\n");
	}

	for(int i = 0; i<row; ++i) free(result[i]);
	free(result);
	return 0;
}
