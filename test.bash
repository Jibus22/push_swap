#!/bin/bash
random10 () {
	for i in `seq 10`
	do
		echo $RANDOM
	done
}

random50 () {
	for i in `seq 50`
	do
		echo $RANDOM
	done
}

random100 () {
	for i in `seq 100`
	do
		echo $RANDOM
	done
}

random500 () {
	for i in `seq 500`
	do
		mod=`expr $RANDOM / 10`
		tot=`expr $RANDOM \* $mod`
		echo $tot
	done
}

#./push_swap 3 2 1 5 4 | wc -l ; ./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
#./push_swap 3 2 5 4 1 | wc -l ; ./push_swap 3 2 5 4 1 | ./checker 3 2 5 4 1

#ARG=$(bash random.bash)
ARG="3 2 1"

if [ $1 ]; then
	if [ $1 == 10 ]; then
		ARG=$(random10);
	elif [ $1 == 50 ]; then
		ARG=$(random50);
	elif [ $1 == 100 ]; then
		ARG=$(random100);
	elif [ $1 == 500 ]; then
		ARG=$(random500);
	fi
fi

#echo $ARG

./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker $ARG
