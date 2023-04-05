#/bin/bash

RST='\033[0m'
RED='\033[0;31m'
GRN='\033[0;32m'


MYCOMMAND="./tlb"

PAGE=1

for I in {1..17}
do
	PAGE=$(($PAGE * 2))
	$MYCOMMAND $PAGE 100000 "results.csv"
done

