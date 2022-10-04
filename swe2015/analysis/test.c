#include <stdio.h>
#include <string.h>

#define hash2(p) (((size_t)(p)[0] - ((size_t)(p)[-1] << 3)) % sizeof (shift))


int main(void){
	char hs[]="123456789123456789123456789123456789";
	char ne[]="567891";
	int hs_len = strlen(hs), ne_len = strlen(ne);
	const unsigned char *end = hs + hs_len - ne_len;
	unsigned char shift[256];
	size_t tmp, shift1;
	size_t m1 = ne_len - 1;
	size_t offset = 0;
	memset (shift, 0, sizeof (shift));
	for (int i = 1; i < m1; i++){
		printf("%ld ",hash2(ne+i));
		shift[hash2 (ne + i)] = i;}
	printf("%ld\n",sizeof(shift));
	for(int i = 0; i<256;++i) printf("%d ",shift[i]); 
	return 0;
}
