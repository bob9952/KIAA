#!/bin/bash
{
rm *.tester.tmp;
rm -r test-data/*.tester.tmp;
} 2>/dev/null

g++ $1 -std=c++17 -O3 -o $1.tester.tmp;
if [ ! -f $1.tester.tmp ];
then
	exit 1;
fi;

{
count=1;
for testfile in test-data/in*.txt; do
    #echo $testfile;
	timeout --preserve-status 0.05 ./$1.tester.tmp <$testfile >$testfile.tester.tmp;
	exitstat=$?;
	printf "%2d : " $count;
	if [ $exitstat = 0 ];
	then
		if [[ $(diff -qbB $testfile.tester.tmp ${out_${count}}.txt ) ]]
		then
			echo "Netacan izlaz";
		else
			echo "OK";
		fi;
	elif [ $exitstat = 143 ];
	then
		echo "Prekoraceno vremensko ogranicenje";
	else
		echo "Greska pri izvrsavanju";
	fi;
	count=$((count + 1));
done;

rm $1.tester.tmp;
rm -r test-data/*tester.tmp;

} 2>/dev/null
