#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Input  */
/* char* seed: seed given as command line argument #1 (argv[1])*/
/* int key: key given as command line argument #2 (argv[2])*/

/* Output  */
/* char* serial: empty array to be filled with generated serial key */
void generate_serial(char *serial, char *seed, int key) {

  /* #################################### */
  /* ######### <Your Code Here> ######### */
  /* #################################### */

	int digit = key % 10, al = key % 10, num;
	char now;
	for(int i = 0; i<20; ++i){
		now = seed[i];
		if(isdigit(now)){
			num = now - digit;
			if(num < 0x30) num += 0xa;
		}else if(isupper(now)){
			num = now - al;
			if(num < 0x41) num += 0x1a;
		}else {
			num = now - al;
			if(num < 0x61) num += 0x1a;
		} seed[i] = num;
	}
	serial[4] = '-', serial[9] = '-', serial[14] = '-', serial[19] = '-';
	for(int i = 0; i<20; ++i){
		serial[i+i/4] = seed[i];
	}
	serial[24] = '\0';
}

int main(int argc, char **argv) {
  char serial[32] = {0};
  char *seed;
  int key;

  if (argc < 3) {
    printf("Seed and Key not provided\n");
    return 1;
  }

  seed = argv[1];
  key = atoi(argv[2]);

  if (strlen(argv[1]) != 20) {
    printf("Incorrect seed format\n");
    return 1;
  }

  if (key < 17 || key > 255) {
    printf("Incorrect key format\n");
    return 1;
  }

  generate_serial(serial, argv[1], atoi(argv[2]));
  printf("%s\n", serial);
  return 0;
}
