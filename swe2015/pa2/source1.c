#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

char inorder[256] = "", postorder[256] = "",**result=0;
int sequence[6] = {1,2,5,11,23,47}, length = 0,row,column, arr[6]={0}, id = 0;

void fill_template(int r, int c, int index){
	
	if(arr[id]<r) arr[++id] = r;

	if(index >= 0) result[r][c] = 0;
	else if(index < 0){ 
		result[r][c] = 0;
		return;}
	else return;
	
	int num = sequence[index];
	
	for(int i=r+1, l = c-1; l>c-num-1; --l,++i) result[i][l] = '/';
	for(int i=r+1, l = c+1; l<c+num+1; ++l,++i) result[i][l] = '\\';

	fill_template( r+num+1, c-num-1, index-1);
	
	fill_template( r+num+1, c+num+1, index-1);
	
}

int main(void){
	
	//receiving the input\
	use getchar 'cause don't know the exact length
	while((letter = getchar()) !='\n'){

		if(isalpha(letter)) inorder[length++]=letter;
	}
	
	length = 0;

	while((letter = getchar()) !='\n'){

		if(isalpha(letter)) postorder[length++]=letter;
	}
	
	//array for depth
	char *depth_arr = (char*)calloc(length,sizeof(char));

	//array for grouping each array store end of\
	the group which will eventually become empty\
	'lend' store left-most index of group which includes \
	corresepoding elements\
	'rend' store right-most index of group which includes \
	corresponding elements
	char lend[256] ={} ;
	char rend[256] = {} ;

	//default setting of grouping array\
	0 on the left right-most index on the right
	for(int i = 0; i<length; ++i) lend[i] = 0, rend[i] = length -1;

	//'left' stores left-most index of group\
	'right' stores right-most index of gruop\
	hash is an array for enhancing the speed\
	by sotre inorder index of alphbets
	char left, right, hash[256] = {0};
	
	//'depth' for depth of tree\
	'index' for index of a current element
	int depth = 0, index;

	for(int i = 0; i<length; ++i) hash[inorder[i]] = i;
	

	for(int i = length - 1; i>=0; --i){
		
		//receiving index from hash table
		index = hash[postorder[i]]; 		
		
		//receiving left-most index and right-most index of the group
		left = lend[index], right = rend[index]; 
		
		//seperating gruop into left and right\
		by incresing depth
		for(int l = left; l<index; ++l) ++depth_arr[l], rend[l] = index -1;
		for(int l = index +1; l<=right; ++l) ++depth_arr[l], lend[l] = index + 1;
	} // get depth of elements in inorder
	
	//get depth of tree
	for(int i = 0; i<length; ++i) if(depth< depth_arr[i]) depth = depth_arr[i];


	//***************************************************************************\
	***********************step for drawing tree*********************************


	row = sequence[depth] + 1, column = sequence[depth+1]; // size of result array
	
	result = (char**)calloc(row,sizeof(char*));
	for(int i = 0; i<row; ++i) result[i] = (char*)calloc(column,sizeof(char)); // result array
	
	for(int i = 0; i<row; ++i) for( int l = 0; l<column; ++l) result[i][l] = ' ';

	fill_template(0,(column-1)/2,depth-1);

	int n = 0,previous_r,previous_c;
	char d,r,c,dr,dc;

	for(int i = 0; i<length; ++i){
		d = depth_arr[i];
		r = arr[d];
		for(; n < column; ++n){
			if(!result[r][n]){
				result[r][n] = inorder[i];
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
