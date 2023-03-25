#/bin/bash

RST='\033[0m'
RED='\033[0;31m'
GRN='\033[0;32m'

cd ~/SKKU/skku-git/third/swe3005/proj1/source \
	&& make && cd ~/SKKU/skku-git/third/swe3005/proj1

MYCOMMAND="./source/riscv-sim"
ACOMMAND="./sample/riscv-sim"

for I in 1 2 3 4 5 6 7
do
	echo -e "Running Test Case ${I}"
	
	MYOUTPUT=$(${MYCOMMAND} sample/proj1_${I}.bin)
	ANSWER=$(${ACOMMAND} sample/proj1_${I}.bin)

	if [ "${MYOUTPUT}" == "${ANSWER}"  ]; then
	    echo -e "${GRN}####################################${RST}"
		echo -e "${GRN}####### Test Case  ${I} Passed ########${RST}"
		echo -e "${GRN}####################################${RST}\n\n"
    
	else
		echo -e "${RED}####################################${RST}"
		echo -e "${RED}####### Test Case  ${I} Failed ########${RST}"
		echo -e "${RED}####################################${RST}\n\n"

	fi

done


cd ~/SKKU/skku-git/third/swe3005/proj1/source \
	&& make clean && cd ~/SKKU/skku-git/third/swe3005/proj1
