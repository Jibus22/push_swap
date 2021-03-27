#!/bin/bash

./push_swap 3 2 1 5 4 | wc -l ; ./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
./push_swap 3 2 5 4 1 | wc -l ; ./push_swap 3 2 5 4 1 | ./checker 3 2 5 4 1
