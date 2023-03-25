#include "inst.h"
#include <sys/types.h>

int main(int argc, char **argv){


	FILE* fp = fopen(argv[1],"rb");
	uint rawInst, count;
	baseInst* inst;
	bool allocCheck;

	for(int count = 0; fread(&rawInst,sizeof(int),1,fp); ++count)
	{
		if(count)
			printf("\n");

		allocCheck = true;

		printf("inst %d: %08x ",count,rawInst);

		switch(parseOpcode(rawInst))
		{
			case 0x37:
				inst = new uInst(rawInst);
				break;

			case 0x17:
				inst = new uInst(rawInst);
				break;

			case 0x6F:
				inst = new jInst(rawInst);
				break;

			case 0x67:
				inst = new iInst(rawInst);
				break;

			case 0x63:
				inst = new bInst(rawInst);
				break;

			case 0x03:
				inst = new iInst(rawInst);
				break;

			case 0x23:
				inst = new sInst(rawInst);
				break;

			case 0x13:
				inst = new iInst(rawInst);
				break;

			case 0x33:
				inst = new rInst(rawInst);
				break;

			default:
				printf("unknown instruction");
				allocCheck = false;
				break;
		}

		if(allocCheck){
			inst->printInst();
			delete inst;
		}
	}

	return 0;
}
