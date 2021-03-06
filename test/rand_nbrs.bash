#!/bin/bash

ARG="3 2 1"

if [ $1 ]; then
	if [ $1 == 10 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 10);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 3 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 3);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 4 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 4);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 5 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 5);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 30 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 30);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 50 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 50);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 100 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 100);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 500 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 500);\
			print(randomlist)' | tr -d ',[]')
	elif [ $1 == 1000 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 1000);\
			print(randomlist)' | tr -d ',[]')
	else
		echo "rand_error: value not handled."
		echo "handled values : 3, 4, 5, 10, 30, 50, 100, 500, 1000"
		echo "Ciao kiss bye"
		exit;
	fi
fi

echo $ARG > ./test/rand_nbrs.log

./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker $ARG
