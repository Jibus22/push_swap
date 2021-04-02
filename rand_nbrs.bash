#!/bin/bash

ARG="3 2 1"

if [ $1 ]; then
	if [ $1 == 10 ]; then
		ARG=$(python3 -c 'import random;\
			randomlist = random.sample(range(-2147483648, 2147483647), 10);\
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
	fi
fi

echo $ARG > rand_nbrs.log

./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker $ARG
