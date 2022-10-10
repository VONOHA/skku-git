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
